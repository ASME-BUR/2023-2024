#include "audio_adc_i2c.hpp"
#include <unistd.h>

Audio_ADC_I2C::Audio_ADC_I2C(char address)
{
    Wire.begin(address);
    Audio_ADC_I2C::addr_ = address;
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
    bit 4-3 [00] - VREF quick-charge duration of 3.5 ms
    bit 2 [0] - broadcast mode disabled
    bit 1 [0] - reserved
    bit 0 [1] - disable sleep mode
    */
    char reg = ADCX140_SLEEP_CFG;
    char data = 0b00000001;
    write(reg, data);

    // 3b. sleep for 1 millisecond 
    usleep(1); // not included in example given?

    // 3c. TODO: override default configuration registers

    // 3d. enable desired input channels by writing to P0_R115
    reg = ADCX140_IN_CH_EN;
    data = 0b11110000; // enabling channels 1-4

    // 3e. enable all desired audio serial interface channels (P0_R116)
    reg = ADCX140_ASI_OUT_CH_EN;
    data = 0b11110000; // channels 1-4

    // 3f. power up ADC, MICBIAS, PLL
    reg = ADCX140_PWR_CFG;
    data = 0b11100000;

    // TODO: apply FSYNC, BCLK?

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
    char reg = ADCX140_SLEEP_CFG;
    char data = 0b00000001;
    write(reg, data);

    // 3b. sleep for 1 millisecond 
    usleep(1); // not included in example given?

    // TODO: apply FSYNC, BCLK?

    return true;
}

bool Audio_ADC_I2C::setSleep()
{
    char reg = ADCX140_SLEEP_CFG;
    char data = 0b00000000;
    write(reg, data);

    // TODO: wait 6 milliseconds, check P0_R119, stop FSYNC, BCLK?

    return true;
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