#include <gui/maintenancetof_screen/MaintenanceTofView.hpp>

#include "PollingRoutines.h"
#include "string.h"

extern uint8_t uartMsgBuf[UART_BUF_SIZE];

MaintenanceTofView::MaintenanceTofView()
{

}

void MaintenanceTofView::setupScreen()
{
    MaintenanceTofViewBase::setupScreen();
}

void MaintenanceTofView::tearDownScreen()
{
    MaintenanceTofViewBase::tearDownScreen();
}

void MaintenanceTofView::uartMsgRdy(){

		uint8_t convert_array_buf[UART_BUF_SIZE];
		memset(convert_array_buf, 0, sizeof(convert_array_buf));
		if(uartMsgBuf[0] == 0) return; //array empty so return

		touchgfx::Vector<uint8_t,16> str_vect;
		for(int i = 3; i < UART_BUF_SIZE && uartMsgBuf[i] != 10 && uartMsgBuf[i] != 13; i++){
			convert_array_buf[i-3] = uartMsgBuf[i];
			str_vect.add(uartMsgBuf[i]);
		}
		switch(uartMsgBuf[0]){
			case 0x4D: //M : maintenance

				switch(uartMsgBuf[1]){
					case 0x54: //T : capteurs ToF

						switch(uartMsgBuf[2]){
							 case 0x30: //0 : Tof n°0 [AVG]
								 memset(&texteTof_0_AVGBuffer, 0, TEXTETOF_0_AVG_SIZE);
								 Unicode::strncpy(texteTof_0_AVGBuffer, (char*)convert_array_buf, TEXTETOF_0_AVG_SIZE - 1);
								 texteTof_0_AVGBuffer[16] = '\0'; //make sure last index is null
								 texteTof_0_AVG.invalidate();
							 break;

							 case 0x31: //1 : Tof n°1 [MG]
								 memset(&texteTof_1_MGBuffer, 0, TEXTETOF_1_MG_SIZE);
								 Unicode::strncpy(texteTof_1_MGBuffer, (char*)convert_array_buf, TEXTETOF_1_MG_SIZE - 1);
				                 texteTof_1_MGBuffer[16] = '\0'; //make sure last index is null
								 texteTof_1_MG.invalidate();
							 break;

							 case 0x32: //2 : Tof n°2 [ARG]
								 memset(&texteTof_2_ARGBuffer, 0, TEXTETOF_2_ARG_SIZE);
								 Unicode::strncpy(texteTof_2_ARGBuffer, (char*)convert_array_buf, TEXTETOF_2_ARG_SIZE - 1);
								 texteTof_2_ARGBuffer[16] = '\0'; //make sure last index is null
								 texteTof_2_ARG.invalidate();
							 break;

							 case 0x33: //3 : Tof n°3 [B]
								 memset(&texteTof_3_BBuffer, 0, TEXTETOF_3_B_SIZE);
								 Unicode::strncpy(texteTof_3_BBuffer, (char*)convert_array_buf, TEXTETOF_3_B_SIZE - 1);
								 texteTof_3_BBuffer[16] = '\0'; //make sure last index is null
								 texteTof_3_B.invalidate();
							 break;

							 case 0x34: //4 : Tof n°4 [ARD]
								 memset(&texteTof_4_ARDBuffer, 0, TEXTETOF_4_ARD_SIZE);
							     Unicode::strncpy(texteTof_4_ARDBuffer, (char*)convert_array_buf, TEXTETOF_4_ARD_SIZE - 1);
								 texteTof_4_ARDBuffer[16] = '\0'; //make sure last index is null
								 texteTof_4_ARD.invalidate();
							 break;

							 case 0x35: //5 : Tof n°5 [MD]
								 memset(&texteTof_5_MDBuffer, 0, TEXTETOF_5_MD_SIZE);
								 Unicode::strncpy(texteTof_5_MDBuffer, (char*)convert_array_buf, TEXTETOF_5_MD_SIZE - 1);
								 texteTof_5_MDBuffer[16] = '\0'; //make sure last index is null
								 texteTof_5_MD.invalidate();
							 break;

							 case 0x36: //6 : Tof n°6 [AVD]
								 memset(&texteTof_6_AVDBuffer, 0, TEXTETOF_6_AVD_SIZE);
								 Unicode::strncpy(texteTof_6_AVDBuffer, (char*)convert_array_buf, TEXTETOF_6_AVD_SIZE - 1);
								 texteTof_6_AVDBuffer[16] = '\0'; //make sure last index is null
								 texteTof_6_AVD.invalidate();
							 break;

							 case 0x37: //7 : Tof n°7 [HD]
								 memset(&texteTof_7_HDBuffer, 0, TEXTETOF_7_HD_SIZE);
								 Unicode::strncpy(texteTof_7_HDBuffer, (char*)convert_array_buf, TEXTETOF_7_HD_SIZE - 1);
								 texteTof_7_HDBuffer[16] = '\0'; //make sure last index is null
								 texteTof_7_HD.invalidate();
							 break;

							 case 0x38: //8 : Tof n°8 [HG]
								 memset(&texteTof_8_HGBuffer, 0, TEXTETOF_8_HG_SIZE);
								 Unicode::strncpy(texteTof_8_HGBuffer, (char*)convert_array_buf, TEXTETOF_8_HG_SIZE - 1);
								 texteTof_8_HGBuffer[16] = '\0'; //make sure last index is null
								 texteTof_8_HG.invalidate();
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

