#ifndef DEFINE_CAN_H
#define DEFINE_CAN_H


#define CAN_BUS_NAME "vcan0"


//                                  0b000000000000000000000000000000
//                                  Ob|1  |5   |10  |15  |20  |25  |29
//                                  Ob|29  |25  |20  |15  |10  |5  |1
#define CAN_FILTER_ADDR_EMETTEUR    0b000000000001111000000000000000
#define CAN_FILTER_ADDR_RECEPTEUR   0b000000000000000111100000000000
#define CAN_FILTER_CODE_FCT         0b000000000000000000011111110000
#define CAN_FILTER_IS_REP           0b000000000000000000000000001000
#define CAN_FILTER_REP_NBR          0b000000000000000000000000000111

#define CAN_DECALAGE_ADDR_EMETTEUR    15
#define CAN_DECALAGE_ADDR_RECEPTEUR  11
#define CAN_DECALAGE_CODE_FCT       4
//#define CAN_DECALAGE_ID_MSG         4
#define CAN_DECALAGE_IS_REP         3
#define CAN_DECALAGE_REP_NBR    0


#define CAN_MAX_VALUE_ADDR  16
#define CAN_MAX_VALUE_CODE_FCT  128
#define CAN_MAX_VALUE_REP_NBR   8




//definition des addresses sur le bus can (de type 0xX00)
#define CAN_ADDR_RASPBERRY 1
#define CAN_ADDR_BASE_ROULANTE 2


#define CAN_LIST_ADDR (int[]){CAN_ADDR_RASPBERRY, CAN_ADDR_BASE_ROULANTE}

//definition des codes fonctions
#define AVANCE 0x01


//definition des codes fonctions de reponse

#define REP_AVANCE 0x81


#define CAN_LIST_CODE_FCT (int[]){AVANCE, REP_AVANCE}

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



#endif