#include "audio_adc_i2c.hpp"

Audio_ADC_I2C::Audio_ADC_I2C(char address)
{
    Wire.begin(address);
    Audio_ADC_I2C::addr_ = address;
}

bool Audio_ADC_I2C::init()
{
}

char Audio_ADC_I2C::read()
{
}
char Audio_ADC_I2C::read(char reg)
{
    Wire.beginTransmission(addr_);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(addr_, 1); // We want one byte
    uint8_t val = Wire.read();
}

bool Audio_ADC_I2C::write(char data)
{
    Wire.beginTransmission();
    Wire.write(data);
    Wire.endTransmission();
}

bool Audio_ADC_I2C::write(char reg, char data)
{
    Wire.beginTransmission();
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}