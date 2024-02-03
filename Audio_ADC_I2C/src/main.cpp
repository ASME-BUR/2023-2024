#include "audio_adc_i2c.hpp"
#include <Arduino.h>

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Audio_ADC_I2C ADC = Audio_ADC_I2C(1001100);
  delay(1000);
  ADC.init();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here: