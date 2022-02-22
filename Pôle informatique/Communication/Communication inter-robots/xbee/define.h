#ifndef DEFINE_XBEE_H
#define DEFINE_XBEE_H

// Paramètres du port série
#define SERIAL_PORT "/dev/ttyAMA0"
#define BAUDRATE 9600
#define DATABITS SERIAL_DATABITS_8
#define PARITY SERIAL_PARITY_NONE
#define STOPBITS SERIAL_STOPBITS_1

// Addresses des robots
#define BROADCAST 0
#define ROBOT_01 1
#define ROBOT_02 2

#define CURRENT_ROBOT ROBOT_01

// Paramètres de la trame message
#define START_SEQ 2
#define END_SEQ 4

// Codes fonctions
#define TEST_ALIVE 1

// Commandes AT
#define AT_ENTER "+++"
#define AT_EXIT "ATCN"
#define AT_END_LINE "\r"
#define AT_WRITE_CONFIG "ATWR"

#define AT_GET_API "ATAP"
#define AT_GET_BAUDRATE "ATBD"
#define AT_GET_AES "ATEE"
#define AT_GET_AES_KEY "ATKY"
#define AT_GET_CHANEL "ATCH"
#define AT_GET_PAN_ID "ATID"
#define AT_GET_COORDINATOR "ATCE"
#define AT_GET_PARITY "ATNB"
#define AT_GET_16BIT_SOURCE_ADDR "ATMY"
#define AT_GET_LOW_DEST_ADDR "ATDL"

#define AT_VALUE_API "0"
#define AT_VALUE_BAUDRATE "3"
#define AT_VALUE_AES "1"
#define AT_VALUE_AES_KEY "32303032"
#define AT_VALUE_CHANEL "C"
#define AT_VALUE_PAN_ID "3332"
#define AT_VALUE_COORDINATOR "0"
#define AT_VALUE_PARITY "0"
#define AT_VALUE_16BIT_SOURCE_ADDR "2"
#define AT_VALUE_LOW_DEST_ADDR "1"

#define AT_EMPTY_VALUE ""
#define AT_SUCCESS_VALUE "OK\r"
#define AT_ERROR_VALUE "ERROR\r"

#define AT_MODE_GET 1
#define AT_MODE_SET 2

// Codes d'erreurs en mode AT
#define AT_ERROR_ENTER -1
#define AT_ERROR_API -2
#define AT_ERROR_BAUDRATE -3
#define AT_ERROR_AES -4
#define AT_ERROR_AES_KEY -13
#define AT_ERROR_CHANEL -5
#define AT_ERROR_PAN_ID -6
#define AT_ERROR_COORDINATOR -7
#define AT_ERROR_PARITY -8
#define AT_ERROR_16BIT_SOURCE_ADDR -9
#define AT_ERROR_LOW_DEST_ADDR -10
#define AT_ERROR_EXIT -11
#define AT_ERROR_WRITE_CONFIG -12
#define AT_ERROR_SUCCESS 0

// Codes d'erreurs 
#define XBEE_ERROR_SUCCESS 0

#endif
