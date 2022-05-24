/*!
 *  \file define.h
 *  \brief Fichier contenant l'ensemble des constantes utilisées dans la librairie XBee.
 *  \author Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 *  \version 3.0
 *  \date 10/03/2022
 */
#ifndef DEFINE_ECRAN_H
#define DEFINE_ECRAN_H

// Configuration d'usine par défaut des modules XBee neufs
#define EC_SERIAL_PORT_DEFAULT "COM8"
#define EC_BAUDRATE_DEFAULT 115200
#define EC_DATABITS_DEFAULT SERIAL_DATABITS_8
#define EC_PARITY_DEFAULT SERIAL_PARITY_NONE
#define EC_STOPBITS_DEFAULT SERIAL_STOPBITS_1

#define EC_MODE_COMPETITION 0x43
#define EC_MODE_MAINTENANCE 0x4D

#define EC_CAT_TOF 0x54
#define EC_CAT_INIT 0x49
#define EC_CAT_SCORE 0x53

#define EC_SOUS_CAT_SCORE_PET_ROB 0x50
#define EC_SOUS_CAT_SCORE_GRD_ROB 0x47
#define EC_SOUS_CAT_SCORE_TOTAL 0x54

#define EC_SOUS_CAT_ODO 0x4F
#define EC_SOUS_CAT_BASE 0x42
#define EC_SOUS_CAT_XBEE 0x58
#define EC_SOUS_CAT_CAN 0x43

#define EC_SOUS_CAT_TOF_0_AVG 0x30
#define EC_SOUS_CAT_TOF_1_MG 0x31
#define EC_SOUS_CAT_TOF_2_ARG 0x32
#define EC_SOUS_CAT_TOF_3_B 0x33
#define EC_SOUS_CAT_TOF_4_ARD 0x34
#define EC_SOUS_CAT_TOF_5_MD 0x35
#define EC_SOUS_CAT_TOF_6_AVD 0x36
#define EC_SOUS_CAT_TOF_7_HD 0x37
#define EC_SOUS_CAT_TOF_8_HG 0x38

#define EC_FIN_TRAME_1 0x0A
#define EC_FIN_TRAME_2 0x0D

#endif
