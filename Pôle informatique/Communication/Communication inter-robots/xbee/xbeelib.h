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
     \brief     Cette classe est utilisée pour la communication entre un module XBee et une RaspberryPi et entre plusieurs modules XBee.
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

    int processTrame(std::vector<uint8_t> trame);
    
    void sendMsg(std::string msg);

    void waitForATrame();

    std::string readBuffer();

    std::vector<uint8_t> readBytes();

    int subTrame(std::vector<uint8_t> msg_recu);

    std::string charToString(char* message);

    bool isExpCorrect(uint8_t exp);

    bool isDestCorrect(uint8_t dest);

    bool isCodeFctCorrect(uint8_t code_fct);

    bool isTrameSizeCorrect(std::vector<uint8_t> trame);

    int processCodeFct(uint8_t code_fct, uint8_t exp);

    void sendHeartbeat();

private:

    typedef struct{
      uint8_t start_seq;
      uint8_t adr_emetteur;
      uint8_t adr_dest;
      uint8_t id_trame;
      uint8_t nb_octets_msg;
      uint8_t code_fct;
      std::vector<uint8_t> param;
      uint8_t crc_low;
      uint8_t crc_high;
      uint8_t end_seq;

    } Trame_t;

    void afficherTrameRecue(Trame_t trame);

    char* stringToChar(std::string chaine);

    void print(const std::vector<uint8_t> &v);

    // Calcul du CRC16 Modbus de la trame
    int crc16(uint8_t trame[], uint8_t taille);
    
    bool isStartSeqCorrect(uint8_t value);

    bool isEndSeqCorrect(uint8_t value);

    bool isCRCCorrect(uint8_t crc_low, uint8_t crc_high, uint8_t trame[], uint8_t trame_size);

    // Retard de temporisation dans l'exécution du code
    void delay(unsigned int time);

    std::vector<uint8_t> slice(const std::vector<uint8_t> &v, uint8_t a, uint8_t b);

    int ID_TRAME = 0x00;
    int BUFFER_SIZE = 0;

    std::vector<std::string> trames {};
};

#endif // XBEE_H
