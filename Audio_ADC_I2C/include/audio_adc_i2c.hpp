// SPDX-License-Identifier: GPL-2.0
// TLV320ADCX140 Sound driver
// Copyright (C) 2020 Texas Instruments Incorporated - https://www.ti.com/

#ifndef AUDIO_ADC_I2C
#define AUDIO_ADC_I2C

#include "tlv320adcx140.h"
#include <Wire.h>

using namespace std;

class Audio_ADC_I2C
{
public:
    Audio_ADC_I2C(char address);
    bool init();
    bool setActive();
    bool setSleep();

private:
    char read();
    char read(char reg);
    bool write(char data);
    bool write(char reg, char data);
    char addr_;
};

#endif /*AUDIO_ADC_I2C */
