#ifndef DEFINE_CAN_H
#define DEFINE_CAN_H


#define CAN_BUS_NAME "vcan0"


//                                  0b00000000000000000000000000000
//                                  Ob|1  |5   |10  |15  |20  |25 |29
//                                  Ob|29 |25  |20  |15  |10  |5  |1
#define CAN_FILTER_ADDR_EMETTEUR    0b01111000000000000000000000000
#define CAN_FILTER_ADDR_RECEPTEUR   0b00000111100000000000000000000
#define CAN_FILTER_CODE_FCT         0b00000000011111111000000000000
#define CAN_FILTER_IDE_MSG          0b00000000000000000111111110000
#define CAN_FILTER_IS_REP           0b00000000000000000000000001000
#define CAN_FILTER_REP_NBR          0b00000000000000000000000000111


#define CAN_DECALAGE_ID_MSG         4
#define CAN_DECALAGE_IS_REP         3

/*
#define CAN_MAX_VALUE_ADDR  16
#define CAN_MAX_VALUE_CODE_FCT  128
#define CAN_MAX_VALUE_REP_NBR   8*/


//                                   0xF000000  (six 0)
//                                   0b01111 0000 0000 0000 0000 0000 0000
//definition des addresses d'émmission sur le bus can (de type 0xX00)
typedef enum {
    CAN_ADDR_RASPBERRY = 0x1000000,
    CAN_ADDR_BASE_ROULANTE = 0x2000000
}CAN_ADDR;


//                                   0x0F00000  (cinq 0)
//                                   0b00000 1111 0000 0000 0000 0000 0000
//definition des addresses de réception sur le bus can (de type 0xX00)
typedef enum {
    CAN_ADDR_RASPBERRY_E = 0x100000,
    CAN_ADDR_BASE_ROULANTE_E = 0x200000
}CAN_EMIT_ADDR;



//      0xFF000  (trois 0)
//      0b00000 0000 1111 1111 0000 0000 0000
typedef enum {
    AVANCE = 0x01000,
    STOP = 0x02000,
    STOP_URGENT = 0x03000,
	AVANCE4 = 0x04000,
    AVANCE5 = 0x05000,
    AVANCE6 = 0x06000,
    REP_AVANCE = 0x81000
}CAN_CODE_FCT;


#define CAN_LIST_CODE_FCT (uint[]){AVANCE, REP_AVANCE}

//definition des code erreur

// OOB => Out Of Bound


#define CAN_E_WRITE_ERROR -501
#define CAN_E_READ_ERROR -502
#define CAN_E_SOCKET_ERROR -503
#define CAN_E_BIND_ERROR -504

//  11X -> taille valeur
#define CAN_E_DATA_SIZE_TOO_LONG -510
#define CAN_E_OOB_ADDR -511
#define CAN_E_OOB_CODE_FCT -512
#define CAN_E_OOB_REP_NBR -513
#define CAN_E_OOB_DATA -514

// 12X -> unknow
#define CAN_E_UNKNOW_ADDR -551
#define CAN_E_UNKNOW_CODE_FCT -552

#define ACTION_IMPOSSIBLE 0
#define FIN_TRAJET 1

#endif
