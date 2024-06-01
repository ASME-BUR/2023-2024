#ifndef UTILITY_FUNC_H
#define UTILITY_FUNC_H 

#include <cmath>

struct Quaternion {
    double w, x, y, z;
};

struct EulerAngles {
    double x, y, z;
};

EulerAngles ToEulerAngles(Quaternion q);
EulerAngles ToEulerAngles(double w, double x, double y, double z);

// angle wrap -180 to 180
double angle_wrap_pi(double angle);

template <typename T>
T clamp(T val, T low, T high);

#endif