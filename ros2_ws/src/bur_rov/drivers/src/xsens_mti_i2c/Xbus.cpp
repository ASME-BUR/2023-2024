#include "Xbus.h"

Xbus::Xbus(int pigpio_id, uint8_t I2C_ADDR, uint8_t I2C_BUS)
{
  pi = pigpio_id;
  I2C_ADDR_ = I2C_ADDR;
  I2C_BUS_ = I2C_BUS;
  // Open i2c port
  handle = i2c_open(pi, I2C_BUS, I2C_ADDR, 0);
  if (handle < 0)
  {
    cout << "Can't open I2C Bus" << endl;
  }
  else
  {
    cout << "I2C Bus Opened" << endl;
  }
}

Xbus::Xbus(uint8_t I2C_ADDR, uint8_t I2C_BUS)
{
  I2C_ADDR_ = I2C_ADDR;
  I2C_BUS_ = I2C_BUS;
  cout << "Need to run setPi to get pigpio_id" << endl;
}

void Xbus::setPi(int pigpio_id)
{
  pi = pigpio_id;
  // Open i2c port
  handle = i2c_open(pi, I2C_BUS_, I2C_ADDR_, 0);
  if (handle < 0)
  {
    cout << "Can't open I2C Bus" << endl;
  }
}

Xbus::~Xbus()
{
  cout << "closing i2c line" << endl;
  i2c_close(pi, handle);
}

uint8_t Xbus::read()
{
  uint8_t message = 0xFF;
  readPipeStatus();
  if (notificationSize > 0)
  { // New notification message available to be read
    readPipeNotif();
    message = parseNotification(datanotif);
  }
  if (measurementSize > 0)
  { // New measurement packet available to be read
    readPipeMeas();
    parseMTData2(datameas, measurementSize);
    message = 1; // Return true if new measurements were read
  }
  return (message);
}

void Xbus::readPipeStatus()
{
  i2c_write_byte(pi, handle, XSENS_STATUS_PIPE);
  i2c_read_i2c_block_data(pi, handle, XSENS_STATUS_PIPE, status, 4);
  notificationSize = (uint16_t)status[0] | ((uint16_t)status[1] << 8);
  measurementSize = (uint16_t)status[2] | ((uint16_t)status[3] << 8);

  // Uncomment to see notif and meas size
  if (notificationSize || measurementSize)
  {
    cout << "notif: " << dec << int(notificationSize) << " ";
    cout << "meas: " << dec << int(measurementSize) << endl;
  }
}

void Xbus::readPipeNotif()
{
  i2c_write_byte(pi, handle, XSENS_NOTIF_PIPE);
  i2c_read_device(pi, handle, datanotif, notificationSize);
  if (notificationSize <= 256)
  {
    // Uncomment to see hex values of data notif
    uint8_t *datanotif_2;
    datanotif_2 = (uint8_t *)datanotif;
    cout << "datanotif: ";
    for (int i = 0; i < notificationSize; i++)
    {
      cout << hex << (int)datanotif_2[i] << " ";
    }
    cout << endl;
  }
}

void Xbus::readPipeMeas()
{
  i2c_write_byte(pi, handle, XSENS_MEAS_PIPE);
  i2c_read_device(pi, handle, datameas, measurementSize); 
  if (measurementSize <= 256)
  {
    // Uncomment to read datameas
    uint8_t *datameas_2;
    datameas_2 = (uint8_t *)datameas;
    cout << "datameas: ";
    for (int i = 0; i < measurementSize; i++)
    {
      cout << hex << (int)datameas_2[i] << " ";
    }
    cout << endl;
  }
}

uint8_t Xbus::parseNotification(char *notif)
{ // Parse the most common notification messages
  uint8_t notifID = notif[0];
  switch (notifID)
  {
  case (uint8_t)MesID::WAKEUP:
  {
    cout << "Received WakeUp message." << endl;
    wakeState = true;
    return (WAKEUP);
  }
  case (uint8_t)MesID::RESET:
  {
    cout << "Received Reset Command." << endl;
    return (RESET);
  }
  case (uint8_t)MesID::ERROR:
  {
    cout << "Received an error with code: ";
    cout << hex << int(notif[2]) << endl;
    return (ERROR);
  }
  case (uint8_t)MesID::WARNING:
  {
    uint32_t warn = (uint32_t)notif[5] | ((uint32_t)notif[4] << 8);
    cout << "Received a warning with code: ";
    cout << warn << endl;
    return (WARNING);
  }
  case (uint8_t)MesID::PRODUCTCODE:
  {
    cout << "Product code is: ";
    for (int i = 2; i < notificationSize - 1; i++)
    {
      cout << char(notif[i]);
    }
    cout << endl;
    productCode = notif[6]; // Store the product code (MTi-#) for later usage
    return (PRODUCTCODE);
  }
  case (uint8_t)MesID::FIRMWAREREV:
  {
    cout << "Firmware version is: ";
    cout << dec << int(notif[2]);
    cout << ".";
    cout << dec << int(notif[3]);
    cout << ".";
    cout << dec << int(notif[4]) << endl;
    return (FIRMWAREREV);
  }
  case (uint8_t)MesID::GOTOCONFIGACK:
  {
    cout << "Received GoToConfigACK." << endl;
    configState = true;
    return (GOTOCONFIGACK);
  }
  case (uint8_t)MesID::GOTOMEASUREMENTACK:
  {
    cout << "Received GoToMeasurementACK." << endl;
    configState = false;
    return (GOTOMEASUREMENTACK);
  }
  case (uint8_t)MesID::OUTPUTCONFIGURATION:
  {
    cout << "Received OutputConfigurationACK." << endl;
    return (OUTPUTCONFIGURATION);
  }
  case (uint8_t)MesID::OPTIONFLAG:
  {
    cout << "Received OptionFlagACK." << endl;
    return (OPTIONFLAG);
  }
  case (uint8_t)MesID::RESTOREFACTORYDEFAUTS:
  {
    cout << "Received RestoreFactoryDefaultsACK." << endl;
    return (RESTOREFACTORYDEFAUTS);
  }
  case (uint8_t)MesID::ICCCOMANDACK:
  {
    cout << "Received ICCCommandACK." << endl;
    for (uint64_t i = 0; i < sizeof(notif); i++)
    {
      cout << hex << int(notif[2]) << " ";
    }
    cout << endl;
    return (ICCCOMANDACK);
  }
  case (uint8_t)MesID::SELFTESTRESULTS:
  {
    cout << "Received Self Test Results" << endl;
    return (SELFTESTRESULTS);
  }
  default:
  {
    cout << "Received undefined notification: " << endl;
    return (0);
  }
  }
}

void Xbus::parseMTData2(char *data, uint8_t datalength)
{
  if (datalength < 2) // Reached the end of the MTData2 message
    return;

  uint8_t XDI = data[0]; // Xsens Data Identifier
  if (XDI == (uint8_t)MesID::MTDATA2)
  { // Start of the MTData2 message
    char length = data[1];
    parseMTData2(data + 2, length);
  }
  else
  {
    char length = data[2];
    uint16_t temp = ((uint16_t)data[1] | ((uint16_t)data[0] << 8)) & (uint16_t)0xFFFF;
    // cout << hex << int(temp) << endl;
    switch (temp)
    { // Extract the 2-byte Xsens Data Identifier
    case (uint16_t)DataID::EULERANGLES:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(euler, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::QUATERNION:
      dataswapendian(data + 3, sizeof(float) * 4);
      memcpy(quat, data + 3, sizeof(float) * 4);
      break;
    case (uint16_t)DataID::ACCELERATION:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(acc, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::RATEOFTURNHR:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(rot, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::RATEOFTURN:
      dataswapendian(data + 3, sizeof(float) * 3);
      memcpy(rot, data + 3, sizeof(float) * 3);
      break;
    case (uint16_t)DataID::TEMPERATURE:
      dataswapendian(data + 3, sizeof(float));
      memcpy(temperature, data + 3, sizeof(float));
      break;
    default:
      break;
    }
    parseMTData2(data + length + 3, datalength - length - 3); // Move onto next data element within MTData2 packet
  }
}

void Xbus::dataswapendian(char *data, const uint8_t length)
{ // Swap the endianness of the data such that the float value can be printed

  // creating arrays w/o set dimensions isn't recommended under C11 standards
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
