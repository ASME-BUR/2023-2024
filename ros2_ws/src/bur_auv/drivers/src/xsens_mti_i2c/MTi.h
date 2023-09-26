#ifndef MTi_h
#define MTi_h

#include "Xbus.h"
#include <thread>
#include <chrono>
#include <pigpiod_if2.h>
#include <string>
#include <iostream>
#include <vector>

#include <iterator>
using namespace std;

class MTi
{
public:
  MTi(int pigpio_id, uint8_t I2C_ADDR = 0x6B, uint8_t I2C_BUS = 1);
  MTi(uint8_t I2C_ADDR = 0x6B, uint8_t I2C_BUS = 1);
  void setPi(int pigpio_id);
  ~MTi();
  bool detect(uint16_t timeout);
  // returns true if detected, false if timeout (milliseconds) is reached
  void requestDeviceInfo();
  // Request device firmware version and product id
  void runSelfTest();
  void restoreFactoryDefaults();
  void configureOutputs(const string mode[], const uint16_t hz[], int length_);
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
  void resetOrientation();
  
  void enableAHS();

  void disableAutoMeas();
  // Disable setting to go to measurement on boot
  void enableICC();
  // Enable In-Run Compass Calibration
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
  void readData();

  float *getEulerAngles()
  {
    return xbus.euler;
  }
  float *getAcceleration()
  {
    return xbus.acc;
  }
  float *getRateOfTurn()
  {
    return xbus.rot;
  }
  // MTi-3 has no Lat Lon
  /*
  float *getLatLon()
  {
    return xbus.latlon;
  }
  */
  float *getQuat()
  {
    return xbus.quat;
  }
  float *getTemp()
  {
    return xbus.temperature;
  }

private:
  Xbus xbus;
  uint8_t readMessages();
  bool sendMessage(char *message, uint8_t numBytes);

  int pi;
  int handle_;
  int getHandle()
  {
    return xbus.handle;
  }
};

#endif
