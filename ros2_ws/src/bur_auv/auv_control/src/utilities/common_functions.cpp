/*
 * Core functions that I use often
 */

#include <sstream>
#include <iomanip>
#include <utilities/common_functions.hpp>

/**
 * Clamps a value between a min and max value
 */
double CommonFunctions::Clamp(double value, double minValue, double maxValue)
{
    return fmin(fmax(value, minValue), maxValue);
}

/**
 * Like the arduino map function
 * Returns "value" scaled from between in_min and in_max to between out_min adn out_max
 */

double CommonFunctions::Interpolate(double value, double in_min, double in_max, double out_min, double out_max)
{
    double in_span = in_max - in_min;
    double out_span = out_max - out_min;

    double scaled = double(value - in_min) / double(in_span);
    return out_min + (scaled * out_span);
}

/**
 * Takes a current and desired angle in radians, returns a signed difference in angle in radians
 * It should do a - b (difference from a to b)
 * logic from https://bitbucket.org/whoidsl/ds_base/src/master/ds_util/src/ds_util/angle.cpp
 */
double CommonFunctions::AngleDiffRadians(double a, double b)
{
    double dot = sin(a) * sin(b) + cos(a) * cos(b);
    double cross = cos(a) * sin(b) - sin(a) * cos(b);
    double diff = atan2(cross, dot);
    return diff;
}

/**
 * Gets hypotenuse from x and y
 */
double CommonFunctions::VectorMagnitude(double x, double y)
{
    return std::sqrt(x * x + y * y);
}

/**
 * Converts degrees to radians
 */
double CommonFunctions::DegreesToRadians(double degrees)
{
    return degrees * 0.017453292519943295;
}

/**
 * Converts radians to degrees
 */
double CommonFunctions::RadiansToDegrees(double radians)
{
    return radians * 57.29577951308232;
}

/*
    converts a quaternion to euler angles in rad
    copied from https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles#Source_code
*/
CommonFunctions::EulerAngles CommonFunctions::ToEulerAngles(Quaternion q)
{
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = std::sqrt(1 + 2 * (q.w * q.y - q.x * q.z));
    double cosp = std::sqrt(1 - 2 * (q.w * q.y - q.x * q.z));
    angles.pitch = 2 * std::atan2(sinp, cosp) - M_PI / 2;

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}

/**
 * Splits a sting around a delimiter, and returns a vector
 * Copied from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
 */
std::vector<std::string> CommonFunctions::SplitString(std::string input, const std::string &delimiter)
{
    std::vector<std::string> out;
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        out.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    out.push_back(input);
    return out;
}

/**
 * Rounds and converts to string
 * Used for printing stuff to the screen
 */
std::string CommonFunctions::RoundToString(double input, int decimals)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(decimals) << input;
    return stream.str();
}

const std::string WHITESPACE = " \n\r\t\f\v";

/**
 * Strips off leading whitespace
 */
std::string CommonFunctions::LStrip(const std::string &s, const std::string &white_space_chars)
{
    size_t start = s.find_first_not_of(white_space_chars);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string CommonFunctions::LStrip(const std::string &s)
{
    return CommonFunctions::LStrip(s, WHITESPACE);
}

/**
 * Strips off trailing whitespace
 */
std::string CommonFunctions::RStrip(const std::string &s, const std::string &white_space_chars)
{
    size_t end = s.find_last_not_of(white_space_chars);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string CommonFunctions::RStrip(const std::string &s)
{
    return CommonFunctions::RStrip(s, WHITESPACE);
}

/**
 * Strips off leading and trailing whitespace
 */
std::string CommonFunctions::Strip(const std::string &s, const std::string &white_space_chars)
{
    return CommonFunctions::LStrip(CommonFunctions::RStrip(s, white_space_chars), white_space_chars);
}

/**
 * Strips off leading and trailing whitespace
 */
std::string CommonFunctions::Strip(const std::string &s)
{
    return CommonFunctions::Strip(s, WHITESPACE);
}

/**
 * Takes a key-value string formatted correctly, and returns a map containing that data
 *
 * Formatting example
 * {a: b, c: d}
 */
std::map<std::string, std::string> CommonFunctions::CreateMapFromString(std::string input)
{
    input.erase(0, 1);
    input.erase(input.size() - 1);
    std::map<std::string, std::string> out_map;

    auto split_by_commas = CommonFunctions::SplitString(input, ",");
    for (const auto &split_section : split_by_commas)
    {
        auto data = CommonFunctions::SplitString(split_section, ":");
        out_map.insert({CommonFunctions::Strip(data[0], WHITESPACE + "\""), CommonFunctions::Strip(data[1], WHITESPACE + "\"")});
    }

    return out_map;
}
