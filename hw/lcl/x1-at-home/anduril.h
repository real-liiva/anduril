// Hank Emisar/Noctigon Lume-X1 config options for Anduril
// Copyright (C) 2017-2026 Selene ToyKeeper
//               2022-2024 Loneoceans
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// For flashlights using the Loneoceans Lume-X1-40W boost driver (AVR32DD20)
// - Same firmware for 6V, 9V, or 12V configs

#define HWDEF_H  lcl/x1-at-home/hwdef.h



//***************************************
//**    RAMP TABLE AND OPERATIONS      **
//***************************************

#define RAMP_SIZE 150

// top level for each "gear": 121 150
#define PWM1_LEVELS \
           0,   0,   0,   1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   3,   3,   3,   4,   4,   5,   5,   5,   6,   6,   7,   8,   8,   9,  10,  11,  11,  12,  13,  14,  15,  17,  18,  19,  21,  22,  24,  25,  27,  29,  31,  33,  35,  37,  40,  42,  45,  48,  51,  54,  57,  60,  64,  68,  72,  76,  80,  84,  89,  94,  99, 104, 110, 115, 121, 128, 134, 141, 148, 155, 163, 171, 179, 188, 197, 206, 215, 225, 235, 246, 257, 269, 280, 293, 305, 319, 332, 346, 361, 376, 391, 407, 424, 441, 459, 477, 496, 515, 535, 556, 577, 599, 622, 645, 669, 694, 720, 746, 773, 801, 830, 859, 889, 921, 953, 986,1019, \
         431, 446, 461, 476, 492, 509, 525, 543, 560, 578, 597, 616, 635, 655, 676, 697, 718, 741, 763, 786, 810, 835, 860, 885, 911, 938, 966, 994,1023
#define PWM2_LEVELS \
         V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, \
         V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25
// RGB aux ramp
// ./bin/level_calc.py 1.6 1 150 7135 2 0.01 60 --pwm 255
#define PWM3_LEVELS \
        2,2,3,3,3,4,4,5,5,6,6,7,7,8,9,9,10,11,12,12,13,14,15,16,17,18,19,19,20,21,22,24,25,26,27,28,29,30,31,33,34,35,36,38,39,40,42,43,44,46,47,48,50,51,53,54,56,57,59,60,62,63,65,67,68,70,72,73,75,77,78,80,82,84,85,87,89,91,93,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,143,145,147,149,151,154,156,158,160,163,165,167,170,172,174,177,179,181,184,186,188,191,193,196,198,201,203,206,208,211,213,216,218,221,223,226,228,231,234,236,239,242,244,247,250,252,255

#define DEFAULT_JUMP_START_LEVEL 16

#define MAX_1x7135           121 //needs to change

#define LED_PATH1_PIN_LEVEL_MIN   0
#define LED_PATH2_PIN_LEVEL_MIN   0
#define LED_PATH3_PIN_LEVEL_MIN  1

#define HALFSPEED_LEVEL     20
#define QUARTERSPEED_LEVEL  10

#define DEFAULT_LEVEL  50


#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     150

#define RAMP_DISCRETE_FLOOR  10
#define RAMP_DISCRETE_CEIL   130
#define RAMP_DISCRETE_STEPS  7

// 10 35 [60] 85 110
#define SIMPLE_UI_FLOOR      10
#define SIMPLE_UI_CEIL       110      // about ~12W
#define SIMPLE_UI_STEPS      5

// don't blink mid-ramp
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif

//***************************************
//**       THERMAL SETTINGS            **
//***************************************

// stop panicking at 6W (not sure of this numbers yet since it depends on the host..)
#define THERM_FASTER_LEVEL  100  // about 6W
#define MIN_THERM_STEPDOWN  60   // similar to single amc7135 in a 3V light

//***************************************
//**       AUX LEDs and MISC           **
//***************************************

// this light has three aux LED channels: R, G, B
// (and some builds tie these also to a RGB side button)
#define USE_AUX_THRESHOLD_CONFIG
#define USE_SMOOTH_POVD
#define USE_AUXRGB_LEDS_WHILE_ON  25

// show each channel while it scroll by in the menu
#define USE_CONFIG_COLORS

// blink numbers on the main LEDs by default (but allow user to change it)
#define DEFAULT_BLINK_CHANNEL  CM_MAIN

// use aux red + aux blue for police strobe
#define USE_POLICE_COLOR_STROBE_MODE
#define POLICE_STROBE_USES_AUX
#define POLICE_COLOR_STROBE_CH1        CM_AUXRED
#define POLICE_COLOR_STROBE_CH2        CM_AUXBLU


// Misc

#define PARTY_STROBE_ONTIME 1  // slow down party strobe
#define STROBE_OFF_LEVEL 1  // keep the regulator chip on between pulses

// smoother candle mode with bigger oscillations
#define CANDLE_AMPLITUDE 30  // default 25

// avr32dd20 has enough space to smooth out voltage readings
#define USE_VOLTAGE_LOWPASS

// enable long-blink as negative sign
#define USE_LONG_BLINK_FOR_NEGATIVE_SIGN

