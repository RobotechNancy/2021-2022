#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <iostream>

#include <unistd.h>


#include "canClass.h"

#include <thread>



#include "define.h"
using namespace std;


void wait(int miliseconde){
    usleep(miliseconde*1000);
    return;
}



int main(int argc, char **argv)
{
	
    Can can;

	int data[8] = {'H','e','l','l','o'};
	//can.send(BASE_ROULANTE, AVANCE, data, 5);;
    thread tListen(&Can::listen, can);
	
	while(true){
		cout << endl;
		cout << can.send(CAN_ADDR_BASE_ROULANTE, AVANCE, data, 5) << endl;
		//can.listen();
		wait(1000);

	}
}


