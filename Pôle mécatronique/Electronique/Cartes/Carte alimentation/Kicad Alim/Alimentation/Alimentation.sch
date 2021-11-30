EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Regulator_Switching:TSR_1-2450 U2
U 1 1 61A62B82
P 3650 6100
F 0 "U2" H 3650 6467 50  0000 C CNN
F 1 "TSR_2-2450" H 3650 6376 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 3650 5950 50  0001 L CIN
F 3 "http://www.tracopower.com/products/tsr1.pdf" H 3650 6100 50  0001 C CNN
	1    3650 6100
	0    -1   -1   0   
$EndComp
Text GLabel 3950 6100 2    50   Input ~ 0
GND
Text GLabel 3550 6600 3    50   Input ~ 0
Vbatt
$Comp
L Connector_Generic:Conn_2Rows-15Pins J7
U 1 1 61A77683
P 3700 4800
F 0 "J7" V 3704 5180 50  0000 L CNN
F 1 "Conn_2Rows-15Pins" V 3795 5180 50  0000 L CNN
F 2 "" H 3700 4800 50  0001 C CNN
F 3 "~" H 3700 4800 50  0001 C CNN
	1    3700 4800
	0    1    1    0   
$EndComp
$Comp
L Regulator_Switching:TSR_1-24120 U3
U 1 1 61A799CF
P 5000 6100
F 0 "U3" V 5046 6329 50  0000 L CNN
F 1 "TSR_2-24120" V 4955 6329 50  0000 L CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 5000 5950 50  0001 L CIN
F 3 "http://www.tracopower.com/products/tsr1.pdf" H 5000 6100 50  0001 C CNN
	1    5000 6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3850 6100 3950 6100
Wire Wire Line
	3550 6500 3550 6600
$Comp
L Regulator_Switching:TSR_1-2450 U1
U 1 1 61A83DA4
P 2600 6100
F 0 "U1" H 2600 6467 50  0000 C CNN
F 1 "TSR_2-2450" H 2600 6376 50  0000 C CNN
F 2 "Converter_DCDC:Converter_DCDC_TRACO_TSR-1_THT" H 2600 5950 50  0001 L CIN
F 3 "http://www.tracopower.com/products/tsr1.pdf" H 2600 6100 50  0001 C CNN
	1    2600 6100
	0    -1   -1   0   
$EndComp
Text GLabel 2900 6100 2    50   Input ~ 0
GND
Text GLabel 2500 6600 3    50   Input ~ 0
Vbatt
Wire Wire Line
	2800 6100 2900 6100
Wire Wire Line
	2500 6500 2500 6600
Wire Wire Line
	4900 5700 4900 5250
Wire Wire Line
	4900 5250 4000 5250
Wire Wire Line
	4000 5250 4000 5100
Wire Wire Line
	4000 5250 3900 5250
Wire Wire Line
	3900 5250 3900 5100
Connection ~ 4000 5250
Wire Wire Line
	3800 5100 3800 5250
Wire Wire Line
	3800 5250 3700 5250
Wire Wire Line
	3700 5250 3700 5100
Wire Wire Line
	3600 5100 3600 5250
Wire Wire Line
	3600 5250 3700 5250
Connection ~ 3700 5250
Wire Wire Line
	3700 5250 3700 5600
Wire Wire Line
	3700 5700 3550 5700
Wire Wire Line
	3500 5100 3500 5400
Wire Wire Line
	3500 5400 2500 5400
Wire Wire Line
	2500 5400 2500 5700
Text GLabel 3200 5200 0    50   Input ~ 0
GND
Wire Wire Line
	3400 5200 3400 5100
Wire Wire Line
	3200 5200 3400 5200
Text GLabel 3300 4500 1    50   Input ~ 0
can_H
Text GLabel 3400 4500 1    50   Input ~ 0
can_L
Wire Wire Line
	3300 4500 3300 4600
Wire Wire Line
	3400 4500 3400 4600
Text GLabel 4900 6600 3    50   Input ~ 0
VbattProtected
Text GLabel 5350 6100 2    50   Input ~ 0
GND
Wire Wire Line
	5200 6100 5350 6100
Wire Wire Line
	4900 6500 4900 6600
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 61A9C7AE
P 1100 1000
F 0 "J1" V 1064 712 50  0000 R CNN
F 1 "Conn_01x04" V 973 712 50  0000 R CNN
F 2 "" H 1100 1000 50  0001 C CNN
F 3 "~" H 1100 1000 50  0001 C CNN
	1    1100 1000
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J5
U 1 1 61A9E8A7
P 1350 2700
F 0 "J5" H 1400 3017 50  0000 C CNN
F 1 "Conn_02x03_Odd_Even" H 1400 2926 50  0000 C CNN
F 2 "" H 1350 2700 50  0001 C CNN
F 3 "~" H 1350 2700 50  0001 C CNN
	1    1350 2700
	1    0    0    -1  
$EndComp
Text GLabel 3600 4500 1    50   Input ~ 0
5Vout1
Text GLabel 3700 4500 1    50   Input ~ 0
5Vout2
Text GLabel 3800 4500 1    50   Input ~ 0
5Vout3
Text GLabel 3900 4500 1    50   Input ~ 0
12Vout1
Text GLabel 4000 4500 1    50   Input ~ 0
12Vout2
Text GLabel 3500 4500 1    50   Input ~ 0
5VRPI
Wire Wire Line
	3500 4500 3500 4600
Wire Wire Line
	3600 4500 3600 4600
Wire Wire Line
	3700 4500 3700 4600
Wire Wire Line
	3800 4500 3800 4600
Wire Wire Line
	3900 4500 3900 4600
Wire Wire Line
	4000 4500 4000 4600
Text GLabel 1100 1300 3    50   Input ~ 0
can_H
Text GLabel 1200 1300 3    50   Input ~ 0
can_L
Text GLabel 1000 1300 3    50   Input ~ 0
GND
Text GLabel 1300 1300 3    50   Input ~ 0
5Vout1
Wire Wire Line
	1000 1200 1000 1300
Wire Wire Line
	1100 1200 1100 1300
Wire Wire Line
	1200 1200 1200 1300
Wire Wire Line
	1300 1200 1300 1300
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 61ABEAEF
P 2100 1000
F 0 "J2" V 2064 712 50  0000 R CNN
F 1 "Conn_01x04" V 1973 712 50  0000 R CNN
F 2 "" H 2100 1000 50  0001 C CNN
F 3 "~" H 2100 1000 50  0001 C CNN
	1    2100 1000
	0    -1   -1   0   
$EndComp
Text GLabel 2100 1300 3    50   Input ~ 0
can_H
Text GLabel 2200 1300 3    50   Input ~ 0
can_L
Text GLabel 2000 1300 3    50   Input ~ 0
GND
Text GLabel 2300 1300 3    50   Input ~ 0
5Vout2
Wire Wire Line
	2000 1200 2000 1300
Wire Wire Line
	2100 1200 2100 1300
Wire Wire Line
	2200 1200 2200 1300
Wire Wire Line
	2300 1200 2300 1300
$Comp
L Connector_Generic:Conn_01x04 J3
U 1 1 61ABFAFB
P 3150 1000
F 0 "J3" V 3114 712 50  0000 R CNN
F 1 "Conn_01x04" V 3023 712 50  0000 R CNN
F 2 "" H 3150 1000 50  0001 C CNN
F 3 "~" H 3150 1000 50  0001 C CNN
	1    3150 1000
	0    -1   -1   0   
$EndComp
Text GLabel 3150 1300 3    50   Input ~ 0
can_H
Text GLabel 3250 1300 3    50   Input ~ 0
can_L
Text GLabel 3050 1300 3    50   Input ~ 0
GND
Text GLabel 3350 1300 3    50   Input ~ 0
5Vout3
Wire Wire Line
	3050 1200 3050 1300
Wire Wire Line
	3150 1200 3150 1300
Wire Wire Line
	3250 1200 3250 1300
Wire Wire Line
	3350 1200 3350 1300
Text GLabel 1800 2600 2    50   Input ~ 0
5VRPI
Text GLabel 1800 2800 2    50   Input ~ 0
GND
Wire Wire Line
	1650 2600 1800 2600
Wire Wire Line
	1800 2800 1650 2800
Text GLabel 1000 2600 0    50   Input ~ 0
can_H
Text GLabel 1000 2800 0    50   Input ~ 0
can_L
Wire Wire Line
	1000 2600 1150 2600
Wire Wire Line
	1150 2800 1000 2800
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 61AD32BF
P 5350 1000
F 0 "J4" V 5314 712 50  0000 R CNN
F 1 "Conn_01x04" V 5223 712 50  0000 R CNN
F 2 "" H 5350 1000 50  0001 C CNN
F 3 "~" H 5350 1000 50  0001 C CNN
	1    5350 1000
	0    -1   -1   0   
$EndComp
Text GLabel 5350 1300 3    50   Input ~ 0
can_H
Text GLabel 5450 1300 3    50   Input ~ 0
can_L
Text GLabel 5250 1300 3    50   Input ~ 0
GND
Text GLabel 5550 1300 3    50   Input ~ 0
12Vout1
Wire Wire Line
	5250 1200 5250 1300
Wire Wire Line
	5350 1200 5350 1300
Wire Wire Line
	5450 1200 5450 1300
Wire Wire Line
	5550 1200 5550 1300
$Comp
L Connector_Generic:Conn_01x04 J6
U 1 1 61AD32CD
P 6400 1000
F 0 "J6" V 6364 712 50  0000 R CNN
F 1 "Conn_01x04" V 6273 712 50  0000 R CNN
F 2 "" H 6400 1000 50  0001 C CNN
F 3 "~" H 6400 1000 50  0001 C CNN
	1    6400 1000
	0    -1   -1   0   
$EndComp
Text GLabel 6400 1300 3    50   Input ~ 0
can_H
Text GLabel 6500 1300 3    50   Input ~ 0
can_L
Text GLabel 6300 1300 3    50   Input ~ 0
GND
Text GLabel 6600 1300 3    50   Input ~ 0
12Vout2
Wire Wire Line
	6300 1200 6300 1300
Wire Wire Line
	6400 1200 6400 1300
Wire Wire Line
	6500 1200 6500 1300
Wire Wire Line
	6600 1200 6600 1300
$Comp
L Relay:G5LE-1 K1
U 1 1 61AEE719
P 7700 4100
F 0 "K1" H 8130 4146 50  0000 L CNN
F 1 "G5LE-1" H 8130 4055 50  0000 L CNN
F 2 "Relay_THT:Relay_SPDT_Omron-G5LE-1" H 8150 4050 50  0001 L CNN
F 3 "http://www.omron.com/ecb/products/pdf/en-g5le.pdf" H 7700 4100 50  0001 C CNN
	1    7700 4100
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Current:ACS712xLCTR-20A U4
U 1 1 61AF3C8B
P 8000 2950
F 0 "U4" V 8046 2506 50  0000 R CNN
F 1 "ACS712xLCTR-20A" V 7955 2506 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8100 2600 50  0001 L CIN
F 3 "http://www.allegromicro.com/~/media/Files/Datasheets/ACS712-Datasheet.ashx?la=en" H 8000 2950 50  0001 C CNN
F 4 "680-7135" V 8000 2950 50  0001 C CNN "Réf"
	1    8000 2950
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_FET:2N7002 Q1
U 1 1 61AF51C2
P 7400 4750
F 0 "Q1" H 7604 4796 50  0000 L CNN
F 1 "2N7002" H 7604 4705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7600 4675 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/NDS7002A-D.PDF" H 7400 4750 50  0001 L CNN
	1    7400 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 61AF7B30
P 8450 2500
F 0 "C2" V 8198 2500 50  0000 C CNN
F 1 "1nF" V 8289 2500 50  0000 C CNN
F 2 "" H 8488 2350 50  0001 C CNN
F 3 "~" H 8450 2500 50  0001 C CNN
	1    8450 2500
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 61AF853B
P 7300 2950
F 0 "C1" V 7048 2950 50  0000 C CNN
F 1 "1nF" V 7139 2950 50  0000 C CNN
F 2 "" H 7338 2800 50  0001 C CNN
F 3 "~" H 7300 2950 50  0001 C CNN
	1    7300 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 2500 8100 2500
Wire Wire Line
	8100 2500 8100 2550
Wire Wire Line
	8400 2950 8600 2950
Wire Wire Line
	8600 2950 8600 2500
Wire Wire Line
	7600 2950 7500 2950
Text GLabel 7150 3100 3    50   Input ~ 0
GND
Wire Wire Line
	7150 2950 7150 3100
Wire Wire Line
	7500 2750 7500 2950
Connection ~ 7500 2950
Wire Wire Line
	7500 2950 7450 2950
Text GLabel 8350 3550 2    50   Input ~ 0
VbattProtected
Wire Wire Line
	7800 3800 7800 3350
Wire Wire Line
	8200 3350 8200 3550
Wire Wire Line
	8200 3550 8350 3550
Text GLabel 3900 5600 2    50   Input ~ 0
5V
Wire Wire Line
	3900 5600 3700 5600
Connection ~ 3700 5600
Wire Wire Line
	3700 5600 3700 5700
Text GLabel 7500 2750 1    50   Input ~ 0
5V
Text GLabel 7500 3600 1    50   Input ~ 0
5V
Wire Wire Line
	7500 3600 7500 3800
Text GLabel 7900 4550 3    50   Input ~ 0
Vbatt
Wire Wire Line
	7900 4550 7900 4400
Wire Wire Line
	7500 4400 7500 4550
Text GLabel 7500 5050 3    50   Input ~ 0
GND
Wire Wire Line
	7500 4950 7500 5050
Text GLabel 7050 4750 0    50   Input ~ 0
cmd_relais
Wire Wire Line
	7050 4750 7200 4750
Text GLabel 1000 2700 0    50   Input ~ 0
cmd_relais
Wire Wire Line
	1000 2700 1150 2700
$EndSCHEMATC
