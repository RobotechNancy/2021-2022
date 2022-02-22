/*
    entrez les valeurs en hexa
*/


#define CAN_BUS_NAME "can0"


//definition des addresses sur le bus can (de type 0xX00)
#define CAN_ADDR_RASPBERRY 0x100
#define CAN_ADDR_BASE_ROULANTE 0x200




//definition des codes fonctions
#define AVANCE 0x01



//definition des codes fonctions de reponse

#define rep_ACANCE 0x81



//definition des code erreur

#define CAN_ERROR_SIZE_TOO_LONG -11