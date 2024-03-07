#include "pid.hpp"
#include <cmath>
PID::PID(double kP, double kI,
         double kD, double output_limit,
         double integrator_limit,
         bool angle_wrap_compensation,
         double windup_limit, double cutoff_frequency) : error_(3, 0), filtered_error_(3, 0),
                                                         error_deriv_(3, 0), filtered_error_deriv_(3, 0)
{
    setGains(kP, kI, kD, output_limit, integrator_limit, angle_wrap_compensation, windup_limit, cutoff_frequency);
}

void PID::setGains(double kP, double kI, double kD,
                   double output_limit, double integrator_limit,
                   bool angle_wrap_compensation, double windup_limit, double cutoff_frequency)
{
    kP_ = kP;
    kD_ = kD;
    kI_ = kI;
    output_limit_ = output_limit;
    integrator_limit_ = integrator_limit;
    angle_wrap_compensation_ = angle_wrap_compensation;
    windup_limit_ = windup_limit;
    cutoff_frequency_ = cutoff_frequency;
    cout << "set gains to: "
         << "P: " << kP_ << " I: " << kI_ << " D: " << kD_ << " out_lim: " << output_limit_
         << " int_lim: " << integrator_limit_ << " angle_wrap: " << angle_wrap_compensation_
         << " windup_lim: " << windup_limit_ << " cutoff_freq: " << cutoff_frequency_ << endl;
}

/**
 * Takes a current and desired angle in radians, returns a signed difference in angle in radians
 * It should do a - b (difference from a to b)
 * logic from https://bitbucket.org/whoidsl/ds_base/src/master/ds_util/src/ds_util/angle.cpp
 */
double AngleDiffRadians(double a, double b)
{
    double dot = sin(a) * sin(b) + cos(a) * cos(b);
    double cross = cos(a) * sin(b) - sin(a) * cos(b);
    double diff = atan2(cross, dot);
    return diff;
}

/**
 * Clamps a value between a min and max value
 */
double Clamp(double value, double minValue, double maxValue)
{
    return fmin(fmax(value, minValue), maxValue);
}

double PID::compute(double setpoint, double state, double dt)
{
    if (angle_wrap_compensation_ == true)
    {
        return compute(AngleDiffRadians(state, setpoint), dt); // state-setpoint because of sign convention for AngleDiffRadians
    }
    else
    {
        return compute(setpoint - state, dt);
    }
}

double PID::compute(double error, double dt)
{
    double control_effort = 0;
    error_.at(2) = error_.at(1);
    error_.at(1) = error_.at(0);
    error_.at(0) = error; // Current error goes to slot 0
    // cout << "error " << error_.at(2) << " " << error_.at(1) << " " << error_.at(0) << endl;

    // integrate the error
    error_integral_ += error_.at(0) * dt;
    // cout << "error_integral " << error_integral << endl;
    // Apply windup limit to limit the size of the integral term
    if (error_integral_ > fabsf(windup_limit_))
        error_integral_ = fabsf(windup_limit_);

    if (error_integral_ < -fabsf(windup_limit_))
        error_integral_ = -fabsf(windup_limit_);

    // My filter reference was Julius O. Smith III, Intro. to Digital Filters
    // With Audio Applications.
    // See https://ccrma.stanford.edu/~jos/filters/Example_Second_Order_Butterworth_Lowpass.html
    if (cutoff_frequency_ != -1)
    {
        // Check if tan(_) is really small, could cause c = NaN
        tan_filt_ = tan((cutoff_frequency_ * 6.2832) * dt / 2);

        // Avoid tan(0) ==> NaN
        if ((tan_filt_ <= 0.) && (tan_filt_ > -0.01))
            tan_filt_ = -0.01;
        if ((tan_filt_ >= 0.) && (tan_filt_ < 0.01))
            tan_filt_ = 0.01;

        c_ = 1 / tan_filt_;
    }

    filtered_error_.at(2) = filtered_error_.at(1);
    filtered_error_.at(1) = filtered_error_.at(0);
    filtered_error_.at(0) = (1 / (1 + c_ * c_ + 1.414 * c_)) * (error_.at(2) + 2 * error_.at(1) + error_.at(0) -
                                                                (c_ * c_ - 1.414 * c_ + 1) * filtered_error_.at(2) -
                                                                (-2 * c_ * c_ + 2) * filtered_error_.at(1));

    // cout << "error filtered " << filtered_error_.at(2) << " " << filtered_error_.at(1) << " " << filtered_error_.at(0) << endl;
    // Take derivative of error
    // First the raw, unfiltered data:
    error_deriv_.at(2) = error_deriv_.at(1);
    error_deriv_.at(1) = error_deriv_.at(0);
    error_deriv_.at(0) = (error_.at(0) - error_.at(1)) / dt;
    // cout << "error deriv " << error_deriv_.at(2) << " " << error_deriv_.at(1) << " " << error_deriv_.at(0) << endl;
    filtered_error_deriv_.at(2) = filtered_error_deriv_.at(1);
    filtered_error_deriv_.at(1) = filtered_error_deriv_.at(0);

    filtered_error_deriv_.at(0) =
        (1 / (1 + c_ * c_ + 1.414 * c_)) *
        (error_deriv_.at(2) + 2 * error_deriv_.at(1) + error_deriv_.at(0) -
         (c_ * c_ - 1.414 * c_ + 1) * filtered_error_deriv_.at(2) - (-2 * c_ * c_ + 2) * filtered_error_deriv_.at(1));

    // calculate the control effort
    double proportional = kP_ * filtered_error_.at(0);
    double integral = kI_ * error_integral_;
    double derivative = kD_ * filtered_error_deriv_.at(0);
    control_effort = proportional + integral + derivative;
    // cout << "control " << control_effort << endl;

    // Prevent Ramping
    control_effort = (last_value + control_effort) / 2;
    last_value = control_effort;

    // Apply saturation limits
    control_effort = Clamp(control_effort, -output_limit_, output_limit_);
    // cout << "control " << control_effort << endl;
    return (control_effort);
}
