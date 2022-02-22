#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>


#include <unistd.h>

#include <thread>


#include <condition_variable>
#include <mutex>  

#include "canClass.h"
#include "define.h"
using namespace std;

Can::Can(){
    int i; 
    int nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;

    idMessageActuel = 0x01;

    printf("CAN Sockets Demo\r\n");

    if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket");
        return;
    }
    strcpy(ifr.ifr_name, CAN_BUS_NAME); //definie le bus sur le quel on travaille (can0 ou vcan0 normalement)
    ioctl(s, SIOCGIFINDEX, &ifr);

    memset(&addr, 0, sizeof(addr));
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind");
        return;
    }
    struct can_filter rfilter[1];
    rfilter[0].can_id   = CAN_ADDR_RASPBERRY;
    rfilter[0].can_mask = 0xF00;


    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

    return;
}

int Can::send(int addr, int codeFct){
    int data[0];
    return send(addr, codeFct ,  data, 0);
}


int Can::send(int addr, int codeFct , int data[], int data_len){
    if (data_len >7){
        cout << "vous ne pouvez envoyer que 7 octet de data" << endl;
        return CAN_ERROR_SIZE_TOO_LONG;   
    }
    

    struct can_frame frame;

    frame.can_id = (addr & 0xf00) + idMessageActuel++;
    if (idMessageActuel >=0xfe)
    {
        idMessageActuel = 0x01;
    }
    frame.can_dlc = data_len+1;
     frame.data[0] = codeFct;

    printf("send : 0x%03X [%d] ",frame.can_id, frame.can_dlc);
    printf("%02X ",frame.data[0]);
    for (int i = 0; i < data_len; i++)
    {
        frame.data[i+1] = data[i];
        printf("%02X ",frame.data[i+1]);
    }
    printf("\r\n");	

    if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) { //on verifie que le nombre de byte envoyer est corecte
        perror("Write");
        return -1;
    }

    return frame.can_id;	
}

struct CanResponse{
	int addr;
    int idMessage;
	int codeFct;
	int dataLen;
	char data[CAN_MAX_DLEN-1];
}; 



int Can::listen(){
	while(true){
		struct can_frame frame;
		struct CanResponse reponse;

		int nbytes;
		nbytes = read(s, &frame, sizeof(struct can_frame));
		if (nbytes < 0) {
			perror("Read");
			return -1 ;
		}

        reponse.addr = frame.can_id & 0xf00;
        reponse.idMessage = frame.can_id & 0x0ff;
        cout << hex << reponse.idMessage <<endl;
        printf("get : 0x%03X [%d] ",frame.can_id, frame.can_dlc);

        for (int i = 0; i < frame.can_dlc; i++){
            printf("%02X ",frame.data[i]);
        }

        printf("\r\n");

        reponse.codeFct = frame.data[0];

        for (int i = 1; i < frame.can_dlc; i++){
            reponse.data[i-1] = frame.data[i];
        }
	}
}



