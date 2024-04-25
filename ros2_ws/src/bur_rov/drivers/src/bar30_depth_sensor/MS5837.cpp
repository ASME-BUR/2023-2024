#include "MS5837.h"

MS5837::MS5837(int pigpio_id, uint8_t I2C_BUS, uint8_t I2C_ADDR)
{
	pi = pigpio_id;
	handle = i2c_open(pi, I2C_BUS, I2C_ADDR, 0);
	if (handle < 0)
	{
		cout << handle << "Failed to open i2c line" << endl;
		return;
	}
	setOSR(5);
	setFluidDensity(DENSITY_FRESHWATER);
}

MS5837::~MS5837()
{
	cout << "destructing" << endl;
	i2c_close(pi, handle);
}

bool MS5837::init()
{
	// Reset the MS5837, per datasheet
	while (!write(MS5837_RESET))
		;

	// Wait for reset to complete
	this_thread::sleep_for(chrono::milliseconds(1000));
	// Read calibration values and Cyclic Reduncdancy Check (CRC)
	// CRC checks data validity
	uint16_t temp;
	for (int i = 0; i < 7; i++)
	{
		temp = i2c_read_word_data(pi, handle, MS5837_PROM_READ + i * 2);
		PROMresult[i] = ((temp & 0x00FF) << 8) | (temp >> 8);
	}
	// Verify that data is correct with CRC
	uint8_t crcRead = (PROMresult[0] & 0xF000) >> 12;
	uint8_t crcCalculated = crc4(PROMresult);

	if (crcCalculated != crcRead)
	{
		cout << "CRC fail" << endl;
		return false; // CRC fail
	}
	uint8_t version = (PROMresult[0] >> 11) & 0x7F; // Extract the sensor version from PROM Word 0
	// Set _model according to the sensor version
	if (version == MS5837_02BA01)
	{
		cout << "version: MS5837_02BA01" << endl;
		_model = MS5837_02BA;
	}
	else if (version == MS5837_02BA21)
	{
		cout << "version: MS5837_02BA21" << endl;
		_model = MS5837_02BA;
	}
	else if (version == MS5837_30BA26)
	{
		cout << "version: MS5837_30BA26" << endl;
		_model = MS5837_30BA;
	}
	else
	{
		_model = MS5837_UNRECOGNISED;
	}
	// The sensor has passed the CRC check, so we should return true even if
	// the sensor version is unrecognised.
	// (The MS5637 has the same address as the MS5837 and will also pass the CRC check)
	// (but will hopefully be unrecognised.)
	return true;
}

void MS5837::setModel(uint8_t model)
{
	_model = model;
}

uint8_t MS5837::getModel()
{
	return (_model);
}

void MS5837::setOSR(uint8_t OSR_)
{
	if (OSR_ > 5)
	{
		cout << "Invalid OSR" << endl;
	}
	else
	{
		OSR = OSR_;
	}
}

void MS5837::setFluidDensity(float density)
{
	fluidDensity = density;
}

void MS5837::read()
{
	// Request D1 conversion
	while (!write(MS5837_CONVERT_D1_256 + (2 * OSR)))
	{
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	// float time = get_current_tick(pi) / (1e6);
	// Maximum conversion time increases linearly with oversampling
	// max time (seconds) ~= 2.2e-6(x) where x = OSR = (2^8, 2^9, ..., 2^13)
	// We use 2.5e-6 for some overhead
	this_thread::sleep_for(chrono::microseconds(int(2.5 * pow(2, (8 + OSR)))));

	D1_pres = 0;
	char p_buff[3];
	while (i2c_read_i2c_block_data(pi, handle, MS5837_ADC_READ, p_buff, 3) < 0)
		;

	// time = get_current_tick(pi) / (1e6) - time;
	// cout << "that took: " << dec << time << " sec" << endl;
	uint8_t *p_buff_int = (uint8_t *)p_buff;
	D1_pres = p_buff_int[0] << 16 | p_buff_int[1] << 8 | p_buff_int[2];

	// Request D2 conversion
	while (!write(MS5837_CONVERT_D2_256 + (2 * OSR)))
	{
		this_thread::sleep_for(chrono::milliseconds(100));
	}

	this_thread::sleep_for(chrono::microseconds(int(2.5 * pow(2, (8 + OSR)))));

	D2_temp = 0;
	char t_buff[3];
	while (i2c_read_i2c_block_data(pi, handle, MS5837_ADC_READ, t_buff, 3) < 0)
		;

	uint8_t *t_buff_int = (uint8_t *)t_buff;
	D2_temp = t_buff_int[0] << 16 | t_buff_int[1] << 8 | t_buff_int[2];
	calculate();
}

void MS5837::calculate()
{
	// Given C1-C6 and D1, D2, calculated TEMP and P
	// Do conversion first and then second order temp compensation

	int32_t dT = 0;
	int64_t SENS = 0;
	int64_t OFF = 0;
	int32_t SENSi = 0;
	int32_t OFFi = 0;
	int32_t Ti = 0;
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;
	// Terms called
	dT = D2_temp - uint32_t(PROMresult[5]) * 256l;
	if (_model == MS5837_02BA)
	{
		SENS = int64_t(PROMresult[1]) * 65536l + (int64_t(PROMresult[3]) * dT) / 128l;
		OFF = int64_t(PROMresult[2]) * 131072l + (int64_t(PROMresult[4]) * dT) / 64l;
		P = (D1_pres * SENS / (2097152l) - OFF) / (32768l);
	}
	else
	{
		SENS = int64_t(PROMresult[1]) * 32768l + (int64_t(PROMresult[3]) * dT) / 256l;
		OFF = int64_t(PROMresult[2]) * 65536l + (int64_t(PROMresult[4]) * dT) / 128l;
		P = (D1_pres * SENS / (2097152l) - OFF) / (8192l);
	}

	// Temp conversion
	TEMP = 2000l + int64_t(dT) * PROMresult[6] / 8388608LL;
	// Second order compensation
	if (_model == MS5837_02BA)
	{
		if ((TEMP / 100) < 20)
		{ // Low temp
			Ti = (11 * int64_t(dT) * int64_t(dT)) / (34359738368LL);
			OFFi = (31 * (TEMP - 2000) * (TEMP - 2000)) / 8;
			SENSi = (63 * (TEMP - 2000) * (TEMP - 2000)) / 32;
		}
	}
	else
	{
		if ((TEMP / 100) < 20)
		{ // Low temp
			Ti = (3 * int64_t(dT) * int64_t(dT)) / (8589934592LL);
			OFFi = (3 * (TEMP - 2000) * (TEMP - 2000)) / 2;
			SENSi = (5 * (TEMP - 2000) * (TEMP - 2000)) / 8;
			if ((TEMP / 100) < -15)
			{ // Very low temp
				OFFi = OFFi + 7 * (TEMP + 1500l) * (TEMP + 1500l);
				SENSi = SENSi + 4 * (TEMP + 1500l) * (TEMP + 1500l);
			}
		}
		else if ((TEMP / 100) >= 20)
		{ // High temp
			Ti = 2 * (dT * dT) / (137438953472LL);
			OFFi = (1 * (TEMP - 2000) * (TEMP - 2000)) / 16;
			SENSi = 0;
		}
	}
	OFF2 = OFF - OFFi; // Calculate pressure and temp second order
	SENS2 = SENS - SENSi;

	TEMP = (TEMP - Ti);

	if (_model == MS5837_02BA)
	{
		P = (((D1_pres * SENS2) / 2097152l - OFF2) / 32768l);
	}
	else
	{
		P = (((D1_pres * SENS2) / 2097152l - OFF2) / 8192l);
	}
}

float MS5837::pressure(float conversion)
{
	if (_model == MS5837_02BA)
	{
		return P * conversion / 100.0f;
	}
	else
	{
		return P * conversion / 10.0f;
	}
}

float MS5837::temperature(float conversion)
{
	float degC = TEMP / 100.0f;
	if (conversion == UNITS_Farenheit)
	{
		return ((9.0 / 5.0) * degC + 32);
	}
	else if (conversion == UNITS_Kelvin)
	{
		return (degC + 273);
	}
	return degC;
}

// The pressure sensor measures absolute pressure, so it will measure the atmospheric pressure + water pressure
// We subtract the atmospheric pressure to calculate the depth with only the water pressure
// The average atmospheric pressure of 101300 pascal is used for the calcuation, but atmospheric pressure varies
// If the atmospheric pressure is not 101300 at the time of reading, the depth reported will be offset
// In order to calculate the correct depth, the actual atmospheric pressure should be measured once in air, and
// that value should subtracted for subsequent depth calculations.
float MS5837::depth()
{
	return (pressure(UNITS_Pa) - 101300) / (fluidDensity * 9.80665);
}

float MS5837::altitude()
{
	return ((1 - pow((pressure() / 1013.25), .190284)) * 145366.45 * .3048);
}

uint8_t MS5837::crc4(uint16_t n_prom[])
{
	uint16_t n_rem = 0;
	uint16_t temp = n_prom[0];
	n_prom[0] = ((n_prom[0]) & 0x0FFF);
	cout << "nprom" << hex << int(n_prom[0]) << endl;
	n_prom[7] = 0;

	for (uint8_t i = 0; i < 16; i++)
	{
		if (i % 2 == 1)
		{
			n_rem ^= (uint16_t)((n_prom[i >> 1]) & 0x00FF);
		}
		else
		{
			n_rem ^= (uint16_t)(n_prom[i >> 1] >> 8);
		}
		for (uint8_t n_bit = 8; n_bit > 0; n_bit--)
		{
			if (n_rem & 0x8000)
			{
				n_rem = (n_rem << 1) ^ 0x3000;
			}
			else
			{
				n_rem = (n_rem << 1);
			}
		}
	}

	n_rem = ((n_rem >> 12) & 0x000F);
	n_prom[0] = temp;
	return n_rem ^ 0x00;
}

bool MS5837::write(uint8_t msg)
{
	char msg_char = (char)msg;
	std::cout << "writing" << hex << msg << endl;
	if (i2c_write_byte(pi, handle, msg_char) != 0)
	{
		// cout << "failed to write: " << hex << int(msg) << endl;
		return false;
	}
	return (true);
}