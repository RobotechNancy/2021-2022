#include <gui/score_screen/ScoreView.hpp>

#include <vector>
#include "PollingRoutines.h"
#include <math.h>       /* pow */

extern uint8_t uartMsgBuf[UART_BUF_SIZE];

ScoreView::ScoreView()
{

}

void ScoreView::setupScreen()
{
    ScoreViewBase::setupScreen();
}

void ScoreView::tearDownScreen()
{
    ScoreViewBase::tearDownScreen();
}

void ScoreView::uartMsgRdy(){
	uint8_t convert_array_buf[UART_BUF_SIZE];
	uint8_t score_total = 0;
	memset(convert_array_buf, 0, sizeof(convert_array_buf));
	if(uartMsgBuf[0] == 0) return; //array empty so return

	touchgfx::Vector<uint8_t,16> str_vect;
	for(int i = 1; i < UART_BUF_SIZE && uartMsgBuf[i] != 10 && uartMsgBuf[i] != 13; i++){
		convert_array_buf[i-1] = uartMsgBuf[i];
		str_vect.add(uartMsgBuf[i]);
	}
	switch(uartMsgBuf[0]){
		case 0x41:
			memset(&textArea1Buffer, 0, TEXTAREA1_SIZE);
			Unicode::strncpy(textArea1Buffer, (char*)convert_array_buf, TEXTAREA1_SIZE - 1);
			textArea1Buffer[16] = '\0'; //make sure last index is null
			textArea1.invalidate();
		break;
		case 0x42:
			memset(&textArea2Buffer, 0, TEXTAREA2_SIZE);
			Unicode::strncpy(textArea2Buffer, (char*)convert_array_buf, TEXTAREA2_SIZE - 1);
			textArea2Buffer[16] = '\0'; //make sure last index is null
			textArea2.invalidate();
		break;
		case 0x43:
			score_total = 0;

			for(int i = 0; i < str_vect.size(); i++){
				score_total += (str_vect[i]-48)*(pow(10,(str_vect.size()-i-1)));
			}
			memset(&textArea3Buffer, 0, TEXTAREA3_SIZE);
			Unicode::strncpy(textArea3Buffer, (char*)convert_array_buf, TEXTAREA3_SIZE - 1);
			gauge1.setValue(score_total);
			textArea3Buffer[16] = '\0'; //make sure last index is null
			textArea3.invalidate();
			gauge1.invalidate();
		break;
		default: break;
	}

}
