#include "audio_adc_i2c.hpp"

Audio_ADC_I2C::Audio_ADC_I2C(char address)
{
    Wire.begin(address);
    addr_ = address;
}

bool Audio_ADC_I2C::init()
{
    return (true);
}

char Audio_ADC_I2C::read()
{
    Wire.requestFrom(addr_, 1); // We want one byte
    char val = Wire.read();
    return (val);
}

char Audio_ADC_I2C::read(char reg)
{
    Wire.beginTransmission(addr_);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(addr_, 1); // We want one byte
    char val = Wire.read();
    return (val);
}

void Audio_ADC_I2C::write(char data)
{
    Wire.beginTransmission(addr_);
    Wire.write(data);
    Wire.endTransmission();
}

void Audio_ADC_I2C::write(char reg, char data)
{
    Wire.beginTransmission(addr_);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}