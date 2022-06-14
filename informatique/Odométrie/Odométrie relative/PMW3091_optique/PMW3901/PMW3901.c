/*
 * PMW3091.c
 *
 *  Created on: May 8, 2022
 *      Author: nacim
 */
#include "../PMW3901/PMW3901.h"

#include "main.h"
#include <string.h>

#ifndef SRC_PMW3091_C_
#define SRC_PMW3091_C_

#define DELTA_X_L 0x03 // Define qui sont dans la datasheet (cf datasheet du capteur)
#define DELTA_X_H 0x04
#define DELTA_Y_L 0x05
#define DELTA_Y_H 0x06

#define PRODUCT_ID 0x49
#define INVERSE_PRODUCT_ID 0xB6

#define HSPI Descriptor->hspi // Define qui initialise le SPI
#define CS_PORT Descriptor->CS_Port
#define CS_PIN Descriptor->CS_Pin

typedef union { // Permet de réunir les données envoyées par le capteur et de les unifier car on les récupère en 2 séries de 8 bits
	uint8_t raw[2];
	int16_t unified;
}PMW3901_Unify_2x8_to_16_t;


PMW3901_Descriptor_t *Descriptor; // Initialise notre port SPI


PMW3901_Status_t PMW3901_RegWrite(uint8_t reg, uint8_t val) // Méthode permettant d'écrire dans des registres en SPI
{

	HAL_StatusTypeDef SPI_status;

	reg |= 0x80;
	uint8_t send[2]={reg,val};

	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);

	SPI_status = HAL_SPI_Transmit(HSPI, send, 2, 1000);
	if (SPI_status != HAL_OK) return PMW3901_ERROR_SPI;

	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);

	return PMW3901_SUCCESS;
}

PMW3901_Status_t PMW3901_RegRead(uint8_t reg, uint8_t *dest) // Méthode permettant de lire des registres en SPI
{

	HAL_StatusTypeDef SPI_status;

	uint8_t value;

	reg &= ~0x80;
	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_RESET);

	SPI_status = HAL_SPI_Transmit(HSPI, &reg, 1, 1000);
	if (SPI_status != HAL_OK) return PMW3901_ERROR_SPI;

	SPI_status = HAL_SPI_Receive(HSPI, &value, 1, 1000);
	if (SPI_status != HAL_OK) return PMW3901_ERROR_SPI;

	HAL_GPIO_WritePin(CS_PORT, CS_PIN, GPIO_PIN_SET);

	*dest = value;

	return PMW3901_SUCCESS;
}

PMW3901_Status_t PMW3901_SetLed() // Fonction permettant d'allumer les leds du capteurs
{
	PMW3901_Status_t status;

	status = PMW3901_RegWrite(0x7f, 0x14);
	if (status) return status;

	status = PMW3901_RegWrite(0x6f, 0x1c);
	if (status) return status;

	status = PMW3901_RegWrite(0x7f, 0x00);
	return status;
}

PMW3901_Status_t PMW3901_Init(PMW3901_Descriptor_t *_Descriptor) // Permet d'initialiser le capteur
{
	PMW3901_Status_t status;

	uint8_t Product_ID;
	uint8_t Inverse_Product_ID;

	Descriptor = _Descriptor;

	status = PMW3901_RegRead(0x00, &Product_ID);
	if (status) return status;

	if(Product_ID != PRODUCT_ID) return PMW3901_ERROR_UNKNOWN_ID;

	status = PMW3901_RegRead(0x5F, &Inverse_Product_ID);
	if (status) return status;

	if(Inverse_Product_ID != INVERSE_PRODUCT_ID) return PMW3901_ERROR_UNKNOWN_ID;

	// Tout ça permet initialiser certains registres du capteur apparaissant dans la datasheet (on se sait pas à quoi ça correspond)
	status = PMW3901_RegWrite(0x3A, 0x00); if(status) return status; // Les if et return permettent de renvoyer un status afin de savoir si tout se passe bien, si status = 0 => tout est bon, si status = 1 => quelque chose fonctionne mal
	status = PMW3901_RegWrite(0x7F, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x61, 0xAD); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x03); if(status) return status;
	status = PMW3901_RegWrite(0x40, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x05); if(status) return status;
	status = PMW3901_RegWrite(0x41, 0xB3); if(status) return status;
	status = PMW3901_RegWrite(0x43, 0xF1); if(status) return status;
	status = PMW3901_RegWrite(0x45, 0x14); if(status) return status;
	status = PMW3901_RegWrite(0x5B, 0x32); if(status) return status;
	status = PMW3901_RegWrite(0x5F, 0x34); if(status) return status;
	status = PMW3901_RegWrite(0x7B, 0x08); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x06); if(status) return status;
	status = PMW3901_RegWrite(0x44, 0x1B); if(status) return status;
	status = PMW3901_RegWrite(0x40, 0xBF); if(status) return status;
	status = PMW3901_RegWrite(0x4E, 0x3F); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x08); if(status) return status;
	status = PMW3901_RegWrite(0x65, 0x20); if(status) return status;
	status = PMW3901_RegWrite(0x6A, 0x18); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x09); if(status) return status;
	status = PMW3901_RegWrite(0x4F, 0xAF); if(status) return status;
	status = PMW3901_RegWrite(0x5F, 0x40); if(status) return status;
	status = PMW3901_RegWrite(0x48, 0x80); if(status) return status;
	status = PMW3901_RegWrite(0x49, 0x80); if(status) return status;
	status = PMW3901_RegWrite(0x57, 0x77); if(status) return status;
	status = PMW3901_RegWrite(0x60, 0x78); if(status) return status;
	status = PMW3901_RegWrite(0x61, 0x78); if(status) return status;
	status = PMW3901_RegWrite(0x62, 0x08); if(status) return status;
	status = PMW3901_RegWrite(0x63, 0x50); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x0A); if(status) return status;
	status = PMW3901_RegWrite(0x45, 0x60); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x4D, 0x11); if(status) return status;
	status = PMW3901_RegWrite(0x55, 0x80); if(status) return status;
	status = PMW3901_RegWrite(0x74, 0x1F); if(status) return status;
	status = PMW3901_RegWrite(0x75, 0x1F); if(status) return status;
	status = PMW3901_RegWrite(0x4A, 0x78); if(status) return status;
	status = PMW3901_RegWrite(0x4B, 0x78); if(status) return status;
	status = PMW3901_RegWrite(0x44, 0x08); if(status) return status;
	status = PMW3901_RegWrite(0x45, 0x50); if(status) return status;
	status = PMW3901_RegWrite(0x64, 0xFF); if(status) return status;
	status = PMW3901_RegWrite(0x65, 0x1F); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x14); if(status) return status;
	status = PMW3901_RegWrite(0x65, 0x60); if(status) return status;
	status = PMW3901_RegWrite(0x66, 0x08); if(status) return status;
	status = PMW3901_RegWrite(0x63, 0x78); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x15); if(status) return status;
	status = PMW3901_RegWrite(0x48, 0x58); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x07); if(status) return status;
	status = PMW3901_RegWrite(0x41, 0x0D); if(status) return status;
	status = PMW3901_RegWrite(0x43, 0x14); if(status) return status;
	status = PMW3901_RegWrite(0x4B, 0x0E); if(status) return status;
	status = PMW3901_RegWrite(0x45, 0x0F); if(status) return status;
	status = PMW3901_RegWrite(0x44, 0x42); if(status) return status;
	status = PMW3901_RegWrite(0x4C, 0x80); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x10); if(status) return status;
	status = PMW3901_RegWrite(0x5B, 0x02); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x07); if(status) return status;
	status = PMW3901_RegWrite(0x40, 0x41); if(status) return status;
	status = PMW3901_RegWrite(0x70, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x32, 0x44); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x07); if(status) return status;
	status = PMW3901_RegWrite(0x40, 0x40); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x06); if(status) return status;
	status = PMW3901_RegWrite(0x62, 0xf0); if(status) return status;
	status = PMW3901_RegWrite(0x63, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x0D); if(status) return status;
	status = PMW3901_RegWrite(0x48, 0xC0); if(status) return status;
	status = PMW3901_RegWrite(0x6F, 0xd5); if(status) return status;
	status = PMW3901_RegWrite(0x7F, 0x00); if(status) return status;
	status = PMW3901_RegWrite(0x5B, 0xa0); if(status) return status;
	status = PMW3901_RegWrite(0x4E, 0xA8); if(status) return status;
	status = PMW3901_RegWrite(0x5A, 0x50); if(status) return status;
	status = PMW3901_RegWrite(0x40, 0x80); if(status) return status;

	status = PMW3901_SetLed();

	return status;
}

PMW3901_Status_t PMW3901_Read_Variation(int16_t *var_x, int16_t *var_y) // Fonction permettant de lire la valeur de la variation
{

	PMW3901_Status_t status;
	PMW3901_Unify_2x8_to_16_t data;
	uint8_t Motion;

	status = PMW3901_RegRead(0x02, &Motion);
	if (status) return status;

	status = PMW3901_RegRead(DELTA_X_H, &data.raw[1]);
	if (status) return status;

	status = PMW3901_RegRead(DELTA_X_L, &data.raw[0]);
	if (status) return status;

	*var_x = data.unified;

	status = PMW3901_RegRead(DELTA_Y_H, &data.raw[1]);
	if (status) return status;

	status = PMW3901_RegRead(DELTA_Y_L, &data.raw[0]);
	if (status) return status;

	*var_y = data.unified;

	return status;
}





#endif /* SRC_PMW3091_C_ */
