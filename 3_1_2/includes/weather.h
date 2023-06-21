#ifndef WEATHER_H
#define WEATHER_H
#include <vector>
#include <string>
struct Weather{
    std::string time;
    double temperature;
    int humidity;
    float wind_speed;
    float atmo_pressure;
    
};
void generate_random_data(std::vector<Weather>& all_readings);
void create_reading_manually(std::vector<Weather>& all_readings);
void get_current_weather(std::vector<Weather>& all_readings);
void write_to_file(std::vector<Weather>& all_readings);
void print_readings(std::vector<Weather>& all_readings);

#endif // WEATHER_H