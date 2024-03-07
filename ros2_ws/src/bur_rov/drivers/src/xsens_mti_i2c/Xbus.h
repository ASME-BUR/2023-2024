#ifndef XBUS_H
#define XBUS_H
#include <pigpiod_if2.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

// Definition of opcodes: For more information on opcodes, refer to https://mtidocs.xsens.com/functional-description$mtssp-synchronous-serial-protocol
#define XSENS_CONTROL_PIPE 0x03 // Use this opcode for sending (configuration) commands to the MTi
#define XSENS_STATUS_PIPE 0x04  // Use this opcode for reading the status of the notification/measurement pipes
#define XSENS_NOTIF_PIPE 0x05   // Use this opcode for reading a notification message
#define XSENS_MEAS_PIPE 0x06    // Use this opcode for reading measurement data (MTData2 message)

class Xbus
{
public:
  Xbus(int pigpio_id, uint8_t I2C_ADDR, uint8_t I2C_BUS);
  Xbus(uint8_t I2C_ADDR, uint8_t I2C_BUS);
  void setPi(int pigpio_id);
  // Closes I2C line
  ~Xbus();
  // Reads pipes and outputs message codes, 1 for data message, or 0xFF (255) for nothing
  uint8_t read();
  void readPipeStatus();
  void readPipeNotif();
  void readPipeMeas();
  void parseMTData2(char *data, const uint8_t datalength);
  uint8_t parseNotification(char *data);
  // Swap the endianness of the data such that the float value can be printed
  void dataswapendian(char *data, uint8_t length);
  
  // Acknowledgement Codes
  enum MesID
  {
    WAKEUP = 0x3E,
    GOTOCONFIGACK = 0x31,
    GOTOMEASUREMENTACK = 0x11,
    REQDID = 0x00,
    DEVICEID = 0x01,
    REQPRODUCTCODE = 0x1C,
    PRODUCTCODE = 0x1D,
    REQFWREV = 0x12,
    FIRMWAREREV = 0x13,
    ERROR = 0x42,
    WARNING = 0x43,
    OUTPUTCONFIGURATION = 0xC1,
    MTDATA2 = 0x36,
    RESET = 0x40,
    OPTIONFLAG = 0x49,
    RESTOREFACTORYDEFAUTS = 0x15,
    ICCCOMANDACK = 0x75,
    SELFTESTRESULTS = 0x25,
  };

  // Data codes, default system is Single precision IEEE 32-bit floating point number with
  // North-East-Down coordinates
  enum DataID
  {
    TEMPERATURE = 0x0810,
    UTC_TIME = 0x1010,
    PACKET_COUNTER = 0x1020,
    SAMPLE_TIME_FINE = 0x1060,
    SAMPLE_TIME_COARSE = 0x1070,
    QUATERNION = 0x2014,
    ROTATION_MATRIX = 0x2024,
    EULERANGLES = 0x2034,
    DELTA_V = 0x4014,
    ACCELERATION = 0x4024,
    FREE_ACCELERATION = 0x4034,
    ACCELERATION_HR = 0x4044,
    RATEOFTURN = 0x8024,
    DELTA_Q = 0x8034,
    RATEOFTURNHR = 0x8044,
    MAGNETIC_FIELD = 0xC024,
  };

  float euler[3] = {NAN}; // Used to store latest EulerAngle reading
  float acc[3] = {NAN};   // Used to store latest Acceleration reading
  float rot[3] = {NAN};   // Used to store latest RateOfTurn reading
  float quat[4] = {NAN};  // Used to store Quaternion reading
  float rot_matrix[9] = {NAN}; // Used to store rotation matrix
  float temperature[1] = {NAN}; // Used to store Temperature reading

  bool configState = false; // True if MTi is in Config mode, false if MTi is in Measurement mode
  char productCode = 3;     // Contains the product code (MTi-#) of the connected device
  bool wakeState = false;

  int pi;     // holds the pigpio_id
  int handle; // holds the i2c line handle for pigpio commands
  uint8_t I2C_ADDR_;
  uint8_t I2C_BUS_;

private:
  char status[4];      // Used to store indicators of the Status Pipe
  char datanotif[256]; // Used to store content read from the Notification Pipe
  char datameas[256];  // Used to store content read from the Measurement Pipe
  uint16_t notificationSize;
  uint16_t measurementSize;
};

#endif
