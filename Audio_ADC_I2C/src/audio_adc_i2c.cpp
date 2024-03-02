#include "audio_adc_i2c.hpp"
#include <string>
#include <Arduino.h>

Audio_ADC_I2C::Audio_ADC_I2C(uint8_t address)
{
  delay(5000);
  Serial.println("init");
  pinMode(shdnz_, OUTPUT);
  digitalWrite(shdnz_, LOW);
  Serial.println("SHDZ low");
  delay(1000);
  Serial.println("powering up");
  digitalWrite(shdnz_, HIGH);
  Serial.println("SHDZ high");
  delay(100);
  //Wire.begin(address);
  addr_ = address;
  delay(100);
  uint8_t reg = ADCX140_SLEEP_CFG;
  uint8_t data = 0b00000001;
  write(reg, data);
  delay(100);
  read(reg, 1);
  reg = ADCX140_SLEEP_CFG;
  data = 0b10000001;
  write(reg, data);
  delay(100);
  read(reg, 1);

  reg = ADCX140_SW_RESET;
  read(reg,1);
  delay(100);
  reg = ADCX140_DEV_STS0;
  read(reg, 1);
  delay(100);
  reg = ADCX140_DEV_STS1;
  read(reg, 1);

  delay(1000);
  AudioMemory(128);
}

bool Audio_ADC_I2C::init()
{
  // 1. apply power to the device
  // 2. transition from hardware shutdown mode to sleep mode

  // 3. transition from sleep mode to active mode whenever required for the recording operation

  // 3a. wake up device by writing to P0_R2
  /* SLEEP_CFG:
    TODO: bit 7 [0] - external 1.8-v AREG supply
    bit 6-5 [00] - reserved
    bit 4-3 [00] - VREF quick-uint8_tge duration of 3.5 ms
    bit 2 [0] - broadcast mode disabled
    bit 1 [0] - reserved
    bit 0 [1] - disable sleep mode
    */
  uint8_t reg, data;
  // write(reg, data);

  // 3b. sleep for 1 millisecond

  // 3c. TODO: override default configuration registers

  // 3d. enable desired input channels by writing to P0_R115
  reg = ADCX140_IN_CH_EN;
  read(reg,1);
  data = 0b11110000; // enabling channels 1-4
  write(reg, data);
  delay(100);
  Serial.println(read(reg, 1));
  delay(100);
  // 3e. enable all desired audio serial interface channels (P0_R116)
  reg = ADCX140_ASI_OUT_CH_EN;
  read(reg,1);
  data = 0b11110000; // channels 1-4
  write(reg, data);
  delay(100);
  Serial.println(read(reg, 1));
  delay(100);
  // 3f. power up ADC, MICBIAS, PLL
  reg = ADCX140_PWR_CFG;
  data = 0b01100000;
  write(reg, data);
  delay(100);
  Serial.println(read(reg, 1));
  delay(100);

  reg = ADCX140_DEV_STS0;
  read(reg, 1);

  reg = ADCX140_DEV_STS1;
  read(reg, 1);
  // TODO: apply FSYNC, BCLK?
  // initAudioInput();
  // initAudioOutput();

  return true;
}

bool Audio_ADC_I2C::initAudioInput()
{
  uint8_t reg, data;
  // Initialize input channel settings
  // AC Coupling & Single Ended-Input
  reg = ADCX140_CH1_CFG0;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  reg = ADCX140_CH2_CFG0;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  reg = ADCX140_CH3_CFG0;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  reg = ADCX140_CH4_CFG0;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));
  return true;
}

bool Audio_ADC_I2C::initAudioOutput()
{
  uint8_t reg, data;
  // Assign output channel slots for each data channel
  // Channel 1 to standard output left
  reg = ADCX140_ASI_CH1;
  data = 0b00000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // Channel 2 to standard output right
  reg = ADCX140_ASI_CH2;
  data = 0b00100000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // Channel 3 to secondary output left
  reg = ADCX140_ASI_CH3;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // Channel 4 to secondary output right
  reg = ADCX140_ASI_CH4;
  data = 0b01100000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // Configure audio output word length
  // Currently: I2S Mode with 16-bit word length
  reg = ADCX140_ASI_CFG0;
  data = 0b01000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // Apply FSYNC = 96 kHz and BCLK = 24.576 MHz
  return true;
}

bool Audio_ADC_I2C::setActive()
{
  // copying steps 3a, 3b from init()

  // 3a. wake up device by writing to P0_R2
  /* SLEEP_CFG:
    TODO: bit 7 [0] - external 1.8-v AREG supply
    bit 6-5 [00] - reserved
    bit 4-3 [00] - VREF quick-charge duration of 3.5 ms
    bit 2 [0] - broadcast mode disabled
    bit 1 [0] - reserved
    bit 0 [1] - disable sleep mode
    */
  uint8_t reg = ADCX140_SLEEP_CFG;
  uint8_t data = 0b00000001;
  write(reg, data);
  Serial.println(read(reg, 1));

  // 3b. sleep for 1 millisecond
  delay(1); // not included in example given?

  // TODO: apply FSYNC, BCLK?

  return true;
}

bool Audio_ADC_I2C::setSleep()
{
  uint8_t reg = ADCX140_SLEEP_CFG;
  uint8_t data = 0b00000000;
  write(reg, data);
  Serial.println(read(reg, 1));

  // TODO: wait 6 milliseconds, check P0_R119, stop FSYNC, BCLK?

  return true;
}

// Read multiple bytes from a starting register and store into uint8_t array
uint8_t Audio_ADC_I2C::read(uint8_t reg, int bytesRequested)
{
  uint8_t bytes_read = 0;
  Wire.beginTransmission(addr_);
  Wire.write((uint8_t)ADCX140_PAGE_SELECT);
  Wire.write((uint8_t)0);
  Wire.endTransmission(true);

  Wire.beginTransmission(addr_);
  Wire.write((uint8_t)reg);
  Wire.endTransmission(false);
  // Serial.println(Wire.endTransmission(false));
  Wire.requestFrom((uint8_t)addr_, (uint8_t)bytesRequested, (uint8_t) false);
  // Serial.println(Wire.requestFrom((uint8_t)addr_, (uint8_t)bytesRequested, (uint8_t) false));

  //Serial.print("available: ");
  // Serial.println(Wire.available());
  while (Wire.available() > 0 && bytes_read < 1)
  {
    outputData[bytes_read] = Wire.read();
    Serial.print("Result: ");
    Serial.println(outputData[bytes_read], BIN);
    bytes_read++;
  }
  Wire.endTransmission();
  // Serial.println(Wire.endTransmission());
  return bytes_read;
}

bool Audio_ADC_I2C::write(uint8_t data)
{
  Wire.beginTransmission((uint8_t)addr_);
  Wire.write((uint8_t)data);
  Wire.endTransmission();
  return true;
}

bool Audio_ADC_I2C::write(uint8_t reg, uint8_t data)
{
  Serial.print("writing ");
  Serial.println(data, BIN);
  Wire.beginTransmission(addr_);
  Wire.write((uint8_t)ADCX140_PAGE_SELECT);
  Wire.write((uint8_t)0);
  Wire.endTransmission(true);
  Wire.beginTransmission(addr_);
  Wire.write((uint8_t)reg);
  Wire.write((uint8_t)data);
  Serial.println(Wire.endTransmission());
  return true;
}