#include "MTi.h"

MTi::MTi(uint8_t address, uint8_t drdy) : xbus()
{
  address_ = address;
  drdy_ = drdy;
  // Wire1.begin();         // Initialize Wire1 library for I2C communication
  // pinMode(drdy_, INPUT); // Data Ready pin, indicates whether data/notifications are available to be read
}

bool MTi::detect(uint16_t timeout, bool verbose)
{
  // Send goToConfig messages until goToConfigAck is received from the device
  Serial.println("Scanning for MTi.");
  long int starttime = millis();
  while ((millis() - starttime) < timeout)
  {
    goToConfig(verbose);
    delay(250);

    readMessages(verbose);
    if (xbus.configState)
    {
      Serial.println("Device detected.");
      return true;
    }
  }
  Serial.println("Failed to detect device.");
  return false;
}

void MTi::configureOutputs(uint16_t freq, bool verbose)
{
  // Configure the outputs of the MTi using Xbus commands. Refer to the MT Low Level Communication Protocol Document for more information on the commands used here:
  // https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation

  if (!xbus.configState)
  {
    goToConfig(verbose);
    delay(100);
  }
  uint8_t high = (uint8_t)((freq & 0xFF00) >> 8);
  uint8_t low = (uint8_t)(freq & 0x00FF);
  readMessages(); // Clear the measurement/notification pipes (without printing) before configuring.
  Serial.println("Configuring Acceleration, Rate of Turn, Quaternion, Mag FIeld at 100 Hz");
  uint8_t outputConfig[] = {0xC0, 0x10, 0x40, 0x28, high, low, 0x80, 0x28, high, low, 0xC0, 0x28, high, low, 0x20, 0x18, high, low};
  sendMessage(outputConfig, sizeof(outputConfig), verbose);
  delay(100);
  readMessages();
}

void MTi::requestOutputs(bool verbose)
{
  if (verbose)
  {
    Serial.println("Current Output Configuration is: ");
  }
  uint8_t requestOutputs[] = {0xC0, 0x00}; // requestOutputs Xbus message
  sendMessage(requestOutputs, sizeof(requestOutputs), verbose);
  delay(100);

  readMessages(verbose);
}

void MTi::requestDeviceInfo(bool verbose)
{
  // Request device info from the MTi using Xbus commands. Refer to the MT Low Level Communication Protocol Document for more information on the commands used here:
  // https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation

  if (!xbus.configState)
  {
    goToConfig(verbose);
  }
  readMessages(verbose); // Clear the measurement/notification pipes (without printing) before configuring.
  if (verbose)
  {
    Serial.println("Requesting device info...");
  }
  uint8_t reqProductCode[] = {0x1C, 0x00}; // reqProductCode Xbus message
  sendMessage(reqProductCode, sizeof(reqProductCode), verbose);
  delay(100);

  readMessages(verbose);

  uint8_t reqFWRev[] = {0x12, 0x00}; // reqFWRev Xbus message
  sendMessage(reqFWRev, sizeof(reqFWRev), verbose);
  delay(100);

  readMessages(verbose);
}

void MTi::goToConfig(bool verbose)
{
  Serial.println("Entering configuration mode.");
  uint8_t goToConfig[] = {0x30, 0x00}; // goToConfig Xbus message
  sendMessage(goToConfig, sizeof(goToConfig), verbose);
  delay(100);
  readMessages(verbose);
}

void MTi::goToMeasurement(bool verbose)
{
  Serial.println("Entering measurement mode.");
  uint8_t goToMeas[] = {0x10, 0x00}; // goToMeasurement Xbus message
  sendMessage(goToMeas, sizeof(goToMeas), verbose);
  delay(100);
  readMessages(verbose);
}

void MTi::sendMessage(uint8_t *message, uint8_t numBytes, bool verbose)
{
  // Compute the checksum for the Xbus message to be sent. See https://mtidocs.xsens.com/messages for details.
  uint8_t checksum = 0x01;
  for (int i = 0; i < numBytes; i++)
  {
    checksum -= message[i];
  }
  message[numBytes] = checksum; // Add the checksum at the end of the Xbus message
  if (verbose)
  {
    Serial.print("writing: ");
    for (int i = 0; i < numBytes + 1; i++)
    {
      Serial.print(message[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
  Wire1.beginTransmission(address_);
  Wire1.write(XSENS_CONTROL_PIPE); // Send the opcode before sending the Xbus command
  Wire1.write(message, numBytes + 1);
  Wire1.endTransmission(true);
  readMessages(verbose);
}

void MTi::readMessages(bool verbose)
{ // read new messages until measurement/notification pipes are empty
  while (digitalRead(drdy_))
  {
    xbus.read(address_, true);
  }
}

void MTi::printData()
{
  if (!isnan(getAcceleration()[0]))
  { // Only true if this data has been received once before
    Serial.println("Acceleration [m/s^2]:");
    for (int i = 0; i < 3; ++i)
    {
      Serial.print(getAcceleration()[i]); // Print the last read value
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  if (!isnan(getRateOfTurn()[0]))
  { // Only true if this data has been received once before
    Serial.println("Rate Of Turn [deg/s]:");
    for (int i = 0; i < 3; ++i)
    {
      Serial.print(getRateOfTurn()[i] * 180 / PI); // Print the last read value
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  if (!isnan(getQuat()[0]))
  { // Only true if this data has been received once before
    Serial.println("Quaternion:");
    for (int i = 0; i < 4; ++i)
    {
      Serial.print(getQuat()[i]); // Print the last read value
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  if (!isnan(getMag()[0]))
  { // Only true if this data has been received once before
    Serial.println("Magnetic Field [au]:");
    for (int i = 0; i < 3; ++i)
    {
      Serial.print(getMag()[i]); // Print the last read value
      Serial.print(" ");
    }
    Serial.println(" ");
  }
}
