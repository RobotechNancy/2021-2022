/*!
 *  \file define.h
 *  \brief Fichier contenant l'ensemble des constantes utilisées dans la librairie Ecran.
 *  \author Samuel-Charles DITTE-DESTREE (samueldittedestree@protonmail.com)
 *  \version 1.0
 *  \date 31/05/2022
 */
#ifndef DEFINE_ECRAN_H
#define DEFINE_ECRAN_H

// Paramètres du port série
#define EC_SERIAL_PORT_DEFAULT "COM8"
#define EC_BAUDRATE_DEFAULT 115200
#define EC_DATABITS_DEFAULT SERIAL_DATABITS_8
#define EC_PARITY_DEFAULT SERIAL_PARITY_NONE
#define EC_STOPBITS_DEFAULT SERIAL_STOPBITS_1

// Modes de l'écran
typedef enum {
	EC_MODE_COMPETITION = 0x43,
	EC_MODE_MAINTENANCE = 0x4D
} Mode_Ecran_t;

// Codes catégories
typedef enum {
	EC_CAT_TOF = 0x54,
	EC_CAT_INIT = 0x49,
    EC_CAT_SCORE = 0x53
} Categorie_Ecran_t;

// Codes sous catégories
typedef enum {
    // Score
	EC_SOUS_CAT_SCORE_PET_ROB = 0x50,
	EC_SOUS_CAT_SCORE_GRD_ROB = 0x47,
    EC_SOUS_CAT_SCORE_TOTAL = 0x54,

    // Initialisation
    EC_SOUS_CAT_ODO = 0x4F,
    EC_SOUS_CAT_BASE = 0x42,
    EC_SOUS_CAT_XBEE = 0x58,
    EC_SOUS_CAT_CAN = 0x43,

    // Maintenance ToF
    EC_SOUS_CAT_TOF_0_AVG = 0x30,
    EC_SOUS_CAT_TOF_1_MG = 0x31,
    EC_SOUS_CAT_TOF_2_ARG = 0x32,
    EC_SOUS_CAT_TOF_3_B = 0x33,
    EC_SOUS_CAT_TOF_4_ARD = 0x34,
    EC_SOUS_CAT_TOF_5_MD = 0x35,
    EC_SOUS_CAT_TOF_6_AVD = 0x36,
    EC_SOUS_CAT_TOF_7_HD = 0x37,
    EC_SOUS_CAT_TOF_8_HG = 0x38
} Sous_Categorie_Ecran_t;

// Codes fin de trame
#define EC_FIN_TRAME_1 0x0A
#define EC_FIN_TRAME_2 0x0D

// Codes erreurs traitement de trame
#define EC_TRAME_E_SUCCESS 200
#define EC_TRAME_E_SIZE -201
#define EC_TRAME_E_DATA -202
#define EC_TRAME_E_END -203
#define EC_TRAME_E_MODE -204
#define EC_TRAME_E_CAT -205
#define EC_TRAME_E_SOUS_CAT -206

// Codes d'erreurs ouverture connexion série
#define EC_SER_E_SUCCESS 500
#define EC_SER_E_NOT_FOUND -501
#define EC_SER_E_OPEN -502
#define EC_SER_E_PARAM -503
#define EC_SER_E_UKN_BAUDRATE -504
#define EC_SER_E_CONFIG -505
#define EC_SER_E_TIMOUT -506
#define EC_SER_E_UKN_DATABITS -507
#define EC_SER_E_UKN_STOPBITS -508
#define EC_SER_E_UKN_PARITY -509

#endif
