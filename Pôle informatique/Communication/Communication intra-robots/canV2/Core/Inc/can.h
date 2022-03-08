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
#include "stm32f0xx_hal.h"
#include <stdbool.h>

typedef unsigned int uint;

struct CanResponse_t{
	uint addr;	/* addresse du destinataire du message */
	uint emetteur;	/* adresse de l'éméteur */
	uint codeFct;	/* code fonction du msg */
	bool isRep;	/* vrai si c'est une reponse a une requete, faux sinon */
	uint RepId;	/* nb de rep atendu si requete, num de la rep si reponse */
	uint dataLen;	/* frame payload length in byte (0 .. 8) */
	unsigned char data[8];
};

CAN_HandleTypeDef hcan_p;

/*!
 *	\class Can
 *  \brief classe qui gère l'envoie et la réception de msg via un bus can
 *  \param s idantifiant du gestionnaire du bus
 *  \param threadListen objet du thread d'écoute du bus can
*/

	struct CanResponse_t traitement_trame( CAN_RxHeaderTypeDef frame, uint8_t data[]);
	int init(uint myAddr);
	bool is_valid_addr(uint addr);
	bool is_valid_code_fct(uint codeFct);
	int send(uint addr, uint codeFct , uint8_t data[], uint data_len, bool isRep, uint repLenght);
	int start_listen();




void CAN_Config(CAN_HandleTypeDef hcan, int adresse);
struct CanMsg;

#endif /* INC_CAN_H_ */
