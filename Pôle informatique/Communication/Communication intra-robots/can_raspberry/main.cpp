#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <iostream>

#include <unistd.h>


#include "canClass.h"

#include <thread>
#include<string.h>

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


int main(int argc, char **argv)
{
	Log sysLog("systeme");

	sysLog << mendl << mendl << "Début du programme" << mendl;

    Can can;
	int err = can.init(CAN_ADDR_RASPBERRY);
	if(err <0){
		can.logC << "erreur dans l'init du bus can. err n°" << dec << err << "\t\t c.f. #define" << mendl;
		return err;
	}
	
	can.start_listen();

	uint8_t data[8] = {0x01,0x02,0xFF,0x34,0x45};

	err = can.send(CAN_ADDR_RASPBERRY, AVANCE, data, 5, true, 5) ;
	if(err < 0){
		can.logC << "erreur dans l'envoie d'une trame. err n°" << dec << err << "\t\t c.f. #define" << mendl;
	}
	while(true){
		//cout << endl;
		
		//can.listen();
		wait(1000);

	}
}


