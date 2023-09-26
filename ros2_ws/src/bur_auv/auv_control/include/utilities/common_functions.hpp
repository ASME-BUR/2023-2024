//
// Created by nathan on 10/30/20.
//

#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iostream>

/**
 * Common functions used across my code
 */
namespace CommonFunctions
{
    double Clamp(double value, double minValue, double maxValue);

    double Interpolate(double value, double in_min, double in_max, double out_min, double out_max);

    double AngleDiffRadians(double a, double b);

    double VectorMagnitude(double x, double y);

    double DegreesToRadians(double degrees);

    double RadiansToDegrees(double radians);

    struct Quaternion
    {
        double w, x, y, z;
    };

    struct EulerAngles
    {
        double roll, pitch, yaw;
    };

    EulerAngles ToEulerAngles(Quaternion q);

    std::vector<std::string> SplitString(std::string input, const std::string &delimiter);

    std::string RoundToString(double input, int decimals);

    std::string LStrip(const std::string &s, const std::string &white_space_chars);

    std::string LStrip(const std::string &s);

    std::string RStrip(const std::string &s, const std::string &white_space_chars);

    std::string RStrip(const std::string &s);

    std::string Strip(const std::string &s, const std::string &white_space_chars);

    std::string Strip(const std::string &s);

    std::map<std::string, std::string> CreateMapFromString(std::string input);
}
