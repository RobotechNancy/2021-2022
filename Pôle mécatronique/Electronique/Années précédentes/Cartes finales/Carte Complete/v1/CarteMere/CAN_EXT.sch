EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 31 31
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5000 3800 0    50   BiDi ~ 0
CAN_H_IN
Text HLabel 5000 4400 0    50   BiDi ~ 0
CAN_L_IN
Text HLabel 6600 3800 2    50   BiDi ~ 0
CAN_H_OUT
Text HLabel 6600 4400 2    50   BiDi ~ 0
CAN_L_OUT
Text Notes 4850 3500 0    118  ~ 0
Protection Bus CAN
$Comp
L power:GND #PWR03101
U 1 1 5FCE1915
P 5700 4150
F 0 "#PWR03101" H 5700 3900 50  0001 C CNN
F 1 "GND" H 5705 3977 50  0000 C CNN
F 2 "" H 5700 4150 50  0001 C CNN
F 3 "" H 5700 4150 50  0001 C CNN
	1    5700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4150 5350 4100
$Comp
L Device:C_Small C3101
U 1 1 5FCDF570
P 5350 3950
F 0 "C3101" H 5442 3996 50  0000 L CNN
F 1 "10n" H 5442 3905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5350 3950 50  0001 C CNN
F 3 "~" H 5350 3950 50  0001 C CNN
	1    5350 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3102
U 1 1 5FCDF571
P 5350 4250
F 0 "C3102" H 5442 4296 50  0000 L CNN
F 1 "10n" H 5442 4205 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5350 4250 50  0001 C CNN
F 3 "~" H 5350 4250 50  0001 C CNN
	1    5350 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 4050 5350 4100
Connection ~ 5350 4100
Wire Wire Line
	5350 3800 5350 3850
Wire Wire Line
	5350 4400 5350 4350
Wire Wire Line
	5350 4100 5700 4100
Wire Wire Line
	5700 4100 5700 4150
$Comp
L Device:D_Zener_x2_ACom_KKA D3101
U 1 1 5FCDF572
P 5900 4100
F 0 "D3101" V 5854 4178 50  0000 L CNN
F 1 "D_Zener_x2_ACom_KKA" V 5945 4178 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5900 4100 50  0001 C CNN
F 3 "~" H 5900 4100 50  0001 C CNN
	1    5900 4100
	0    1    -1   0   
$EndComp
Connection ~ 5700 4100
Wire Wire Line
	5900 3800 5350 3800
Wire Wire Line
	5900 4400 5350 4400
Text Notes 4050 4800 0    79   ~ 0
Protection de la carte contre les ESD par deux diodes TVS
Wire Wire Line
	6600 4400 5900 4400
Connection ~ 5900 4400
Wire Wire Line
	5350 4400 5000 4400
Connection ~ 5350 4400
Wire Wire Line
	5000 3800 5350 3800
Connection ~ 5350 3800
Wire Wire Line
	5900 3800 6600 3800
Connection ~ 5900 3800
$EndSCHEMATC
