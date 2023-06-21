#ifndef UTILS_H
#define UTILS_H
#include<vector>
#include<string>
void create_timestamps(std::vector<std::string>& time_stamp);
void create_temperatures(std::vector<float>& doubles);
void create_humidity(std::vector<int>& humidities);
void create_windspeed(std::vector<float>& windspeeds);
void create_atmo_press(std::vector<float>& atmo_press);
int validate_wind(float wind_speed);
int validate_humidity(int humidity);
int validate_atmo_press(float pressure);
int validate_heat(float heat);
std::string validate_time(std::string& time);
bool clear_cin();



#endif // UTILS_H