#include "MTi.h"
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <array>
#include <signal.h>
using namespace std;

int main()
{
    int pi = pigpio_start("192.168.8.157", NULL);
    MTi MyMTi = MTi(pi);
    if (!MyMTi.detect(1000))
    { // Check if MTi is detected before moving on
        cout << "Please check your hardware connections." << endl;
        while (!MyMTi.detect(1000))
        {
            cout << "Cannot continue because no MTi was detected." << endl;
        }
    }
    // MyMTi.reset();
    MyMTi.goToConfig();        // Switch device to Config mode
    MyMTi.requestDeviceInfo(); // Request the device's product code and firmware version
    MyMTi.requestOutputConfig();
    const string modes[] = {"QUATERNION", "RATEOFTURNHR", "ACCELERATION"};
    const uint16_t hz[] = {60, 60, 60};
    // cout << hz.size() << endl;
    // cout << dec << int(sizeof(hz) / sizeof(uint16_t)) << endl;
    MyMTi.configureOutputs(modes, hz, 3); // Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
    MyMTi.requestOutputConfig();
    // MyMTi.requestOutputConfig();
    MyMTi.getOptionFlags();
    MyMTi.disableAutoMeas();
    MyMTi.getOptionFlags();
    // MyMTi.reset();
    // MyMTi.detect(1000);
    MyMTi.goToMeasurement();
    while (true)
    // for (int i = 0; i < 10; i++)
    {
        MyMTi.printData();
        // MyMTi.readData();
        // this_thread::sleep_for(chrono::milliseconds(100));
    }
}