#ifndef PID_H
#define PID_H

#include <memory>
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;
/**
 * PID code based off of https://bitbucket.org/AndyZe/pid/src/master/src/pid.cpp
 */
class PID
{
public:
    PID(double kP = 0, double kI = 0, double kD = 0, double output_limit = 0,
        double integrator_limit = 0, bool angle_wrap_compensation = true,
        double windup_limit = 1000, double cutoff_frequency = -1);
    void setGains(double kP, double kI, double kD, double output_limit,
                  double integrator_limit, bool angle_wrap_compensation, double windup_limit, double cutoff_frequency);
    double compute(double setpoint, double state, double dt);
    double compute(double error, double dt);

private:
    bool angle_wrap_compensation_ = true;

    // PID gains
    double kP_;
    double kI_;
    double kD_;
    double error_integral_ = 0;
    double integrator_limit_;
    double output_limit_;
    double last_value;

    // Cutoff frequency for the derivative calculation in Hz.
    // Negative -> Has not been set by the user yet, so use a default.
    double cutoff_frequency_ = -1;

    // Used in filter calculations. Default 1.0 corresponds to a cutoff frequency
    // at
    // 1/4 of the sample rate.
    double c_ = 1.;

    // Used to check for tan(0)==>NaN in the filter calculation
    double tan_filt_ = 1.;

    // Anti-windup term. Limits the absolute value of the integral term.
    double windup_limit_ = 1000;

    // Initialize filter data with zeros
    std::vector<double> error_, filtered_error_, error_deriv_, filtered_error_deriv_;

    // Diagnostic objects
    double min_loop_frequency_ = 1, max_loop_frequency_ = 1000;
    int measurements_received_ = 0;
};

#endif // SRC_PID_H
