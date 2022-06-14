EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Interface_CAN_LIN:TCAN337 U?
U 1 1 5FC0A40B
P 5850 2200
AR Path="/5FC0A40B" Ref="U?"  Part="1" 
AR Path="/5FCD74DC/5FC0A40B" Ref="U?"  Part="1" 
AR Path="/5FBD6585/5FC0A40B" Ref="U?"  Part="1" 
F 0 "U?" H 6300 1700 50  0000 C CNN
F 1 "TCAN337" H 6300 1800 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5850 1700 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tcan337.pdf" H 5850 2200 50  0001 C CNN
F 4 "TCAN337GDR" H 5850 2200 50  0001 C CNN "MFR.Part #"
F 5 " C191004" H 5850 2200 50  0001 C CNN "LCSC Part #"
F 6 "SOIC-8_3.9x4.9x1.27P" H 5850 2200 50  0001 C CNN "Package"
	1    5850 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC0A411
P 5850 2600
AR Path="/5FC0A411" Ref="#PWR?"  Part="1" 
AR Path="/5FCD74DC/5FC0A411" Ref="#PWR?"  Part="1" 
AR Path="/5FBD6585/5FC0A411" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5850 2350 50  0001 C CNN
F 1 "GND" H 5855 2472 50  0000 R CNN
F 2 "" H 5850 2600 50  0001 C CNN
F 3 "" H 5850 2600 50  0001 C CNN
	1    5850 2600
	1    0    0    -1  
$EndComp
Text Notes 5200 1300 0    118  ~ 0
CAN Tranceiver
$Comp
L power:+3.3V #PWR?
U 1 1 5FC0A418
P 5850 1800
AR Path="/5FC0A418" Ref="#PWR?"  Part="1" 
AR Path="/5FCD74DC/5FC0A418" Ref="#PWR?"  Part="1" 
AR Path="/5FBD6585/5FC0A418" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5850 1650 50  0001 C CNN
F 1 "+3.3V" H 5865 1973 50  0000 C CNN
F 2 "" H 5850 1800 50  0001 C CNN
F 3 "" H 5850 1800 50  0001 C CNN
	1    5850 1800
	1    0    0    -1  
$EndComp
Text Notes 4900 4850 0    118  ~ 0
Protection Bus CAN
Text Notes 4900 3900 0    118  ~ 0
Connecteur Bus CAN
Text Label 6600 2100 2    50   ~ 0
CAN_P
Text Label 6600 2300 2    50   ~ 0
CAN_N
Text Label 5600 4200 0    50   ~ 0
CAN_P
Text Label 5600 4300 0    50   ~ 0
CAN_N
Wire Wire Line
	5850 4300 5600 4300
Wire Wire Line
	5600 4200 5850 4200
Wire Wire Line
	6600 2300 6350 2300
Wire Wire Line
	6350 2100 6600 2100
$Comp
L Device:C_Small C?
U 1 1 5FC0A428
P 2800 2200
F 0 "C?" H 2892 2246 50  0000 L CNN
F 1 "100n" H 2892 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2800 2200 50  0001 C CNN
F 3 "~" H 2800 2200 50  0001 C CNN
	1    2800 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FC0A42E
P 3150 2200
F 0 "C?" H 3242 2246 50  0000 L CNN
F 1 "10u" H 3242 2155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3150 2200 50  0001 C CNN
F 3 "~" H 3150 2200 50  0001 C CNN
	1    3150 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 2000 2800 2100
Wire Wire Line
	2800 2000 3150 2000
Wire Wire Line
	3150 2000 3150 2100
Wire Wire Line
	3150 2300 3150 2400
Connection ~ 3150 2400
Wire Wire Line
	2800 2300 2800 2400
Wire Wire Line
	2800 2400 3150 2400
Connection ~ 3150 2000
$Comp
L power:+3.3V #PWR?
U 1 1 5FC0A43C
P 3150 1850
F 0 "#PWR?" H 3150 1700 50  0001 C CNN
F 1 "+3.3V" H 3165 2023 50  0000 C CNN
F 2 "" H 3150 1850 50  0001 C CNN
F 3 "" H 3150 1850 50  0001 C CNN
	1    3150 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 1850 3150 2000
$Comp
L power:GND #PWR?
U 1 1 5FC0A443
P 3150 2550
F 0 "#PWR?" H 3150 2300 50  0001 C CNN
F 1 "GND" H 3155 2377 50  0000 C CNN
F 2 "" H 3150 2550 50  0001 C CNN
F 3 "" H 3150 2550 50  0001 C CNN
	1    3150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2550 3150 2400
Text Label 5150 5150 0    50   ~ 0
CAN_P
Text Label 5150 5750 0    50   ~ 0
CAN_N
$Comp
L Device:R_Small R?
U 1 1 5FC0A44C
P 5450 5300
F 0 "R?" H 5509 5346 50  0000 L CNN
F 1 "56" H 5509 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5450 5300 50  0001 C CNN
F 3 "~" H 5450 5300 50  0001 C CNN
	1    5450 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5FC0A452
P 5450 5600
F 0 "R?" H 5509 5646 50  0000 L CNN
F 1 "56" H 5509 5555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5450 5600 50  0001 C CNN
F 3 "~" H 5450 5600 50  0001 C CNN
	1    5450 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 5750 5450 5700
Wire Wire Line
	5150 5750 5450 5750
Wire Wire Line
	5450 5150 5450 5200
Wire Wire Line
	5150 5150 5450 5150
Wire Wire Line
	5450 5400 5450 5450
$Comp
L Device:C_Small C?
U 1 1 5FC0A45D
P 5750 5450
F 0 "C?" H 5842 5496 50  0000 L CNN
F 1 "10n" H 5842 5405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5750 5450 50  0001 C CNN
F 3 "~" H 5750 5450 50  0001 C CNN
	1    5750 5450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5650 5450 5450 5450
Connection ~ 5450 5450
Wire Wire Line
	5450 5450 5450 5500
$Comp
L power:GND #PWR?
U 1 1 5FC0A466
P 6300 5500
F 0 "#PWR?" H 6300 5250 50  0001 C CNN
F 1 "GND" H 6305 5327 50  0000 C CNN
F 2 "" H 6300 5500 50  0001 C CNN
F 3 "" H 6300 5500 50  0001 C CNN
	1    6300 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 5500 5950 5450
Wire Wire Line
	5950 5450 5850 5450
$Comp
L Device:C_Small C?
U 1 1 5FC0A46E
P 5950 5300
F 0 "C?" H 6042 5346 50  0000 L CNN
F 1 "10n" H 6042 5255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5950 5300 50  0001 C CNN
F 3 "~" H 5950 5300 50  0001 C CNN
	1    5950 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FC0A474
P 5950 5600
F 0 "C?" H 6042 5646 50  0000 L CNN
F 1 "10n" H 6042 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5950 5600 50  0001 C CNN
F 3 "~" H 5950 5600 50  0001 C CNN
	1    5950 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 5400 5950 5450
Connection ~ 5950 5450
Wire Wire Line
	5450 5150 5950 5150
Wire Wire Line
	5950 5150 5950 5200
Connection ~ 5450 5150
Wire Wire Line
	5450 5750 5950 5750
Wire Wire Line
	5950 5750 5950 5700
Connection ~ 5450 5750
Wire Wire Line
	5950 5450 6300 5450
Wire Wire Line
	6300 5450 6300 5500
$Comp
L Device:D_Zener_x2_ACom_KKA D?
U 1 1 5FC0A484
P 6500 5450
F 0 "D?" V 6454 5528 50  0000 L CNN
F 1 "D_Zener_x2_ACom_KKA" V 6545 5528 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6500 5450 50  0001 C CNN
F 3 "~" H 6500 5450 50  0001 C CNN
	1    6500 5450
	0    1    -1   0   
$EndComp
Connection ~ 6300 5450
Wire Wire Line
	6500 5150 5950 5150
Connection ~ 5950 5150
Wire Wire Line
	6500 5750 5950 5750
Connection ~ 5950 5750
$Comp
L Device:R_Small R?
U 1 1 5FC0A48F
P 2150 4200
AR Path="/5FC0A48F" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FC0A48F" Ref="R?"  Part="1" 
AR Path="/5FBD6585/5FC0A48F" Ref="R?"  Part="1" 
F 0 "R?" V 1954 4200 50  0000 C CNN
F 1 "1k" V 2045 4200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2150 4200 50  0001 C CNN
F 3 "~" H 2150 4200 50  0001 C CNN
	1    2150 4200
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FC0A495
P 2300 4350
F 0 "C?" H 2392 4396 50  0000 L CNN
F 1 "10n" H 2392 4305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2300 4350 50  0001 C CNN
F 3 "~" H 2300 4350 50  0001 C CNN
	1    2300 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC0A49B
P 2300 4450
F 0 "#PWR?" H 2300 4200 50  0001 C CNN
F 1 "GND" H 2305 4277 50  0000 C CNN
F 2 "" H 2300 4450 50  0001 C CNN
F 3 "" H 2300 4450 50  0001 C CNN
	1    2300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 4250 2300 4200
Wire Wire Line
	2300 4200 2250 4200
Wire Wire Line
	2300 4200 3150 4200
Connection ~ 2300 4200
Text Label 3150 4200 2    50   ~ 0
CAN_SILENT_FILTERED
Wire Wire Line
	5350 2400 4500 2400
Text Label 4500 2400 0    50   ~ 0
CAN_SILENT_FILTERED
$Comp
L Device:R_Small R?
U 1 1 5FC0A4A8
P 2150 4950
AR Path="/5FC0A4A8" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FC0A4A8" Ref="R?"  Part="1" 
AR Path="/5FBD6585/5FC0A4A8" Ref="R?"  Part="1" 
F 0 "R?" V 1954 4950 50  0000 C CNN
F 1 "0R" V 2045 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2150 4950 50  0001 C CNN
F 3 "~" H 2150 4950 50  0001 C CNN
	1    2150 4950
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FC0A4AE
P 2300 5100
F 0 "C?" H 2392 5146 50  0000 L CNN
F 1 "10n" H 2392 5055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2300 5100 50  0001 C CNN
F 3 "~" H 2300 5100 50  0001 C CNN
	1    2300 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC0A4B4
P 2300 5200
F 0 "#PWR?" H 2300 4950 50  0001 C CNN
F 1 "GND" H 2305 5027 50  0000 C CNN
F 2 "" H 2300 5200 50  0001 C CNN
F 3 "" H 2300 5200 50  0001 C CNN
	1    2300 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 5000 2300 4950
Wire Wire Line
	2300 4950 2250 4950
Wire Wire Line
	2300 4950 3150 4950
Connection ~ 2300 4950
Text Label 3150 4950 2    50   ~ 0
CAN_TX_FILTERED
Wire Wire Line
	5350 2000 4500 2000
Text Label 4500 2000 0    50   ~ 0
CAN_TX_FILTERED
Text Label 4500 2300 0    50   ~ 0
CAN_FAULT_OUT
Wire Wire Line
	4500 2300 5350 2300
Text Label 1600 6200 0    50   ~ 0
CAN_FAULT_OUT
Wire Wire Line
	1600 6200 2300 6200
$Comp
L Device:C_Small C?
U 1 1 5FC0A4C5
P 2300 6400
F 0 "C?" H 2392 6446 50  0000 L CNN
F 1 "10n" H 2392 6355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2300 6400 50  0001 C CNN
F 3 "~" H 2300 6400 50  0001 C CNN
	1    2300 6400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC0A4CB
P 2300 6500
F 0 "#PWR?" H 2300 6250 50  0001 C CNN
F 1 "GND" H 2305 6327 50  0000 C CNN
F 2 "" H 2300 6500 50  0001 C CNN
F 3 "" H 2300 6500 50  0001 C CNN
	1    2300 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6300 2300 6200
Connection ~ 2300 6200
Wire Wire Line
	2300 6200 2450 6200
$Comp
L Device:R_Small R?
U 1 1 5FC0A4D4
P 2550 6050
AR Path="/5FC0A4D4" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FC0A4D4" Ref="R?"  Part="1" 
AR Path="/5FBD6585/5FC0A4D4" Ref="R?"  Part="1" 
F 0 "R?" V 2354 6050 50  0000 C CNN
F 1 "0R" V 2445 6050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2550 6050 50  0001 C CNN
F 3 "~" H 2550 6050 50  0001 C CNN
	1    2550 6050
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 6050 2300 6050
Wire Wire Line
	2300 6050 2300 6200
$Comp
L Device:R_Small R?
U 1 1 5FC0A4DC
P 2300 5900
AR Path="/5FC0A4DC" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FC0A4DC" Ref="R?"  Part="1" 
AR Path="/5FBD6585/5FC0A4DC" Ref="R?"  Part="1" 
F 0 "R?" V 2104 5900 50  0000 C CNN
F 1 "10k" V 2195 5900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2300 5900 50  0001 C CNN
F 3 "~" H 2300 5900 50  0001 C CNN
	1    2300 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6000 2300 6050
Connection ~ 2300 6050
$Comp
L power:+3.3V #PWR?
U 1 1 5FC0A4E4
P 2300 5800
F 0 "#PWR?" H 2300 5650 50  0001 C CNN
F 1 "+3.3V" H 2315 5973 50  0000 C CNN
F 2 "" H 2300 5800 50  0001 C CNN
F 3 "" H 2300 5800 50  0001 C CNN
	1    2300 5800
	1    0    0    -1  
$EndComp
Text Label 4500 2100 0    50   ~ 0
CAN_RX_DIRECT
Wire Wire Line
	4500 2100 5350 2100
Text Label 1550 7100 0    50   ~ 0
CAN_RX_DIRECT
Wire Wire Line
	1550 7100 2400 7100
Text Notes 2500 1450 0    118  ~ 0
Decouplage
Text Notes 1650 3800 0    118  ~ 0
Adaptation des IO
$Comp
L Device:R_Small R?
U 1 1 5FC0A4F0
P 2500 7100
AR Path="/5FC0A4F0" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FC0A4F0" Ref="R?"  Part="1" 
AR Path="/5FBD6585/5FC0A4F0" Ref="R?"  Part="1" 
F 0 "R?" V 2304 7100 50  0000 C CNN
F 1 "0R" V 2395 7100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2500 7100 50  0001 C CNN
F 3 "~" H 2500 7100 50  0001 C CNN
	1    2500 7100
	0    1    1    0   
$EndComp
Text Notes 7250 4700 0    79   ~ 0
Protection de la carte contre les ESD par deux diodes TVS
Text Notes 3650 7150 0    79   ~ 0
Diodes 0R à dimensionner en fonction \nde la fréquence des signaux.\nElles permettent de limiter le courant appelé\net de réduire les perturbation EM provenant\ndes traces correspondantes.
Text HLabel 2050 4200 0    50   Input ~ 0
SILENT
Text HLabel 2050 4950 0    50   Input ~ 0
TX
Text HLabel 2450 6200 2    50   Output ~ 0
FAULT
Text HLabel 2650 6050 2    50   Input ~ 0
SHDN
Text HLabel 2600 7100 2    50   Output ~ 0
RX
Text HLabel 5850 4200 2    50   BiDi ~ 0
CANH
Text HLabel 5850 4300 2    50   BiDi ~ 0
CANL
$EndSCHEMATC
