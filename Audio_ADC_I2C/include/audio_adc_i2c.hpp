// SPDX-License-Identifier: GPL-2.0
// TLV320ADCX140 Sound driver
// Copyright (C) 2020 Texas Instruments Incorporated - https://www.ti.com/

#ifndef AUDIO_ADC_I2C
#define AUDIO_ADC_I2C

#include "tlv320adcx140.h"
#include <Wire.h>
#include "Audio.h"
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
// AudioInputI2SQuad        i2s_quad1;      //xy=271.1999969482422,192.1999969482422
// AudioMixer4              mixer2;         //xy=409.20001220703125,290.20001220703125
// AudioMixer4              mixer1;         //xy=417.20001220703125,115.19999694824219
// AudioOutputUSB           usb1;           //xy=553.1999969482422,197.1999969482422
// AudioConnection          patchCord1(i2s_quad1, 0, mixer1, 0);
// AudioConnection          patchCord2(i2s_quad1, 1, mixer1, 1);
// AudioConnection          patchCord3(i2s_quad1, 2, mixer2, 0);
// AudioConnection          patchCord4(i2s_quad1, 3, mixer2, 1);
// AudioConnection          patchCord5(mixer2, 0, usb1, 1);
// AudioConnection          patchCord6(mixer1, 0, usb1, 0);
// GUItool: end automatically generated code

using namespace std;

class Audio_ADC_I2C {
public:
  Audio_ADC_I2C(uint8_t address);
  bool init();
  bool setActive();
  bool setSleep();
  bool initAudioOutput();
  bool initAudioInput();
private:
  uint8_t read(uint8_t reg, int bytesRequested);
  bool write(uint8_t data);
  bool write(uint8_t reg, uint8_t data);
  uint8_t outputData[128];
  char addr_;
  const uint8_t shdnz_ = 22;
};

#endif /*AUDIO_ADC_I2C */