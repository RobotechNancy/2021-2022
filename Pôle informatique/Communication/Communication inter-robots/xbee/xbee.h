/*!
 \file    xbee.h
 \brief   Fichier d'en-tête de la classe XBee. Cette classe est utilisée afin de programmer les modules XBee en UART et de mettre en place des communications entre différents modules XBee.
 \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 \version 1.0
 \date    03/02/2022
 */

#ifndef XBEE_H
#define XBEE_H

#include "define.h"
#include "serialib.h"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

/*!  \class     xbee
     \brief     Cette classe est utilisée pour la communication entre un module XBee et une RaspberryPi et entre plusieurs modules XBee.
*/
class xbee{

public:

    // Constructeur de la classe
    xbee();

    // Desctructeur de la classe
    ~xbee();
    
    // Ouverture de la connexion série
    int openSerialConnection();

    // Fermeture de la connexion série
    void closeSerialConnection();
    
    // Entrée dans le mode de configuration AT
    bool enterATMode();

    // Sortie du mode de configuration AT
    bool exitATMode();

    // Vérification et correction de la configuration AT du module
    int checkATConfig();

    // Lecture de la réponse du module à une commande AT
    bool readATResponse(const char *value = AT_EMPTY_VALUE);

    // Envoi d'une commande AT 
    bool sendATCommand(const char *command, const char *value, unsigned int mode);

    // Ecriture de la configuration AT dans la mémoire flash du module
    bool writeATConfig();

    // Création et envoi de la trame de message structurée
    void sendTrame(char ad_dest, char code_fct, char data[]);

private:

    // Calcul du CRC16 Modbus de la trame
    int crc16(std::vector<char> trame);

    // Retard de temporisation dans l'exécution du code
    void delay(unsigned int time);
};

#endif