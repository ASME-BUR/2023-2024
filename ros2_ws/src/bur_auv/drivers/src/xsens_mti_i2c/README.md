# XSENS_MTI_3 Library

Raspi library for the [Xsens mti-3 imu](https://www.xsens.com/hubfs/Downloads/Leaflets/MTi-3.pdf).

This library also somewhat supports the other Mti versions (relevant code commented out)

# Documentation

[wiki](https://git.whoi.edu/mural/drivers/xsens_mti_i2c/-/wikis/home)

Please see the examples for normal operation. Below are the available functions used in the library.

``` cpp
  MTi(int pigpio_id, uint8_t I2C_ADDR=0x6B, uint8_t I2C_BUS=1);
  ~MTi();
  bool detect(uint16_t timeout);
  // returns true if detected, false if timeout (milliseconds) is reached
  void requestDeviceInfo();
  // Request device firmware version and product id
  void configureOutputs(const string mode[],const uint16_t hz[], int length_);
  // Input an array of modes and output frequencies and specify the length
  void goToConfig();
  // Go to configuration state
  void goToMeasurement();
  // Go to measurement state
  void printData();
  // Print outputs set in configureOutputs
  void reset();
  // Reset MTi
  void getOptionFlags();
  // 
  void disableAutoMeas();
  // Disable setting to go to measurement on boot
  void enableICC();
  // Enable In-Run Compass Calibration
  void restoreDefauts();
  // Restore default option flag settings
  void startICC();
  // Start ICC
  void stopICC();
  // Stop ICC
  void storeICC();
  // Store ICC result
  void getRepMo();
  // Get ICC Status
  void requestOutputConfig();
  // Get Output config
  float *getEulerAngles()
  float *getAcceleration()
  float *getRateOfTurn()
  float *getLatLon()
  float *getQuat()
  float *getTemp()

```

# Reference

- [Xsens Documentation](https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation).
- Original Arduino Library [here](https://github.com/Steven-GH/Xsens_MTi_I2C)
