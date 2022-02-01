/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <math.h>
#include "stm32f0xx_it.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

TIM_HandleTypeDef htim14;

/* USER CODE BEGIN PV */
//int CLK = 48000000;
int PSC=4800;
int ARR=1000;
int target = -1;
int cnt = -1;
int timer_val;
int arret = 0;


//CAN
CAN_TxHeaderTypeDef TxHeader;
CAN_RxHeaderTypeDef RxHeader;
uint8_t TxData[8];
uint8_t RxData[8];
uint32_t TxMailbox;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM14_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */
void CAN_Config(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
uint8_t CAN_Transmit(uint32_t addr, uint32_t data_size, uint8_t *tab_data);

void test_moteur(void);
void stop(int s);
void change_dir(int dir);
void change_step(int f);
void transmit(void);
void transmit2(int msg);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void CAN_Config(void) {
	CAN_FilterTypeDef sFilterConfig;

	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK; //Mode de filtrage choisit (avec maqsque ou liste d'adresses)
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT; //1 filtre de 32 bits ou 1 de 16 bits
	sFilterConfig.FilterIdHigh = 0x325 << 5; //Adresse de l'émetteur à filtrer (ou du groupe) sur les bits de poids fort
	sFilterConfig.FilterIdLow = 0; //
	sFilterConfig.FilterMaskIdHigh = 0xFFF << 5; //Masque utilisé (FFF pour une adresse unique) sur les bits de poids fort
	sFilterConfig.FilterMaskIdLow = 0;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0; //File utilisée (3 disponibles, donc potentiellement 3 filtres configurables sur chacune)
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14; // choix du filtre dans la banque

	HAL_CAN_ConfigFilter(&hcan, &sFilterConfig); //configuration du filtre sur le controleur can

	HAL_CAN_Start(&hcan);                         // Démarre le périphérique CAN
	HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING); // Active le mode interruption

	RxHeader.StdId = 0x324; //adresse dans l'en-tête du mesage reçu
	RxHeader.FilterMatchIndex = 0; //degré de concordance entre l'entête et les informations renseignées.
	RxHeader.DLC = 2; // taille de la donnée
	RxHeader.IDE = CAN_ID_STD; //type d'identifieur can
	RxHeader.RTR = CAN_RTR_DATA; //type de message (ici data)

	//TxData[0] = valeur; // Vous pouvez changer toutes les valeurs de Txdata[0] à Txdata[TxHeader.DLC - 1] (TxHeader.DLC étant défini ci dessus)

}

//fct interrupt (qd stm reçoit msg)
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	//HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);
	// Traitement des données
	uint8_t RxData[8];
	//réception du message
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData);

	transmit(); //(accusé de réception)

	stop(RxData[0]);
	change_dir(RxData[1]);
	change_step(RxData[2]);
}

//accusé de réception
void transmit(void) {
	//Définition de l'en-tête de transmission:
	CAN_TxHeaderTypeDef txHeader;

	txHeader.DLC = 3; // taille des données à transmettre en octets
	txHeader.StdId = 0x324; //adresse à mettre en en-tête du message (adresse de l'émetteur), qui servira pour l'arbitrage
	txHeader.IDE = CAN_ID_STD; //on choisit l'adressage standard
	txHeader.RTR = CAN_RTR_DATA; // On choisit quel type de message envoyer (requête ou data)
	txHeader.TransmitGlobalTime = DISABLE;

	uint8_t data[3] = { 's', 'l', 't' }; // création du message

	uint32_t TxMailbox; //création d'un message pour avoir le numéro de la mailbox dans laquelle est stocké le message (afin de suivre son évolution jusqu'à l'envoi)

	HAL_CAN_AddTxMessage(&hcan, &txHeader, data, &TxMailbox); //Ajouter le message (avec en-tête) à l'une des mailbox (disponible).

	//HAL_CAN_AddTxMessage(&hcan, (uint8_t*)data, sizeof(data), 1000);

}
void transmit2(int msg) {
	//Définition de l'en-tête de transmission:
		CAN_TxHeaderTypeDef txHeader;

		txHeader.DLC = 3; // taille des données à transmettre en octets
		txHeader.StdId = 0x324; //adresse à mettre en en-tête du message (adresse de l'émetteur), qui servira pour l'arbitrage
		txHeader.IDE = CAN_ID_STD; //on choisit l'adressage standard
		txHeader.RTR = CAN_RTR_DATA; // On choisit quel type de message envoyer (requête ou data)
		txHeader.TransmitGlobalTime = DISABLE;

		uint8_t data[3] = { 0x00, 0, msg }; // création du message

		uint32_t TxMailbox; //création d'un message pour avoir le numéro de la mailbox dans laquelle est stocké le message (afin de suivre son évolution jusqu'à l'envoi)

		HAL_CAN_AddTxMessage(&hcan, &txHeader, data, &TxMailbox); //Ajouter le message (avec en-tête) à l'une des mailbox (disponible).

		//HAL_CAN_AddTxMessage(&hcan, (uint8_t*)data, sizeof(data), 1000);


}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//char uart_buf[50];
//int uart_buf_len;
//uint16_t timer_val;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM14_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */
  CAN_Config();

    //start timer
    HAL_TIM_Base_Start_IT(&htim14);


    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
    //Driver 1
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    //transmit();
    while (1)
      {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN;
  hcan.Init.Prescaler = 12;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_8TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = DISABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = DISABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 4800;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 65535;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA5 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void stop(int s){
	if (s==0){
		arret = 0;
	}
	else if (s==1){
		arret = 1;
	}
}

void change_dir(int dir){
	if (dir==0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	}
	else if (dir==1){
		transmit();
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	}
}

void change_step(int f){
	transmit2(f);
	//int freq = f;
	TIM14->ARR = f;
}

// Callback: timer has rolled over
	/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
	{
	  // Check which version of the timer triggered this callback and toggle LED
	  if (htim == &htim14)
	  {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10, SET);
	  }
	}*/

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

