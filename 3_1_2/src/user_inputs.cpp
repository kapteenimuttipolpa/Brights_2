#include "../includes/user_inputs.h"
#include "../includes/constants.h"
#include "../includes/utils.h"
#include <iostream>
#include <string>
/**
 * @brief user_input.cpp
 *  asks user data for new weather reading
 *  validates everything and keeps user
 *  inside while loop till correct value 
 *  is given
 */
std::string get_time() {
  std::string time{};
  std::cout << "Input time (00:00 format): ";
  std::getline(std::cin >> std::ws, time);
  std::string time_status = validate_time(time);
  if (time_status == NO_TIME) {
    std::cout << "Time not in correct format.\n";
    return NO_TIME;
  }
  return time_status;
}

float get_temp() {
  float temp{};
  while (true) {
    std::cout << "Insert temperature: ";
    std::cin >> temp;
    if (!clear_cin()) {
      std::cout << "Invalid input.\n ";
      continue;
    };
    break;
  }

  try {
    validate_heat(temp);
  } catch (std::range_error const &e) {
    std::cout << "Exception: " << e.what() << '\n';
    return NO_TEMP;
  }
  return temp;
}

int get_humid() {
  int humidity{};
  while (true) {
    std::cout << "Insert humidity %: ";
    std::cin >> humidity;
    if (!clear_cin()) {
      std::cout << "Invalid humidity.\n";
      continue;
    }
    break;
  }

  try {
    validate_humidity(humidity);
  } catch (std::range_error const &e) {
    std::cout << "Exception: " << e.what() << '\n';
    return NO_HUMID;
  }
  return humidity;
}

float get_wind_s() {
  float wind_s{};
  while (true) {
    std::cout << "Insert wind speed: ";
    std::cin >> wind_s;
    if (!clear_cin()) {
      std::cout << "Invalid wind speed.\n";
      continue;
    }
    break;
  }

  try {
    validate_wind(wind_s);
  } catch (std::range_error const &e) {
    std::cout << "Exception: " << e.what() << '\n';
    return NO_WIND;
  }
  return wind_s;
}
float get_atmo_press() {
  float atmo_press{};
  while (true) {
    std::cout << "Insert atmospheric pressure: ";
    std::cin >> atmo_press;
    if(!clear_cin()){
        std::cout << "Invalid atmo press.\n";
        continue;
    }
    break;
  }

  try {
    validate_atmo_press(atmo_press);
  } catch (std::range_error const &e) {
    std::cout << "Exception: " << e.what() << '\n';
    return NO_ATMO_PRESS;
  }
  return atmo_press;
}
