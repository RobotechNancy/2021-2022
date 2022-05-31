/*!
 \file    ecranlib.h
 \brief   Fichier d'en-tête de la classe Ecran. Cette classe est utilisée afin de communique en UART avec l'écran sur la RaspberryPi.
 \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 \version 1.0
 \date    31/05/2022
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

/*!
  * \typedef Trame_t
  * \brief Format des trames reçues en fonction des paramètres de la trame
*/  
typedef struct{
  Mode_Ecran_t mode;
  Categorie_Ecran_t categorie;
  Sous_Categorie_Ecran_t sous_categorie;
  uint8_t *valeur;
  int taille;
} Trame_t;

/*!  \class     Ecran
 *   \brief     Cette classe est utilisée pour la communication entre un ecran STM32F7G et une RaspberryPi.
 */
class Ecran{

public:

    // Constructeur de la classe écran
    Ecran();

    // Desctructeur de la classe écran
    ~Ecran();
    
    // Ouverture de la connexion série
    int openSerialConnection();

    // Fermeture de la connexion série
    void closeSerialConnection();

    // Envoi d'une trame en UART à l'écran
    void sendTrame(Trame_t trame);

private:

    // Retard de temporisation dans l'exécution du code
    void delay(unsigned int time);

};

#endif // XBEE_H
