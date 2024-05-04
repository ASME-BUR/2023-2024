#include "Xbus.h"
#include <Wire.h>

Xbus::Xbus()
{
}

bool Xbus::read(uint8_t address, bool verbose)
{
  readPipeStatus(address, verbose);
  if (notificationSize)
  { // New notification message available to be read
    readPipeNotif(address, verbose);
    parseNotification(datanotif, verbose);
  }
  if (measurementSize)
  { // New measurement packet available to be read
    readPipeMeas(address, verbose);
    parseMTData2(datameas, measurementSize);
    return true; // Return true if new measurements were read
  }
  else
  {
    return false;
  }
}

void Xbus::readPipeStatus(uint8_t address, bool verbose)
{
  Wire1.beginTransmission(address);
  Wire1.write(XSENS_STATUS_PIPE);
  Wire1.endTransmission(false);

  Wire1.requestFrom(address, uint8_t(4), false);
  if (Wire1.available() > 0)
  {
    for (int i = 0; i < 4; i++)
    {
      status[i] = Wire1.read();
    }
  }

  notificationSize = (uint16_t)status[0] | ((uint16_t)status[1] << 8);
  measurementSize = (uint16_t)status[2] | ((uint16_t)status[3] << 8);
  if (verbose)
  {
    SerialUSB.print("notification: ");
    SerialUSB.print(notificationSize);
    SerialUSB.print(" measurement: ");
    SerialUSB.print(measurementSize);
    SerialUSB.println();
  }
  Wire1.endTransmission(true);
}

void Xbus::readPipeNotif(uint8_t address, bool verbose)
{
  Wire1.beginTransmission(address);
  Wire1.write((int)XSENS_NOTIF_PIPE);
  Wire1.endTransmission(false);

  Wire1.requestFrom((int)address, (int)notificationSize, false);
  if (Wire1.available() > 0)
  {
    for (uint16_t i = 0; i < notificationSize; i++)
    {
      datanotif[i] = Wire1.read();
      if (verbose)
      {
        SerialUSB.print(datanotif[i], HEX);
        SerialUSB.print(" ");
      }
    }
    if (verbose)
    {
      SerialUSB.println();
    }
  }
  Wire1.endTransmission(true);
}

void Xbus::readPipeMeas(uint8_t address, bool verbose)
{
  // Use this function if you cant modify the wire buffer
  /*
    uint8_t remainder = measurementSize % 32;
    uint8_t iterations = (measurementSize - remainder) / 32;
    for (uint8_t j = 0; j < iterations; j++)
    {
      Wire1.beginTransmission(address);
      Wire1.write((int)XSENS_MEAS_PIPE);
      Wire1.endTransmission(false);
      Wire1.requestFrom((int)address, (int)32, (int) false);
      if (Wire1.available() > 0)
      {
        for (uint16_t i = 0; i < 32; i++)
        {
          datameas[j * 32 + i] = Wire1.read();
          if (verbose)
          {
            Serial.print(datameas[j * 32 + i], HEX);
            Serial.print(" ");
          }
        }
      }
      Wire1.endTransmission(true);
    }
    Wire1.beginTransmission(address);
    Wire1.write((int)XSENS_MEAS_PIPE);
    Wire1.endTransmission(false);
    Wire1.requestFrom((int)address, (int)remainder, (int) false);
    if (Wire1.available() > 0)
    {
      for (uint16_t i = 0; i < remainder; i++)
      {
        datameas[iterations * 32 + i] = Wire1.read();
        if (verbose)
        {
          Serial.print(datameas[iterations * 32 + i], HEX);
          Serial.print(" ");
        }
      }
      if (verbose)
      {
        Serial.println();
      }
    }
    Wire1.endTransmission(true);
  */

  // Increase wire buffer to 256
  Wire1.beginTransmission(address);
  Wire1.write((int)XSENS_MEAS_PIPE);
  Wire1.endTransmission(false);
  Wire1.requestFrom((int)address, (int)measurementSize, (int)false);
  if (Wire1.available() > 0)
  {
    for (uint16_t i = 0; i < measurementSize; i++)
    {
      datameas[i] = Wire1.read();
      if (verbose)
      {
        SerialUSB.print(datameas[i], HEX);
        SerialUSB.print(" ");
      }
    }
    if (verbose)
    {
      SerialUSB.println();
    }
  }
  Wire1.endTransmission(true);
}

void Xbus::parseMTData2(uint8_t *data, uint8_t datalength)
{
  if (datalength < 2) // Reached the end of the MTData2 message
    return;

  uint8_t XDI = data[0]; // Xsens Data Identifier
  if (XDI == (uint8_t)MesID::MTDATA2)
  { // Start of the MTData2 message
    uint8_t length = data[1];
    parseMTData2(data + 2, length);
  }
  else
  {
    uint8_t length = data[2];
    switch (((uint16_t)data[1] | ((uint16_t)data[0] << 8)) & (uint16_t)0xFFFF)
    { // Extract the 2-byte Xsens Data Identifier
    case (uint16_t)DataID::QUATERNION:
      dataswapendian(data + 3, sizeof(float) * 4);
      memcpy(quat, data + 3, sizeof(float) * 4);
      break;
    case (uint16_t)DataID::ACCELERATION:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(acc, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::RATEOFTURN:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(rot, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::MAG:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(mag, data + 3, sizeof(float) * 3);
      break;
    default:
      break;
    }
    parseMTData2(data + length + 3, datalength - length - 3); // Move onto next data element within MTData2 packet
  }
}

void Xbus::parseNotification(uint8_t *notif, bool verbose)
{ // Parse the most common notification messages
  uint8_t notifID = notif[0];
  switch (notifID)
  {
  case (uint8_t)MesID::WAKEUP:
  {
    if (verbose)
    {
      SerialUSB.println("Received WakeUp message.");
    }
    break;
  }
  case (uint8_t)MesID::ERROR:
  {
    if (verbose)
    {
      SerialUSB.print("Received an error with code: ");
      SerialUSB.println(notif[2]);
    }
    break;
  }
  case (uint8_t)MesID::WARNING:
  {
    if (verbose)
    {
      uint32_t warn = (uint32_t)notif[5] | ((uint32_t)notif[4] << 8);
      SerialUSB.print("Received a warning with code: ");
      SerialUSB.println(warn);
    }
    break;
  }
  case (uint8_t)MesID::PRODUCTCODE:
  {
    if (verbose)
    {
      SerialUSB.print("Product code is: ");
      for (int i = 2; i < notificationSize - 1; i++)
      {
        SerialUSB.print(char(notif[i]));
      }
      SerialUSB.println();
      productCode = char(notif[6]); // Store the product code (MTi-#) for later usage
    }
    break;
  }
  case (uint8_t)MesID::FIRMWAREREV:
  {
    if (verbose)
    {
      SerialUSB.print("Firmware version is: ");
      SerialUSB.print(notif[2]);
      SerialUSB.print(".");
      SerialUSB.print(notif[3]);
      SerialUSB.print(".");
      SerialUSB.println(notif[4]);
    }
    break;
  }
  case (uint8_t)MesID::GOTOCONFIGACK:
  {
    if (verbose)
    {
      SerialUSB.println("Received GoToConfigACK.");
      configState = true;
      break;
    }
  }
  case (uint8_t)MesID::GOTOMEASUREMENTACK:
  {
    if (verbose)
    {
      SerialUSB.println("Received GoToMeasurementACK.");
      configState = false;
      break;
    }
  }
  case (uint8_t)MesID::OUTPUTCONFIGURATION:
  {
    if (verbose)
    {
      SerialUSB.println("Received SetOutputConfigurationACK.");
      break;
    }
  }
  default:
  {
    if (verbose)
    {
      SerialUSB.print("Received undefined notification: ");
      for (int i = 0; i < notificationSize - 1; i++)
      {
        SerialUSB.print(notif[i], HEX);
        SerialUSB.print(" ");
      }
      SerialUSB.println();
      break;
    }
  }
  }
}

void Xbus::dataswapendian(uint8_t *data, uint8_t length)
{                            // Swap the endianness of the data such that the float value can be printed
  uint8_t cpy[length];       // Create a copy of the data
  memcpy(cpy, data, length); // Create a copy of the data
  for (int i = 0; i < length / 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      data[j + i * 4] = cpy[3 - j + i * 4]; // Within each 4-byte (32-bit) float, reverse the order of the individual bytes
    }
  }
}
