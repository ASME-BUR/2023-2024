#ifndef RASPI_DMA_PWM_HPP
#define RASPI_DMA_PWM_HPP
#include <pigpiod_if2.h>

class PWM_obj
{
public:
    PWM_obj(int pigpio_id, uint8_t pin_, int min_ = 1100, int max_ = 1900, int frequency_ = 200);
    ~PWM_obj();
    void run(float speed_);

private:
    uint8_t pi;
    uint8_t pin;
    int min;
    int max;
    int mid;
    int frequency;
};

#endif