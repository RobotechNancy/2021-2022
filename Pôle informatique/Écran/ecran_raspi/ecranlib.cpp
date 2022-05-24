#include "ecranlib.h"

using namespace std;

serialib serial;
Log logEcran("ecran");

//_____________________________________
// ::: Constructeurs et destructeurs :::

/*!
    \brief Constructeur de la classe xbee.
*/
Ecran::Ecran(){ }

/*!
    \brief Destructeur de la classe xbee.
*/
Ecran::~Ecran(){ }


//_________________________________________
// ::: Configuration and initialisation :::

int Ecran::openSerialConnection(){
    int errorOpening;
    errorOpening = serial.openDevice(EC_SERIAL_PORT_DEFAULT, EC_BAUDRATE_DEFAULT, EC_DATABITS_DEFAULT, EC_PARITY_DEFAULT, EC_STOPBITS_DEFAULT);      

    if (errorOpening != 500)
        logEcran << "(serial) /!\\ erreur " << errorOpening << " : impossible d'ouvrir le port " << EC_SERIAL_PORT_DEFAULT  << " - baudrate : " << EC_BAUDRATE_DEFAULT << " - parité : " << EC_PARITY_DEFAULT << mendl;
    else{
        logEcran << "(serial) connexion ouverte avec succès sur le port " << EC_SERIAL_PORT_DEFAULT << " - baudrate : " << EC_BAUDRATE_DEFAULT << " - parité : " << EC_PARITY_DEFAULT << mendl;
	}    

    return errorOpening;
}

/*!
    \brief Nettoyage du buffer et fermeture de la connexion UART entre la RaspberryPi et le module XBee
 */
void Ecran::closeSerialConnection(){
    serial.flushReceiver();
    logEcran << "(serial) buffer Rx nettoyé avec succès" << mendl;
    
    serial.closeDevice();
    logEcran << "(serial) connexion série fermée avec succès" << mendl;
}

void Ecran::sendMsg(uint8_t mode, uint8_t categorie, uint8_t sous_categorie, uint8_t *value){
    uint8_t length_trame = (sizeof(value)/sizeof(value[0]))+3;
    uint8_t trame[length_trame];

    trame[0] = mode;
    trame[1] = categorie;
    trame[2] = sous_categorie;

    for(size_t i = 0; i < sizeof(value)/sizeof(value[0]); i++){
        trame[i+3] = value[i]; 
    }

    trame[(sizeof(value)/sizeof(value[0]))+3] = EC_FIN_TRAME_1;
    trame[(sizeof(value)/sizeof(value[0]))+4] = EC_FIN_TRAME_2;

    serial.writeBytes(trame, length_trame);

    logEcran << "(sendMsg) envoi de la trame effectué avec succès" << mendl; 
}


string Ecran::readString() {
     char *reponse(0);
     unsigned int timeout = 100;
     reponse = new char;
     string rep;
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
    \brief Fonction permettant de retarder l'exécution du code
    \param time : temps du retard en secondes
 */
void Ecran::delay(unsigned int time){ std::this_thread::sleep_for(std::chrono::milliseconds(time*1000)); }
