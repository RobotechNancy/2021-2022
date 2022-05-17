#include <gui/accueil_screen/AccueilView.hpp>
#include "stm32f7xx_hal.h"
#include "main.h"
extern UART_HandleTypeDef huart1;

AccueilView::AccueilView()
{

}

void AccueilView::setupScreen()
{
    AccueilViewBase::setupScreen();
}

void AccueilView::tearDownScreen()
{
    AccueilViewBase::tearDownScreen();
}

void AccueilView::fctInitOdo(){
	uint8_t data[] = {0x43,0x58,0x0A,0x0D};
	HAL_UART_Transmit(&huart1,data,2,3);
}
