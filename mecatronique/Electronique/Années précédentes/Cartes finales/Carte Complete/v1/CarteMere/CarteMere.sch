EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 31
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1400 800  2250 1250
U 5FB7B166
F0 "Gestion de l'alimentation" 50
F1 "gestion_alim.sch" 50
F2 "CAN_H" B R 3650 900 50 
F3 "CAN_L" B R 3650 1000 50 
$EndSheet
$Sheet
S 1400 2250 2250 1150
U 5FB7B1A2
F0 "Gestion de la Motorisation" 50
F1 "gestion_moteurs.sch" 50
F2 "CAN_H" B R 3650 2350 50 
F3 "CAN_L" B R 3650 2450 50 
$EndSheet
$Sheet
S 8800 4950 2250 1250
U 5FB7B1E6
F0 "Raspberry" 50
F1 "raspi.sch" 50
F2 "CS" O L 8800 5050 50 
F3 "CLK" O L 8800 5150 50 
F4 "MISO" I L 8800 5250 50 
F5 "MOSI" O L 8800 5350 50 
$EndSheet
$Sheet
S 5900 4950 2250 1250
U 5FB7B30F
F0 "Gestion des communications" 50
F1 "comm.sch" 50
F2 "CAN_H" B L 5900 5050 50 
F3 "CAN_L" B L 5900 5150 50 
F4 "CS" I R 8150 5050 50 
F5 "CLK" I R 8150 5150 50 
F6 "MISO" O R 8150 5250 50 
F7 "MOSI" I R 8150 5350 50 
$EndSheet
Text Label 9250 1800 2    50   ~ 0
CAN_EXT_P
Text Label 9250 1900 2    50   ~ 0
CAN_EXT_N
Wire Wire Line
	9250 1900 8800 1900
Wire Wire Line
	8800 1800 9250 1800
Text Label 7100 1800 0    50   ~ 0
CAN_P
Text Label 7100 1900 0    50   ~ 0
CAN_N
$Sheet
S 1400 3600 2250 1150
U 5FCDCA9E
F0 "Gestion odometrie" 50
F1 "odometrie.sch" 50
F2 "CAN_H" B R 3650 3700 50 
F3 "CAN_L" B R 3650 3800 50 
$EndSheet
$Sheet
S 1400 4950 2250 1150
U 5FCDCBDF
F0 "Gestion du bras" 50
F1 "gestion_bras.sch" 50
F2 "CAN_H" B R 3650 5050 50 
F3 "CAN_L" B R 3650 5150 50 
$EndSheet
$Sheet
S 1400 6300 2250 1150
U 5FCDCE63
F0 "Gestion des glissieres" 50
F1 "gestion_glissieres.sch" 50
F2 "CAN_H" B R 3650 6400 50 
F3 "CAN_L" B R 3650 6500 50 
$EndSheet
Text Label 4100 900  2    50   ~ 0
CAN_P
Text Label 4100 1000 2    50   ~ 0
CAN_N
Text Label 4100 2350 2    50   ~ 0
CAN_P
Text Label 4100 2450 2    50   ~ 0
CAN_N
Text Label 4100 3700 2    50   ~ 0
CAN_P
Text Label 4100 3800 2    50   ~ 0
CAN_N
Text Label 4100 5050 2    50   ~ 0
CAN_P
Text Label 4100 5150 2    50   ~ 0
CAN_N
Text Label 4100 6400 2    50   ~ 0
CAN_P
Text Label 4100 6500 2    50   ~ 0
CAN_N
Text Label 5450 5050 0    50   ~ 0
CAN_P
Text Label 5450 5150 0    50   ~ 0
CAN_N
$Sheet
S 7550 700  1250 550 
U 5FCDE6FD
F0 "Terminaison Bus CAN" 50
F1 "term_can.sch" 50
F2 "CAN_H" B L 7550 900 50 
F3 "CAN_L" B L 7550 1000 50 
$EndSheet
$Sheet
S 7550 1600 1250 550 
U 5FCD939A
F0 "protections can vers exterieur" 50
F1 "CAN_EXT.sch" 50
F2 "CAN_H_IN" B L 7550 1800 50 
F3 "CAN_L_IN" B L 7550 1900 50 
F4 "CAN_H_OUT" B R 8800 1800 50 
F5 "CAN_L_OUT" B R 8800 1900 50 
$EndSheet
Text Label 7100 900  0    50   ~ 0
CAN_P
Text Label 7100 1000 0    50   ~ 0
CAN_N
Wire Wire Line
	8800 5350 8150 5350
Wire Wire Line
	8150 5250 8800 5250
Wire Wire Line
	8800 5150 8150 5150
Wire Wire Line
	8150 5050 8800 5050
Text Notes 7550 3600 0    118  ~ 0
3V3 : Microcontrolleurs et capteurs\n5P : RPi\n5V : 5V accessoires\n12V : 12V accessoires\n+BATT : Tension batterie protégee
Text Notes 7550 2650 0    118  ~ 24
Gestion des rails d'alimentation
Wire Wire Line
	3650 900  5150 900 
Wire Wire Line
	3650 1000 5250 1000
Wire Wire Line
	3650 6500 5250 6500
Connection ~ 5250 1000
Wire Wire Line
	5250 1000 6750 1000
Wire Wire Line
	3650 6400 5150 6400
Connection ~ 5150 900 
Wire Wire Line
	5150 900  6850 900 
Wire Wire Line
	3650 2450 5250 2450
Connection ~ 5250 2450
Wire Wire Line
	3650 3800 5250 3800
Connection ~ 5250 3800
Wire Wire Line
	5250 1000 5250 2450
Wire Wire Line
	5150 2350 3650 2350
Connection ~ 5150 2350
Wire Wire Line
	5150 2350 5150 900 
Wire Wire Line
	5250 2450 5250 3800
Connection ~ 5150 3700
Wire Wire Line
	5150 3700 5150 2350
Wire Wire Line
	3650 5050 5150 5050
Connection ~ 5150 5050
Wire Wire Line
	5150 5050 5150 3700
Wire Wire Line
	5150 5050 5150 6400
Wire Wire Line
	5250 3800 5250 5150
Wire Wire Line
	5900 5050 5150 5050
Wire Wire Line
	5250 5150 5900 5150
Connection ~ 5250 5150
Wire Wire Line
	5250 5150 5250 6500
Wire Wire Line
	3650 5150 5250 5150
Wire Wire Line
	6850 1800 6850 900 
Wire Wire Line
	6850 1800 7550 1800
Connection ~ 6850 900 
Wire Wire Line
	6850 900  7550 900 
Wire Wire Line
	6750 1000 6750 1900
Wire Wire Line
	6750 1900 7550 1900
Connection ~ 6750 1000
Wire Wire Line
	6750 1000 7550 1000
Wire Wire Line
	3650 3700 5150 3700
$EndSCHEMATC
