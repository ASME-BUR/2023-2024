#include "audio_adc_i2c.hpp"
#include <Arduino.h>

// put function declarations here:

int main() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Audio_ADC_I2C ADC = Audio_ADC_I2C(0b1001100);
  ADC.init();
}