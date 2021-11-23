EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
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
U 1 1 5FBDF5E8
P 5750 1900
AR Path="/5FBDF5E8" Ref="U?"  Part="1" 
AR Path="/5FCD74DC/5FBDF5E8" Ref="U?"  Part="1" 
F 0 "U?" H 6200 1400 50  0000 C CNN
F 1 "TCAN337" H 6200 1500 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5750 1400 50  0001 C CIN
F 3 "http://www.ti.com/lit/ds/symlink/tcan337.pdf" H 5750 1900 50  0001 C CNN
F 4 "TCAN337GDR" H 5750 1900 50  0001 C CNN "MFR.Part #"
F 5 " C191004" H 5750 1900 50  0001 C CNN "LCSC Part #"
F 6 "SOIC-8_3.9x4.9x1.27P" H 5750 1900 50  0001 C CNN "Package"
	1    5750 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBDF5EE
P 5750 2300
AR Path="/5FBDF5EE" Ref="#PWR?"  Part="1" 
AR Path="/5FCD74DC/5FBDF5EE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5750 2050 50  0001 C CNN
F 1 "GND" H 5755 2172 50  0000 R CNN
F 2 "" H 5750 2300 50  0001 C CNN
F 3 "" H 5750 2300 50  0001 C CNN
	1    5750 2300
	1    0    0    -1  
$EndComp
Text Notes 5100 1000 0    118  ~ 0
CAN Tranceiver
Text GLabel 2350 5900 2    50   Output ~ 0
CAN_FAULT
$Comp
L power:+3.3V #PWR?
U 1 1 5FBDF5F6
P 5750 1500
AR Path="/5FBDF5F6" Ref="#PWR?"  Part="1" 
AR Path="/5FCD74DC/5FBDF5F6" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5750 1350 50  0001 C CNN
F 1 "+3.3V" H 5765 1673 50  0000 C CNN
F 2 "" H 5750 1500 50  0001 C CNN
F 3 "" H 5750 1500 50  0001 C CNN
	1    5750 1500
	1    0    0    -1  
$EndComp
Text Notes 4800 4550 0    118  ~ 0
Protection Bus CAN
Text Notes 4800 3600 0    118  ~ 0
Connecteur Bus CAN
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5FBDF5FE
P 5950 3900
AR Path="/5FBDF5FE" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FBDF5FE" Ref="J?"  Part="1" 
AR Path="/5FCD74DC/5FBDF5FE" Ref="J?"  Part="1" 
F 0 "J?" H 6030 3892 50  0000 L CNN
F 1 "Conn_01x02 JST" H 6030 3801 50  0000 L CNN
F 2 "Connector_JST:JST_XH_B2B-XH-A_1x02_P2.50mm_Vertical" H 5950 3900 50  0001 C CNN
F 3 "~" H 5950 3900 50  0001 C CNN
	1    5950 3900
	1    0    0    -1  
$EndComp
Text Label 6500 1800 2    50   ~ 0
CAN_P
Text Label 6500 2000 2    50   ~ 0
CAN_N
Text Label 5500 3900 0    50   ~ 0
CAN_P
Text Label 5500 4000 0    50   ~ 0
CAN_N
Wire Wire Line
	5750 4000 5500 4000
Wire Wire Line
	5500 3900 5750 3900
Wire Wire Line
	6500 2000 6250 2000
Wire Wire Line
	6250 1800 6500 1800
$Comp
L Device:C_Small C?
U 1 1 5FBDF60C
P 2700 1900
F 0 "C?" H 2792 1946 50  0000 L CNN
F 1 "100n" H 2792 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2700 1900 50  0001 C CNN
F 3 "~" H 2700 1900 50  0001 C CNN
	1    2700 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FBDF612
P 3050 1900
F 0 "C?" H 3142 1946 50  0000 L CNN
F 1 "10u" H 3142 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3050 1900 50  0001 C CNN
F 3 "~" H 3050 1900 50  0001 C CNN
	1    3050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 1700 2700 1800
Wire Wire Line
	2700 1700 3050 1700
Wire Wire Line
	3050 1700 3050 1800
Wire Wire Line
	3050 2000 3050 2100
Connection ~ 3050 2100
Wire Wire Line
	2700 2000 2700 2100
Wire Wire Line
	2700 2100 3050 2100
Connection ~ 3050 1700
$Comp
L power:+3.3V #PWR?
U 1 1 5FBDF620
P 3050 1550
F 0 "#PWR?" H 3050 1400 50  0001 C CNN
F 1 "+3.3V" H 3065 1723 50  0000 C CNN
F 2 "" H 3050 1550 50  0001 C CNN
F 3 "" H 3050 1550 50  0001 C CNN
	1    3050 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 1550 3050 1700
$Comp
L power:GND #PWR?
U 1 1 5FBDF627
P 3050 2250
F 0 "#PWR?" H 3050 2000 50  0001 C CNN
F 1 "GND" H 3055 2077 50  0000 C CNN
F 2 "" H 3050 2250 50  0001 C CNN
F 3 "" H 3050 2250 50  0001 C CNN
	1    3050 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2250 3050 2100
Text Label 5050 4850 0    50   ~ 0
CAN_P
Text Label 5050 5450 0    50   ~ 0
CAN_N
$Comp
L Device:R_Small R?
U 1 1 5FBDF630
P 5350 5000
F 0 "R?" H 5409 5046 50  0000 L CNN
F 1 "56" H 5409 4955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5350 5000 50  0001 C CNN
F 3 "~" H 5350 5000 50  0001 C CNN
	1    5350 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5FBDF636
P 5350 5300
F 0 "R?" H 5409 5346 50  0000 L CNN
F 1 "56" H 5409 5255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 5350 5300 50  0001 C CNN
F 3 "~" H 5350 5300 50  0001 C CNN
	1    5350 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 5450 5350 5400
Wire Wire Line
	5050 5450 5350 5450
Wire Wire Line
	5350 4850 5350 4900
Wire Wire Line
	5050 4850 5350 4850
Wire Wire Line
	5350 5100 5350 5150
$Comp
L Device:C_Small C?
U 1 1 5FBDF641
P 5650 5150
F 0 "C?" H 5742 5196 50  0000 L CNN
F 1 "10n" H 5742 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5650 5150 50  0001 C CNN
F 3 "~" H 5650 5150 50  0001 C CNN
	1    5650 5150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5550 5150 5350 5150
Connection ~ 5350 5150
Wire Wire Line
	5350 5150 5350 5200
$Comp
L power:GND #PWR?
U 1 1 5FBDF64A
P 6200 5200
F 0 "#PWR?" H 6200 4950 50  0001 C CNN
F 1 "GND" H 6205 5027 50  0000 C CNN
F 2 "" H 6200 5200 50  0001 C CNN
F 3 "" H 6200 5200 50  0001 C CNN
	1    6200 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5200 5850 5150
Wire Wire Line
	5850 5150 5750 5150
$Comp
L Device:C_Small C?
U 1 1 5FBDF652
P 5850 5000
F 0 "C?" H 5942 5046 50  0000 L CNN
F 1 "10n" H 5942 4955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5850 5000 50  0001 C CNN
F 3 "~" H 5850 5000 50  0001 C CNN
	1    5850 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FBDF658
P 5850 5300
F 0 "C?" H 5942 5346 50  0000 L CNN
F 1 "10n" H 5942 5255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5850 5300 50  0001 C CNN
F 3 "~" H 5850 5300 50  0001 C CNN
	1    5850 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5100 5850 5150
Connection ~ 5850 5150
Wire Wire Line
	5350 4850 5850 4850
Wire Wire Line
	5850 4850 5850 4900
Connection ~ 5350 4850
Wire Wire Line
	5350 5450 5850 5450
Wire Wire Line
	5850 5450 5850 5400
Connection ~ 5350 5450
Wire Wire Line
	5850 5150 6200 5150
Wire Wire Line
	6200 5150 6200 5200
$Comp
L Device:D_Zener_x2_ACom_KKA D?
U 1 1 5FBDF668
P 6400 5150
F 0 "D?" V 6354 5228 50  0000 L CNN
F 1 "D_Zener_x2_ACom_KKA" V 6445 5228 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 6400 5150 50  0001 C CNN
F 3 "~" H 6400 5150 50  0001 C CNN
	1    6400 5150
	0    1    -1   0   
$EndComp
Connection ~ 6200 5150
Wire Wire Line
	6400 4850 5850 4850
Connection ~ 5850 4850
Wire Wire Line
	6400 5450 5850 5450
Connection ~ 5850 5450
$Comp
L Device:R_Small R?
U 1 1 5FBDF673
P 2050 3900
AR Path="/5FBDF673" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FBDF673" Ref="R?"  Part="1" 
F 0 "R?" V 1854 3900 50  0000 C CNN
F 1 "1k" V 1945 3900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2050 3900 50  0001 C CNN
F 3 "~" H 2050 3900 50  0001 C CNN
	1    2050 3900
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FBDF679
P 2200 4050
F 0 "C?" H 2292 4096 50  0000 L CNN
F 1 "10n" H 2292 4005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2200 4050 50  0001 C CNN
F 3 "~" H 2200 4050 50  0001 C CNN
	1    2200 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBDF67F
P 2200 4150
F 0 "#PWR?" H 2200 3900 50  0001 C CNN
F 1 "GND" H 2205 3977 50  0000 C CNN
F 2 "" H 2200 4150 50  0001 C CNN
F 3 "" H 2200 4150 50  0001 C CNN
	1    2200 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3950 2200 3900
Wire Wire Line
	2200 3900 2150 3900
Wire Wire Line
	2200 3900 3050 3900
Connection ~ 2200 3900
Text Label 3050 3900 2    50   ~ 0
CAN_SILENT_FILTERED
Wire Wire Line
	5250 2100 4400 2100
Text Label 4400 2100 0    50   ~ 0
CAN_SILENT_FILTERED
Text GLabel 1950 4650 0    50   Input ~ 0
TXD_TCAN337
$Comp
L Device:R_Small R?
U 1 1 5FBDF68D
P 2050 4650
AR Path="/5FBDF68D" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FBDF68D" Ref="R?"  Part="1" 
F 0 "R?" V 1854 4650 50  0000 C CNN
F 1 "0R" V 1945 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2050 4650 50  0001 C CNN
F 3 "~" H 2050 4650 50  0001 C CNN
	1    2050 4650
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FBDF693
P 2200 4800
F 0 "C?" H 2292 4846 50  0000 L CNN
F 1 "10n" H 2292 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2200 4800 50  0001 C CNN
F 3 "~" H 2200 4800 50  0001 C CNN
	1    2200 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBDF699
P 2200 4900
F 0 "#PWR?" H 2200 4650 50  0001 C CNN
F 1 "GND" H 2205 4727 50  0000 C CNN
F 2 "" H 2200 4900 50  0001 C CNN
F 3 "" H 2200 4900 50  0001 C CNN
	1    2200 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4700 2200 4650
Wire Wire Line
	2200 4650 2150 4650
Wire Wire Line
	2200 4650 3050 4650
Connection ~ 2200 4650
Text Label 3050 4650 2    50   ~ 0
CAN_TX_FILTERED
Wire Wire Line
	5250 1700 4400 1700
Text Label 4400 1700 0    50   ~ 0
CAN_TX_FILTERED
Text Label 4400 2000 0    50   ~ 0
CAN_FAULT_OUT
Wire Wire Line
	4400 2000 5250 2000
Text Label 1500 5900 0    50   ~ 0
CAN_FAULT_OUT
Wire Wire Line
	1500 5900 2200 5900
$Comp
L Device:C_Small C?
U 1 1 5FBDF6AA
P 2200 6100
F 0 "C?" H 2292 6146 50  0000 L CNN
F 1 "10n" H 2292 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2200 6100 50  0001 C CNN
F 3 "~" H 2200 6100 50  0001 C CNN
	1    2200 6100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBDF6B0
P 2200 6200
F 0 "#PWR?" H 2200 5950 50  0001 C CNN
F 1 "GND" H 2205 6027 50  0000 C CNN
F 2 "" H 2200 6200 50  0001 C CNN
F 3 "" H 2200 6200 50  0001 C CNN
	1    2200 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6000 2200 5900
Connection ~ 2200 5900
Wire Wire Line
	2200 5900 2350 5900
Text GLabel 2550 5750 2    50   Input ~ 0
CAN_SHDN
$Comp
L Device:R_Small R?
U 1 1 5FBDF6BA
P 2450 5750
AR Path="/5FBDF6BA" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FBDF6BA" Ref="R?"  Part="1" 
F 0 "R?" V 2254 5750 50  0000 C CNN
F 1 "0R" V 2345 5750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2450 5750 50  0001 C CNN
F 3 "~" H 2450 5750 50  0001 C CNN
	1    2450 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	2350 5750 2200 5750
Wire Wire Line
	2200 5750 2200 5900
$Comp
L Device:R_Small R?
U 1 1 5FBDF6C2
P 2200 5600
AR Path="/5FBDF6C2" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FBDF6C2" Ref="R?"  Part="1" 
F 0 "R?" V 2004 5600 50  0000 C CNN
F 1 "10k" V 2095 5600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2200 5600 50  0001 C CNN
F 3 "~" H 2200 5600 50  0001 C CNN
	1    2200 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5700 2200 5750
Connection ~ 2200 5750
$Comp
L power:+3.3V #PWR?
U 1 1 5FBDF6CA
P 2200 5500
F 0 "#PWR?" H 2200 5350 50  0001 C CNN
F 1 "+3.3V" H 2215 5673 50  0000 C CNN
F 2 "" H 2200 5500 50  0001 C CNN
F 3 "" H 2200 5500 50  0001 C CNN
	1    2200 5500
	1    0    0    -1  
$EndComp
Text GLabel 2500 6800 2    50   Output ~ 0
RXD_TCAN337
Text Label 4400 1800 0    50   ~ 0
CAN_RX_DIRECT
Wire Wire Line
	4400 1800 5250 1800
Text Label 1450 6800 0    50   ~ 0
CAN_RX_DIRECT
Wire Wire Line
	1450 6800 2300 6800
Text Notes 2400 1150 0    118  ~ 0
Decouplage
Text Notes 1550 3500 0    118  ~ 0
Adaptation des IO
$Comp
L Device:R_Small R?
U 1 1 5FBDF6D7
P 2400 6800
AR Path="/5FBDF6D7" Ref="R?"  Part="1" 
AR Path="/5FCD74DC/5FBDF6D7" Ref="R?"  Part="1" 
F 0 "R?" V 2204 6800 50  0000 C CNN
F 1 "0R" V 2295 6800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2400 6800 50  0001 C CNN
F 3 "~" H 2400 6800 50  0001 C CNN
	1    2400 6800
	0    1    1    0   
$EndComp
Text GLabel 1950 3900 0    50   Input ~ 0
CAN_SILENT
Text Notes 7150 4400 0    79   ~ 0
Protection de la carte contre les ESD par deux diodes TVS
Text Notes 3550 6850 0    79   ~ 0
Diodes 0R à dimensionner en fonction \nde la fréquence des signaux.\nElles permettent de limiter le courant appelé\net de réduire les perturbation EM provenant\ndes traces correspondantes.
$EndSCHEMATC
