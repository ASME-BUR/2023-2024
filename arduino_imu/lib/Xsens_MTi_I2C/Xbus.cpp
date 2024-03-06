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
    parseNotification(datanotif);
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

  Wire1.requestFrom(address, uint8_t(4));
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
    Serial.print("notification: ");
    Serial.print(notificationSize);
    Serial.print(" measurement: ");
    Serial.print(measurementSize);
    Serial.println();
  }
  Wire1.endTransmission(true);
}

void Xbus::readPipeNotif(uint8_t address, bool verbose)
{
  Wire1.beginTransmission(address);
  Wire1.write(XSENS_NOTIF_PIPE);
  Wire1.endTransmission(false);

  Wire1.requestFrom((int)address, (int)notificationSize);
  if (Wire1.available() > 0)
  {
    for (uint16_t i = 0; i < notificationSize; i++)
    {
      datanotif[i] = Wire1.read();
      if (verbose)
      {
        Serial.print(datanotif[i], HEX);
        Serial.print(" ");
      }
    }
    if (verbose)
    {
      Serial.println();
    }
  }
  Wire1.endTransmission(true);
}

void Xbus::readPipeMeas(uint8_t address, bool verbose)
{
  Wire1.beginTransmission(address);
  Wire1.write(XSENS_MEAS_PIPE);
  Wire1.endTransmission(false);
  uint16_t remainder = measurementSize % 32;
  for (uint16_t i = 0; i < measurementSize / 32; i++)
  {
    Wire1.requestFrom((int)address, 32);
    if (Wire1.available() > 0)
    {
      for (uint16_t j = 0; j < 32; j++)
      {
        datameas[i*32+j] = Wire1.read();
        if (verbose)
        {
          Serial.print(datameas[i*32+j], HEX);
          Serial.print(" ");
        }
      }
      if (verbose)
      {
        Serial.println();
      }
    }
  }
  Wire1.requestFrom((int)address, remainder);
  if (Wire1.available() > 0)
  {
    int start = measurementSize - remainder - 1;
    for (uint16_t i = 0; i < remainder; i++)
    {
      datameas[start + i] = Wire1.read();
      if (verbose)
      {
        Serial.print(datameas[start + i], HEX);
        Serial.print(" ");
      }
    }
    if (verbose)
    {
      Serial.println();
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

void Xbus::parseNotification(uint8_t *notif)
{ // Parse the most common notification messages
  uint8_t notifID = notif[0];
  switch (notifID)
  {
  case (uint8_t)MesID::WAKEUP:
  {
    Serial.println("Received WakeUp message.");
    break;
  }
  case (uint8_t)MesID::ERROR:
  {
    Serial.print("Received an error with code: ");
    Serial.println(notif[2]);
    break;
  }
  case (uint8_t)MesID::WARNING:
  {
    uint32_t warn = (uint32_t)notif[5] | ((uint32_t)notif[4] << 8);
    Serial.print("Received a warning with code: ");
    Serial.println(warn);
    break;
  }
  case (uint8_t)MesID::PRODUCTCODE:
  {
    Serial.print("Product code is: ");
    for (int i = 2; i < notificationSize - 1; i++)
    {
      Serial.print(char(notif[i]));
    }
    Serial.println();
    productCode = char(notif[6]); // Store the product code (MTi-#) for later usage
    break;
  }
  case (uint8_t)MesID::FIRMWAREREV:
  {
    Serial.print("Firmware version is: ");
    Serial.print(notif[2]);
    Serial.print(".");
    Serial.print(notif[3]);
    Serial.print(".");
    Serial.println(notif[4]);
    break;
  }
  case (uint8_t)MesID::GOTOCONFIGACK:
  {
    Serial.println("Received GoToConfigACK.");
    configState = true;
    break;
  }
  case (uint8_t)MesID::GOTOMEASUREMENTACK:
  {
    Serial.println("Received GoToMeasurementACK.");
    configState = false;
    break;
  }
  case (uint8_t)MesID::OUTPUTCONFIGURATION:
  {
    Serial.println("Received SetOutputConfigurationACK.");
    break;
  }
  default:
  {
    Serial.print("Received undefined notification: ");
    for (int i = 0; i < notificationSize - 1; i++)
    {
      Serial.print(notif[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    break;
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
