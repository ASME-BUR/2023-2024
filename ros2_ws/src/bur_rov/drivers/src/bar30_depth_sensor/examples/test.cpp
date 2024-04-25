#include "MS5837.h"
#include <iostream>
#include <cstdlib>
#include <signal.h>

using namespace std;
MS5837 *sensor;
int pi;

// void signal_callback_handler(int signum)
// {
//   cout << "Caught signal " << signum << endl;
//   // Terminate program
//   sensor->~MS5837();
//   cout << "stopping pigpio" << endl;
//   pigpio_stop(pi);
//   exit(signum);
// }

int main()
{
  // signal(SIGINT, signal_callback_handler);
  pi = pigpio_start("10.42.0.24", NULL);
  // cout << pi << endl;
  sensor = new MS5837(pi);
  cout << "Starting" << endl;

  // Initialize pressure sensor
  // Returns true if initialization was successful
  // We can't continue with the rest of the program unless we can initialize the sensor
  while (!sensor->init())
  {
    cout << "Init failed!" << endl;
    cout << "Are SDA/SCL connected correctly?" << endl;
    cout << "Blue Robotics Bar30: White=SDA, Green=SCL" << endl;
    cout << "\n\n\n"
         << endl;
    this_thread::sleep_for(chrono::milliseconds(100));
  }
  // .init sets the sensor model for us but we can override it if required.
  // Uncomment the next line to force the sensor model to the MS5837_30BA.
  sensor->setModel(1);
  sensor->setOSR(5);
  cout << "model" << sensor->getModel() << endl;

  sensor->setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
  cout << hex << int(sensor->getModel()) << endl;
  while (true)
  {
    // Update pressure and temperature readings
    sensor->read();
    cout << "P: " << sensor->pressure() << " mbar\t";
    cout << "T: " << sensor->temperature() << " deg C\t";
    cout << "Depth: " << sensor->depth() << " m\t";
    cout << "Altitude: " << sensor->altitude() << " m above mean sea level\t";
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(10));
  }
  // return EXIT_SUCCESS;
}