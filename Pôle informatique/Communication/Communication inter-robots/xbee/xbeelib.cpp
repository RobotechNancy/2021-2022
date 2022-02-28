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
    char errorOpening = serial.openDevice(XB_SERIAL_PORT, XB_BAUDRATE, XB_DATABITS, XB_PARITY, XB_STOPBITS);

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
    \return {XB_AT_E_SUCCESS} succès
    \return {XB_AT_E_ENTER} impossible d'entrer dans le mode AT
    \return {XB_AT_E_API} impossible de configurer le mode API
    \return {XB_AT_E_BAUDRATE} impossible de configurer le baudrate
    \return {XB_AT_E_AES} impossible de configurer le paramètre de chiffrement AES
    \return {XB_AT_E_AES_KEY} impossible de configurer la clé de chiffrement AES 
    \return {XB_AT_E_CHANEL} impossible de configurer le canal de découverte réseau
    \return {XB_AT_E_PAN_ID} impossible de configurer l'ID du réseau
    \return {XB_AT_E_COORDINATOR} impossible de configurer le mode coordinateur
    \return {XB_AT_E_PARITY} impossible de configurer le nombre de bits de parité
    \return {XB_AT_E_16BIT_SOURCE_ADDR} impossible de configurer l'addresse source 16bits
    \return {XB_AD_E_LOW_DEST_ADDR} impossible de sortir du mode AT 
    \return {XB_AT_E_WRITE_CONFIG} impossible d'écrire les paramètres dans la mémoire flash
    \return {XB_AT_E_EXIT} impossible de sortir du mode AT
 */
int XBee::checkATConfig(){
    if(!enterATMode())
	return XB_AT_E_ENTER;

    if(!sendATCommand(XB_AT_CMD_API, XB_AT_V_API))
	return XB_AT_E_API;

    if(!sendATCommand(XB_AT_CMD_BAUDRATE, XB_AT_V_BAUDRATE))
	return XB_AT_E_BAUDRATE;

    if(!sendATCommand(XB_AT_CMD_AES, XB_AT_V_AES))
	return XB_AT_E_AES;

    if(!sendATCommand(XB_AT_CMD_AES_KEY, XB_AT_V_AES_KEY))
	return XB_AT_E_AES_KEY;

    if(!sendATCommand(XB_AT_CMD_CHANEL, XB_AT_V_CHANEL))
	return XB_AT_E_CHANEL;

    if(!sendATCommand(XB_AT_CMD_PAN_ID, XB_AT_V_PAN_ID))
	return XB_AT_E_PAN_ID;

    if(!sendATCommand(XB_AT_CMD_COORDINATOR, XB_AT_V_COORDINATOR))
	return XB_AT_E_COORDINATOR;

    if(!sendATCommand(XB_AT_CMD_PARITY, XB_AT_V_PARITY))
	return XB_AT_E_PARITY;

    if(!sendATCommand(XB_AT_CMD_16BIT_SOURCE_ADDR, XB_AT_V_16BIT_SOURCE_ADDR))
	return XB_AT_E_16BIT_SOURCE_ADDR;

    if(!sendATCommand(XB_AT_CMD_LOW_DEST_ADDR, XB_AT_V_LOW_DEST_ADDR))
	return XB_AT_E_LOW_DEST_ADDR;

    if(!writeATConfig())
	return XB_AT_E_WRITE_CONFIG;

    if(!exitATMode())
	return XB_AT_E_EXIT;

    return XB_AT_E_SUCCESS;
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
    serial.writeString(XB_AT_CMD_ENTER);
    //cout << "* Entrée en mode AT..." << endl;
    delay(2);
    serial.writeString(XB_AT_V_END_LINE);
    return readATResponse(XB_AT_R_SUCCESS);
}

/*!
    \brief Fonction permettant de sortir du mode AT
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::exitATMode(){
    serial.writeString(XB_AT_CMD_EXIT);
    serial.writeString(XB_AT_V_END_LINE);
    //cout << "* Sortie du mode AT..." << endl;
    return readATResponse(XB_AT_R_SUCCESS);
}

/*!
    \brief Fonction permettant d'écrire dans la mémoire flash du module XBee, les paramètres AT définis
    \return true la réponse du module XBee est celle attendue
    \return false la réponse du module XBee n'est pas celle attendue
 */
bool XBee::writeATConfig(){
    serial.writeString(XB_AT_CMD_WRITE_CONFIG);
    serial.writeString(XB_AT_V_END_LINE);
    //cout << "* Ecriture de la configuration AT..." << endl;
    return readATResponse(XB_AT_R_SUCCESS);
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
    serial.writeString(XB_AT_V_END_LINE);
    if(mode == XB_AT_M_GET){
        //cout << "* Envoi de la commande " << command << "...\n";
        return readATResponse(value);
    }else{
        //cout << "* Envoi de la commande " << command << "=" << value << "...\n";
        return readATResponse(XB_AT_R_SUCCESS);
    }
}

//__________________________________________________________
// ::: Envoi/Réception/Traitement des trames de messages :::

/*!
    \brief Fonction permettant de calculer le CRC16 Modbus de la trame XBee envoyée
    \param trame : la trame XBee complète sauf le CRC et le caractère de fin de trame
    \param taille : la taille de la trame
    \return la valeur entière du crc calculée sur 16 bits
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
    \return {XB_TRAME_E_SUCCESS} succès
 */
int XBee::sendTrame(int ad_dest, int code_fct, char* data){
   
    cout << hex << showbase;

    int length_trame = strlen(data)+8;
    int trame[strlen(data)+5];
    trame[0] = XB_V_START;
    trame[1] = XB_ADR_CURRENT_ROBOT;
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
    trame[strlen(data)+8] = XB_V_END;

    for(int i = 0; i < length_trame+1; i++){
        cout << trame[i] << " ";
    }

    cout << endl;

    serial.writeBytes(trame, length_trame);

    return XB_TRAME_E_SUCCESS;
}

/*!
 *  \brief Découpe une trame reçue en fonction de ses paramètres et interprete son code fonction
 *  \return {XB_TRAME_E_SUCCESS} succès
 *  \return {XB_TRAME_E_SIZE} taille de la trame incorrecte ou non concordante
 *  \return {XB_TRAME_E_START} premier caractère de la trame incorrect
 *  \return {XB_TRAME_E_END} dernier caractère de la trame incorrect
 *  \return {XB_TRAME_E_CRC} valeur du CRC incorrecte
 *  \return {XB_TRAME_E_EXP} adresse de l'expéditeur incorrecte ou inconnue
 *  \return {XB_TRAME_E_DEST} addresse du destinataire incorrecte ou inconnue
 */
int XBee::processTrame(vector<int> trame_recue){
    
    if(!isTrameSizeCorrect(trame_recue))
        return XB_TRAME_E_SIZE;

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
        return XB_TRAME_E_START;

    if(!isEndSeqCorrect(trame.end_seq))
        return XB_TRAME_E_END;

    if(!isCRCCorrect(trame.crc_low, trame.crc_high, decoupe_trame, trame_recue[4]+2))
        return XB_TRAME_E_CRC;

    if(!isExpCorrect(trame.adr_emetteur))
        return XB_TRAME_E_EXP;

    if(!isDestCorrect(trame.adr_dest))
        return XB_TRAME_E_DEST;

    processCodeFct(trame.code_fct, trame.adr_emetteur);
    
    return XB_TRAME_E_SUCCESS;
}

/*!
 *  \brief Interprète le code fonction issu d'une trame reçue
 *  \return {XB_FCT_E_SUCCESS} succès
 *  \return {XB_FCT_E_NOT_FOUND} code erreur incorrect
 *  \return {XB_FCT_E_NONE_REACHABLE} code erreur existant mais ne déclenchant aucune action  
 */
int XBee::processCodeFct(int code_fct, int exp){
    if(!isCodeFctCorrect(code_fct))
        return XB_FCT_E_NOT_FOUND;

    char msg[] = {};
    switch(code_fct){
       case XB_FCT_TEST_ALIVE :
           msg[0] = {XB_V_ACK};
           sendTrame(exp, XB_FCT_TEST_ALIVE, msg);
           break;

       default : 
           return XB_FCT_E_NONE_REACHABLE;
    }

    return XB_FCT_E_SUCCESS;
}

/*!
 *  \brief Vérifie si le code fonction donné est présent dans le fichier define.h
 *  \param code_fct : le code fonction à vérifier
 *  \return true : le code fonction est correct
 *  \return false : le code fonction est incorrect/n'existe pas
 */
bool XBee::isCodeFctCorrect(int code_fct){
    int size_list_code_fct = sizeof(XB_LIST_CODE_FCT)/sizeof(XB_LIST_CODE_FCT[0]), i = 0;

    while(i < size_list_code_fct){
        if(XB_LIST_CODE_FCT[i] == code_fct)
            return true;
        i++;
    }

    return false;
}

/*!
 *  \brief Vérifie si la taille de la trame est cohérente
 *  \param trame : la trame à vérifier
 *  \return true : la taille de la trame semble cohérente
 *  \return false : la taille de la trame est incorrecte, trop petite ou non cohérente
 */
bool XBee::isTrameSizeCorrect(vector<int> trame){
    if(trame.size() > 9 && trame.size() == trame[4]+5)
        return true;

    return false;
}

/*!
 *  \brief Vérifie si une adresse d'expéditeur est correcte
 *  \param exp : l'adresse de l'expéditeur à vérifier
 *  \return true : l'adresse est correcte
 *  \return false : l'adresse est incorrecte
 */
bool XBee::isExpCorrect(int exp){
    int size_list_addr = sizeof(XB_LIST_ADR)/sizeof(XB_LIST_ADR[0]), i = 0;

    while(i < size_list_addr){
        if(XB_LIST_ADR[i] == exp)
            return true;

        i++;
    }

    return false;
}

/*!
 *  \brief Vérifie si une adresse de destination est correcte
 *  \param exp : l'adresse de destination à vérifier
 *  \return true : l'adresse est correcte
 *  \return false : l'adresse est incorrecte
 */
bool XBee::isDestCorrect(int dest){
    int size_list_addr = sizeof(XB_LIST_ADR)/sizeof(XB_LIST_ADR[0]), i = 0;

    while(i < size_list_addr){
        if(XB_LIST_ADR[i] == dest)
            return true;

        i++;
    }

    return false;
}

/*!
 *  \brief Vérifie si le caractère de début de la trame correpond à celui attendu
 *  \param value : le caractère à vérifier
 *  \return true : le caratère est bien celui attendu
 *  \return false : le caractère est incorrect
 */
bool XBee::isStartSeqCorrect(int value){
    if(value == XB_V_START)
        return true;

    return false;
}

/*!
 *  \brief Vérifie si le caractère de fin de la trame correpond à celui attendu
 *  \param value : le caractère à vérifier
 *  \return true : le caratère est bien celui attendu
 *  \return false : le caractère est incorrect
 */
bool XBee::isEndSeqCorrect(int value){
    if(value == XB_V_END)
        return true;

    return false;
}

/*!
 *  \brief Vérifie si le CRC reçu est cohérent avec la trame reçue
 *  \param crc_low : les bits de poids faible du CRC reçu
 *  \param crc_high : les bits de poids forts du CRC reçu
 *  \param trame : la trame reçue (en enlevant le CRC et le caratère de fin de trame)
 *  \param trame_size : la taille de le trame telle qu'entrée dans la fonction
 *  \return true : la valeur du CRC reçue est bien celle calculée à partir du reste de la trame
 *  \return false : la valeur du CRC est incohérente ou non calculable
 */
bool XBee::isCRCCorrect(int crc_low, int crc_high, int trame[], int trame_size){
    int crc = crc16(trame, trame_size);

    int newcrc_low = crc & 0xFF;
    int newcrc_high = (crc >> 8) & 0xFF;

    if(newcrc_low == crc_low && newcrc_high == crc_high)
        return true;

    return false;
}

/*!
 *  \brief Permet de lire l'intégralité du buffer UART de réception de la RaspberryPi
 *  \return rep : la valeur du buffer concaténée sous forme d'une chaine de caractère
 */
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

/*!
 *  \brief Permet de lire l'intégralité du buffer UART de réception de la RaspberryPi
 *  \return rep : la valeur du buffer concaténée sous forme d'un vecteur d'entiers
 */
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

/*!
 *  \brief Permet l'attente et la vérification régulée d'une trame en entrée dans le buffer du port Rx de la RaspberryPi et d'appeler la fonction de découpe des trames.
 */
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
        if(msg_recu[i] == XB_V_START)
            list_start_seq.push_back(i);

        if(msg_recu[i] == XB_V_END)
            list_end_seq.push_back(i);
    }

    if(list_start_seq.size() != list_end_seq.size())
        return XB_SUB_TRAME_E_SIZE;

    for(int i = 0; i < list_start_seq.size(); i++){
        if(list_start_seq[i] > list_end_seq[i])
            return XB_SUB_TRAME_E_REPARTITION;

        if(i != 0){
            if(list_start_seq[i] != list_end_seq[i-1]-1)
                return XB_SUB_TRAME_E_DECOUPAGE;
        }
    }

    if(list_start_seq[0] != 0)
        return XB_SUB_TRAME_E_START;

    if(list_end_seq[list_end_seq.size()] != msg_recu[msg_recu.size()])
        return XB_SUB_TRAME_E_END;
    
    for(int i = 0; i < msg_recu.size(); i++){
       for(i = list_start_seq[i]; i < list_end_seq[i]; i++){
            decoupe.push_back(msg_recu[i]);
       }
       print(decoupe);
       processTrame(decoupe);
    }   

    return XB_SUB_TRAME_E_SUCCESS;  
}

void XBee::sendHeartbeat(){
   while(true){
      delay(1/100);
      sendTrame(XB_ADR_ROBOT_02, XB_FCT_TEST_ALIVE, stringToChar(""));
   } 
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
