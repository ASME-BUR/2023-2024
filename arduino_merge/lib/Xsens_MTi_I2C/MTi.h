#ifndef MTi_h
#define MTi_h

#include "Xbus.h"
#include <Wire.h>

class MTi
{
public:
  MTi(uint8_t x, uint8_t y);
  uint8_t drdy_;
  uint8_t address_;
  bool detect(uint16_t timeout, bool verbose = false);
  void requestDeviceInfo(bool verbose = false);
  void configureOutputs(uint16_t freq, bool verbose = false);
  void requestOutputs(bool verbose = false);
  void resetInclination(bool verbose = false);
  void resetHeading(bool verbose = false);
  void resetAlignment(bool verbose = false);
  void saveReset(bool verbose = false);
  void goToConfig(bool verbose = false);
  void goToMeasurement(bool verbose = false);
  void readMessages(bool verbose = false);
  void printData();

  float *getQuat()
  {
    return xbus.quat;
  }
  float *getAcceleration()
  {
    return xbus.acc;
  }
  float *getRateOfTurn()
  {
    return xbus.rot;
  }
  float *getMag()
  {
    return xbus.mag;
  }

private:
  Xbus xbus;
  void sendMessage(uint8_t *message, uint8_t numBytes, bool verbose = false);
};

#endif
