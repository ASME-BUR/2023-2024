#include <Arduino.h>

#include "MTi.h"
#include <Wire.h>

#define DRDY 3       // Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B // MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *IMU = NULL;
bool verbose = true;

void setup()
{
  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  Wire1.begin(); // Initialize Wire1 library for I2C communication
  pinMode(DRDY, INPUT);
  // Configure serial transport
  SerialUSB.begin(250000);
  IMU->detect(1000, verbose);
  // Check if MTi is detected before moving on
  IMU->goToConfig(verbose); // Switch device to Config mode
  // IMU->requestDeviceInfo(verbose);   // Request the device's product code and firmware version
  IMU->configureOutputs(100, verbose); // Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
  // IMU->requestOutputs(verbose);
  IMU->requestOutputs(verbose);
  delay(1000);
  IMU->goToMeasurement(); // Switch device to Measurement mode
}

void loop()
{
  if (digitalRead(DRDY))
  {
    IMU->readMessages();
    IMU->printData();
  }
}