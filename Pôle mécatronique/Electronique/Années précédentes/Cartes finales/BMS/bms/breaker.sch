EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 31
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5100 3550 2    50   Input ~ 10
IN
Text HLabel 3200 3450 0    50   Output ~ 10
OUT
Text HLabel 2700 5450 0    50   Input ~ 0
EN
Wire Wire Line
	4700 3950 4500 3950
$Comp
L Transistor_FET:BSS138 Q401
U 1 1 5FBB5E81
P 3400 5450
F 0 "Q401" H 3604 5496 50  0000 L CNN
F 1 "BSS138" H 3604 5405 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3600 5375 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 3400 5450 50  0001 L CNN
	1    3400 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3950 3750 3950
$Comp
L Device:R_Small R?
U 1 1 5FBB9448
P 2800 5450
AR Path="/5FB514CA/5FBB9448" Ref="R?"  Part="1" 
AR Path="/5FB4C14D/5FBB9448" Ref="R?"  Part="1" 
AR Path="/5FB7B166/5FB4C14D/5FBB9448" Ref="R401"  Part="1" 
F 0 "R401" V 2604 5450 50  0000 C CNN
F 1 "1k" V 2695 5450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2800 5450 50  0001 C CNN
F 3 "~" H 2800 5450 50  0001 C CNN
	1    2800 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5FBB944F
P 2950 5600
AR Path="/5FB514CA/5FBB944F" Ref="R?"  Part="1" 
AR Path="/5FB4C14D/5FBB944F" Ref="R?"  Part="1" 
AR Path="/5FB7B166/5FB4C14D/5FBB944F" Ref="R402"  Part="1" 
F 0 "R402" H 2891 5554 50  0000 R CNN
F 1 "10k" H 2891 5645 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2950 5600 50  0001 C CNN
F 3 "~" H 2950 5600 50  0001 C CNN
	1    2950 5600
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 5450 2950 5450
Wire Wire Line
	2950 5450 2950 5500
$Comp
L power:GND #PWR?
U 1 1 5FBB9457
P 2950 5700
AR Path="/5FB514CA/5FBB9457" Ref="#PWR?"  Part="1" 
AR Path="/5FB4C14D/5FBB9457" Ref="#PWR?"  Part="1" 
AR Path="/5FB7B166/5FB4C14D/5FBB9457" Ref="#PWR0401"  Part="1" 
F 0 "#PWR0401" H 2950 5450 50  0001 C CNN
F 1 "GND" H 2955 5527 50  0000 C CNN
F 2 "" H 2950 5700 50  0001 C CNN
F 3 "" H 2950 5700 50  0001 C CNN
	1    2950 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 5450 3200 5450
Connection ~ 2950 5450
$Comp
L power:GND #PWR?
U 1 1 5FBBD111
P 3500 5700
AR Path="/5FB514CA/5FBBD111" Ref="#PWR?"  Part="1" 
AR Path="/5FB4C14D/5FBBD111" Ref="#PWR?"  Part="1" 
AR Path="/5FB7B166/5FB4C14D/5FBBD111" Ref="#PWR0402"  Part="1" 
F 0 "#PWR0402" H 3500 5450 50  0001 C CNN
F 1 "GND" H 3505 5527 50  0000 C CNN
F 2 "" H 3500 5700 50  0001 C CNN
F 3 "" H 3500 5700 50  0001 C CNN
	1    3500 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5700 3500 5650
$Comp
L Diode:BAT54CW D401
U 1 1 5FBBDD50
P 3950 4550
F 0 "D401" V 3904 4638 50  0000 L CNN
F 1 "BAT54CW" V 3995 4638 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 4025 4675 50  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/BAT54W_SER.pdf" H 3870 4550 50  0001 C CNN
	1    3950 4550
	0    -1   1    0   
$EndComp
Wire Wire Line
	3500 3950 3500 4250
Wire Wire Line
	4150 4550 4500 4550
Wire Wire Line
	3950 4250 3500 4250
Connection ~ 4500 3950
Wire Wire Line
	4500 3950 4350 3950
Wire Wire Line
	3500 4850 3950 4850
NoConn ~ 3750 3650
Wire Wire Line
	3200 3450 3750 3450
$Comp
L Relay:G5LE-1 K?
U 1 1 5FB4EA79
P 4050 3750
AR Path="/5FB4EA79" Ref="K?"  Part="1" 
AR Path="/5FB4C14D/5FB4EA79" Ref="K?"  Part="1" 
AR Path="/5FB514CA/5FB4EA79" Ref="K?"  Part="1" 
AR Path="/5FB7B166/5FB4C14D/5FB4EA79" Ref="K401"  Part="1" 
F 0 "K401" H 4480 3796 50  0000 L CNN
F 1 "G5LE-1" H 4480 3705 50  0000 L CNN
F 2 "Relay_THT:Relay_SPDT_Omron-G5LE-1" H 4500 3700 50  0001 L CNN
F 3 "http://www.omron.com/ecb/products/pdf/en-g5le.pdf" H 4050 3750 50  0001 C CNN
	1    4050 3750
	0    -1   -1   0   
$EndComp
Connection ~ 3500 4250
Connection ~ 3500 4850
Wire Wire Line
	3500 4850 3500 5250
Wire Wire Line
	3500 4250 3500 4850
Wire Wire Line
	4500 3950 4500 4550
Text HLabel 4700 3950 2    50   Output ~ 0
BAU_L
Text HLabel 5350 3950 0    50   Output ~ 0
BAU_H
Wire Wire Line
	4350 3550 5100 3550
$EndSCHEMATC
