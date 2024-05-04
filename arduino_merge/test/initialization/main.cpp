#include <Arduino.h>

#include "MTi.h"
#include <Wire.h>

#define DRDY 3       // Arduino Digital IO pin used as input for MTi-DRDY
#define ADDRESS 0x6B // MTi I2C address 0x6B (default I2C address for MTi 1-series)
MTi *IMU = NULL;
bool verbose = true;
float accel_offset[3] = {0};
float quat_offset[4] = {0};
float mag_offset[3] = {0};
float omega_offset[3] = {0};

void setup()
{
  // IMU Initialization
  IMU = new MTi(ADDRESS, DRDY);
  Wire1.begin(); // Initialize Wire1 library for I2C communication
  delay(1000);
  
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
  u_long current = millis();
  while (current - millis() < 20000)
  {
    if (digitalRead(DRDY))
    {
      IMU->readMessages(verbose);
      for (size_t i = 0; i < 3; i++)
      {
        accel_offset[i] = 0.9 * accel_offset[i] + 0.1 * IMU->getAcceleration()[i];
        mag_offset[i] = 0.9 * mag_offset[i] + 0.1 * IMU->getMag()[i];
        omega_offset[i] = 0.9 * omega_offset[i] + 0.1 * IMU->getRateOfTurn()[i];
      }
      for (size_t i = 0; i < 4; i++)
      {
        quat_offset[i] = 0.9 * quat_offset[i] + 0.1 * IMU->getQuat()[i];
      }
    }
  }
  for (size_t i = 0; i < 3; i++)
  {
    Serial.println(accel_offset[i]); 
  }
}

void loop()
{
  if (digitalRead(DRDY))
  {
    // IMU->readMessages();
    // IMU->printData();
  }
}