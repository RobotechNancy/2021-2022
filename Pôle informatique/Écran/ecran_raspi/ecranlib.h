/*!
 \file    xbeelib.h
 \brief   Fichier d'en-tête de la classe XBee. Cette classe est utilisée afin de programmer les modules XBee en UART et de mettre en place des communications entre différents modules XBee.
 \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 \version 3.0
 \date    10/03/2022
 */
#ifndef ECRAN_H
#define ECRAN_H

#include "ecran_define.h"
#include "serialib.h"
#include "loglib.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <iterator>

/*!  \class     XBee
 *   \brief     Cette classe est utilisée pour la communication entre un module XBee et une RaspberryPi et entre plusieurs modules XBee.
 */
class Ecran{

public:

    // Constructeur de la classe
    Ecran();

    // Desctructeur de la classe
    ~Ecran();
    
    // Ouverture de la connexion série
    int openSerialConnection();

    // Fermeture de la connexion série
    void closeSerialConnection();

    void sendMsg(uint8_t mode, uint8_t categorie, uint8_t sous_categorie, uint8_t *value);

    std::string readString();

private:

    /*!
     * \typedef Trame_t
     * \brief Format des trames reçues en fonction des paramètres de la trame
     */  
    typedef struct{
      uint8_t mode;
      uint8_t categorie;
      uint8_t sous_categorie;
      uint8_t valeur;

    } Trame_t;

    // Retard de temporisation dans l'exécution du code
    void delay(unsigned int time);

};

#endif // XBEE_H
