/*!
 * 	\file can.h
 *  \brief     classe de gestion d'un bus can
 *  \details   Cette classe permet d'envoyer et de recevoir des messages via un bus can
 *  \author    Theo RUSINOWITCH <theo.rusinowitch1@etu.univ-lorraine.fr>
 *  \version   4.1a
 *  \date      2021-2022
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_
#include "stm32f3xx_hal.h"
#include <stdbool.h>
#include <defineCan.h>

typedef unsigned int uint;

typedef union {
    struct {
    	 uint8_t unused : 3;
    	 uint8_t idRep : 3;
    	 bool isRep : 1;
    	 uint8_t idMsg : 8;
    	 uint8_t codeFct : 8;
    	 uint8_t recepteur : 4;
    	 uint8_t emeteur : 4;
    	 bool msgUrgent : 1;
    } f;
    uint32_t champId;
} Tramme_Can_extID_t;


typedef union {
    struct {
        uint32_t nb_steps : 32;
        uint8_t div0 : 8;
        uint8_t div1 : 8;
        uint8_t div2 : 8;
        bool dir0 : 1;
        bool dir1 : 1;
        bool dir2 : 1;
    } fields;
    uint64_t unified;
    uint8_t raw_data[8];
} Tramme_Moteur_t;




struct CanResponse_t{
	uint addr;	/* addresse du destinataire du message */
	uint emetteur;	/* adresse de l'éméteur */
	uint codeFct;	/* code fonction du msg */
	bool isRep;	/* vrai si c'est une reponse a une requete, faux sinon */
	uint RepId;	/* nb de rep atendu si requete, num de la rep si reponse */
	//Tramme_Can_extID_t ExtID;
	uint dataLen;	/* frame payload length in byte (0 .. 8) */
	unsigned char data[8];
};

extern CAN_HandleTypeDef hcan_p;
extern uint8_t CanAdresse;


struct CanResponse_t traitement_trame( CAN_RxHeaderTypeDef frame, uint8_t data[]);
void CAN_Config(CAN_HandleTypeDef hcan, CAN_EMIT_ADDR adresse);
int send(CAN_ADDR addr, CAN_CODE_FCT codeFct , uint8_t data[], uint data_len, bool isRep, uint repLenght);
int start_listen();




struct CanMsg;

#endif /* INC_CAN_H_ */
