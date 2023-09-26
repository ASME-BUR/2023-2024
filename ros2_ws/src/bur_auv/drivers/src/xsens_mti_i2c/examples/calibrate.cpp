#include "MTi.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <cstdlib>
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

    MyMTi.goToConfig(); // Switch device to Config mode
    // MyMTi.restoreDefauts();
    MyMTi.enableICC();
    MyMTi.startICC();
    auto start = chrono::steady_clock::now();
    while ((chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start)).count() < 5)
    {
        MyMTi.readData();
    }
    MyMTi.stopICC();
    cout << "Store data?" << endl;
    string answer;
    cin >> answer;
    if (answer == "yes")
    {
        MyMTi.storeICC();
    }
}
