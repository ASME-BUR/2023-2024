#include "MTi.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <pigpiod_if2.h>
using namespace std;

MTi::MTi(int pigpio_id, uint8_t I2C_ADDR, uint8_t I2C_BUS) : xbus(pigpio_id, I2C_ADDR, I2C_BUS)
{
  if (pigpio_id < 0)
  {
    cout << "pigpio failed to start" << endl;
  }
  pi = pigpio_id;
  handle_ = getHandle();
}

MTi::MTi(uint8_t I2C_ADDR, uint8_t I2C_BUS) : xbus(I2C_ADDR, I2C_BUS)
{
  cout << "Need to run setPi() to get pigpio_id" << endl;
}

void MTi::setPi(int pigpio_id)
{
  if (pigpio_id < 0)
  {
    cout << "pigpio failed to start" << endl;
  }
  pi = pigpio_id;
  xbus.setPi(pi);
  handle_ = getHandle();
}

MTi::~MTi()
{
  xbus.~Xbus();
  cout << "destructing imu" << endl;
}

/*
--------------------------------------------------------------------------------------------------------------------
*************************************Public Methods****************************************************************
--------------------------------------------------------------------------------------------------------------------
*/

bool MTi::detect(uint16_t timeout)
{
  // Send goToConfig messages until goToConfigAck is received from the device
  cout << "Scanning for MTi." << endl;
  auto start = chrono::steady_clock::now();
  while (chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() < timeout)
  {
    goToConfig();
    readMessages();
    if (xbus.configState)
    {
      cout << "Device detected." << endl;
      return true;
    }
  }
  cout << "Failed to detect device." << endl;
  return false;
}

void MTi::reset()
{
  cout << "resetting" << endl;
  char reset[4] = {XSENS_CONTROL_PIPE, 0x40, 0x00, 0x00}; // goToConfig Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(reset, sizeof(reset));
  readMessages();
  this_thread::sleep_for(chrono::milliseconds(2000));
  readMessages();
}

void MTi::goToConfig()
{
  cout << "Entering configuration mode." << endl;
  char goToConfig[4] = {XSENS_CONTROL_PIPE, 0x30, 0x00, 0x00}; // goToConfig Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(goToConfig, sizeof(goToConfig));
  for (int i = 0; i < 20; i++)
  {
    if (readMessages() == xbus.GOTOCONFIGACK)
    {
      break;
    }
  }
  // readMessages();
}

void MTi::requestDeviceInfo()
{
  // Request device info from the MTi using Xbus commands. Refer to the MT Low Level Communication Protocol Document for more information on the commands used here:
  // https://mtidocs.xsens.com/mt-low-level-communication-protocol-documentation

  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Requesting device info..." << endl;

  char reqFWRev[4] = {XSENS_CONTROL_PIPE, 0x12, 0x00, 0x00}; // reqFWRev Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(reqFWRev, sizeof(reqFWRev));
  // clear pipe
  readMessages();

  char reqProductCode[4] = {XSENS_CONTROL_PIPE, 0x1C, 0x00, 0x00}; // reqProductCode Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(reqProductCode, sizeof(reqProductCode));
  // clear pipe
  readMessages();
}

void MTi::runSelfTest()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Running self-test..." << endl;
  char runSelfTest[4] = {XSENS_CONTROL_PIPE, 0x24, 0x00, 0x00}; // reqFWRev Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(runSelfTest, sizeof(runSelfTest));
  // clear pipe
  while (readMessages() != xbus.SELFTESTRESULTS)
    ;
  // readMessages();
}

void MTi::restoreFactoryDefaults()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Restoring factory defaults..." << endl;
  char restore[4] = {XSENS_CONTROL_PIPE, 0x0E, 0x00, 0x00}; // reqFWRev Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(restore, sizeof(restore));
  // clear pipe
  while (readMessages() != xbus.WAKEUP)
    ;
  // readMessages();
}

// Option Flags Settings
void MTi::disableAutoMeas()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Disabling Auto Measurement" << endl;
  char optionFlag[12] = {XSENS_CONTROL_PIPE, 0x48, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00};
  readMessages();
  sendMessage(optionFlag, sizeof(optionFlag));
  readMessages();
}

void MTi::enableICC()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Disabling Auto Measurement" << endl;
  uint8_t optionFlag[12] = {XSENS_CONTROL_PIPE, 0x48, 0x08, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00};
  char *optionFlag_char;
  optionFlag_char = (char *)optionFlag;
  readMessages();
  sendMessage(optionFlag_char, sizeof(optionFlag));
  readMessages();
}

void MTi::getOptionFlags()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Getting option flags" << endl;
  char optionFlag[4] = {XSENS_CONTROL_PIPE, 0x48, 0x00, 0x00};
  readMessages();
  sendMessage(optionFlag, sizeof(optionFlag));
  readMessages();
}

void MTi::resetOrientation()
{
  cout << "Resetting orientation" << endl;
  uint8_t reset[6] = {XSENS_CONTROL_PIPE, 0xA4, 0x02, 0x00, 0x03, 0x00};
  char *reset_char = (char *)reset;
  readMessages();
  sendMessage(reset_char, sizeof(reset));
  readMessages();
}

void MTi::enableAHS()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Enabling AHS" << endl;
  uint8_t optionFlag[12] = {XSENS_CONTROL_PIPE, 0x48, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
  char *optionFlag_char;
  optionFlag_char = (char *)optionFlag;
  readMessages();
  sendMessage(optionFlag_char, sizeof(optionFlag));
  readMessages();
}

// Compass Calibration Commands
void MTi::startICC()
{
  if (xbus.configState)
  {
    goToMeasurement();
  }
  cout << "Starting In-run Compass Calibration" << endl;
  cout << "Make sure there are no magnets nearby!" << endl;
  char msg[5] = {XSENS_CONTROL_PIPE, 0x74, 0x01, 0x00, 0x00};
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(msg, sizeof(msg));
  readMessages();
}

void MTi::stopICC()
{
  if (xbus.configState)
  {
    goToMeasurement();
  }
  cout << "Stopping In-run Compass Calibration" << endl;
  char msg[5] = {XSENS_CONTROL_PIPE, 0x74, 0x01, 0x01, 0x00};
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(msg, sizeof(msg));
  readMessages();
}

void MTi::storeICC()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  cout << "Storing In-run Compass Calibration" << endl;
  char msg[5] = {XSENS_CONTROL_PIPE, 0x74, 0x01, 0x02, 0x00};
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(msg, sizeof(msg));
  readMessages();
}

void MTi::getRepMo()
{
  if (xbus.configState)
  {
    goToMeasurement();
  }
  cout << "Getting current Representative Motion state" << endl;
  char msg[5] = {XSENS_CONTROL_PIPE, 0x74, 0x01, 0x03, 0x00};
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(msg, sizeof(msg));
  readMessages();
}

// Set Output
void MTi::requestOutputConfig()
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  uint8_t msg[4] = {XSENS_CONTROL_PIPE, 0xC0, 0x00, 0x00}; // setOutputConfiguration Xbus message with Data field 0x20 0x30 0x00 0x01 (EulerAngles, 32-bit float, at 1 Hz)
  cout << "Requesting Output Config" << endl;
  char *msg_char;
  msg_char = (char *)msg;
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(msg_char, sizeof(msg));
  readMessages();
}

void MTi::configureOutputs(const string mode[], const uint16_t hz[], int length_)
{
  if (!xbus.configState)
  {
    goToConfig();
  }
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();

  int length = length_;
  if (length_ > 32)
  {
    cout << "Too many data types, max is 32" << endl;
    length = 32;
  }
  uint8_t msg_size = (length * 4) + 4;
  char *outputConfig_char;
  vector<uint8_t> outputConfig;
  outputConfig.clear();
  outputConfig.push_back(XSENS_CONTROL_PIPE);
  outputConfig.push_back(0xC0);
  outputConfig.push_back(4 * length);

  for (int i = 0; i < length; i++)
  {
    uint8_t *data_type;
    uint8_t high = (uint8_t)((hz[i] & 0xFF00) >> 8);
    uint8_t low = (uint8_t)(hz[i] & 0x00FF);
    cout << "setting output to " << mode[i] << " at: " << dec << hz[i] << " hz" << endl;
    if (mode[i] == "QUATERNION")
    {
      if (hz[i] > 100)
      {
        cout << "Frequency too high! Max frequency is 100Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x20, 0x14, high, low};
      data_type = temp;
    }
    else if (mode[i] == "EULER")
    {
      if (hz[i] > 100)
      {
        cout << "Frequency too high! Max frequency is 100Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x20, 0x34, high, low};
      data_type = temp;
    }
    else if (mode[i] == "ACCELERATION")
    {
      if (hz[i] > 100)
      {
        cout << "Frequency too high! Max frequency is 100Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x40, 0x24, high, low};
      data_type = temp;
    }
    else if (mode[i] == "TEMPERATURE")
    {
      if (hz[i] > 1)
      {
        cout << "Frequency too high! Max frequency is 1Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x08, 0x10, high, low};
      data_type = temp;
    }
    else if (mode[i] == "RATEOFTURN")
    {
      if (hz[i] > 100)
      {
        cout << "Frequency too high! Max frequency is 100Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x80, 0x24, high, low};
      data_type = temp;
    }
    else if (mode[i] == "RATEOFTURNHR")
    {
      if (hz[i] > 100)
      {
        cout << "Frequency too high! Max frequency is 100Hz" << endl;
        high = 0xFF;
        low = 0xFF;
      }
      uint8_t temp[4] = {0x80, 0x44, high, low};
      data_type = temp;
    }
    else
    {
      cout << "Invalid Output Type!" << endl;
      return;
    }
    for (int i = 0; i < 4; i++)
    {
      outputConfig.insert(outputConfig.end(), data_type[i]);
    }
  }
  outputConfig.push_back(0x00);
  outputConfig_char = (char *)outputConfig.data();
  // for (int i = 0; i < outputConfig.size(); i++)
  // {
  //   cout << hex << int(outputConfig[i]) << " ";
  // }
  // cout << endl;

  // Clear the measurement/notification pipes (without printing) before configuring.
  // readMessages();
  for (int i = 0; i < 20; i++)
  {
    if (readMessages() == xbus.OUTPUTCONFIGURATION)
    {
      break;
    }
    sendMessage(outputConfig_char, msg_size);
  }
  // readMessages();
}

void MTi::goToMeasurement()
{
  cout << "Entering measurement mode." << endl;
  char goToMeas[4] = {XSENS_CONTROL_PIPE, 0x10, 0x00, 0x00}; // goToMeasurement Xbus message
  // Clear the measurement/notification pipes (without printing) before configuring.
  readMessages();
  sendMessage(goToMeas, sizeof(goToMeas));
  readMessages();
}

void MTi::printData()
{
  if (readMessages() == 1)
  {
    if (!isnan(getAcceleration()[0]))
    { // Only true if this data has been received once before
      cout << "Acceleration [m/s^2]:" << endl;
      for (int i = 0; i < 3; ++i)
      {
        cout << getAcceleration()[i] << endl; // Print the last read value
        cout << " " << endl;
      }
      cout << " " << endl;
    }
    if (!isnan(getRateOfTurn()[0]))
    { // Only true if this data has been received once before
      cout << "Rate Of Turn [deg/s]:" << endl;
      for (int i = 0; i < 3; ++i)
      {
        cout << getRateOfTurn()[i] * 180 / M_PI << endl; // Print the last read value
        cout << " " << endl;
      }
      cout << " " << endl;
    }
    if (!isnan(getEulerAngles()[0]))
    { // Only true if this data has been received once before
      cout << "Euler angles [deg]:" << endl;
      for (int i = 0; i < 3; ++i)
      {
        cout << getEulerAngles()[i] << endl; // Print the last read value
        cout << " " << endl;
      }
      cout << " " << endl;
    }
    if (!isnan(getQuat()[0]))
    {
      cout << "Quaternion:" << endl;
      for (int i = 0; i < 4; ++i)
      {
        cout << getQuat()[i] << endl; // Print the last read value
        cout << " " << endl;
      }
      cout << " " << endl;
    }
    if (!isnan(getTemp()[0]))
    {
      cout << "Temperature [C]:" << endl;
      cout << getTemp()[0] << endl; // Print the last read value
      cout << " " << endl;
      cout << " " << endl;
    }
    /*
    if (xbus.productCode == '7' | xbus.productCode == '8')
    { // MTi-7 or MTi-8 GNSS/INS
      cout << "Lat/Lon [deg]:" << endl;
      for (int i = 0; i < 2; ++i)
      {
        cout << (getLatLon()[i], 5) << endl; // Print the last read value. Will be "NaN" as long as there is no GNSS fix
        cout << " " << endl;
      }
      cout << " " << endl;
    }
    */
  }
}

void MTi::readData()
{
  xbus.read();
}

/*
--------------------------------------------------------------------------------------------------------------------
*************************************Private Methods****************************************************************
--------------------------------------------------------------------------------------------------------------------
*/
/*
// This method is not allowed under newer cpp versions
bool MTi::sendMessage(char *message, uint8_t numBytes)
{
  // Compute the checksum for the Xbus message to be sent. See https://mtidocs.xsens.com/messages for details.
  char message_cs[numBytes + 2] = {0};
  uint8_t checksum = 0x01;
  for (int i = 1; i < numBytes + 1; i++)
  {
    message_cs[i] = message[i - 1];
    checksum -= message[i - 1];
  }
  // insert the opcode before the Xbus command
  message_cs[0] = XSENS_CONTROL_PIPE;
  message_cs[numBytes + 1] = checksum; // Add the checksum at the end of the Xbus message

  // uint8_t *message_2;
  // message_2 = (uint8_t *)message_cs;
  // for (int i = 0; i < numBytes + 2; i++)
  // {
  //   cout << hex << (unsigned int)message_2[i] << " ";
  // }
  // cout << endl;
  readMessages();
  if (i2c_write_device(pi, handle_, message_cs, numBytes + 2) != 0)
  {
    this_thread::sleep_for(chrono::milliseconds(100));
    cout << "write failed" << endl;
    return (false);
  }
  return (true);
}
*/

bool MTi::sendMessage(char *message, uint8_t numBytes)
{
  // Compute the checksum for the Xbus message to be sent. See https://mtidocs.xsens.com/messages for details.
  uint8_t checksum = 0x01;
  for (int i = 1; i < numBytes; i++)
  {
    checksum -= message[i];
  }
  message[numBytes - 1] = checksum; // Add the checksum at the end of the Xbus message

  uint8_t *message_2;
  message_2 = (uint8_t *)message;
  cout << "Sending: ";
  for (int i = 0; i < numBytes; i++)
  {
    cout << hex << (int)message_2[i] << " ";
  }
  cout << endl;
  if (i2c_write_device(pi, handle_, message, numBytes) != 0)
  {
    cout << "Write failed: ";
    for (int i = 0; i < numBytes; i++)
    {
      cout << hex << (int)message[i] << " ";
    }
    cout << endl;
    return (false);
  }
  return (true);
}

uint8_t MTi::readMessages()
{
  uint8_t i = xbus.read();
  return (i);
}