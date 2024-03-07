#include <pigpiod_if2.h>
#include <unistd.h>
#include <iostream>
using namespace std;
#define Addr 0x5D

int main()
{
    // start pigpio and i2c line
    int pi = pigpio_start("192.168.1.55", NULL);
    int handle = i2c_open(pi, 1, Addr, 0);
    cout << pi << " " << handle << endl;
    // start device, send 0x00 to register 0x20
    cout << i2c_write_byte_data(pi, handle, 0x20, 0x00) << endl;
    // set sensor to high precision
    cout << i2c_write_byte_data(pi, handle, 0x10, 0x79) << endl;
    // Turn on the pressure sensor analog front end in single shot mode
    cout << i2c_write_byte_data(pi, handle, 0x20, 0x84) << endl;
    // cout << i2c_write_byte_data(pi, handle, 0x21, 0x84) << endl;
    // while (true)
    // {
    // Run one shot measurement (T and P), self clearing bit when done
    cout << i2c_write_byte_data(pi, handle, 0x21, 0x01) << endl;

    // Wait until measurement is done, should take around 0.03s
    double time = get_current_tick(pi);
    double current;
    // output on register 0x21 should be 0x00 when measurement is done
    while (i2c_read_byte_data(pi, handle, 0x21) != 0)
    {
        current = get_current_tick(pi) - time;
    }
    cout << "data ready" << endl;
    cout << "that took " << current / (1e6) << "s" << endl;

    // read temperature measurement
    uint8_t t[2];
    t[0] = i2c_read_byte_data(pi, handle, 0x2B);
    t[1] = i2c_read_byte_data(pi, handle, 0x2C);
    // temp conversion
    float temp = (int16_t)(t[1] << 8 | t[0]);
    // Convert to Celsius
    float tempC = 42.5 + temp / 480;
    // Output data
    cout << "temp is : ";
    cout << tempC;
    cout << " C" << endl;

    // Pressure data
    uint8_t data[3];
    data[0] = i2c_read_byte_data(pi, handle, 0x28);
    data[1] = i2c_read_byte_data(pi, handle, 0x29);
    data[2] = i2c_read_byte_data(pi, handle, 0x2A);
    // Pressure conversion
    float pressure = ((int32_t)data[2] << 16) | ((int32_t)data[1] << 8) | data[0];
    float pressure_mb = pressure / 4096;
    cout << "Pressure is: " << pressure_mb << " millibars" << endl;
    // }
    i2c_close(pi, handle);
    pigpio_stop(pi);
}