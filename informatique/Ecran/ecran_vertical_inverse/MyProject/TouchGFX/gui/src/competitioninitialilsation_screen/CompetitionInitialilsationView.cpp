#include <gui/competitioninitialilsation_screen/CompetitionInitialilsationView.hpp>

#include "PollingRoutines.h"
#include "string.h"

extern uint8_t uartMsgBuf[UART_BUF_SIZE];


CompetitionInitialilsationView::CompetitionInitialilsationView()
{

}

void CompetitionInitialilsationView::setupScreen()
{
    CompetitionInitialilsationViewBase::setupScreen();
}

void CompetitionInitialilsationView::tearDownScreen()
{
    CompetitionInitialilsationViewBase::tearDownScreen();
}

void CompetitionInitialilsationView::uartMsgRdy(){

		uint8_t convert_array_buf[UART_BUF_SIZE];
		memset(convert_array_buf, 0, sizeof(convert_array_buf));
		if(uartMsgBuf[0] == 0) return; //array empty so return

		for(int i = 3; i < UART_BUF_SIZE && uartMsgBuf[i] != 10 && uartMsgBuf[i] != 13; i++){
			convert_array_buf[i-3] = uartMsgBuf[i];
		}
		switch(uartMsgBuf[0]){
			case 0x43: //C : compétition

				switch(uartMsgBuf[1]){
					case 0x49: //I : initialisation

						switch(uartMsgBuf[2]){
							case 0x4F: //O : odométrie
								memset(&etatInit1Buffer, 0, ETATINIT1_SIZE);
								Unicode::strncpy(etatInit1Buffer, (char*)convert_array_buf, ETATINIT1_SIZE - 1);
								etatInit1Buffer[16] = '\0'; //make sure last index is null
								etatInit1.invalidate();
							break;

							case 0x42: //B : base roulante
								memset(&etatInit2Buffer, 0, ETATINIT2_SIZE);
								Unicode::strncpy(etatInit2Buffer, (char*)convert_array_buf, ETATINIT2_SIZE - 1);
								etatInit2Buffer[16] = '\0'; //make sure last index is null
								etatInit2.invalidate();
							break;

							case 0x58: //X : xbee
								memset(&etatInit3Buffer, 0, ETATINIT3_SIZE);
								Unicode::strncpy(etatInit3Buffer, (char*)convert_array_buf, ETATINIT3_SIZE - 1);
								etatInit3Buffer[16] = '\0'; //make sure last index is null
								etatInit3.invalidate();
							break;

							case 0x43: //C : bus CAN
								memset(&etatInit4Buffer, 0, ETATINIT4_SIZE);
								Unicode::strncpy(etatInit4Buffer, (char*)convert_array_buf, ETATINIT4_SIZE - 1);
								etatInit4Buffer[16] = '\0'; //make sure last index is null
								etatInit4.invalidate();
							break;
							default: break;
						}

					break;
					default: break;
				}

			break;
			default: break;
		}
}
