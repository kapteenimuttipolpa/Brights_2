#ifndef CONSTANTS_H
#define CONSTANTS_H
#include<string>
 //Some constant values defined
constexpr int READINGS_IN_DAY = 144;
constexpr float MIN_HEAT = -273.15;
constexpr float MAX_HEAT = 57.0;
constexpr float MIN_WIND = 0.0;
constexpr float MAX_WIND = 80.0;
constexpr int MIN_HUMID = 0;
constexpr int MAX_HUMID = 100;
constexpr float MIN_PRESSURE = 850;
constexpr float MAX_PRESSURE = 1100;
constexpr float MEAN_ATMO_PRESS = 1009.651;
constexpr float MEAN_WIND_SPEED = 3.5;
const std::string NO_TIME = "NO_TIME";
constexpr float NO_TEMP = -1000000;
constexpr int NO_HUMID = -1;
constexpr float NO_WIND = -1.0;
constexpr float NO_ATMO_PRESS = -1.0;

#endif // CONSTANTS_H