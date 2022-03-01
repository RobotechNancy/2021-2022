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

	Log test("can");

	long long oskout = 32;
	//test.save(2);
	test << "eaz" << oskout << 3 << mendl;

	test << "e" << oskout << 3 << mendl;


    Can can;
	int err = can.init(CAN_ADDR_RASPBERRY);
	if(err <0){
		cout << "erreur dans l'init du bus can. err n°" << dec << err << "\t\t c.f. #define" << endl;
		return err;
	}
	
	can.start_listen();

	uint8_t data[8] = {0x01,0x02,0xFF,0x34,0x45};

	err = can.send(CAN_ADDR_RASPBERRY, AVANCE, data, 5, true, 5) ;
	if(err < 0){
		cout << "erreur dans l'envoie d'une trame. err n°" << dec << err << "\t\t c.f. #define" << endl;
	}
	while(true){
		//cout << endl;
		
		//can.listen();
		wait(1000);

	}
}


