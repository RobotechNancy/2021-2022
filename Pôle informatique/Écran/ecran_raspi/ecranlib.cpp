/*!
 \file    ecranlib.h
 \brief   Fichier d'en-tête de la classe Ecran. Cette classe est utilisée afin de communique en UART avec l'écran sur la RaspberryPi.
 \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 \version 1.0
 \date    31/05/2022
 */
#include "ecranlib.h"

using namespace std;

serialib serial;
Log logEcran("ecran");

//_____________________________________
// ::: Constructeurs et destructeurs :::

/*!
    \brief Constructeur de la classe Ecran.
*/
Ecran::Ecran(){ }

/*!
    \brief Destructeur de la classe Ecran.
*/
Ecran::~Ecran(){ }


//_________________________________________
// ::: Configuration and initialisation :::

/*!
    \brief Nettoyage du buffer et ouverture de la connexion UART entre la RaspberryPi et l'écran
    \return 500 succès
    \return -501 port série non trouvé
    \return -502 erreur lors de l'ouverture du port série
    \return -503 erreur lors de la récupération des informations du port série
    \return -504 baudrate non reconnu
    \return -505 erreur lors de l'écriture de la configuration du port série
    \return -506 erreur lors de l'écriture du timeout
    \return -507 databits non reconnus
    \return -508 stopbits non reconnus
    \return -509 parité non reconnue
 */
int Ecran::openSerialConnection(){
    int errorOpening;
    errorOpening = serial.openDevice(EC_SERIAL_PORT_DEFAULT, EC_BAUDRATE_DEFAULT, EC_DATABITS_DEFAULT, EC_PARITY_DEFAULT, EC_STOPBITS_DEFAULT);      

    if (errorOpening != EC_SER_E_SUCCESS)
        logEcran << "(serial) /!\\ erreur " << errorOpening << " : impossible d'ouvrir le port " << EC_SERIAL_PORT_DEFAULT  << " - baudrate : " << EC_BAUDRATE_DEFAULT << " - parité : " << EC_PARITY_DEFAULT << mendl;
    else{
        logEcran << "(serial) connexion ouverte avec succès sur le port " << EC_SERIAL_PORT_DEFAULT << " - baudrate : " << EC_BAUDRATE_DEFAULT << " - parité : " << EC_PARITY_DEFAULT << mendl;
	}    

    return errorOpening;
}

/*!
    \brief Nettoyage du buffer et fermeture de la connexion UART entre la RaspberryPi et l'écran
 */
void Ecran::closeSerialConnection(){
    serial.flushReceiver();
    logEcran << "(serial) buffer Rx nettoyé avec succès" << mendl;
    
    serial.closeDevice();
    logEcran << "(serial) connexion série fermée avec succès" << mendl;
}

/*!
    \brief Fonction permettant d'envoyer une trame de message structurée via UART à l'écran
    \param mode : le mode de configuration de l'écran
    \param categorie : la catégorie correspondant au mode choisi
    \param sous_categorie : la sous-catégorie (spécification) en fonction de la catégorie choisie
    \param value : les data à transmettre
    \return 200 succès
    \return -201 taille de la trame incorrecte
    \return -202 data de la trame incorrecte
    \return -203 fin de trame incorrecte
    \return -204 mode choisi pour la trame incorrect ou inconnu 
    \return -205 catégorie choisie pour la trame incorrecte ou inconnue 
    \return -206 sous-catégorie choisie pour la trame incorrecte ou inconnue 
 */
int Ecran::sendTrame(Trame_t trame_recue){
    int length_trame = 0;

    if(trame_recue.taille >= 5)
        length_trame = trame_recue.taille;
    else
        return EC_TRAME_E_SIZE;

    uint8_t trame[length_trame];

    trame[0] = trame_recue.mode;
    trame[1] = trame_recue.categorie;
    trame[2] = trame_recue.sous_categorie;

    for(size_t i = 0; i < sizeof(trame_recue.valeur)/sizeof(trame_recue.valeur[0]); i++){
        trame[i+3] = trame_recue.valeur[i]; 
    }

    trame[length_trame-2] = EC_FIN_TRAME_1;
    trame[length_trame-1] = EC_FIN_TRAME_2;

    serial.writeBytes(trame, length_trame);

    logEcran << "(sendMsg) envoi de la trame effectué avec succès" << mendl; 
    return EC_TRAME_E_SUCCESS;
}

/*!
    \brief Fonction permettant de retarder l'exécution du code
    \param time : temps du retard en secondes
 */
void Ecran::delay(unsigned int time){ std::this_thread::sleep_for(std::chrono::milliseconds(time*1000)); }
