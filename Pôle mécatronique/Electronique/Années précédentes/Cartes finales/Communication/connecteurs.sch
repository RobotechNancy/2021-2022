EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 900  950  0    118  ~ 0
Connecteur Raspberry Pi\n
$Comp
L power:+3.3V #PWR?
U 1 1 5FC8BF98
P 1550 1350
AR Path="/5FC8BF98" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BF98" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 1200 50  0001 C CNN
F 1 "+3.3V" V 1565 1478 50  0000 L CNN
F 2 "" H 1550 1350 50  0001 C CNN
F 3 "" H 1550 1350 50  0001 C CNN
	1    1550 1350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFB0
P 2050 2750
AR Path="/5FC8BFB0" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFB0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 2500 50  0001 C CNN
F 1 "GND" V 2055 2622 50  0000 R CNN
F 2 "" H 2050 2750 50  0001 C CNN
F 3 "" H 2050 2750 50  0001 C CNN
	1    2050 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 1350 2200 1350
Wire Wire Line
	2050 1450 2850 1450
Connection ~ 2850 1450
Connection ~ 2200 1350
Text GLabel 5550 1300 0    50   Input ~ 0
CAN_P
Text GLabel 5550 1500 0    50   Input ~ 0
CAN_N
Text Notes 4700 1050 0    118  ~ 0
Connecteur Bus CAN
Wire Wire Line
	5650 1450 5550 1450
Wire Wire Line
	5550 1450 5550 1500
Wire Wire Line
	5650 1350 5550 1350
Wire Wire Line
	5550 1350 5550 1300
Text GLabel 5550 1700 0    50   Input ~ 0
CAN_P
Text GLabel 5550 1900 0    50   Input ~ 0
CAN_N
Wire Wire Line
	5650 1850 5550 1850
Wire Wire Line
	5550 1850 5550 1900
Wire Wire Line
	5650 1750 5550 1750
Wire Wire Line
	5550 1750 5550 1700
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5FC9FE24
P 5850 1350
AR Path="/5FC9FE24" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FC9FE24" Ref="J?"  Part="1" 
F 0 "J?" H 5930 1342 50  0000 L CNN
F 1 "Conn_01x02" H 5930 1251 50  0000 L CNN
F 2 "" H 5850 1350 50  0001 C CNN
F 3 "~" H 5850 1350 50  0001 C CNN
	1    5850 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5FC9FE2A
P 5850 1750
AR Path="/5FC9FE2A" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FC9FE2A" Ref="J?"  Part="1" 
F 0 "J?" H 5930 1742 50  0000 L CNN
F 1 "Conn_01x02" H 5930 1651 50  0000 L CNN
F 2 "" H 5850 1750 50  0001 C CNN
F 3 "~" H 5850 1750 50  0001 C CNN
	1    5850 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5FCAEBD3
P 5600 4600
AR Path="/5FCAEBD3" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBD3" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4450 50  0001 C CNN
F 1 "+5V" V 5615 4728 50  0000 L CNN
F 2 "" H 5600 4600 50  0001 C CNN
F 3 "" H 5600 4600 50  0001 C CNN
	1    5600 4600
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCAEBD9
P 5600 4500
AR Path="/5FCAEBD9" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBD9" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4250 50  0001 C CNN
F 1 "GND" V 5605 4372 50  0000 R CNN
F 2 "" H 5600 4500 50  0001 C CNN
F 3 "" H 5600 4500 50  0001 C CNN
	1    5600 4500
	0    1    -1   0   
$EndComp
Text Notes 4600 4100 0    118  ~ 0
Connecteur Alimentation
$Comp
L power:+12V #PWR?
U 1 1 5FCAEBE0
P 5600 4400
AR Path="/5FCAEBE0" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBE0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4250 50  0001 C CNN
F 1 "+12V" V 5615 4528 50  0000 L CNN
F 2 "" H 5600 4400 50  0001 C CNN
F 3 "" H 5600 4400 50  0001 C CNN
	1    5600 4400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 POWER?
U 1 1 5FCAEBE6
P 5800 4500
AR Path="/5FCAEBE6" Ref="POWER?"  Part="1" 
AR Path="/5FC789B7/5FCAEBE6" Ref="POWER?"  Part="1" 
F 0 "POWER?" H 5718 4175 50  0000 C CNN
F 1 "Conn_01x03" H 5718 4266 50  0000 C CNN
F 2 "Connector_JST:JST_XH_B3B-XH-A_1x03_P2.50mm_Vertical" H 5800 4500 50  0001 C CNN
F 3 "~" H 5800 4500 50  0001 C CNN
	1    5800 4500
	1    0    0    1   
$EndComp
$Comp
L Connecteurs:STM32_SW PROG?
U 1 1 5FCB524B
P 2200 4600
AR Path="/5FCB524B" Ref="PROG?"  Part="1" 
AR Path="/5FC789B7/5FCB524B" Ref="PROG?"  Part="1" 
F 0 "PROG?" H 2794 4351 50  0000 L CNN
F 1 "STM32_SW" H 2794 4260 50  0000 L CNN
F 2 "Connecteurs:JTAG10" H 2450 4800 50  0001 C CNN
F 3 "" H 2450 4800 50  0001 C CNN
	1    2200 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FCB5251
P 2050 4600
AR Path="/5FCB5251" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCB5251" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 4450 50  0001 C CNN
F 1 "+3.3V" V 2065 4728 50  0000 L CNN
F 2 "" H 2050 4600 50  0001 C CNN
F 3 "" H 2050 4600 50  0001 C CNN
	1    2050 4600
	0    -1   -1   0   
$EndComp
Text GLabel 1300 4750 0    50   Input ~ 0
SWDIO
Text GLabel 1300 4850 0    50   Input ~ 0
SWCLK
Text GLabel 2100 4950 0    50   Input ~ 0
SWO
Text GLabel 2100 5050 0    50   Input ~ 0
NRST
Text Notes 1000 4200 0    118  ~ 0
      Connecteurs \nProgrammation STM32\n
$Comp
L Device:R_Small R?
U 1 1 5FCB525F
P 1400 4650
AR Path="/5FCB525F" Ref="R?"  Part="1" 
AR Path="/5FC789B7/5FCB525F" Ref="R?"  Part="1" 
F 0 "R?" H 1459 4696 50  0000 L CNN
F 1 "10KOhms" H 1459 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" H 1400 4650 50  0001 C CNN
F 3 "~" H 1400 4650 50  0001 C CNN
F 4 "0603WAF1002T5E" H 1400 4650 50  0001 C CNN "MFR.Part #"
F 5 "C25804" H 1400 4650 50  0001 C CNN "LCSC Part #"
F 6 "0603" H 1400 4650 50  0001 C CNN "Package"
	1    1400 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5FCB5268
P 1400 4950
AR Path="/5FCB5268" Ref="R?"  Part="1" 
AR Path="/5FC789B7/5FCB5268" Ref="R?"  Part="1" 
F 0 "R?" H 1459 4996 50  0000 L CNN
F 1 "10KOhms" H 1459 4905 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" H 1400 4950 50  0001 C CNN
F 3 "~" H 1400 4950 50  0001 C CNN
F 4 "0603WAF1002T5E" H 1400 4950 50  0001 C CNN "MFR.Part #"
F 5 "C25804" H 1400 4950 50  0001 C CNN "LCSC Part #"
F 6 "0603" H 1400 4950 50  0001 C CNN "Package"
	1    1400 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FCB526E
P 1400 4550
AR Path="/5FCB526E" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCB526E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1400 4400 50  0001 C CNN
F 1 "+3.3V" H 1150 4650 50  0000 L CNN
F 2 "" H 1400 4550 50  0001 C CNN
F 3 "" H 1400 4550 50  0001 C CNN
	1    1400 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCB5274
P 1400 5050
AR Path="/5FCB5274" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCB5274" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1400 4800 50  0001 C CNN
F 1 "GND" H 1405 4922 50  0000 R CNN
F 2 "" H 1400 5050 50  0001 C CNN
F 3 "" H 1400 5050 50  0001 C CNN
	1    1400 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 4750 1400 4750
Wire Wire Line
	1400 4750 2100 4750
Connection ~ 1400 4750
Wire Wire Line
	1300 4850 1400 4850
Wire Wire Line
	1400 4850 2100 4850
Connection ~ 1400 4850
$Comp
L Device:C_Small C?
U 1 1 5FCB5283
P 2050 4500
AR Path="/5FCB5283" Ref="C?"  Part="1" 
AR Path="/5FC789B7/5FCB5283" Ref="C?"  Part="1" 
F 0 "C?" H 1900 4450 50  0000 L CNN
F 1 "C_Small" H 1600 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2050 4500 50  0001 C CNN
F 3 "~" H 2050 4500 50  0001 C CNN
F 4 "CL05B103KB5NNNC" H 2050 4500 50  0001 C CNN "MFR.Part #"
F 5 "C15195" H 2050 4500 50  0001 C CNN "LCSC Part #"
F 6 "0402" H 2050 4500 50  0001 C CNN "Package"
	1    2050 4500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCB5289
P 2100 5200
AR Path="/5FCB5289" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCB5289" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2100 4950 50  0001 C CNN
F 1 "GND" V 2105 5072 50  0000 R CNN
F 2 "" H 2100 5200 50  0001 C CNN
F 3 "" H 2100 5200 50  0001 C CNN
	1    2100 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	2100 4600 2050 4600
Connection ~ 2050 4600
$Comp
L power:GND #PWR?
U 1 1 5FCB5291
P 2050 4400
AR Path="/5FCB5291" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCB5291" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 4150 50  0001 C CNN
F 1 "GND" V 2055 4272 50  0000 R CNN
F 2 "" H 2050 4400 50  0001 C CNN
F 3 "" H 2050 4400 50  0001 C CNN
	1    2050 4400
	0    1    1    0   
$EndComp
Text Notes 900  950  0    118  ~ 0
Connecteur Raspberry Pi\n
$Comp
L power:+3.3V #PWR?
U 1 1 5FC8BF92
P 1550 2150
AR Path="/5FC8BF92" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BF92" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 2000 50  0001 C CNN
F 1 "+3.3V" V 1565 2278 50  0000 L CNN
F 2 "" H 1550 2150 50  0001 C CNN
F 3 "" H 1550 2150 50  0001 C CNN
	1    1550 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FC8BF98
P 1550 1350
AR Path="/5FC8BF98" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BF98" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 1200 50  0001 C CNN
F 1 "+3.3V" V 1565 1478 50  0000 L CNN
F 2 "" H 1550 1350 50  0001 C CNN
F 3 "" H 1550 1350 50  0001 C CNN
	1    1550 1350
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BF9E
P 2050 1550
AR Path="/5FC8BF9E" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BF9E" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 1300 50  0001 C CNN
F 1 "GND" V 2055 1422 50  0000 R CNN
F 2 "" H 2050 1550 50  0001 C CNN
F 3 "" H 2050 1550 50  0001 C CNN
	1    2050 1550
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFAA
P 2050 2250
AR Path="/5FC8BFAA" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFAA" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 2000 50  0001 C CNN
F 1 "GND" V 2055 2122 50  0000 R CNN
F 2 "" H 2050 2250 50  0001 C CNN
F 3 "" H 2050 2250 50  0001 C CNN
	1    2050 2250
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFB6
P 1550 3250
AR Path="/5FC8BFB6" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFB6" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 3000 50  0001 C CNN
F 1 "GND" V 1555 3122 50  0000 R CNN
F 2 "" H 1550 3250 50  0001 C CNN
F 3 "" H 1550 3250 50  0001 C CNN
	1    1550 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFBC
P 1550 2550
AR Path="/5FC8BFBC" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFBC" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 2300 50  0001 C CNN
F 1 "GND" V 1555 2422 50  0000 R CNN
F 2 "" H 1550 2550 50  0001 C CNN
F 3 "" H 1550 2550 50  0001 C CNN
	1    1550 2550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFC2
P 1550 1750
AR Path="/5FC8BFC2" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFC2" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1550 1500 50  0001 C CNN
F 1 "GND" V 1555 1622 50  0000 R CNN
F 2 "" H 1550 1750 50  0001 C CNN
F 3 "" H 1550 1750 50  0001 C CNN
	1    1550 1750
	0    1    1    0   
$EndComp
Text GLabel 1400 2250 0    50   Input ~ 0
MOSI
Text GLabel 1400 2450 0    50   Input ~ 0
SCLK
Text GLabel 1400 2350 0    50   Input ~ 0
MISO
Text GLabel 2200 2450 2    50   Input ~ 0
CE0
$Comp
L Device:C_Small C?
U 1 1 5FC8BFCF
P 2200 1250
AR Path="/5FC8BFCF" Ref="C?"  Part="1" 
AR Path="/5FC789B7/5FC8BFCF" Ref="C?"  Part="1" 
F 0 "C?" H 2000 1500 50  0000 L CNN
F 1 "C_Small" H 1900 1400 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2200 1250 50  0001 C CNN
F 3 "~" H 2200 1250 50  0001 C CNN
F 4 "CL05B103KB5NNNC" H 2200 1250 50  0001 C CNN "MFR.Part #"
F 5 "C15195" H 2200 1250 50  0001 C CNN "LCSC Part #"
F 6 "0402" H 2200 1250 50  0001 C CNN "Package"
	1    2200 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FC8BFD8
P 2850 1550
AR Path="/5FC8BFD8" Ref="C?"  Part="1" 
AR Path="/5FC789B7/5FC8BFD8" Ref="C?"  Part="1" 
F 0 "C?" H 2650 1550 50  0000 L CNN
F 1 "C_Small" H 2350 1550 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2850 1550 50  0001 C CNN
F 3 "~" H 2850 1550 50  0001 C CNN
F 4 "CL05B103KB5NNNC" H 2850 1550 50  0001 C CNN "MFR.Part #"
F 5 "C15195" H 2850 1550 50  0001 C CNN "LCSC Part #"
F 6 "0402" H 2850 1550 50  0001 C CNN "Package"
	1    2850 1550
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFDE
P 2200 1150
AR Path="/5FC8BFDE" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFDE" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2200 900 50  0001 C CNN
F 1 "GND" V 2205 1022 50  0000 R CNN
F 2 "" H 2200 1150 50  0001 C CNN
F 3 "" H 2200 1150 50  0001 C CNN
	1    2200 1150
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC8BFE4
P 2850 1650
AR Path="/5FC8BFE4" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFE4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2850 1400 50  0001 C CNN
F 1 "GND" V 2855 1522 50  0000 R CNN
F 2 "" H 2850 1650 50  0001 C CNN
F 3 "" H 2850 1650 50  0001 C CNN
	1    2850 1650
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5FC8BFED
P 2200 1350
AR Path="/5FC8BFED" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFED" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2200 1200 50  0001 C CNN
F 1 "+5V" V 2215 1478 50  0000 L CNN
F 2 "" H 2200 1350 50  0001 C CNN
F 3 "" H 2200 1350 50  0001 C CNN
	1    2200 1350
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5FC8BFF4
P 2850 1450
AR Path="/5FC8BFF4" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFF4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2850 1300 50  0001 C CNN
F 1 "+5V" V 2865 1578 50  0000 L CNN
F 2 "" H 2850 1450 50  0001 C CNN
F 3 "" H 2850 1450 50  0001 C CNN
	1    2850 1450
	0    1    1    0   
$EndComp
Text GLabel 5550 1300 0    50   Input ~ 0
CAN_P
Text GLabel 5550 1500 0    50   Input ~ 0
CAN_N
Text Notes 4700 1050 0    118  ~ 0
Connecteur Bus CAN
Text GLabel 5550 1700 0    50   Input ~ 0
CAN_P
Text GLabel 5550 1900 0    50   Input ~ 0
CAN_N
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5FC9FE24
P 5850 1350
AR Path="/5FC9FE24" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FC9FE24" Ref="J?"  Part="1" 
F 0 "J?" H 5930 1342 50  0000 L CNN
F 1 "Conn_01x02" H 5930 1251 50  0000 L CNN
F 2 "" H 5850 1350 50  0001 C CNN
F 3 "~" H 5850 1350 50  0001 C CNN
	1    5850 1350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5FC9FE2A
P 5850 1750
AR Path="/5FC9FE2A" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FC9FE2A" Ref="J?"  Part="1" 
F 0 "J?" H 5930 1742 50  0000 L CNN
F 1 "Conn_01x02" H 5930 1651 50  0000 L CNN
F 2 "" H 5850 1750 50  0001 C CNN
F 3 "~" H 5850 1750 50  0001 C CNN
	1    5850 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5FCAEBD3
P 5600 4600
AR Path="/5FCAEBD3" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBD3" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4450 50  0001 C CNN
F 1 "+5V" V 5615 4728 50  0000 L CNN
F 2 "" H 5600 4600 50  0001 C CNN
F 3 "" H 5600 4600 50  0001 C CNN
	1    5600 4600
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCAEBD9
P 5600 4500
AR Path="/5FCAEBD9" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBD9" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4250 50  0001 C CNN
F 1 "GND" V 5605 4372 50  0000 R CNN
F 2 "" H 5600 4500 50  0001 C CNN
F 3 "" H 5600 4500 50  0001 C CNN
	1    5600 4500
	0    1    -1   0   
$EndComp
Text Notes 4600 4100 0    118  ~ 0
Connecteur Alimentation
$Comp
L power:+12V #PWR?
U 1 1 5FCAEBE0
P 5600 4400
AR Path="/5FCAEBE0" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FCAEBE0" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 5600 4250 50  0001 C CNN
F 1 "+12V" V 5615 4528 50  0000 L CNN
F 2 "" H 5600 4400 50  0001 C CNN
F 3 "" H 5600 4400 50  0001 C CNN
	1    5600 4400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 POWER?
U 1 1 5FCAEBE6
P 5800 4500
AR Path="/5FCAEBE6" Ref="POWER?"  Part="1" 
AR Path="/5FC789B7/5FCAEBE6" Ref="POWER?"  Part="1" 
F 0 "POWER?" H 5718 4175 50  0000 C CNN
F 1 "Conn_01x03" H 5718 4266 50  0000 C CNN
F 2 "Connector_JST:JST_XH_B3B-XH-A_1x03_P2.50mm_Vertical" H 5800 4500 50  0001 C CNN
F 3 "~" H 5800 4500 50  0001 C CNN
	1    5800 4500
	1    0    0    1   
$EndComp
$Comp
L Connecteurs:STM32_SW PROG?
U 1 1 5FCB524B
P 2200 4600
F 0 "PROG?" H 2794 4351 50  0000 L CNN
F 1 "STM32_SW" H 2794 4260 50  0000 L CNN
F 2 "Connecteurs:JTAG10" H 2450 4800 50  0001 C CNN
F 3 "" H 2450 4800 50  0001 C CNN
	1    2200 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FCB5251
P 2050 4600
F 0 "#PWR?" H 2050 4450 50  0001 C CNN
F 1 "+3.3V" V 2065 4728 50  0000 L CNN
F 2 "" H 2050 4600 50  0001 C CNN
F 3 "" H 2050 4600 50  0001 C CNN
	1    2050 4600
	0    -1   -1   0   
$EndComp
Text GLabel 1300 4750 0    50   Input ~ 0
SWDIO
Text GLabel 1300 4850 0    50   Input ~ 0
SWCLK
Text GLabel 2100 4950 0    50   Input ~ 0
SWO
Text GLabel 2100 5050 0    50   Input ~ 0
NRST
Text Notes 1000 4200 0    118  ~ 0
      Connecteurs \nProgrammation STM32\n
$Comp
L Device:R_Small R?
U 1 1 5FCB525F
P 1400 4650
F 0 "R?" H 1459 4696 50  0000 L CNN
F 1 "10KOhms" H 1459 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" H 1400 4650 50  0001 C CNN
F 3 "~" H 1400 4650 50  0001 C CNN
F 4 "0603WAF1002T5E" H 1400 4650 50  0001 C CNN "MFR.Part #"
F 5 "C25804" H 1400 4650 50  0001 C CNN "LCSC Part #"
F 6 "0603" H 1400 4650 50  0001 C CNN "Package"
	1    1400 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 5FCB5268
P 1400 4950
F 0 "R?" H 1459 4996 50  0000 L CNN
F 1 "10KOhms" H 1459 4905 50  0000 L CNN
F 2 "Resistor_SMD:R_0201_0603Metric" H 1400 4950 50  0001 C CNN
F 3 "~" H 1400 4950 50  0001 C CNN
F 4 "0603WAF1002T5E" H 1400 4950 50  0001 C CNN "MFR.Part #"
F 5 "C25804" H 1400 4950 50  0001 C CNN "LCSC Part #"
F 6 "0603" H 1400 4950 50  0001 C CNN "Package"
	1    1400 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FCB526E
P 1400 4550
F 0 "#PWR?" H 1400 4400 50  0001 C CNN
F 1 "+3.3V" H 1150 4650 50  0000 L CNN
F 2 "" H 1400 4550 50  0001 C CNN
F 3 "" H 1400 4550 50  0001 C CNN
	1    1400 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCB5274
P 1400 5050
F 0 "#PWR?" H 1400 4800 50  0001 C CNN
F 1 "GND" H 1405 4922 50  0000 R CNN
F 2 "" H 1400 5050 50  0001 C CNN
F 3 "" H 1400 5050 50  0001 C CNN
	1    1400 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5FCB5283
P 2050 4500
F 0 "C?" H 1900 4450 50  0000 L CNN
F 1 "C_Small" H 1600 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2050 4500 50  0001 C CNN
F 3 "~" H 2050 4500 50  0001 C CNN
F 4 "CL05B103KB5NNNC" H 2050 4500 50  0001 C CNN "MFR.Part #"
F 5 "C15195" H 2050 4500 50  0001 C CNN "LCSC Part #"
F 6 "0402" H 2050 4500 50  0001 C CNN "Package"
	1    2050 4500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCB5289
P 2100 5200
F 0 "#PWR?" H 2100 4950 50  0001 C CNN
F 1 "GND" V 2105 5072 50  0000 R CNN
F 2 "" H 2100 5200 50  0001 C CNN
F 3 "" H 2100 5200 50  0001 C CNN
	1    2100 5200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FCB5291
P 2050 4400
F 0 "#PWR?" H 2050 4150 50  0001 C CNN
F 1 "GND" V 2055 4272 50  0000 R CNN
F 2 "" H 2050 4400 50  0001 C CNN
F 3 "" H 2050 4400 50  0001 C CNN
	1    2050 4400
	0    1    1    0   
$EndComp
Text GLabel -1850 1650 0    50   Input ~ 0
P1
Text GLabel -1700 1650 2    50   Input ~ 0
P2
Text GLabel -1850 1750 0    50   Input ~ 0
P3
Text GLabel -1700 1750 2    50   Input ~ 0
P4
Text GLabel -1850 1850 0    50   Input ~ 0
P5
Text GLabel -1700 1850 2    50   Input ~ 0
P6
Text GLabel -1850 1950 0    50   Input ~ 0
P7
Text GLabel -1700 1950 2    50   Input ~ 0
P8
Text GLabel -1850 2050 0    50   Input ~ 0
P9
Text GLabel -1700 2050 2    50   Input ~ 0
P10
Text GLabel -1850 2150 0    50   Input ~ 0
P11
Text GLabel -1700 2150 2    50   Input ~ 0
P12
Text GLabel -1850 2250 0    50   Input ~ 0
P13
Text GLabel -1700 2250 2    50   Input ~ 0
P14
Text GLabel -1850 2350 0    50   Input ~ 0
P15
Text GLabel -1700 2350 2    50   Input ~ 0
P16
Text GLabel -1850 2450 0    50   Input ~ 0
P17
Text GLabel -1700 2450 2    50   Input ~ 0
P18
Text GLabel -1850 2550 0    50   Input ~ 0
P19
Text GLabel -1850 2750 0    50   Input ~ 0
P23
Text GLabel -1700 2750 2    50   Input ~ 0
P24
Text GLabel -1850 2850 0    50   Input ~ 0
P25
Text GLabel -1700 2850 2    50   Input ~ 0
P26
Text GLabel -1850 2950 0    50   Input ~ 0
P27
Text GLabel -1700 2950 2    50   Input ~ 0
P28
Text GLabel -1850 3050 0    50   Input ~ 0
P29
Text GLabel -1700 3050 2    50   Input ~ 0
P30
Text GLabel -1850 3150 0    50   Input ~ 0
P31
Text GLabel -1700 3150 2    50   Input ~ 0
P32
Text GLabel -1850 3250 0    50   Input ~ 0
P33
Text GLabel -1700 3250 2    50   Input ~ 0
P34
Text GLabel -1850 3350 0    50   Input ~ 0
P35
Text GLabel -1700 3350 2    50   Input ~ 0
P36
Text GLabel -1850 3450 0    50   Input ~ 0
P37
Text GLabel -1700 3450 2    50   Input ~ 0
P38
Text GLabel -1850 3550 0    50   Input ~ 0
P39
Text GLabel -1700 3550 2    50   Input ~ 0
P40
Text GLabel -1700 2650 2    50   Input ~ 0
P22
Text GLabel -1850 2650 0    50   Input ~ 0
P21
Text GLabel -1700 2550 2    50   Input ~ 0
P20
Text GLabel 1100 1450 0    50   Input ~ 0
P3
Text GLabel 1100 1550 0    50   Input ~ 0
P5
Text GLabel 1100 1650 0    50   Input ~ 0
P7
Text GLabel 1100 1850 0    50   Input ~ 0
P11
Text GLabel 1100 1950 0    50   Input ~ 0
P13
Text GLabel 1100 2050 0    50   Input ~ 0
P15
Text GLabel 1100 2250 0    50   Input ~ 0
P19
Text GLabel 1100 2450 0    50   Input ~ 0
P23
Text GLabel 1100 2650 0    50   Input ~ 0
P27
Text GLabel 1100 2750 0    50   Input ~ 0
P29
Text GLabel 1100 2850 0    50   Input ~ 0
P31
Text GLabel 1100 2950 0    50   Input ~ 0
P33
Text GLabel 1100 3050 0    50   Input ~ 0
P35
Text GLabel 1100 3150 0    50   Input ~ 0
P37
Text GLabel 1100 2350 0    50   Input ~ 0
P21
$Comp
L Connector_Generic:Conn_02x20_Odd_Even J?
U 1 1 5FC8BF8B
P 1750 2250
AR Path="/5FC8BF8B" Ref="J?"  Part="1" 
AR Path="/5FC789B7/5FC8BF8B" Ref="J?"  Part="1" 
F 0 "J?" H 1800 3367 50  0000 C CNN
F 1 "Conn_Raspi" H 1800 3276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 1750 2250 50  0001 C CNN
F 3 "~" H 1750 2250 50  0001 C CNN
	1    1750 2250
	1    0    0    -1  
$EndComp
Text GLabel 2200 1650 2    50   Input ~ 0
UART_TX_Raspi
Text GLabel 2200 1750 2    50   Input ~ 0
UART_RX_Raspi
$Comp
L power:GND #PWR?
U 1 1 5FC8BFA4
P 2050 1950
AR Path="/5FC8BFA4" Ref="#PWR?"  Part="1" 
AR Path="/5FC789B7/5FC8BFA4" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2050 1700 50  0001 C CNN
F 1 "GND" V 2055 1822 50  0000 R CNN
F 2 "" H 2050 1950 50  0001 C CNN
F 3 "" H 2050 1950 50  0001 C CNN
	1    2050 1950
	0    -1   -1   0   
$EndComp
Text GLabel 3400 1650 2    50   Input ~ 0
P8
Text GLabel 3400 1750 2    50   Input ~ 0
P10
Text GLabel 3400 1850 2    50   Input ~ 0
P12
Text GLabel 3400 2050 2    50   Input ~ 0
P16
Text GLabel 3400 2150 2    50   Input ~ 0
P18
Text GLabel 3400 2450 2    50   Input ~ 0
P24
Text GLabel 3400 2550 2    50   Input ~ 0
P26
Text GLabel 3400 2650 2    50   Input ~ 0
P28
Text GLabel 3400 2850 2    50   Input ~ 0
P32
Text GLabel 3400 2950 2    50   Input ~ 0
P34
Text GLabel 3400 3050 2    50   Input ~ 0
P36
Text GLabel 3400 3150 2    50   Input ~ 0
P38
Text GLabel 3400 3250 2    50   Input ~ 0
P40
Text GLabel 3400 2350 2    50   Input ~ 0
P22
Wire Wire Line
	3400 3250 2050 3250
Wire Wire Line
	2050 3150 3400 3150
Wire Wire Line
	3400 3050 2050 3050
Wire Wire Line
	2050 2950 3400 2950
Wire Wire Line
	3400 2850 2050 2850
Wire Wire Line
	3400 2650 2050 2650
Wire Wire Line
	2050 2550 3400 2550
Wire Wire Line
	3400 2350 2050 2350
Wire Wire Line
	3400 2150 2050 2150
Wire Wire Line
	2050 2050 3400 2050
Wire Wire Line
	3400 1850 2050 1850
Wire Wire Line
	2050 1750 3400 1750
Wire Wire Line
	3400 1650 2050 1650
Wire Wire Line
	2050 2450 3400 2450
Wire Wire Line
	1550 1450 1100 1450
Wire Wire Line
	1100 1550 1550 1550
Wire Wire Line
	1550 1650 1100 1650
Wire Wire Line
	1550 1850 1100 1850
Wire Wire Line
	1100 1950 1550 1950
Wire Wire Line
	1550 2050 1100 2050
Wire Wire Line
	1550 2250 1100 2250
Wire Wire Line
	1100 2350 1550 2350
Wire Wire Line
	1550 2450 1100 2450
Wire Wire Line
	1550 2650 1100 2650
Wire Wire Line
	1100 2750 1550 2750
Wire Wire Line
	1550 2850 1100 2850
Wire Wire Line
	1550 2950 1100 2950
Wire Wire Line
	1100 3050 1550 3050
Wire Wire Line
	1550 3150 1100 3150
$EndSCHEMATC
