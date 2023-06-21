#include "../includes/weather.h"
#include "../includes/constants.h"
#include "../includes/user_inputs.h"
#include "../includes/utils.h"
#include <algorithm>
#include <cmath>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
/**
 * @brief generate_random_data
   generates somewhat realistic
   randomish weather readings
 * for every 10 minutes in a day
 * @param all_readings
 */
void generate_random_data(std::vector<Weather> &all_readings) {
  std::vector<std::string> time_stamp{};
  std::vector<float> temps{};
  std::vector<float> temps2{};
  std::vector<double> all_temps{};
  std::vector<int> humidities{};
  std::vector<float> winds_speeds{};
  std::vector<float> atmo_press{};

  create_timestamps(time_stamp);

  create_temperatures(temps);
  create_temperatures(temps2);
  create_humidity(humidities);
  create_windspeed(winds_speeds);
  create_atmo_press(atmo_press);
  // made 2 vectors for temperatures
  // one of them i sort in ascending order
  // and the second descending
  // to make weather jumps not as big
  std::sort(temps.begin(), temps.end());
  std::sort(temps2.begin(), temps2.end(), std::greater<double>());

  std::copy(temps.begin(), temps.end(), std::back_inserter(all_temps));
  std::copy(temps2.begin(), temps2.end(), std::back_inserter(all_temps));
  std::sort(atmo_press.begin(), atmo_press.end());
  // currently generates 144 readings for a day
  for (int i = 0; i < READINGS_IN_DAY; i++) {
    Weather new_reading;
    new_reading.time = time_stamp.at(i);
    new_reading.temperature = all_temps.at(i);
    new_reading.humidity = humidities.at(i);
    new_reading.wind_speed = winds_speeds.at(i);
    new_reading.atmo_pressure = atmo_press.at(i);
    all_readings.push_back(new_reading);
  }
  // write data to file
  write_to_file(all_readings);
}
void create_reading_manually(std::vector<Weather> &all_readings) {
  std::string time{};
  float temp{};
  int humidity{};
  float wind_s{};
  float atmo_press{};

  while (true) {
    time = get_time();
    if (time == NO_TIME) {
      continue;
    }
    break;
  }
  while (true) {
    temp = get_temp();
    if (temp == NO_TEMP) {
      continue;
    }
    break;
  }

  while (true) {
    humidity = get_humid();
    if (humidity == NO_HUMID) {
      continue;
    }
    break;
  }

  while (true) {
    wind_s = get_wind_s();
    if (wind_s == NO_WIND) {
      continue;
    }
    break;
  }

  while (true) {
    atmo_press = get_atmo_press();
    if (atmo_press == NO_ATMO_PRESS) {
      continue;
    }
    break;
  }
  // creates new weater object and pushes it to all_readings vector
  Weather new_weather_reading;
  new_weather_reading.time = time;
  new_weather_reading.temperature = temp;
  new_weather_reading.humidity = humidity;
  new_weather_reading.wind_speed = wind_s;
  new_weather_reading.atmo_pressure = atmo_press;
  all_readings.push_back(new_weather_reading);
  write_to_file(all_readings);
}
/**
 * @brief get_current_weather
 *  gets current weather from closest 10 minute (real time)
 *
 * @param all_readings
 */
void get_current_weather(std::vector<Weather> &all_readings) {
  const std::time_t now = std::time(nullptr);
  const std::tm calendar_time =
      *std::localtime(std::addressof(now)); // get the current time
  time_t minute = calendar_time.tm_min;     // current minutes
  time_t hour = calendar_time.tm_hour;      // current hours

  time_t rounded_min = (minute / 10) * 10; // round to closest 10

  if (minute % 10 >= 5) {
    rounded_min += 10;
  }

  std::string time_hour = std::to_string(hour); // convers to strings
  std::string time_minute = std::to_string(rounded_min);
  std::string time_to_find(time_hour + ':' + time_minute);
  std::cout << time_to_find;
  for (auto &reading :
       all_readings) { // find matching weather read based on time
    if (reading.time == time_to_find) {
      std::cout << "\nCurrent weather\n"
                << "Time: " << reading.time << '\n'
                << "Temperature: " << reading.temperature << '\n'
                << "Humidity: " << reading.humidity << '\n'
                << "Wind speed: " << reading.wind_speed << '\n'
                << "Atmo pressure: " << reading.atmo_pressure << '\n';
    }
  }
}
/**
 * @brief write_to_files
 *  writes all_readings to file
 * @param all_readings
 */
void write_to_file(std::vector<Weather> &all_readings) {
  std::string file_name = "Data.txt";
  std::ofstream file_object(file_name);
  for (auto &reading : all_readings) {
    file_object << "Time: " << reading.time << '\n';
    file_object << "Temperature: " << reading.temperature << '\n';
    file_object << "humidity: " << reading.humidity << '\n';
    file_object << "Winds speed: " << reading.wind_speed << '\n';
    file_object << "Atmospheric pressure: " << reading.atmo_pressure;
  }
  file_object.close();
}
/**
 * @brief print_readings
 *  prints every reading
 * @param all_readings 
 */
void print_readings(std::vector<Weather> &all_readings) {
  for (auto &reading : all_readings) {
    std::cout << std::fixed << std::setprecision(1) << reading.time << '\t'
              << reading.temperature << '\t' << reading.humidity << '\t'
              << reading.wind_speed << '\t' << reading.atmo_pressure << '\n';
  }
}