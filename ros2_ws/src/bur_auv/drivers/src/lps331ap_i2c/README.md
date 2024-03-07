# Raspberry Pi C++ library for Pololu LPS331AP pressure sensor boards

[www.pololu.com](https://www.pololu.com/product/2126/resources)


## Summary

This library is based on the Arduino library for the LPS Pololu sensors found [here](https://github.com/pololu/lps-arduino) 

* [Pololu LPS331AP pressure/altitude sensor carrier](https://www.pololu.com/catalog/product/2126)


The library also provides functions to help calculate altitude based
on the measured pressure.


## Getting started

### Hardware

A LPS carrier can be purchased from Pololu's website. Before
continuing, careful reading of the product page as well as the chip
datasheet is recommended.

Make the following connections with wires between the Arduino and the
LPS board:


### Software

If you are using version 1.6.2 or later of the
[Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use
the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then
   "Manage Libraries...".
2. Search for "LPS".
3. Click the LPS entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pololu/lps-arduino/releases)
   and decompress it.
2. Rename the folder "lps-arduino-xxxx" to "LPS".
3. Drag the "LPS" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Examples

Several example sketches are available that show how to use the
library. You can access them from the Arduino IDE by opening the
"File" menu, selecting "Examples", and then selecting "LPS". If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.


## Library reference

- `bool init(deviceType device, byte sa0)` <br> Initializes the library with the
  device being used (`LPS::device_331AP`, `LPS::device_25H`, `LPS::device_22DF`,
  or `LPS::device_auto`) and the state of the SA0 pin (`LPS::sa0_low`,
  `LPS::sa0_high`, or `LPS::sa0_auto`; `LOW` or `HIGH` also work), which
  determines the least significant bit of the sensor's address. Both of these
  arguments are optional; if they are not specified, the library will try to
  automatically detect the device and address. The return value is a boolean
  indicating whether a device was successfully detected.
- `deviceType getDeviceType(void)` <br> Returns the device type
  detected by `init()`.
- `byte getAddress(void)` <br> Returns the address detected by
  `init()`.
- `void enableDefault(void)` <br> Turns on the pressure sensor in a
  default configuration that gives continuous output at 10 Hz or 12.5 Hz.
- `void writeReg(int reg, byte value)` <br> Writes a pressure sensor
  register with the given value. Register addresses are defined by the
  regAddr enumeration type in LPS.h.  Example use:
  `ps.writeReg(LPS::CTRL_REG1, 0xE0);`
- `byte readReg(int reg)` <br> Reads a pressure sensor register and
  returns the value read.
- `float readPressureMillibars(void)` <br> Returns a pressure reading
  from the sensor in units of millibars (mbar)/hectopascals (hPa).
- `float readPressureInchesHg(void)` <br> Returns a pressure reading
  from the sensor in units of inches of mercury (inHg).
- `long readPressureRaw(void)` <br> Returns a raw 24-bit pressure
  reading from the sensor.
- `float readTemperatureC(void)` <br> Returns a temperature reading
  from the sensor in units of degrees Celsius.
- `float readTemperatureF(void)` <br> Returns a temperature reading
  from the sensor in units of degrees Fahrenheit.
- `int readTemperatureRaw(void)` <br> Returns a raw 16-bit temperature
  reading from the sensor.
- `float pressureToAltitudeMeters(float pressure_mbar, float
  altimeter_setting_mbar)` <br> Converts a pressure in mbar to an
  altitude in meters, using the 1976
  [U.S. Standard Atmosphere](https://en.wikipedia.org/wiki/U.S._Standard_Atmosphere)
  model (note that this formula only applies up to an altitude of 11
  km, or about 36000 ft). If the optional `altimeter_setting_mbar`
  argument is given, specifying an "altimeter setting" or "QNH"
  (barometric pressure adjusted to sea level, often used in aviation
  and obtained from a local weather monitoring station), this function
  returns an indicated altitude compensated for the actual regional
  pressure. Otherwise, it returns a pressure altitude above the
  standard pressure level of 1013.25 mbar (29.9213 inHg).
- `float pressureToAltitudeFeet(float pressure_inHg, float
  altimeter_setting_inHg)` <br> Converts a pressure in inHg to an
  altitude in feet. See the preceding description of
  `pressureToAltitudeMeters()` for details.


## Version history

* 3.1.0 (2023-06-08): Added support for LPS22DF.
* 3.0.1 (2022-08-31): Fixed a compile error on the ESP8266.
* 3.0.0 (2016-08-17): Updated library to work with the Arduino Library Manager.
* 2.0.0 (2014-06-03): Major rewrite. List of significant changes:
   * Renamed library to LPS.
   * Added support for LPS25H and automatic detection of device type.
   * Library constants converted to enums.
* 1.0.1 (2014-01-08): Changed raw output byte combination logic to work properly on 32-bit microcontrollers and be more portable.
* 1.0.0 (2013-03-22): Original release of LPS331 library.
