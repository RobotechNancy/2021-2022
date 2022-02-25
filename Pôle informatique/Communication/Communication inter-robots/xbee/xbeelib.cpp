/*!
    \file    xbeelib.cpp
    \brief   Fichier source de la classe XBee. Cette classe est utilisée afin de programmer les modules XBee en UART et de mettre en place des communications entre différents modules XBee.
    \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
    \version 1.0
    \date    03/02/2022
 */
#include "xbeelib.h"
#include <iterator>

using namespace std;

serialib serial;


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
void XBee::delay(unsigned int time){ std::this_thread::sleep_for(std::chrono::milliseconds(time*1000)); }


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
int XBee::crc16(int trame[], int taille){
    int crc = 0xFFFF, count = 0;
    int octet_a_traiter;
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
        
    }while(count < taille);

    return crc;
}

/*!
    \brief Fonction permettant d'envoyer une trame de message structurée via UART en XBee
    \param ad_dest : l'adresse du destinataire du message
    \param code_fct : le code de la fonction concernée par le message
    \param data : les valeurs des paramètres demandées par le code fonction
 */
int XBee::sendTrame(int ad_dest, int code_fct, char* data){
   
    cout << hex << showbase;

    int length_trame = strlen(data)+8;
    int trame[strlen(data)+5];
    trame[0] = START_SEQ;
    trame[1] = CURRENT_ROBOT;
    trame[2] = ad_dest;
    trame[3] = ++ID_TRAME;
    trame[4] = strlen(data)+3;
    trame[5] = code_fct;
 
    for(size_t i = 0; i < strlen(data); i++){
        trame[i+6] = data[i]; 
    }

    int crc = crc16(trame, strlen(data)+5);
    uint8_t crc_low = crc & 0xFF;
    uint8_t crc_high = (crc >> 8) & 0xFF;

    trame[strlen(data)+6] = crc_low;
    trame[strlen(data)+7] = crc_high;
    trame[strlen(data)+8] = END_SEQ;

    for(int i = 0; i < length_trame+1; i++){
        cout << trame[i] << " ";
    }

    cout << endl;

    serial.writeBytes(trame, length_trame);

    return XBEE_ERROR_SUCCESS;
}

int XBee::processTrame(vector<int> trame_recue){
    
    if(!isTrameSizeCorrect(trame_recue))
        return TRAME_ERR_SIZE;

    Trame_t trame = {
        .start_seq = trame_recue[0],
        .adr_emetteur = trame_recue[1],
        .adr_dest = trame_recue[2],
        .id_trame = trame_recue[3],
        .nb_octets_msg = trame_recue[4]-3,
        .code_fct = trame_recue[5],
        .crc_low = trame_recue[3+trame_recue[4]],
        .crc_high = trame_recue[4+trame_recue[4]],
        .end_seq = trame_recue[5+trame_recue[4]]
    };

    vector<int> data {};
    
    for(int i = 0; i < trame.nb_octets_msg; i++){
       data.push_back(trame_recue[6+i]); 
    }

    trame.param = data;

    afficherTrameRecue(trame);

    int decoupe_trame[trame_recue[4]+5];

    for(int i = 0; i < trame_recue[4]+3; i++){
        decoupe_trame[i] = trame_recue[i];
    }

    if(!isStartSeqCorrect(trame.start_seq))
        return TRAME_ERR_START_SEQ;

    if(!isEndSeqCorrect(trame.end_seq))
        return TRAME_ERR_END_SEQ;

    if(!isCRCCorrect(trame.crc_low, trame.crc_high, decoupe_trame, trame_recue[4]+2))
        return TRAME_ERR_CRC;

    if(!isExpCorrect(trame.adr_emetteur))
        return TRAME_ERR_EXP;

    if(!isDestCorrect(trame.adr_dest))
        return TRAME_ERR_DEST;

    processCodeFct(trame.code_fct, trame.adr_emetteur);
    
    return XBEE_ERROR_SUCCESS;
}

int XBee::processCodeFct(int code_fct, int exp){
    if(!isCodeFctCorrect(code_fct))
        return CODE_FCT_ERR;

    char msg[] = {};
    switch(code_fct){
       case TEST_ALIVE :
           msg[0] = {RETURN_ACK};
           sendTrame(exp, TEST_ALIVE, msg);
           break;

       default : 
           return CODE_FCT_NT;
    }

    return XBEE_ERROR_SUCCESS;
}

bool XBee::isCodeFctCorrect(int code_fct){
    int size_list_code_fct = sizeof(LIST_CODE_FCT)/sizeof(LIST_CODE_FCT[0]), i = 0;

    while(i < size_list_code_fct){
        if(LIST_CODE_FCT[i] == code_fct)
            return true;
        i++;
    }

    return false;
}

bool XBee::isTrameSizeCorrect(vector<int> trame){
    if(trame.size() == trame[4]+5)
        return true;

    return false;
}

bool XBee::isExpCorrect(int exp){
    int size_list_addr = sizeof(LIST_ADDR)/sizeof(LIST_ADDR[0]), i = 0;

    while(i < size_list_addr){
        if(LIST_ADDR[i] == exp)
            return true;

        i++;
    }

    return false;
}

bool XBee::isDestCorrect(int dest){
    int size_list_addr = sizeof(LIST_ADDR)/sizeof(LIST_ADDR[0]), i = 0;

    while(i < size_list_addr){
        if(LIST_ADDR[i] == dest)
            return true;

        i++;
    }

    return false;
}

bool XBee::isStartSeqCorrect(int value){
    if(value == START_SEQ)
        return true;

    return false;
}

bool XBee::isEndSeqCorrect(int value){
    if(value == END_SEQ)
        return true;

    return false;
}

bool XBee::isCRCCorrect(int crc_low, int crc_high, int trame[], int trame_size){
    int crc = crc16(trame, trame_size);

    int newcrc_low = crc & 0xFF;
    int newcrc_high = (crc >> 8) & 0xFF;

    if(newcrc_low == crc_low && newcrc_high == crc_high)
        return true;

    return false;
}

string XBee::readBuffer(){
    char *reponse(0);
    unsigned int timeout = 100;
    reponse = new char;
    string rep = "";
    delay(1);
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

vector<int> XBee::readBytes(){
    int *rep;
    vector<int> rep_vector;
    delay(1);
    BUFFER_SIZE = serial.available();

    serial.readBytes(rep, BUFFER_SIZE);
   
    for(int i = 0; i < BUFFER_SIZE; i++){
        rep_vector.push_back(rep[i]);
    }

    return rep_vector;
}

void XBee::waitForATrame(){
   while(true){
     vector<int> rep;

     delay(1/100);
     
     if(serial.available() > 0){
       rep = readBytes();

       subTrame(rep);
     }
   }
}

int XBee::subTrame(vector<int> msg_recu){

    vector<int> list_start_seq {};
    vector<int> list_end_seq {};
    vector<int> decoupe {};

    for(int i = 0; i < msg_recu.size(); i++){
        if(msg_recu[i] == START_SEQ)
            list_start_seq.push_back(i);

        if(msg_recu[i] == END_SEQ)
            list_end_seq.push_back(i);
    }

    if(list_start_seq.size() != list_end_seq.size())
        return -1;

    for(int i = 0; i < list_start_seq.size(); i++){
        if(list_start_seq[i] > list_end_seq[i])
            return -2;

        if(i != 0){
            if(list_start_seq[i] != list_end_seq[i-1]-1)
                return -3;
        }
    }

    if(list_start_seq[0] != 0)
        return -4;

    if(list_end_seq[list_end_seq.size()] != msg_recu.size())
        return -5;
    
    for(int i = 0; i < msg_recu.size(); i++){
       for(i = list_start_seq[i]; i < list_end_seq[i]; i++){
            decoupe.push_back(msg_recu[i]);
       }
       processTrame(decoupe);
    }   

    return XBEE_ERROR_SUCCESS;  
}

void XBee::sendHeatbeat(){
    
}

void XBee::sendMsg(string msg){
    serial.writeString(stringToChar(msg));
    //cout << "Message envoyé avec succès !" << endl;
}

char* XBee::stringToChar(string chaine){
    char* message = strcpy(new char[chaine.size() + 1], chaine.c_str());
    return message;
}

string XBee::charToString(char* message){
    string chaine = string(message);
    return chaine;
}

void XBee::afficherTrameRecue(Trame_t trame){
    cout << hex << showbase;
    cout << "\t-> Start seq : " << trame.start_seq << endl;
    cout << "\t-> Emetteur : " << trame.adr_emetteur << endl;
    cout << "\t-> Destinataire : " << trame.adr_dest << endl;
    cout << "\t-> Id trame : " << trame.id_trame << endl;
    cout << "\t-> Taille msg : " << trame.nb_octets_msg << endl;
    cout << "\t-> Code fct : " << trame.code_fct << endl;
    cout << "\t-> Data : ";
    print(trame.param);
    cout << "\t-> CRC : " << trame.crc_low << " " << trame.crc_high << endl;
    cout << "\t-> End seq : " << trame.end_seq << endl;
}

void XBee::print(const vector<int> &v){
    copy(v.begin(), v.end(),
            ostream_iterator<int>(cout, " "));
    cout << endl;
}
