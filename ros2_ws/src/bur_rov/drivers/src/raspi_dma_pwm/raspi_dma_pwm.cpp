#include "raspi_dma_pwm.h"
#include <iostream>
using namespace std;

PWM_obj::PWM_obj(int pigpio_id, uint8_t pin_, int min_, int max_, int frequency_)
{
    // cout << "initializing" << endl;
    // pi = pigpio_start(NULL, NULL);
    pin = pin_;
    frequency = frequency_;
    min = min_;
    max = max_;
    mid = ((max_ - min_) / 2) + min_;
    pi = pigpio_id;
    // cout << "initialize complete" << endl;
    set_mode(pi, pin, PI_OUTPUT);
    set_PWM_frequency(pi, pin, frequency);
    if (get_PWM_range(pi, pin) != 255)
    {
        set_PWM_range(pi, pin, 255);
    }
    run(0);
}

PWM_obj::~PWM_obj()
{
    cout << "destructing" << endl;
    run(0);
}

void PWM_obj::run(float speed_)
{
    if (speed_ > 1)
    {
        speed_ = 1;
    }
    else if (speed_ < -1)
    {
        speed_ = -1;
    }
    int pulse = (speed_ * (max - min) / 2) + mid;
    uint duty_cycle = pulse * frequency * 255 * 1e-6;
    cout << "duty cycle: " << duty_cycle << " "
         << "pulse: " << pulse << endl;
    set_PWM_dutycycle(pi, pin, duty_cycle);
}