#include <LPS.h>
// Constructors //////////////////////////////////////////////////////

LPS::LPS(int pigpio_id)
{
  pi = pigpio_id;
  _device = device_auto;
  // Pololu board pulls SA0 high, so default assumption is that it is
  // high
  address = SA0_HIGH_ADDRESS;
}
LPS::~LPS()
{
  cout << "destructing pressure sensor" << endl;
  cout << i2c_close(pi, handle) << endl;
}
// Public Methods ////////////////////////////////////////////////////

// sets or detects device type and slave address; returns bool indicating success
bool LPS::init(deviceType device, char sa0)
{
  handle = i2c_open(pi, 1, address, 0);
  if (handle < 0)
  {
    cout << "Can't open I2C Bus" << endl;
  }
  else
  {
    cout << "I2C Bus Opened" << endl;
  }
  if (!detectDeviceAndAddress(device, (sa0State)sa0))
    return false;

  switch (_device)
  {
    /*
    case device_25H:
      translated_regs[-REF_P_L] = LPS25H_REF_P_L;
      translated_regs[-REF_P_H] = LPS25H_REF_P_H;
      translated_regs[-CTRL_REG1] = LPS25H_CTRL_REG1;
      translated_regs[-CTRL_REG2] = LPS25H_CTRL_REG2;
      translated_regs[-CTRL_REG3] = LPS25H_CTRL_REG3;
      translated_regs[-CTRL_REG4] = LPS25H_CTRL_REG4;
      translated_regs[-INTERRUPT_CFG] = LPS25H_INTERRUPT_CFG;
      translated_regs[-INT_SOURCE] = LPS25H_INT_SOURCE;
      translated_regs[-FIFO_CTRL] = LPS25H_FIFO_CTRL;
      translated_regs[-THS_P_L] = LPS25H_THS_P_L;
      translated_regs[-THS_P_H] = LPS25H_THS_P_H;
      translated_regs[-RPDS_L] = LPS25H_RPDS_L;
      translated_regs[-RPDS_H] = LPS25H_RPDS_H;
      return true;
      */

  case device_331AP:
    translated_regs[-REF_P_L] = LPS331AP_REF_P_L;
    translated_regs[-REF_P_H] = LPS331AP_REF_P_H;
    translated_regs[-CTRL_REG1] = LPS331AP_CTRL_REG1;
    translated_regs[-CTRL_REG2] = LPS331AP_CTRL_REG2;
    translated_regs[-CTRL_REG3] = LPS331AP_CTRL_REG3;
    translated_regs[-INTERRUPT_CFG] = LPS331AP_INTERRUPT_CFG;
    translated_regs[-INT_SOURCE] = LPS331AP_INT_SOURCE;
    translated_regs[-THS_P_L] = LPS331AP_THS_P_L;
    translated_regs[-THS_P_H] = LPS331AP_THS_P_H;
    return true;
    /*
    case device_22DF:
      translated_regs[-REF_P_L] = LPS22DF_REF_P_L;
      translated_regs[-REF_P_H] = LPS22DF_REF_P_H;
      translated_regs[-CTRL_REG1] = LPS22DF_CTRL_REG1;
      translated_regs[-CTRL_REG2] = LPS22DF_CTRL_REG2;
      translated_regs[-CTRL_REG3] = LPS22DF_CTRL_REG3;
      translated_regs[-CTRL_REG4] = LPS22DF_CTRL_REG4;
      translated_regs[-INTERRUPT_CFG] = LPS22DF_INTERRUPT_CFG;
      translated_regs[-INT_SOURCE] = LPS22DF_INT_SOURCE;
      translated_regs[-FIFO_CTRL] = LPS22DF_FIFO_CTRL;
      translated_regs[-THS_P_L] = LPS22DF_THS_P_L;
      translated_regs[-THS_P_H] = LPS22DF_THS_P_H;
      translated_regs[-RPDS_L] = LPS22DF_RPDS_L;
      translated_regs[-RPDS_H] = LPS22DF_RPDS_H;
      return true;
    */
  default:
    return false;
  }
}

// turns on sensor and enables continuous output
void LPS::enableDefault(void)
{
  /*
  if (_device == device_22DF)
  {
    // 0x18 = 0b00011000
    // ODR = 0011 (10 Hz pressure & temperature output data rate); AVG = 000 (4 averages)
    writeReg(CTRL_REG1, 0x18);
    // 0x01 = 0b00000001
    // INT_H_L = 0 (INT pin active high); PP_OD = 0 (INT pin push-pull); IF_ADD_INC = 1 (register address auto-increment enabled)
    writeReg(CTRL_REG3, 0x01);
  }
  else if (_device == device_25H)
  {
    // 0xB0 = 0b10110000
    // PD = 1 (active mode);  ODR = 011 (12.5 Hz pressure & temperature output data rate)
    writeReg(CTRL_REG1, 0xB0);
  }
  else if (_device == device_331AP)
  */
  if (_device == device_331AP)
  {
    // 0xE0 = 0b11100000
    // PD = 1 (active mode);  ODR = 110 (12.5 Hz pressure & temperature output data rate)
    // must power down before changing configuration
    writeReg(CTRL_REG1, 0x00);
    writeReg(RES_CONF, 0x79);
    writeReg(CTRL_REG1, 0xE0);
    // readReg(CTRL_REG1);
    // readReg(RES_CONF);
  }
}

bool LPS::readData()
{
  if (i2c_read_byte_data(pi, handle, STATUS_REG) == 0x00)
  {
    return (false);
  }
  else
  {
    return (true);
  }
}

void LPS::run()
{
    while (readData() == false);
    temperature = readTemperatureC();
    pressure = readPressureMillibars();
    altitude = pressureToAltitudeMeters(pressure);

    cout << "p: ";
    cout << pressure;
    cout << " mbar\ta: ";
    cout << altitude;
    cout << " m\tt: ";
    cout << temperature;
    cout << " deg C" << endl;
}

// reads pressure in millibars (mbar)/hectopascals (hPa)
float LPS::readPressureMillibars(void)
{
  return (float)readPressureRaw() / 4096;
}

// reads pressure in inches of mercury (inHg)
float LPS::readPressureInchesHg(void)
{
  return (float)readPressureRaw() / 138706.5;
}

// reads pressure and returns raw 24-bit sensor output
int32_t LPS::readPressureRaw(void)
{
  if (_device == device_25H || _device == device_331AP)
  {
    // assert MSB to enable register address auto-increment
    i2c_write_byte_data(pi, handle, PRESS_OUT_XL, (PRESS_OUT_XL | (1 << 7)));
  }
  // else // 22DF
  // {
  //   i2c_write_byte(pi, handle, PRESS_OUT_XL);
  // }

  uint8_t pxl = i2c_read_byte_data(pi, handle, 0x28);
  uint8_t pl = i2c_read_byte_data(pi, handle, 0x29);
  uint8_t ph = i2c_read_byte_data(pi, handle, 0x2A);

  // combine chars
  return (int32_t)(int8_t)ph << 16 | (uint16_t)pl << 8 | pxl;
}

// reads temperature in degrees C
float LPS::readTemperatureC(void)
{
  if (_device == device_22DF)
  {
    return (float)readTemperatureRaw() / 100;
  }
  else if (_device == device_25H || _device == device_331AP)
  {
    return 42.5 + (float)readTemperatureRaw() / 480;
  }

  // fall-through case if device is not set
  return NAN;
}

// reads temperature in degrees F
float LPS::readTemperatureF(void)
{
  if (_device == device_22DF)
  {
    return 32 + (float)readTemperatureRaw() / 100 * 1.8;
  }
  else if (_device == device_25H || _device == device_331AP)
  {
    return 108.5 + (float)readTemperatureRaw() / 480 * 1.8;
  }

  // fall-through case if device is not set
  return NAN;
}

// reads temperature and returns raw 16-bit sensor output
int16_t LPS::readTemperatureRaw(void)
{
  if (_device == device_25H || _device == device_331AP)
  {
    // assert MSB to enable register address auto-increment
    i2c_write_byte_data(pi, handle, TEMP_OUT_L, (TEMP_OUT_L | (1 << 7)));
  }
  // else // 22DF
  // {
  //   i2c_write_byte(pi, handle, TEMP_OUT_L);
  // }

  uint8_t tl = i2c_read_byte_data(pi, handle, 0x2B);
  uint8_t th = i2c_read_byte_data(pi, handle, 0x2C);

  // combine bytes
  return (int16_t)(th << 8 | tl);
}

// converts pressure in mbar to altitude in meters, using 1976 US
// Standard Atmosphere model (note that this formula only applies to a
// height of 11 km, or about 36000 ft)
//  If altimeter setting (QNH, barometric pressure adjusted to sea
//  level) is given, this function returns an indicated altitude
//  compensated for actual regional pressure; otherwise, it returns
//  the pressure altitude above the standard pressure level of 1013.25
//  mbar or 29.9213 inHg
float LPS::pressureToAltitudeMeters(float pressure_mbar, float altimeter_setting_mbar)
{
  return (1 - pow(pressure_mbar / altimeter_setting_mbar, 0.190263)) * 44330.8;
}

// converts pressure in inHg to altitude in feet; see notes above
float LPS::pressureToAltitudeFeet(float pressure_inHg, float altimeter_setting_inHg)
{
  return (1 - pow(pressure_inHg / altimeter_setting_inHg, 0.190263)) * 145442;
}

// Private Methods ///////////////////////////////////////////////////

// writes register
bool LPS::writeReg(char reg, char value)
{
  // if dummy register address, look up actual translated address (based on device type)
  if (reg < 0)
  {
    reg = translated_regs[-reg];
  }
  uint8_t value2 = (uint8_t)value;
  cout << "Value to write: " << hex << (unsigned int)value2 << " to reg: " << hex << (unsigned int)reg << endl;
  if (i2c_write_byte_data(pi, handle, reg, value2) < 0)
  {
    cout << "failed to write" << endl;
    return (false);
  }
  return (true);
}

// reads register
char LPS::readReg(char reg)
{
  // if dummy register address, look up actual translated address (based on device type)
  if (reg < 0)
  {
    reg = translated_regs[-reg];
  }
  cout << i2c_write_byte(pi, handle, reg) << endl;
  uint8_t value = i2c_read_byte(pi, handle);
  cout << "Value of reg: " << hex << (unsigned int)reg << " = " << hex << (unsigned int)value << endl;
  return (value);
}

bool LPS::detectDeviceAndAddress(deviceType device, sa0State sa0)
{
  if (sa0 == sa0_auto || sa0 == sa0_high)
  {
    address = SA0_HIGH_ADDRESS;
    cout << "sa0 high" << endl;
    if (detectDevice(device))
      return true;
  }
  if (sa0 == sa0_auto || sa0 == sa0_low)
  {
    address = SA0_LOW_ADDRESS;
    cout << "sa0 low" << endl;
    if (detectDevice(device))
      return true;
  }

  return false;
}

bool LPS::detectDevice(deviceType device)
{
  int id = testWhoAmI(address);
  /*
  if ((device == device_auto || device == device_22DF) && id == LPS22DF_WHO_ID)
  {
    _device = device_22DF;
    return true;
  }
  if ((device == device_auto || device == device_25H) && id == LPS25H_WHO_ID)
  {
    _device = device_25H;
    return true;
  }
  */
  if ((device == device_auto || device == device_331AP) && id == LPS331AP_WHO_ID)
  {
    _device = device_331AP;
    return true;
  }

  return false;
}

int LPS::testWhoAmI(char address)
{

  i2c_write_byte(pi, handle, WHO_AM_I);

  int output = i2c_read_byte_data(pi, handle, 0x0F);
  if (output > 0)
  {
    return output;
  }
  else
  {
    return TEST_REG_NACK;
  }
}