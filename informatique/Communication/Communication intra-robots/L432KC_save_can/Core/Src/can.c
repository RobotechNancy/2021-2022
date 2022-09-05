/**
 ******************************************************************************
 * @file           : can.c
 * @brief          : Gestion du bus can
 * @author 		: Theo RUSINOWITCH <teo.rusi@hotmail.fr>
 ******************************************************************************
 */
#include "main.h"
#include "can.h"
#include "defineCan.h"
#include "stm32l4xx_hal.h"

struct CanMsg{
	int addr;
    int idMessage;
	int codeFct;
	int dataLen;
	char data[];
};


/*!
 * \struct CanResponse_t
 * \brief contient un message décoder venant du bus can
 * \param addr addresse du destinataire du message
 * \param emetteur adresse de l'émeteur du message
 * \param codeFct code fonction du message
 * \param isRep vrai si c'est une reponse a une requete, faux sinon
 * \param RepId indique le nombre de reponse atendu pour une requete et le num de la reponse pour une reponse
 * \param dataLen frame payload length in byte (0 .. 8) aka data length code
 * \param data CAN frame payload (up to 8 byte)
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	// traitement et mise en forme de la trame
	/////////////////////////////////////////////////////////////////////////
	uint8_t RxData[8];
	CAN_RxHeaderTypeDef RxHeader;
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);

	struct CanResponse_t msg;
	msg = traitement_trame( RxHeader, RxData);
	// PAS TOUCHE
	/////////////////////////////////////////////////////////////////////////
	//	le message et ses info sont dans la variable msg
	//	écrire le code ICI

	switch(msg.codeFct){
	case AVANCE:;
		Tramme_Moteur_t trammeMotor;
		for(int i=0;i<8;i++){
			trammeMotor.raw_data[i] = msg.data[i];
		}

	break;
	default :

	break;
	}









	//renvoi un msg sur le bus can
	//uint8_t data[8] = {0x01,0x02,0xFF,0x34,0x45};
	//send(CAN_ADDR_RASPBERRY, AVANCE, data, 5, true, 5) ;
}



/**
 * @brief  Configure le bus can
 * @param  Variable ascocié au bus can crée automatiquement par stm
 * @param  Adresse ascocier à cette carte STM
 * @param  PinState specifies the value to be written to the selected bit.
 *          This parameter can be one of the GPIO_PinState enum values:
 *            @arg GPIO_PIN_RESET: to clear the port pin
 *            @arg GPIO_PIN_SET: to set the port pin
 * @retval None
 */
void CAN_Config(CAN_HandleTypeDef hcan, CAN_EMIT_ADDR adresse) {
	CAN_FilterTypeDef sFilterConfig;

	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK; //Mode de filtrage choisit (avec maqsque ou liste d'adresses)
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT; //1 filtre de 32 bits ou 1 de 16 bits
	
	//sFilterConfig.FilterIdHigh = 0b000100000000000
	sFilterConfig.FilterIdHigh = adresse>>13; //Adresse de l'émetteur à filtrer (ou du groupe) sur les bits de poids fort 
						  //à vérifier
	sFilterConfig.FilterIdLow = 0; //
	sFilterConfig.FilterMaskIdHigh = 0b111100000000000; //Masque utilisé (FFF pour une adresse unique) sur les bits de poids fort
	sFilterConfig.FilterMaskIdLow = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0; //File utilisée (3 disponibles, donc potentiellement 3 filtres configurables sur chacune)
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14; // choix du filtre dans la banque

	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig); //configuration du filtre sur le controleur can

	HAL_CAN_Start(&hcan);                         // Démarre le périphérique CAN
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING); // Active le mode interruption
	hcan_p = hcan;
	//TxData[0] = valeur; // Vous pouvez changer toutes les valeurs de Txdata[0] à Txdata[TxHeader.DLC - 1] (TxHeader.DLC étant défini ci dessus)
	CanAdresse = adresse;
}


/*!
 *  \brief envoie un message sur le bus can
 *  \param addr addresse du destinataire
 *  \param codeFct code fct du message
 *  \param data tableau d'octet d'une taille 0 ... 8
 *  \param data_len nombre d'octet de data, compris entre 0 et 8
 *  \param isRep true si le message est une réponse à une requete, false sinon
 *  \param repLenght isRep = true : id du msg dans la réponse. isRep = false : nbr de reponse atendu
 *  \retval 0 le message a bien etait envoyé
 *  \retval {CAN_E_DATA_SIZE_TOO_LONG} data_len n'est pas compris entre 0 et 8 inclu
 *  \retval {CAN_E_OOB_ADDR} l'adresse n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_ADDR})
 *  \retval {CAN_E_OOB_CODE_FCT} le code fct n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_CODE_FCT})
 *  \retval {CAN_E_OOB_REP_NBR} le rep nbr n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_REP_NBR})
 *  \retval {CAN_E_OOB_DATA} au moins une des donnés n'est pas dans les valeurs possible (0 - 255)
 *  \retval {CAN_E_UNKNOW_ADDR} l'adresse n'est pas dans le #define
 *  \retval {CAN_E_UNKNOW_CODE_FCT} le code fonction n'est pas dans le #define
 *  \retval {CAN_E_WRITE_ERROR} une erreur à eu lieu lors de l'envoie du message
*/
int send(CAN_ADDR addr, CAN_CODE_FCT codeFct , uint8_t data[], uint dataLen, bool isRep, uint repLenght, uint idMessage){

	if (dataLen >8){
		return CAN_E_DATA_SIZE_TOO_LONG;
	}
/*
	if(addr < 0 || addr > CAN_MAX_VALUE_ADDR) return CAN_E_OOB_ADDR;
	if(codeFct < 0 || codeFct > CAN_MAX_VALUE_CODE_FCT) return CAN_E_OOB_CODE_FCT;
	if(repLenght < 0 || repLenght > CAN_MAX_VALUE_REP_NBR) return CAN_E_OOB_REP_NBR;
*/
	//if(!is_valid_addr(addr)) return CAN_E_UNKNOW_ADDR;
	//if(!is_valid_code_fct(codeFct)) return CAN_E_UNKNOW_CODE_FCT;


	CAN_TxHeaderTypeDef txHeader;
	txHeader.DLC = dataLen; // taille des données à transmettre en octets

	//adresse à mettre en en-tête du message (adresse de l'émetteur), qui servira pour l'arbitrage

	txHeader.ExtId = addr | CAN_ADDR_BASE_ROULANTE_E | codeFct | repLenght | idMessage << CAN_DECALAGE_ID_MSG | isRep << CAN_DECALAGE_IS_REP | repLenght;
	//txHeader.ExtId = 0b11101100100100000010000011111;
	//1 111 0001 0000 10010000 00000000 1 001
	//1011 0001 00001001 00000000 0000 1 001000000011001
	txHeader.IDE = CAN_ID_EXT; //on choisit l'adressage étendue
	txHeader.RTR = CAN_RTR_DATA; // On choisit quel type de message envoyer (requête ou data)
	txHeader.TransmitGlobalTime = DISABLE;


	uint32_t TxMailbox; //création d'un message pour avoir le numéro de la mailbox dans laquelle est stocké le message (afin de suivre son évolution jusqu'à l'envoi)

	HAL_CAN_AddTxMessage(&hcan_p, &txHeader, data, &TxMailbox);

	return 0;
}

/*!
 *  \brief extrait d'une trame reçu les différentes informations
 *  \param[out] rep pointeur d'une structure dans le quel la trame décoder est stocker
 *  \param frame structure contenant le header de la trame
 *  \param data contient les data du msg
 *  \retval 0 la trame à bien etait décodé
 *  \retval {CAN_E_OOB_ADDR} l'adresse n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_ADDR})
 *  \retval {CAN_E_OOB_CODE_FCT} le code fct n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_CODE_FCT})
 *  \retval {CAN_E_OOB_REP_NBR} le rep nbr n'est pas dans les valeurs possible (0 - {CAN_MAX_VALUE_REP_NBR})
 *  \retval {CAN_E_OOB_DATA} au moins une des donnés n'est pas dans les valeurs possible (0 - 255)
 *  \retval {CAN_E_UNKNOW_ADDR} l'adresse n'est pas dans le #define
 *  \retval {CAN_E_UNKNOW_CODE_FCT} le code fonction n'est pas dans le #define
 *  \retval {CAN_E_READ_ERROR} erreur dans la lecture de la trame depuis le buffer
*/
struct CanResponse_t traitement_trame(CAN_RxHeaderTypeDef frame, uint8_t data[]){
		struct CanResponse_t rep;
		//rep.ExtID.champId = frame.ExtId;

		rep.addr = (frame.ExtId & CAN_FILTER_ADDR_EMETTEUR)  ;
		rep.emetteur = (frame.ExtId &  CAN_FILTER_ADDR_RECEPTEUR) ;
		rep.codeFct = (frame.ExtId & CAN_FILTER_CODE_FCT);
		rep.isRep = (frame.ExtId & CAN_FILTER_IS_REP) >> CAN_DECALAGE_IS_REP;
		rep.RepId = (frame.ExtId & CAN_FILTER_REP_NBR) ;
		rep.idMessage = (frame.ExtId & CAN_FILTER_IDE_MSG) >> CAN_DECALAGE_ID_MSG;

        /*if(rep.addr <0 || rep.addr > CAN_MAX_VALUE_ADDR) return CAN_E_OOB_ADDR;
        if(rep.codeFct <0 || rep.codeFct > CAN_MAX_VALUE_CODE_FCT) return CAN_E_OOB_CODE_FCT;
        if(rep.RepId <0 || rep.RepId > CAN_MAX_VALUE_REP_NBR) return CAN_E_OOB_REP_NBR;

        if(!is_valid_addr(rep.addr)) return CAN_E_UNKNOW_ADDR;
        if(!is_valid_addr(rep.emetteur)) return CAN_E_UNKNOW_ADDR;
        if(!is_valid_code_fct(rep.codeFct)) return CAN_E_UNKNOW_CODE_FCT;
        if (frame.DLC >8)  return CAN_E_DATA_SIZE_TOO_LONG;*/

        rep.dataLen = frame.DLC;


        for (int i = 0; i < frame.DLC; i++){
            //if(data[i] <0 || data[i] > 255) return CAN_E_OOB_DATA;
            rep.data[i] = data[i];
        }


    return rep;
}

