/* Blue Robotics Arduino MS5837-30BA Pressure/Temperature Sensor Library
------------------------------------------------------------

Title: Blue Robotics Arduino MS5837-30BA Pressure/Temperature Sensor Library

Description: This library provides utilities to communicate with and to
read data from the Measurement Specialties MS5837-30BA pressure/temperature
sensor.

Authors: Rustom Jehangir, Blue Robotics Inc.
		 Adam Šimko, Blue Robotics Inc.

-------------------------------
The MIT License (MIT)

Copyright (c) 2015 Blue Robotics Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-------------------------------*/

#ifndef MS5837_H_BLUEROBOTICS
#define MS5837_H_BLUEROBOTICS

#include "pigpiod_if2.h"
#include <cmath>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

const uint8_t  MS5837_ADDR = 0x76;
const uint8_t  MS5837_RESET = 0x1E;
const uint8_t  MS5837_ADC_READ = 0x00;
const uint8_t  MS5837_PROM_READ = 0xA0;
const uint8_t  MS5837_CONVERT_D1_256 = 0x40;
const uint8_t  MS5837_CONVERT_D2_256 = 0x50;

// Oversampling options
const uint8_t OSR_256 = 0;
const uint8_t OSR_512 = 1;
const uint8_t OSR_1024 = 2;
const uint8_t OSR_2048 = 3;
const uint8_t OSR_4096 = 4;
const uint8_t OSR_8192 = 5;

const float UNITS_Pa     = 100.0;
const float UNITS_hPa    = 1.0;
const float UNITS_kPa    = 0.1;
const float UNITS_mbar   = 1.0;
const float UNITS_bar    = 0.001;
const float UNITS_atm    = 0.000986923;
const float UNITS_Torr   = 0.750062;
const float UNITS_psi    = 0.014503773773022;

// Valid units
const uint8_t UNITS_Centigrade = 1;
const uint8_t UNITS_Farenheit  = 2;
const uint8_t UNITS_Kelvin     = 3;

// kg/m^3 convenience
const float DENSITY_FRESHWATER = 997;
const float DENSITY_SALTWATER = 1029;

const uint8_t  MS5837_02BA01 = 0x00; // Sensor version: From MS5837_02BA datasheet Version PROM Word 0
const uint8_t  MS5837_02BA21 = 0x15; // Sensor version: From MS5837_02BA datasheet Version PROM Word 0
const uint8_t  MS5837_30BA26 = 0x1A; // Sensor version: From MS5837_30BA datasheet Version PROM Word 0

class MS5837
{
public:
	const uint8_t MS5837_30BA = 0;
	const uint8_t MS5837_02BA = 1;
	const uint8_t MS5837_UNRECOGNISED = 255;

	MS5837(int pigpio_id, uint8_t I2C_BUS=1, uint8_t I2C_ADDR=MS5837_ADDR);
	~MS5837();
	bool init();

	/** Set oversampling option. Valid options are 0, 1, 2, 3, 4, 5 (default)
	 */
	void setOSR(uint8_t OSR_);

	/** Set model of MS5837 sensor. Valid options are MS5837::MS5837_30BA (default)
	 * and MS5837::MS5837_02BA.
	 */
	void setModel(uint8_t model);
	uint8_t getModel();

	/** Provide the density of the working fluid in kg/m^3. Default is for
	 * seawater. Should be 997 for freshwater.
	 */
	void setFluidDensity(float density);

	/** The read from I2C takes up to 40 ms, so use sparingly is possible.
	 */
	void read();

	/** Pressure returned in mbar or mbar*conversion rate.
	 */
	float pressure(float conversion = UNITS_mbar);

	/** Temperature returned in deg C.
	 */
	float temperature(float conversion = UNITS_Centigrade);

	/** Depth returned in meters (valid for operation in incompressible
	 *  liquids only. Uses density that is set for fresh or seawater.
	 */
	float depth();

	/** Altitude returned in meters (valid for operation in air only).
	 */
	float altitude();

private:
	uint16_t PROMresult[8];
	uint32_t D1_pres, D2_temp;
	int32_t TEMP;
	int32_t P;
	char _model;
	int handle;
	int pi;
	uint8_t OSR = 0;

	float fluidDensity;

	/** Performs calculations per the sensor data sheet for conversion and
	 *  second order compensation.
	 */
	void calculate();
	bool write(uint8_t msg);
	uint8_t crc4(uint16_t n_prom[]);
};

#endif
