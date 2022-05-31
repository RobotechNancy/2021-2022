#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <iostream>

#include <unistd.h>


#include "canClass.h"

#include <thread>
#include <string.h>

#include <ctime>
#include <sstream>  

#include <iostream>
#include <fstream>


#include "logLib.h"
#include "defineCan.h"

using namespace std;

  

void wait(int miliseconde){
    usleep(miliseconde*1000);
    return;
}


void debug_lulu(Can &can){
	Tramme_Moteur_t moteur;
		CAN_ADDR adr = CAN_ADDR_BASE_ROULANTE;
		uint cdFct;
		CAN_CODE_FCT codeFct;
		uint32_t nbStep;
		uint32_t div0;
		uint32_t div1;
		uint32_t div2;
		uint32_t dir1;
		uint32_t dir2;
		uint32_t dir0;
		/*cout << "adr : ";
		cin >> adr;*/
		cout << "codeFct : ";
		cin >> cdFct;
		switch (cdFct)
		{
		case 1:
			codeFct = AVANCE;
		break;
		case 2:
			codeFct = AVANCE2;
		break;
		case 3:
			codeFct = AVANCE3;
		break;
		case 4:
			codeFct = AVANCE4;
		break;
		case 5:
			codeFct = AVANCE5;
		break;
		case 6:
			codeFct = AVANCE6;
		break;
		
		default:
			break;
		}

		cout << "step (<4294967296) : ";
		cin >> nbStep;

		cout << endl << "div0 (<255) : ";
		cin >> div0;

		cout << endl << "div1 (<255) : ";
		cin >> div1;

		cout << endl << "div2 (<255) : ";
		cin >>div2;

		cout << endl << "dir0 (0 ou 1) : ";
		cin >> dir0;

		cout << endl << "dir1 (0 ou 1) : ";
		cin >>  dir1;

		cout << endl << "dir2 (0 ou 1) : ";
		cin >> dir2;
		moteur.fields.nb_steps = nbStep;
		moteur.fields.div0 = div0;
		moteur.fields.div1 = div1;
		moteur.fields.div2 = div2;
		moteur.fields.dir0 = dir0;
		moteur.fields.dir1 = dir1;
		moteur.fields.dir2 = dir2;

		cout << "Cr send : " << can.send(adr, codeFct, moteur.raw_data, 8, false, 1,0) << endl;
}

void debug_tibo(Can &can){
	Tramme_Moteur_t moteur;
		CAN_ADDR adr = CAN_ADDR_ACTIONNEUR;
		uint cdFct;
		CAN_CODE_FCT codeFct;
		uint16_t angle;
		uint16_t vitesse;
		/*cout << "adr : ";
		cin >> adr;*/
		/*cout << "codeFct : ";
		cin >> cdFct;
		switch (cdFct)
		{
		case 1:
			codeFct = DEPLACEMENT_BRAS_POMPE;
		break;
		case 2:
			codeFct = AVANCE2;
		break;
		case 3:
			codeFct = AVANCE3;
		break;
		case 4:
			codeFct = AVANCE4;
		break;
		case 5:
			codeFct = AVANCE5;
		break;
		case 6:
			codeFct = AVANCE6;
		break;
		
		default:
			break;
		}
*/
		cout << endl<< "angle (<255) : ";
		cin >> angle;/*

		cout << endl << "vitesse (<255²) : ";
		cin >> vitesse;*/

		uint8_t data[3] = {(uint8_t)angle};
		cout << "Cr send : " << can.send(adr, DEPLACEMENT_BRAS_POMPE, data, 1, false, 1,0) << endl;
		wait(1000);
		/*cin >> cdFct;
		uint8_t data2[3] = {0, 6,1};
		cout << "Cr send : " << can.send(adr, DEPLACEMENT_BRAS_POMPE, data2, 3, false, 1) << endl;
		wait(1000);
		cin >> cdFct;*/

}

void debug_nacim(Can &can){
	
		uint8_t data[] ={};
		cout << "Cr send : " << can.send(CAN_ADDR_ODOMETRIE, GET_VARIATION_XY, data, 0, false, 1,0) << endl;
		wait(5000);

}


int main(int argc, char **argv)
{
	Log sysLog("systeme");

	sysLog << mendl << mendl << "Début du programme" << mendl;

    Can can;
	int err = can.init(CAN_ADDR_RASPBERRY_E);//CAN_ADDR_RASPBERRY
	if(err <0){
		can.logC << "erreur dans l'init du bus can. err n°" << dec << err << "\t\t c.f. #define" << mendl;
		return err;
	}
	
	

	uint8_t data[8] = {0x01,0x02,0xFF,0x34,0x45};

	/*err = can.send(CAN_ADDR_BASE_ROULANTE, DEPLACEMENT_COURROIE, data, 8, true, 5) ;
	if(err < 0){
		can.logC << "erreur dans l'envoie d'une trame. err n°" << dec << err << "\t\t c.f. #define" << mendl;
	}*/
	can.start_listen();
	while(true){
		//debug_lulu(can);
		//debug_tibo(can);
		//debug_nacim(can);
		if(can.messages.find(1) != can.messages.end()){
			cout << can.messages[1].codeFct << endl;
			
		}
		wait(1000);

	}
}


