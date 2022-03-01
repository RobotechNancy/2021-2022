/*! 
 *  \brief     classe de gestion d'un bus can
 *  \details   Cette classe permet d'envoyer et de recevoir des messages via un bus can
 *  \author    Theo RUSINOWITCH <theo.rusinowitch1@etu.univ-lorraine.fr>
 *  \version   4.1a
 *  \date      2021-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>


#include <unistd.h>

#include <thread>



#include "canClass.h"
#include "defineCan.h"
using namespace std;

Can::Can(){
    
    return;
}


/*!
 *  \brief initialise le bus can
 *  \param myAddr adresse sur le bus can
 *  \retval 0 : succes
 *  \retval {CAN_E_SOCKET_ERROR} : erreur dans l'ouverture du socket
 *  \retval {CAN_E_BIND_ERROR} : erreur dans le bind du bus
 *  \retval {CAN_E_OOB_ADDR} : adresse en dehors des bornes
 *  \retval {CAN_E_UNKNOW_ADDR} : l'adresse n'est pas dans le #define
*/
int Can::init(uint myAddr){
    int i; 
    int nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;


    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket");
        return CAN_E_SOCKET_ERROR;
    }
    strcpy(ifr.ifr_name, CAN_BUS_NAME); //definie le bus sur le quel on travaille (can0 ou vcan0 normalement)
    ioctl(s, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return CAN_E_BIND_ERROR;
    }

    // si l'address est incorect on ne setup juste pas de filtre
    if(myAddr <0 || myAddr > CAN_MAX_VALUE_ADDR) return CAN_E_OOB_ADDR;
    if(!is_valid_addr(myAddr)) return CAN_E_UNKNOW_ADDR;
    
    //  Initialisation de l'adresse
    struct can_filter rfilter[1];
    rfilter[0].can_id   = myAddr << CAN_DECALAGE_ADDR_RECEPTEUR;
    rfilter[0].can_mask = CAN_FILTER_ADDR_RECEPTEUR;


    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

    return 0;
}

/*!
 *  \brief regarde si l'adresse est connue
 *  \param myAddr addresse à verifier
 *  \retval true : l'adresse est connue
 *  \retval false : l'adresse n'est pas connue
*/
bool Can::is_valid_addr(uint addr){
    int size = sizeof(CAN_LIST_ADDR)/sizeof(CAN_LIST_ADDR[0]);
    for (int i = 0; i < size; i++)
    {
        if(addr == CAN_LIST_ADDR[i]) return true;
    }
    return false;
}

/*!
 *  \brief regarde si le code fct est connue
 *  \param codeFct code fct à verifier
 *  \retval true : le code fct est connue
 *  \retval false : le code fct n'est pas connue
*/
bool Can::is_valid_code_fct(uint codeFct){
    int size = sizeof(CAN_LIST_CODE_FCT)/sizeof(CAN_LIST_CODE_FCT[0]);
    for (int i = 0; i < size; i++)
    {
        if(codeFct == CAN_LIST_CODE_FCT[i]) return true;
    }
    return false;
}

/*!
 *  \brief envoie un message sur le bus can
 *  \param addr addresse du destinataire
 *  \param codeFct code fct du message
 *  \param data tableau d'octet d'une taille 0 ... 8
 *  \param data_len nombre d'octet de data, compris entre 0 et 8
 *  \param isRep true si le message est une réponse à une requete, false sinon
 *  \param repLenght isRep = true : id du msg dans la réponse. isRep = false : nbr de reponse atendu
 *  \retval 0 : le message a bien etait envoyé
 *  \retval {CAN_E_DATA_SIZE_TOO_LONG} : data_len n'est pas compris entre 0 et 8 inclu
 *  \retval {CAN_E_OOB_ADDR} : l'adresse n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_ADDR})
 *  \retval {CAN_E_OOB_CODE_FCT} : le code fct n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_CODE_FCT})
 *  \retval {CAN_E_OOB_REP_NBR} : le rep nbr n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_REP_NBR})
 *  \retval {CAN_E_OOB_DATA} : au moins une des donnés n'est pas dans les valeurs possible (0 - 255)
 *  \retval {CAN_E_UNKNOW_ADDR} : l'adresse n'est pas dans le #define
 *  \retval {CAN_E_UNKNOW_CODE_FCT} : le code fonction n'est pas dans le #define
 *  \retval {CAN_E_WRITE_ERROR} : une erreur à eu lieu lors de l'envoie du message
*/
int Can::send(uint addr, uint codeFct , uint8_t data[], uint data_len, bool isRep, uint repLenght){
    if (data_len >8){
        cout << "vous ne pouvez envoyer que 8 octet de data" << endl;
        return CAN_E_DATA_SIZE_TOO_LONG;   
    }

    if(addr < 0 || addr > CAN_MAX_VALUE_ADDR) return CAN_E_OOB_ADDR;
    if(codeFct < 0 || codeFct > CAN_MAX_VALUE_CODE_FCT) return CAN_E_OOB_CODE_FCT;
    if(repLenght < 0 || repLenght > CAN_MAX_VALUE_REP_NBR) return CAN_E_OOB_REP_NBR;

    if(!is_valid_addr(addr)) return CAN_E_UNKNOW_ADDR;
    if(!is_valid_code_fct(codeFct)) return CAN_E_UNKNOW_CODE_FCT;




    struct can_frame frame;
    frame.can_id = (
          (addr << CAN_DECALAGE_ADDR_RECEPTEUR) 
        + (CAN_ADDR_RASPBERRY << CAN_DECALAGE_ADDR_EMETTEUR) 
        + (codeFct << CAN_DECALAGE_CODE_FCT) 
        + (isRep << CAN_DECALAGE_IS_REP) 
        + (repLenght << CAN_DECALAGE_REP_NBR)
        )| CAN_EFF_FLAG;

    cout << hex << frame.can_id << endl;
    frame.can_dlc = data_len;

    printf("send : 0x%03X [%d] ",frame.can_id, frame.can_dlc);
    for (int i = 0; i < data_len; i++)
    {
        if(data[i] <0 || data[i] > 255) return CAN_E_OOB_DATA;
        frame.data[i] = data[i];
        printf("%02X ",frame.data[i]);
    }
    printf("\r\n");	

    if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) { //on verifie que le nombre de byte envoyer est corecte
        perror("Write");
        return CAN_E_WRITE_ERROR;
    }

    return 0;	
}

/*!
 *  \brief extrait d'une trame reçu les différentes informations
 *  \param[out] rep pointeur d'une structure dans le quel la trame décoder est stocker
 *  \param frame structure contenant la trame à décoder
 *  \retval 0 : la trame à bien etait décodé
 *  \retval {CAN_E_OOB_ADDR} : l'adresse n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_ADDR})
 *  \retval {CAN_E_OOB_CODE_FCT} : le code fct n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_CODE_FCT})
 *  \retval {CAN_E_OOB_REP_NBR} : le rep nbr n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_REP_NBR})
 *  \retval {CAN_E_OOB_DATA} : au moins une des donnés n'est pas dans les valeurs possible (0 - 255)
 *  \retval {CAN_E_UNKNOW_ADDR} : l'adresse n'est pas dans le #define
 *  \retval {CAN_E_UNKNOW_CODE_FCT} : le code fonction n'est pas dans le #define
 *  \retval {CAN_E_READ_ERROR} : erreur dans la lecture de la trame depuis le buffer
*/
int Can::traitement_trame(CanResponse_t &rep, can_frame frame){

    int nbytes;
		nbytes = read(s, &frame, sizeof(struct can_frame));
		if (nbytes < 0) {
			perror("Read");
            return CAN_E_READ_ERROR;
		}

        rep.addr = (frame.can_id & CAN_FILTER_ADDR_RECEPTEUR ) >> CAN_DECALAGE_ADDR_RECEPTEUR ;
        rep.emetteur = (frame.can_id & CAN_FILTER_ADDR_EMETTEUR) >> CAN_DECALAGE_ADDR_EMETTEUR;
        rep.codeFct = (frame.can_id & CAN_FILTER_CODE_FCT) >> CAN_DECALAGE_CODE_FCT;
        rep.isRep = (frame.can_id & CAN_FILTER_IS_REP) >> CAN_DECALAGE_IS_REP;
        rep.RepId = (frame.can_id & CAN_FILTER_REP_NBR) >> CAN_DECALAGE_REP_NBR;


        if(rep.addr <0 || rep.addr > CAN_MAX_VALUE_ADDR) return CAN_E_OOB_ADDR;
        if(rep.codeFct <0 || rep.codeFct > CAN_MAX_VALUE_CODE_FCT) return CAN_E_OOB_CODE_FCT;
        if(rep.RepId <0 || rep.RepId > CAN_MAX_VALUE_REP_NBR) return CAN_E_OOB_REP_NBR;

        if(!is_valid_addr(rep.addr)) return CAN_E_UNKNOW_ADDR;
        if(!is_valid_addr(rep.emetteur)) return CAN_E_UNKNOW_ADDR;
        if(!is_valid_code_fct(rep.codeFct)) return CAN_E_UNKNOW_CODE_FCT;
        if (frame.can_dlc >8)  return CAN_E_DATA_SIZE_TOO_LONG;   
        rep.dataLen = frame.can_dlc;
        

        for (int i = 0; i < frame.can_dlc; i++){
            if(frame.data[i] <0 || frame.data[i] > 255) return CAN_E_OOB_DATA;
            rep.data[i] = frame.data[i];
        }


    return 0;
}

/*!
 *  \brief fonction à lancer en thread qui ecoute le buffer et deocde les trames
 */

void Can::listen(){
	while(true){
		struct can_frame frame;
		struct CanResponse_t reponse;
        
        int err =traitement_trame(reponse, frame);
        if(err < 0){
            cout << "erreur dans le décodage d'une trame. err n°" << dec << err << "\t\t c.f. #define" << endl;
            continue;
        }


        cout << "addr : " << hex << reponse.addr ;
        cout << "   emetteur : " << hex << reponse.emetteur;
        cout << "   codeFct : " << hex << reponse.codeFct;
        cout << "   isRep : " << reponse.isRep;
        cout << "   RepId : " << hex << reponse.RepId;
        cout << "       Data : ["<< (int)reponse.dataLen <<"] ";
        for (int i = 0; i < frame.can_dlc; i++) printf("%02X ",reponse.data[i]);
        printf("\r\n");

        thread test(&Can::traitement,this, reponse);
        test.detach();
        
	}
}

/*!
 *  \brief traite le message décodé dans un nouveau thread
 *  \param msg structure contenant le message decoder
*/    
void Can::traitement(CanResponse_t msg){
    switch (msg.emetteur){
    case CAN_ADDR_BASE_ROULANTE:
        switch (msg.codeFct){
        case AVANCE:


        break;
        default:
            cout << "code fonction inconu" << endl;
        break;
        }


    break;
    case CAN_ADDR_RASPBERRY:
        cout << "self emeteur" << endl;
    break;
    default:
        cout << "emetteur inconu" << endl;
    break;
    }
}

/*!
 *  \brief démarre le thread d'écoute du bus can
 *  \retval 0 : le thread a bien etait lancer 
*/
int Can::start_listen(){
    thread tListen(&Can::listen, this);
	tListen.detach();
    threadListen = &tListen;
    return 0;
}



