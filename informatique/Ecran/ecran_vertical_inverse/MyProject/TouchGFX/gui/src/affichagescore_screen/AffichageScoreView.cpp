#include <gui/affichagescore_screen/AffichageScoreView.hpp>
#include <gui_generated/competition_screen/CompetitionViewBase.hpp>

#include <vector>
#include "PollingRoutines.h"
#include <math.h>
#include <string.h>

extern uint8_t uartMsgBuf[UART_BUF_SIZE];

extern uint32_t colorBox;
extern BoxWithBorder boxWithBorder1;
extern TextAreaWithOneWildcard scoreTotal;
extern TextAreaWithOneWildcard scorePetitRobot;
extern TextAreaWithOneWildcard scoreGrandRobot;
extern const uint16_t SCORETOTAL_SIZE = 17;
extern Unicode::UnicodeChar scoreTotalBuffer[SCORETOTAL_SIZE];
extern const uint16_t SCOREPETITROBOT_SIZE = 17;
extern Unicode::UnicodeChar scorePetitRobotBuffer[SCOREPETITROBOT_SIZE];
extern const uint16_t SCOREGRANDROBOT_SIZE = 17;
extern Unicode::UnicodeChar scoreGrandRobotBuffer[SCOREGRANDROBOT_SIZE];


AffichageScoreView::AffichageScoreView()
{

}

void AffichageScoreView::setupScreen()
{
    AffichageScoreViewBase::setupScreen();
	colortype colorBoxScore(colorBox);
	boxWithBorder1.setBorderColor(colorBoxScore);
}

void AffichageScoreView::tearDownScreen()
{
    AffichageScoreViewBase::tearDownScreen();
}


void AffichageScoreView::uartMsgRdy(){

		uint8_t convert_array_buf[UART_BUF_SIZE];
		uint8_t score_total = 0;

		memset(convert_array_buf, 0, sizeof(convert_array_buf));
		if(uartMsgBuf[0] == 0) return; //array empty so return

		touchgfx::Vector<uint8_t,16> str_vect;
		for(int i = 3; i < UART_BUF_SIZE && uartMsgBuf[i] != 10 && uartMsgBuf[i] != 13; i++){
			convert_array_buf[i-3] = uartMsgBuf[i];
			str_vect.add(uartMsgBuf[i]);
		}

		switch(uartMsgBuf[0]){
			case 0x43: //C : compétition

				switch(uartMsgBuf[1]){
					case 0x53: //S : score

						switch(uartMsgBuf[2]){
							case 0x50: //P : score petit robot
								memset(&scoreGrandRobotBuffer, 0, SCOREGRANDROBOT_SIZE);
								Unicode::strncpy(scoreGrandRobotBuffer, (char*)convert_array_buf, SCOREGRANDROBOT_SIZE - 1);
								scoreGrandRobotBuffer[16] = '\0'; //make sure last index is null
								scoreGrandRobot.invalidate();
							break;

							case 0x47: //G : score grand robot
								memset(&scorePetitRobotBuffer, 0, SCOREPETITROBOT_SIZE);
								Unicode::strncpy(scorePetitRobotBuffer, (char*)convert_array_buf, SCOREPETITROBOT_SIZE - 1);
								scorePetitRobotBuffer[16] = '\0'; //make sure last index is null
								scorePetitRobot.invalidate();
							break;

							case 0x54: //T : score total
								score_total = 0;

								for(int i = 3; i < str_vect.size(); i++){
									score_total += (str_vect[i]-48)*(pow(10,(str_vect.size()-i-1)));
								}
								memset(&scoreTotalBuffer, 0, SCORETOTAL_SIZE);
								Unicode::strncpy(scoreTotalBuffer, (char*)convert_array_buf, SCORETOTAL_SIZE - 1);
								scoreTotalBuffer[16] = '\0'; //make sure last index is null
								scoreTotal.invalidate();
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

