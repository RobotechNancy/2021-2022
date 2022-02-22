/**
 ******************************************************************************
 * @file           : can.c
 * @brief          : Gestion du bus can
 * @author 		: Theo RUSINOWITCH <teo.rusi@hotmail.fr>
 ******************************************************************************
 */
#include "main.h"
#include "can.h"


struct CanMsg{
	int addr;
    int idMessage;
	int codeFct;
	int dataLen;
	char data[];
};




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
void CAN_Config(CAN_HandleTypeDef hcan, int adresse) {
	CAN_FilterTypeDef sFilterConfig;

	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK; //Mode de filtrage choisit (avec maqsque ou liste d'adresses)
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT; //1 filtre de 32 bits ou 1 de 16 bits
	sFilterConfig.FilterIdHigh = adresse << 5; //Adresse de l'émetteur à filtrer (ou du groupe) sur les bits de poids fort
	sFilterConfig.FilterIdLow = 0; //
	sFilterConfig.FilterMaskIdHigh = 0xF00 << 5; //Masque utilisé (FFF pour une adresse unique) sur les bits de poids fort
	sFilterConfig.FilterMaskIdLow = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0; //File utilisée (3 disponibles, donc potentiellement 3 filtres configurables sur chacune)
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14; // choix du filtre dans la banque

	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig); //configuration du filtre sur le controleur can

	HAL_CAN_Start(&hcan);                         // Démarre le périphérique CAN
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING); // Active le mode interruption
	hcan_p = hcan;
	//TxData[0] = valeur; // Vous pouvez changer toutes les valeurs de Txdata[0] à Txdata[TxHeader.DLC - 1] (TxHeader.DLC étant défini ci dessus)

}

/**
 * @brief  envoie d'un octet sans id et sans code fonction (DEBUG ONLY)
 * @param  Adresse de l'apareil au quel on envoie le message (0xX00)
 * @param  Octet à envoyer
 * @retval None
 */
int send_one(int adr, uint8_t msg){

	uint8_t data[1] = {};
	return send_can(adr, data ,1);
}

/**
 * @brief  envoie d'un message sans id et sans code fonction (DEBUG ONLY)
 * @param  Adresse de l'apareil au quel on envoie le message (0xX00)
 * @param  Tableau contenant le message a envoyer
 * @param  taille du message entre 0 et 8
 * @retval None
 */
int send_can(int adrr, uint8_t msg[], int msg_size){
	return send_can(adrr, 0x00, 0xff, msg, msg_size);
}

/**
 * @brief  envoie d'un message dans le bus can
 * @param  Adresse de l'apareil au quel on envoie le message (0xX00)
 * @param  Id du message (pour une réponse prendre le meme que la demande)
 * @param  Code fonction du message
 * @param  Tableau contenant le message a envoyer
 * @param  taille du message entre 0 et 8
 * @retval 0
 */
int send_can(int adrr,int idMsg , int codeFct, uint8_t msg[], int msg_size){
	CAN_TxHeaderTypeDef txHeader;
	txHeader.DLC = msg_size+1; // taille des données à transmettre en octets
	txHeader.StdId = (adrr & 0xF00) + (idMsg & Ox0FF); //adresse à mettre en en-tête du message (adresse de l'émetteur), qui servira pour l'arbitrage
	txHeader.IDE = CAN_ID_STD; //on choisit l'adressage standard
	txHeader.RTR = CAN_RTR_DATA; // On choisit quel type de message envoyer (requête ou data)
	txHeader.TransmitGlobalTime = DISABLE;

	uint8_t data[msg_size+1];

	data[0] = codeFct;
	for(int i =1; i <msg_size; i++){
		data[i] = msg[i-1];
	}

	uint32_t TxMailbox; //création d'un message pour avoir le numéro de la mailbox dans laquelle est stocké le message (afin de suivre son évolution jusqu'à l'envoi)

	HAL_CAN_AddTxMessage(&hcan_p, &txHeader, msg, &TxMailbox);
	return 0;
}

