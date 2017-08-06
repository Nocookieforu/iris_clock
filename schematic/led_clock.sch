EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:led_clock
LIBS:led_clock-cache
EELAYER 25 0
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
L CONN_01X04 J3
U 1 1 59860A09
P 10300 1500
F 0 "J3" H 10300 1750 50  0000 C CNN
F 1 "CONN_01X04" V 10400 1500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 10300 1500 50  0001 C CNN
F 3 "" H 10300 1500 50  0001 C CNN
	1    10300 1500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 J4
U 1 1 59860A93
P 10400 3050
F 0 "J4" H 10400 3300 50  0000 C CNN
F 1 "CONN_01X04" V 10500 3050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 10400 3050 50  0001 C CNN
F 3 "" H 10400 3050 50  0001 C CNN
	1    10400 3050
	1    0    0    -1  
$EndComp
Text Notes 9950 750  0    60   ~ 0
Neopixel Header
Text Notes 10000 2550 0    60   ~ 0
DotStar Header
Wire Wire Line
	10000 1550 10100 1550
$Comp
L +5V #PWR01
U 1 1 59860B76
P 10000 1050
F 0 "#PWR01" H 10000 900 50  0001 C CNN
F 1 "+5V" H 10000 1190 50  0000 C CNN
F 2 "" H 10000 1050 50  0001 C CNN
F 3 "" H 10000 1050 50  0001 C CNN
	1    10000 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 59860BC8
P 10150 3300
F 0 "#PWR02" H 10150 3050 50  0001 C CNN
F 1 "GND" H 10150 3150 50  0000 C CNN
F 2 "" H 10150 3300 50  0001 C CNN
F 3 "" H 10150 3300 50  0001 C CNN
	1    10150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	10000 1550 10000 1050
$Comp
L +5V #PWR03
U 1 1 59860BFA
P 10050 2800
F 0 "#PWR03" H 10050 2650 50  0001 C CNN
F 1 "+5V" H 10050 2940 50  0000 C CNN
F 2 "" H 10050 2800 50  0001 C CNN
F 3 "" H 10050 2800 50  0001 C CNN
	1    10050 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 3200 10050 2800
Wire Wire Line
	10200 2900 10150 2900
Wire Wire Line
	10150 2900 10150 3300
$Comp
L GND #PWR04
U 1 1 59860C2C
P 10000 1750
F 0 "#PWR04" H 10000 1500 50  0001 C CNN
F 1 "GND" H 10000 1600 50  0000 C CNN
F 2 "" H 10000 1750 50  0001 C CNN
F 3 "" H 10000 1750 50  0001 C CNN
	1    10000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 1650 10000 1650
Wire Wire Line
	10000 1650 10000 1750
Wire Wire Line
	10050 3200 10200 3200
$Comp
L CP C3
U 1 1 59860D25
P 10950 1800
F 0 "C3" H 10975 1900 50  0000 L CNN
F 1 "100u" H 10975 1700 50  0000 L CNN
F 2 "Capacitors_SMD:CP_Elec_4x5.8" H 10988 1650 50  0001 C CNN
F 3 "" H 10950 1800 50  0001 C CNN
	1    10950 1800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 59860D5F
P 10950 1550
F 0 "#PWR05" H 10950 1400 50  0001 C CNN
F 1 "+5V" H 10950 1690 50  0000 C CNN
F 2 "" H 10950 1550 50  0001 C CNN
F 3 "" H 10950 1550 50  0001 C CNN
	1    10950 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 1550 10950 1650
$Comp
L GND #PWR06
U 1 1 59860D80
P 10950 2100
F 0 "#PWR06" H 10950 1850 50  0001 C CNN
F 1 "GND" H 10950 1950 50  0000 C CNN
F 2 "" H 10950 2100 50  0001 C CNN
F 3 "" H 10950 2100 50  0001 C CNN
	1    10950 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 2100 10950 1950
$Comp
L CONN_01X15 J1
U 1 1 59860DCB
P 1700 2050
F 0 "J1" H 1700 2850 50  0000 C CNN
F 1 "CONN_01X15" V 1800 2050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x15_Pitch2.54mm" H 1700 2050 50  0001 C CNN
F 3 "" H 1700 2050 50  0001 C CNN
	1    1700 2050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X15 J2
U 1 1 5986117E
P 2250 2050
F 0 "J2" H 2250 2850 50  0000 C CNN
F 1 "CONN_01X15" V 2350 2050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x15_Pitch2.54mm" H 2250 2050 50  0001 C CNN
F 3 "" H 2250 2050 50  0001 C CNN
	1    2250 2050
	-1   0    0    -1  
$EndComp
Text Notes 1650 1050 0    60   ~ 0
STM32 Headers
$Comp
L GND #PWR07
U 1 1 5986134C
P 2750 1750
F 0 "#PWR07" H 2750 1500 50  0001 C CNN
F 1 "GND" H 2750 1600 50  0000 C CNN
F 2 "" H 2750 1750 50  0001 C CNN
F 3 "" H 2750 1750 50  0001 C CNN
	1    2750 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1750 2750 1450
Wire Wire Line
	2750 1450 2450 1450
Text Notes 1550 2950 0    60   ~ 0
CN3
Text Notes 2200 2950 0    60   ~ 0
CN4
$Comp
L GND #PWR08
U 1 1 598617A5
P 1250 1700
F 0 "#PWR08" H 1250 1450 50  0001 C CNN
F 1 "GND" H 1250 1550 50  0000 C CNN
F 2 "" H 1250 1700 50  0001 C CNN
F 3 "" H 1250 1700 50  0001 C CNN
	1    1250 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1700 1250 1650
Wire Wire Line
	1250 1650 1500 1650
$Comp
L +5V #PWR09
U 1 1 59861859
P 2900 1350
F 0 "#PWR09" H 2900 1200 50  0001 C CNN
F 1 "+5V" H 2900 1490 50  0000 C CNN
F 2 "" H 2900 1350 50  0001 C CNN
F 3 "" H 2900 1350 50  0001 C CNN
	1    2900 1350
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR010
U 1 1 59861870
P 2800 2500
F 0 "#PWR010" H 2800 2350 50  0001 C CNN
F 1 "+3V3" H 2800 2640 50  0000 C CNN
F 2 "" H 2800 2500 50  0001 C CNN
F 3 "" H 2800 2500 50  0001 C CNN
	1    2800 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 1650 2900 1650
Wire Wire Line
	2900 1650 2900 1350
Wire Wire Line
	2450 2650 2800 2650
Wire Wire Line
	2800 2650 2800 2500
$Comp
L C C1
U 1 1 5986192D
P 3350 1250
F 0 "C1" H 3375 1350 50  0000 L CNN
F 1 "0.1u" H 3375 1150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3388 1100 50  0001 C CNN
F 3 "" H 3350 1250 50  0001 C CNN
	1    3350 1250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR011
U 1 1 59861980
P 3350 1000
F 0 "#PWR011" H 3350 850 50  0001 C CNN
F 1 "+5V" H 3350 1140 50  0000 C CNN
F 2 "" H 3350 1000 50  0001 C CNN
F 3 "" H 3350 1000 50  0001 C CNN
	1    3350 1000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 598619B7
P 3350 1500
F 0 "#PWR012" H 3350 1250 50  0001 C CNN
F 1 "GND" H 3350 1350 50  0000 C CNN
F 2 "" H 3350 1500 50  0001 C CNN
F 3 "" H 3350 1500 50  0001 C CNN
	1    3350 1500
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR013
U 1 1 598619EF
P 3750 1000
F 0 "#PWR013" H 3750 850 50  0001 C CNN
F 1 "+3V3" H 3750 1140 50  0000 C CNN
F 2 "" H 3750 1000 50  0001 C CNN
F 3 "" H 3750 1000 50  0001 C CNN
	1    3750 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 1000 3350 1100
Wire Wire Line
	3350 1400 3350 1500
$Comp
L C C2
U 1 1 59861B12
P 3750 1250
F 0 "C2" H 3775 1350 50  0000 L CNN
F 1 "0.1u" H 3775 1150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3788 1100 50  0001 C CNN
F 3 "" H 3750 1250 50  0001 C CNN
	1    3750 1250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 59861B1E
P 3750 1500
F 0 "#PWR014" H 3750 1250 50  0001 C CNN
F 1 "GND" H 3750 1350 50  0000 C CNN
F 2 "" H 3750 1500 50  0001 C CNN
F 3 "" H 3750 1500 50  0001 C CNN
	1    3750 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1000 3750 1100
Wire Wire Line
	3750 1400 3750 1500
Text Notes 4050 4200 0    60   ~ 0
TODO:\nLight sensor\nTemp sensor/Audio sensor?\nJST SM connectors for LEDs\nRTC\nPower
Text GLabel 9750 3000 0    60   Input ~ 0
DS_CLK
Wire Wire Line
	9750 3000 10200 3000
Text GLabel 9750 3150 0    60   Input ~ 0
DS_DAT
Wire Wire Line
	9750 3150 9950 3150
Wire Wire Line
	9950 3150 9950 3100
Wire Wire Line
	9950 3100 10200 3100
Wire Wire Line
	9750 1450 10100 1450
$Comp
L R R3
U 1 1 59866F98
P 8250 2000
F 0 "R3" V 8330 2000 50  0000 C CNN
F 1 "10K" V 8250 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 8180 2000 50  0001 C CNN
F 3 "" H 8250 2000 50  0001 C CNN
	1    8250 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 59866F9E
P 8250 2250
F 0 "#PWR015" H 8250 2000 50  0001 C CNN
F 1 "GND" H 8250 2100 50  0000 C CNN
F 2 "" H 8250 2250 50  0001 C CNN
F 3 "" H 8250 2250 50  0001 C CNN
	1    8250 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2250 8250 2150
Wire Wire Line
	8250 1550 8250 1850
$Comp
L R R2
U 1 1 59867035
P 8050 2000
F 0 "R2" V 8130 2000 50  0000 C CNN
F 1 "10K" V 8050 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 7980 2000 50  0001 C CNN
F 3 "" H 8050 2000 50  0001 C CNN
	1    8050 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 5986703B
P 8050 2250
F 0 "#PWR016" H 8050 2000 50  0001 C CNN
F 1 "GND" H 8050 2100 50  0000 C CNN
F 2 "" H 8050 2250 50  0001 C CNN
F 3 "" H 8050 2250 50  0001 C CNN
	1    8050 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2250 8050 2150
Wire Wire Line
	8050 1450 8050 1850
$Comp
L SN74LVC2T45 U1
U 1 1 59868BF1
P 7250 1450
F 0 "U1" H 7050 1100 60  0000 C CNN
F 1 "SN74LVC2T45" H 7250 1700 60  0000 C CNN
F 2 "Housings_SSOP:MSOP-8_3x3mm_Pitch0.65mm" H 7250 1450 60  0001 C CNN
F 3 "" H 7250 1450 60  0001 C CNN
	1    7250 1450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR017
U 1 1 59868CCF
P 7800 1250
F 0 "#PWR017" H 7800 1100 50  0001 C CNN
F 1 "+5V" H 7800 1390 50  0000 C CNN
F 2 "" H 7800 1250 50  0001 C CNN
F 3 "" H 7800 1250 50  0001 C CNN
	1    7800 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 1250 7800 1350
Wire Wire Line
	7800 1350 7700 1350
Text GLabel 9750 1450 0    60   Input ~ 0
NP_DAT
Wire Wire Line
	7700 1450 8700 1450
Wire Wire Line
	7700 1550 8500 1550
$Comp
L GND #PWR018
U 1 1 59868F87
P 6700 1750
F 0 "#PWR018" H 6700 1500 50  0001 C CNN
F 1 "GND" H 6700 1600 50  0000 C CNN
F 2 "" H 6700 1750 50  0001 C CNN
F 3 "" H 6700 1750 50  0001 C CNN
	1    6700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1650 7800 1650
$Comp
L +3V3 #PWR019
U 1 1 59869103
P 6700 1250
F 0 "#PWR019" H 6700 1100 50  0001 C CNN
F 1 "+3V3" H 6700 1390 50  0000 C CNN
F 2 "" H 6700 1250 50  0001 C CNN
F 3 "" H 6700 1250 50  0001 C CNN
	1    6700 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 1250 6700 1350
Wire Wire Line
	6700 1350 6800 1350
Text GLabel 8700 1250 2    60   Output ~ 0
NP_DAT
Wire Wire Line
	8500 1450 8500 1250
Wire Wire Line
	8500 1250 8700 1250
Connection ~ 8050 1450
Text GLabel 8700 1450 2    60   Output ~ 0
DS_DAT
Text GLabel 8700 1600 2    60   Output ~ 0
DS_CLK
Connection ~ 8500 1450
Wire Wire Line
	8500 1550 8500 1600
Wire Wire Line
	8500 1600 8700 1600
Connection ~ 8250 1550
Text GLabel 6300 1450 0    60   Input ~ 0
PIX_DAT
Wire Wire Line
	6300 1450 6800 1450
Text GLabel 6300 1600 0    60   Input ~ 0
PIX_CLK
Wire Wire Line
	6300 1600 6550 1600
Wire Wire Line
	6550 1600 6550 1550
Wire Wire Line
	6550 1550 6800 1550
Wire Wire Line
	6700 1750 6700 1650
Wire Wire Line
	6700 1650 6800 1650
Text GLabel 6300 2350 0    60   Input ~ 0
PIX_DIR
Wire Wire Line
	7800 1650 7800 2350
Wire Wire Line
	7800 2350 6300 2350
Text Notes 6800 850  0    60   ~ 0
LED Level Translation
$Comp
L R R1
U 1 1 598697F5
P 6450 2100
F 0 "R1" V 6530 2100 50  0000 C CNN
F 1 "10K" V 6450 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 6380 2100 50  0001 C CNN
F 3 "" H 6450 2100 50  0001 C CNN
	1    6450 2100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR020
U 1 1 598698A3
P 6450 1900
F 0 "#PWR020" H 6450 1750 50  0001 C CNN
F 1 "+3V3" H 6450 2040 50  0000 C CNN
F 2 "" H 6450 1900 50  0001 C CNN
F 3 "" H 6450 1900 50  0001 C CNN
	1    6450 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 1900 6450 1950
Wire Wire Line
	6450 2250 6450 2350
Connection ~ 6450 2350
$EndSCHEMATC