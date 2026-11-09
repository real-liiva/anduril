// Lumintop FWAA PWM helper functions
// Copyright (C) 2019-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

void set_level_zero();

void set_level_main(uint8_t level);
bool gradual_tick_main(uint8_t gt);


Channel channels[] = {
    { // main LEDs
        .set_level    = set_level_main,
        .gradual_tick = gradual_tick_main
    },
};


void set_level_zero() {
    CH1_PWM = 0;
    CH2_PWM = 0;
}

uint8_t PWM_GET_NEW(const PWM_DATATYPE* channel, uint8_t level){
    if (channel==pwm1_levels)
    {
        if (level>=MAX_1x7135-1) return 255*(level!=255);
    }
    return pgm_read_byte(channel+level);
}

// TODO: implement delta-sigma modulation for better low modes

// single set of LEDs with 2 stacked power channels, FET+1
void set_level_main(uint8_t level) {
    PWM_DATATYPE ch1_pwm = PWM_GET(pwm1_levels, level);
    PWM_DATATYPE ch2_pwm = PWM_GET(pwm2_levels, level);

    CH1_PWM = ch1_pwm;
    CH2_PWM = ch2_pwm;
}

bool gradual_tick_main(uint8_t gt) {
    PWM_DATATYPE pwm1 = PWM_GET(pwm1_levels, gt);
    PWM_DATATYPE pwm2 = PWM_GET(pwm2_levels, gt);

    GRADUAL_ADJUST_STACKED(pwm1, CH1_PWM, PWM_TOP_INIT);
    GRADUAL_ADJUST_SIMPLE (pwm2, CH2_PWM);

    if (   (pwm1 == CH1_PWM)
        && (pwm2 == CH2_PWM)
       ) {
        return true;  // done
    }
    return false;  // not done yet
}

