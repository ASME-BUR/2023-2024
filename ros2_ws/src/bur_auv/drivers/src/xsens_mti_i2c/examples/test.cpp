#include "MTi.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>
using namespace std;

int main()
{
    int pi = pigpio_start("192.168.8.157", NULL);
    MTi MyMTi = MTi(pi);
    // MyMTi.restoreFactoryDefaults();
    // MyMTi.runSelfTest();
    // MyMTi.restoreFactoryDefaults();
    MyMTi.requestDeviceInfo(); // Request the device's product code and firmware version
    MyMTi.requestOutputConfig();
    MyMTi.getOptionFlags();
    MyMTi.disableAutoMeas();
    MyMTi.getOptionFlags();
    const string modes[] = {"QUATERNION", "RATEOFTURNHR", "ACCELERATION"};
    const uint16_t hz[] = {30, 30, 30};
    MyMTi.configureOutputs(modes, hz, 3); // Configure the device's outputs based on its functionality. See MTi::configureOutputs() for more alternative output configurations.
    MyMTi.goToMeasurement();              // Switch device to Measurement mode]
    for (int i = 0; i < 20; i++)
    {
        MyMTi.printData();
    }
    MyMTi.resetOrientation();
    MyMTi.enableAHS();
    MyMTi.getOptionFlags();
    MyMTi.goToMeasurement();
    for (int i = 0; i < 20; i++)
    {
        MyMTi.printData();
    }
    while (true)
    {
        MyMTi.printData(); //...and print them to the serial monitor (Ctrl+Shift+M)
    }
}