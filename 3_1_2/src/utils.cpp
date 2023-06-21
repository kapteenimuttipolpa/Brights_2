#include "../includes/utils.h"
#include "../includes/constants.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <ctime>
#include <exception>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>
/**
 * @brief create_timestamps
 *  creates a vector with a time stamp every 10 minutes
 * @param time_stamp empty std::vector
 */
void create_timestamps(std::vector<std::string> &time_stamp) {

  std::string hour_s{"00"};
  std::string minute_s{"00"};
  while (true) {
    if (hour_s == "23" and minute_s == "50") {
      time_stamp.push_back(hour_s + ":" + minute_s);
      return;
    }
    time_stamp.push_back(hour_s + ":" + minute_s);
    int hour_i = std::stoi(hour_s);
    int min_i = std::stoi(minute_s);
    if (min_i == 50 and hour_i < 23) {
      hour_i += 1;
      min_i = 0;
    } else {
      min_i += 10;
    }
    hour_s = std::to_string(hour_i);
    minute_s = std::to_string(min_i);
    if (hour_s.length() == 1) {
      hour_s.insert(0, "0");
    }
    if (minute_s.length() == 1) {
      minute_s.insert(0, "0");
    }
  }
}
/**
 * @brief create_temperaturs
    distribution of temperatures
 *  for the day
 * @param temps 
 */
void create_temperatures(std::vector<float> &temps) {
  std::random_device rd{};
  std::mt19937 generator(rd());
  std::normal_distribution<double> distr_sum(20, 4); // summer dist
  for (int i = 0; i < 72; i++) {
    int heat = distr_sum(rd);
    try {
        validate_heat(heat);
      } catch (std::range_error const &e) {
        std::cout << "Exception: " << e.what();
      }
    temps.push_back(heat);
  }

}
/**
 * @brief create_humudity
 *  Generates distribution of humidity% for the day
 * @param humidities 
 */
void create_humidity(std::vector<int> &humidities) {
  std::random_device rd{};
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distr{0, 3};
  int roll = distr(rd);
  std::uniform_int_distribution<int> distr_2{30, 45}; // made some custom ranges so
  std::uniform_int_distribution<int> distr_3{45, 55}; // humidity doesnt change that much
  std::uniform_int_distribution<int> distr_4{55, 70}; // during the day
  std::uniform_int_distribution<int> distr_5{70, 83};
  if (roll == 0) {
    for (int i = 0; i < READINGS_IN_DAY; i++) {
      int humidity = distr_2(rd);
      try {
        validate_humidity(humidity);
      } catch (std::range_error const &e) {
        std::cout << "Exception: " << e.what();
      }
      humidities.push_back(humidity);
    }
  }
  if (roll == 1) {
    for (int i = 0; i < READINGS_IN_DAY; i++) {
      int humidity = distr_3(rd);
      try {
        validate_humidity(humidity);
      } catch (std::range_error const &e) {
        std::cout << "Exception: " << e.what();
      }
      humidities.push_back(humidity);
    }
  }
  if (roll == 2) {
    for (int i = 0; i < READINGS_IN_DAY; i++) {
      int humidity = distr_4(rd);
      try {
        validate_humidity(humidity);
      } catch (std::range_error const &e) {
        std::cout << "Exception: " << e.what();
      }
      humidities.push_back(humidity);
    }
  }
  if (roll == 3) {
    for (int i = 0; i < READINGS_IN_DAY; i++) {
      int humidity = distr_5(rd);
      try {
        validate_humidity(humidity);
      } catch (std::range_error const &e) {
        std::cout << "Exception: " << e.what();
      }
      humidities.push_back(humidity);
    }
  }
}
/**
 * @brief create_windspeed
 *  creates a distribution of winds speeds
 * @param windspeeds 
 */
void create_windspeed(std::vector<float> &windspeeds) {
  std::random_device rd{};
  std::mt19937 generator(rd());
  std::normal_distribution<float> distr_sum(MEAN_WIND_SPEED, 0.8);
  for (int i = 0; i < READINGS_IN_DAY; i++) {
    float wind_speed = distr_sum(rd);
    try {
      validate_wind(wind_speed);
    } catch (std::range_error const &e) {
      std::cout << "Abnormal wind speed recorded: " << e.what() << '\n';
      return;
    }
    windspeeds.push_back(distr_sum(rd));
  }
}
/**
 * @brief create_atmo_press
 *  creates a distribution of atmospheric pressures
 * @param atmo_press 
 */
void create_atmo_press(std::vector<float> &atmo_press) {
  std::random_device rd{};
  std::mt19937 generator(rd());
  std::normal_distribution<float> distr_sum(MEAN_ATMO_PRESS, 3);
  for (int i = 0; i < READINGS_IN_DAY; i++) {
    float pressure = distr_sum(rd);
    try {
      validate_atmo_press(pressure);
    } catch (std::range_error const &e) {
      std::cout << "Abnormal atmosphere pressure recorded: " << e.what() << '\n';
      return;
    }
    
    atmo_press.push_back(pressure);
  }
}
/**
 * @brief validate_wind
 * validates that the wind is inside
 * given bounds
 * @param wind_speed 
 * @return int 
 */
int validate_wind(float wind_speed) {
  if (wind_speed > MAX_WIND or wind_speed < MIN_WIND) {
    throw std::range_error("Abnormal wind speed recorded");
    return 1;
  }
  return 0;
}
/**
 * @brief validate_humidity
 *  validates that the humidity is inside
 * given bounds
 * @param humidity 
 * @return int 
 */
int validate_humidity(int humidity) {
  if (humidity > MAX_HUMID or humidity < MIN_HUMID) {
    throw std::range_error("Abnormal humidity reading");
    return 1;
  }
  return 0;
}
/**
 * @brief validate_atmo_press
 *  validates that the atmo press is inside
 * given bounds
 * @param pressure 
 * @return int 
 */
int validate_atmo_press(float pressure){
    if(pressure > MAX_PRESSURE or pressure < MIN_PRESSURE){
        throw std::range_error("Abnormal pressure reading");
        return 1;
    }
    return 0;
}
/**
 * @brief validate_heat
 *  validates that the temperature is inside
 * given bounds
 * @param heat 
 * @return int 
 */
int validate_heat(float heat){
    if(heat > MAX_HEAT or heat < MIN_HEAT){
        throw std::range_error("Abnormal heat reading");
        return 1;
    }
    return 0;
}
/**
 * @brief validate_time
 *  validates that user gives
 * time in correct format
 * @param s 
 * @return std::string 
 */
std::string validate_time(std::string& s)
{
  bool found = false;
  for(char c : s ){
    if(!std::isdigit(c) and c != ':'){ // only allows digits and :
      return NO_TIME;
    }
    if(c == ':'){ 
      found = true;
    }
  }
  if(!found){ //if theres no : user gave wrong format
    return NO_TIME;
  }

  std::string hours{};
  std::string mins{};
  std::stringstream stream(s);
  std::getline(stream, hours, ':');
  std::getline(stream, mins); //splits hours and mins to 
  //separate strings

 
  int i_hour = std::stoi(hours);
  int i_min = std::stoi(mins); // swap to int to make comparing easier
  if(i_hour > 23 or i_hour < 0){
    return NO_TIME;
  }
  if(i_min > 59 or i_min < 0){
    return NO_TIME;
  }

  if(hours.size() < 2 && mins.size() < 2){
    hours.insert(0, "0");
    mins.insert(0, "0");
    return hours + ':' + mins; //if time is lets say 1:1, makes it 01:01
  }
  if(mins.size() < 2){
    mins.insert(0, "0");
    return hours + ':' + mins;
  }
  return s;
}
/**
 * @brief clear_com
 *  clears cin
 * @return true 
 * @return false 
 */
bool clear_cin()
{
  if(!std::cin)
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
  return true;
}


