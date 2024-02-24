#include "audio_adc_i2c.hpp"
#include <Arduino.h>
#include <Wire.h>

// put your setup code here, to run once:
void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Audio_ADC_I2C ADC = Audio_ADC_I2C(0b1001100);
  ADC.init();
}

void loop()
{
}

int main()
{
  setup();
  while (1)
  {
    loop();
  }
  return(0);
}