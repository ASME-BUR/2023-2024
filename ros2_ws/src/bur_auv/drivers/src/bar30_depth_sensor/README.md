# MS5837 Library

Raspi library for the MS5837 pressure sensor. The MS5837 is a tiny SMT pressures sensor from Measurement Specialties that can measure pressure of up to 30 Bar (300m depth) with resolution of 0.2 mbar.

This library also supports the MS5837-02BA which has a much smaller measurement range and is better suited for altitude measurement in air.

# Documentation

More info in the [wiki](https://git.whoi.edu/mural/drivers/bar30_depth_sensor/-/wikis/home)

Please see the examples for normal operation. Below are the available functions used in the library.

``` cpp
    MS5837(int pigpio_id, uint8_t I2C_BUS=1, uint8_t I2C_ADDR=MS5837_ADDR);
	~MS5837();
	bool init();

	/** Set oversampling option. Valid options are 0, 1, 2, 3, 4, 5(default)
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

```

# Reference

- You can find the [MS5837-30BA datasheet here](http://www.mouser.com/ds/2/418/MS5837-30BA-736494.pdf).
- Original Bluerobotics Arduino Library [here](https://github.com/bluerobotics/BlueRobotics_MS5837_Library)
- Original Bluerobotics Raspberry Pi Library using SMbus [here](https://github.com/bluerobotics/ms5837-python)