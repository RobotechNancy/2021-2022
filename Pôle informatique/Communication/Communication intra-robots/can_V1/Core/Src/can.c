/*
 * can.c
 *
 *  Created on: Jan 19, 2022
 *      Author: Teoru
 */
#include "main.h"
#include "can.h"


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
	sFilterConfig.FilterMaskIdHigh = 0xFFF << 5; //Masque utilisé (FFF pour une adresse unique) sur les bits de poids fort
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

int send_one(int adr, uint8_t data){

	uint8_t msg[1] = {data};
	return send_can(adr, msg ,1);
}

int send_can(int adr, uint8_t msg[], int msg_size){
	CAN_TxHeaderTypeDef txHeader;
	txHeader.DLC = msg_size; // taille des données à transmettre en octets
	txHeader.StdId = adr; //adresse à mettre en en-tête du message (adresse de l'émetteur), qui servira pour l'arbitrage
	txHeader.IDE = CAN_ID_STD; //on choisit l'adressage standard
	txHeader.RTR = CAN_RTR_DATA; // On choisit quel type de message envoyer (requête ou data)
	txHeader.TransmitGlobalTime = DISABLE;

	uint32_t TxMailbox; //création d'un message pour avoir le numéro de la mailbox dans laquelle est stocké le message (afin de suivre son évolution jusqu'à l'envoi)

	HAL_CAN_AddTxMessage(&hcan_p, &txHeader, msg, &TxMailbox);
	return 0;
}

