/*!
    \file    xbeelib.cpp
    \brief   Fichier source de la classe XBee. Cette classe est utilisée afin de programmer les modules XBee en UART et de mettre en place des communications entre différents modules XBee.
    \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
    \version 1.0
    \date    03/02/2022
 */
#include "xbeelib.h"

using namespace std;

serialib serial;

/*!
    \struct Trame
    \brief Structure permettant de définir une trame de message reçue et envoyée
 */
struct Trame{
    int id_exp;
    int id_dest;
    int code_fct;
    int id_trame;
    int size;
    string data;
};

//_____________________________________
// ::: Constructeurs et destructeurs :::

/*!
    \brief Constructeur de la classe xbee.
*/
XBee::XBee(){ }

/*!
    \brief Destructeur de la classe xbee.
*/
XBee::~XBee(){ }


//_________________________________________
// ::: Configuration and initialisation :::

/*!
    \brief Nettoyage du buffer et ouverture de la connexion UART entre la RaspberryPi et le module XBee
    \return 1 succès
    \return -1 port série non trouvé
    \return -2 erreur lors de l'ouverture du port série
    \return -3 erreur lors de la récupération des informations du port série
    \return -4 baudrate non reconnu
    \return -5 erreur lors de l'écriture de la configuration du port série
    \return -6 erreur lors de l'écriture du timeout
    \return -7 databits non reconnus
    \return -8 stopbits non reconnus
    \return -9 parité non reconnue
 */
int XBee::openSerialConnection(){
    serial.flushReceiver();
    char errorOpening = serial.openDevice(SERIAL_PORT, BAUDRATE, DATABITS, PARITY, STOPBITS);

    return (int) errorOpening;
}

/*!
    \brief Nettoyage du buffer et fermeture de la connexion UART entre la RaspberryPi et le module XBee
 */
void XBee::closeSerialConnection(){
    serial.flushReceiver();
    serial.closeDevice();
}

//_________________________________________
// ::: Configuration en mode AT :::

/*!
    \brief Vérification et paramétrage de la bonne configuration pour le module XBee
    \return 0 succès
    \return -1 impossible d'entrer dans le mode AT
    \return -2 impossible de configurer le mode API
    \return -3 impossible de configurer le baudrate
    \return -4 impossible de configurer le paramètre de chiffrement AES
    \return -5 impossible de configurer la clé de chiffrement AES 
    \return -6 impossible de configurer le canal de découverte réseau
    \return -7 impossible de configurer l'ID du réseau
    \return -8 impossible de configurer le mode coordinateur
    \return -9 impossible de configurer le nombre de bits de parité
    \return -10 impossible de configurer l'addresse source 16bits
    \return -11 impossible de sortir du mode AT 
    \return -12 impossible d'écrire les paramètres dans la mémoire flash
 */
int XBee::checkATConfig(){
    if(!enterATMode())
	return AT_ERROR_ENTER;

    if(!sendATCommand(AT_GET_API, AT_VALUE_API, AT_MODE_SET))
	return AT_ERROR_API;

    if(!sendATCommand(AT_GET_BAUDRATE, AT_VALUE_BAUDRATE, AT_MODE_SET))
	return AT_ERROR_BAUDRATE;

    if(!sendATCommand(AT_GET_AES, AT_VALUE_AES, AT_MODE_SET))
	return AT_ERROR_AES;

    if(!sendATCommand(AT_GET_AES_KEY, AT_VALUE_AES_KEY, AT_MODE_SET))
	return AT_ERROR_AES_KEY;

    if(!sendATCommand(AT_GET_CHANEL, AT_VALUE_CHANEL, AT_MODE_SET))
	return AT_ERROR_CHANEL;

    if(!sendATCommand(AT_GET_PAN_ID, AT_VALUE_PAN_ID, AT_MODE_SET))
	return AT_ERROR_PAN_ID;

    if(!sendATCommand(AT_GET_COORDINATOR, AT_VALUE_COORDINATOR, AT_MODE_SET))
	return AT_ERROR_COORDINATOR;

    if(!sendATCommand(AT_GET_PARITY, AT_VALUE_PARITY, AT_MODE_SET))
	return AT_ERROR_PARITY;

    if(!sendATCommand(AT_GET_16BIT_SOURCE_ADDR, AT_VALUE_16BIT_SOURCE_ADDR, AT_MODE_SET))
	return AT_ERROR_16BIT_SOURCE_ADDR;

    if(!sendATCommand(AT_GET_LOW_DEST_ADDR, AT_VALUE_LOW_DEST_ADDR, AT_MODE_SET))
	return AT_ERROR_LOW_DEST_ADDR;

    if(!writeATConfig())
	return AT_ERROR_WRITE_CONFIG;

    if(!exitATMode())
	return AT_ERROR_EXIT;

    return AT_ERROR_SUCCESS;
}

/*!
    \brief Fonction permettant de retarder l'exécution du code
    \param time : temps du retard en secondes
 */
void XBee::delay(unsigned int time){ usleep(time*1000000); }


/*!
    \brief Fonction permettant de lire la réponse à un envoi de commande AT au module XBee
    \param value : la valeur de réponse attendue pour la commande envoyée
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::readATResponse(const char *value){
    string reponse = readBuffer();

    if(reponse == value) return true;
    else return false;
}

/*!
    \brief Fonction permettant d'entrer dans le mode AT
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::enterATMode(){
    serial.writeString(AT_ENTER);
    //cout << "* Entrée en mode AT..." << endl;
    delay(2);
    serial.writeString(AT_END_LINE);
    return readATResponse(AT_SUCCESS_VALUE);
}

/*!
    \brief Fonction permettant de sortir du mode AT
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::exitATMode(){
    serial.writeString(AT_EXIT);
    serial.writeString(AT_END_LINE);
    //cout << "* Sortie du mode AT..." << endl;
    return readATResponse(AT_SUCCESS_VALUE);
}

/*!
    \brief Fonction permettant d'écrire dans la mémoire flash du module XBee, les paramètres AT définis
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::writeATConfig(){
    serial.writeString(AT_WRITE_CONFIG);
    serial.writeString(AT_END_LINE);
    //cout << "* Ecriture de la configuration AT..." << endl;
    return readATResponse(AT_SUCCESS_VALUE);
}

/*!
    \brief Fonction permettant d'envoyer en UART via le port série une commmande AT
    \param command : le paramètre AT a envoyer au module
    \param value : la valeur de réponse attendue
    \param mode : le mode de transmission de la commande AT (mode lecture ou écriture)
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::sendATCommand(const char *command, const char *value, unsigned int mode){
    serial.writeString(command);
    serial.writeString(value);
    serial.writeString(AT_END_LINE);
    if(mode == AT_MODE_GET){
        //cout << "* Envoi de la commande " << command << "...\n";
        return readATResponse(value);
    }else{
        //cout << "* Envoi de la commande " << command << "=" << value << "...\n";
        return readATResponse(AT_SUCCESS_VALUE);
    }
}

//__________________________________________________________
// ::: Envoi/Réception/Traitement des trames de messages :::

/*!
    \brief Fonction permettant de calculer le CRC16 Modbus de la trame XBee envoyée
    \param trame : la trame XBee complète sauf le CRC et le caractère de fin de trame
    \return la valeur entière du crc calculé sur 16 bits
 */
int XBee::crc16(vector<uint8_t> trame){
    int crc = 0xFFFF, count = 0;
    unsigned char octet_a_traiter;
    const int POLYNOME = 0xA001;

    octet_a_traiter = trame[0];

    do{
        crc ^= octet_a_traiter;
        for(int i = 0; i < 8; i++){

            if((crc%2)!=0)
	        crc = (crc >> 1) ^ POLYNOME;

            else
                crc = (crc >> 1);

        }
        count++;
        octet_a_traiter = trame[count];

    }while(count < trame.size());

    return crc;
}

/*!
    \brief Fonction permettant d'envoyer une trame de message structurée via UART en XBee
    \param ad_dest : l'adresse du destinataire du message
    \param code_fct : le code de la fonction concernée par le message
    \param data : les valeurs des paramètres demandées par le code fonction
 */
char* XBee::sendTrame(uint8_t ad_dest, uint8_t code_fct, char* data){
    string trame_str = "";
    vector<uint8_t>trame((strlen(data)+8)*4);

    trame.push_back(START_SEQ);
    trame.push_back(CURRENT_ROBOT);
    trame.push_back(ad_dest);
    trame.push_back(++ID_TRAME);
    trame.push_back(strlen(data)+1);
    trame.push_back(TEST_ALIVE);
    
    for(uint8_t i = 0; i < strlen(data); i++){
        trame.push_back(data[i]); 
    }

    int crc = crc16(trame);
    
    trame.push_back(crc);
    trame.push_back(END_SEQ);

    stringstream ss;

    for(uint8_t i : trame){
       if(i != 0)
       ss << hex << setfill('0') << setw(2) << int(i);
    }

    trame_str = ss.str();

    cout << "Trame envoyée convertie : " << trame_str << endl;

    //serial.writeString(stringToChar(trame));
    return stringToChar(trame_str);
}

void XBee::processTrame(char* trame){
    string trame_convertie = charToString(trame);

    Trame trame_recue;
    trame_recue.id_exp = stoi(trame_convertie.substr(2,2));
    trame_recue.id_dest = stoi(trame_convertie.substr(4,2));
    trame_recue.id_trame = stoi(trame_convertie.substr(6,2));
    trame_recue.size = stoi(trame_convertie.substr(8,2));
    trame_recue.code_fct = stoi(trame_convertie.substr(10,2));
    trame_recue.data = trame_convertie.substr(12,2*trame_recue.size-2);

    cout << "STX : " << hex << showbase << stoi(trame_convertie.substr(0,2)) << endl;
    cout << "ID EXP : " << trame_recue.id_exp << endl;
    cout << "ID DEST : " << trame_recue.id_dest << endl;
    cout << "ID TRAME : " << trame_recue.id_trame << endl;
    cout << "TAILLE MSG : " << trame_recue.size << endl;
    cout << "CODE FCT : " << trame_recue.code_fct << endl;
    cout << "DATA : " << trame_recue.data << endl;
    cout << "CRC : " << stoi(trame_convertie.substr(12+2*trame_recue.size-2)) << endl;
    //cout << "EOT : " << stoi(trame_convertie.substr(12+2*trame_recue.size, 2)) << endl;
}

string XBee::readBuffer(){
    char *reponse(0);
    unsigned int timeout = 100;
    reponse = new char;
    delay(1);
    string rep = "";
    int i = 0;
    while(serial.available() > 0){
        i++;
        serial.readChar(reponse, timeout);
        rep += *reponse;
    }
    delete reponse;
    reponse = 0;

    return rep;
}

void XBee::sendMsg(string msg){
    serial.writeString(stringToChar(msg));
    cout << "Message envoyé avec succès !" << endl;
}

char* XBee::stringToChar(string chaine){
    char* message = new char(chaine.length() + 1);
    strcpy(message, chaine.c_str());

    return message;
}

string XBee::charToString(char* message){
    string chaine = string(message);
    
    return chaine;
}
