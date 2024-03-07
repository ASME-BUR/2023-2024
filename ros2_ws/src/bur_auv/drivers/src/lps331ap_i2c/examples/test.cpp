#include <unistd.h>
#include <LPS.h>
#include <iostream>
#include <pigpiod_if2.h>
#include <cstdlib>
#include <signal.h>
using namespace std;

LPS ps(pigpio_start("192.168.1.55", NULL));

// void signal_callback_handler(int signum)
// {
//     cout << "Caught signal " << signum << endl;
//     // Terminate program
//     exit(signum);
// }

int main()
{
    // Register signal and signal handler
    // signal(SIGINT, signal_callback_handler);
    if (!ps.init())
    {
        cout << "Failed to autodetect pressure sensor!" << endl;
        while (1)
            ;
    }

    ps.enableDefault();

    ps.run();
    // return EXIT_SUCCESS;
}
