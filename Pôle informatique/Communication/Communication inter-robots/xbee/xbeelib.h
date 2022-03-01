/*!
 \file    xbeelib.h
 \brief   Fichier d'en-tête de la classe XBee. Cette classe est utilisée afin de programmer les modules XBee en UART et de mettre en place des communications entre différents modules XBee.
 \author  Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 \version 3.0
 \date    28/02/2022
 */

#ifndef XBEE_H
#define XBEE_H

#include "define.h"
#include "serialib.h"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <bitset>

/*!  \class     XBee
 *   \brief     Cette classe est utilisée pour la communication entre un module XBee et une RaspberryPi et entre plusieurs modules XBee.
 */
class XBee{

public:

    // Constructeur de la classe
    XBee();

    // Desctructeur de la classe
    ~XBee();
    
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
    bool readATResponse(const char *value = XB_AT_R_EMPTY);

    // Envoi d'une commande AT 
    bool sendATCommand(const char *command, const char *value, unsigned int mode = XB_AT_M_SET);

    // Ecriture de la configuration AT dans la mémoire flash du module
    bool writeATConfig();

    // Création et envoi de la trame de message structurée
    int sendTrame(uint8_t ad_dest, uint8_t code_fct, char* data = 0x00);

    int processTrame(std::vector<int> trame);
    
    void sendMsg(std::string msg);

    void waitForATrame();

    std::vector<int> readBuffer();

    std::string readString();

    int subTrame(std::vector<int> msg_recu);

    std::string charToString(char* message);

    bool isExpCorrect(int exp);

    bool isDestCorrect(int dest);

    bool isCodeFctCorrect(int code_fct);

    bool isTrameSizeCorrect(std::vector<int> trame);

    int processCodeFct(int code_fct, int exp);

    void sendHeartbeat();

private:

    typedef struct{
      int start_seq;
      int adr_emetteur;
      int adr_dest;
      int id_trame;
      int nb_octets_msg;
      int code_fct;
      std::vector<int> param;
      int crc_low;
      int crc_high;
      int end_seq;

    } Trame_t;

    void afficherTrameRecue(Trame_t trame);

    char* stringToChar(std::string chaine);

    void print(const std::vector<int> &v);

    // Calcul du CRC16 Modbus de la trame
    int crc16(int trame[], uint8_t taille);
    
    bool isStartSeqCorrect(int value);

    bool isEndSeqCorrect(int value);

    bool isCRCCorrect(uint8_t crc_low, uint8_t crc_high, int trame[], int trame_size);

    // Retard de temporisation dans l'exécution du code
    void delay(unsigned int time);

    std::vector<int> slice(const std::vector<int> &v, int a, int b);

    int ID_TRAME = 0x00;
};

#endif // XBEE_H
