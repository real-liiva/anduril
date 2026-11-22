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

// Contrast ratio on the s21e driver is ~2000:1
// top level for each "gear": 120 150
#define PWM1_LEVELS \
           0,   0,   1,   1,   1,   1,   1,   2,   2,   2,   2,   3,   3,   3,   4,   4,   5,   5,   6,   6,   7,   7,   8,   9,   9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  20,  21,  22,  24,  26,  27,  29,  31,  33,  35,  38,  40,  42,  45,  48,  51,  54,  57,  60,  63,  67,  71,  75,  79,  83,  88,  92,  97, 102, 107, 113, 119, 125, 131, 137, 144, 151, 158, 166, 173, 181, 190, 198, 207, 217, 226, 236, 247, 258, 269, 280, 292, 304, 317, 330, 344, 358, 372, 387, 403, 419, 435, 452, 469, 487, 506, 525, 545, 565, 586, 608, 630, 653, 676, 701, 726, 751, 778, 805, 833, 861, 891, 921, 952, 984,1017, \
         430, 444, 458, 473, 488, 504, 520, 537, 554, 571, 589, 607, 626, 645, 665, 685, 705, 727, 748, 770, 793, 816, 840, 864, 889, 914, 941, 967, 995,1023
#define PWM2_LEVELS \
         V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, V10, \
         V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25, V25
#define MAX_1x7135           120
// RGB aux ramp
// ./bin/level_calc.py 1.6 1 150 7135 2 0.01 60 --pwm 255
#define PWM3_LEVELS \
        2,2,3,3,3,4,4,5,5,6,6,7,7,8,9,9,10,11,12,12,13,14,15,16,17,18,19,19,20,21,22,24,25,26,27,28,29,30,31,33,34,35,36,38,39,40,42,43,44,46,47,48,50,51,53,54,56,57,59,60,62,63,65,67,68,70,72,73,75,77,78,80,82,84,85,87,89,91,93,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,143,145,147,149,151,154,156,158,160,163,165,167,170,172,174,177,179,181,184,186,188,191,193,196,198,201,203,206,208,211,213,216,218,221,223,226,228,231,234,236,239,242,244,247,250,252,255

#define DEFAULT_JUMP_START_LEVEL 16

#define LED_PATH1_PIN_LEVEL_MIN   0
#define LED_PATH2_PIN_LEVEL_MIN   0
#define LED_PATH3_PIN_LEVEL_MIN  1

#define HALFSPEED_LEVEL     20
#define QUARTERSPEED_LEVEL  10

#define DEFAULT_LEVEL  50


#define RAMP_SMOOTH_FLOOR    1
#define RAMP_SMOOTH_CEIL     150

#define RAMP_DISCRETE_FLOOR  10
#define RAMP_DISCRETE_CEIL   150
#define RAMP_DISCRETE_STEPS  7


#define SIMPLE_UI_FLOOR      10
#define SIMPLE_UI_CEIL       120      
#define SIMPLE_UI_STEPS      5

// don't blink mid-ramp
#ifdef BLINK_AT_RAMP_MIDDLE
#undef BLINK_AT_RAMP_MIDDLE
#endif

//***************************************
//**       THERMAL SETTINGS            **
//***************************************

// stop panicking at 6W (not sure of this numbers yet since it depends on the host..)
#define THERM_FASTER_LEVEL  130  // about 6W
#define MIN_THERM_STEPDOWN  100   // similar to single amc7135 in a 3V light

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


// Misc

#define PARTY_STROBE_ONTIME 1  // slow down party strobe
#define STROBE_OFF_LEVEL 1  // keep the regulator chip on between pulses

// smoother candle mode with bigger oscillations
#define CANDLE_AMPLITUDE 30  // default 25

// avr32dd20 has enough space to smooth out voltage readings
#define USE_VOLTAGE_LOWPASS

// enable long-blink as negative sign
#define USE_LONG_BLINK_FOR_NEGATIVE_SIGN

