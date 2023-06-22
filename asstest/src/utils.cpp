#include "../includes/utils.h"
#include <filesystem>
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
/**
 * @brief clear_cin
 *  clears_cin if user gave wrong format
  for money (std::string etc);
 * @return true 
 * @return false 
 */
bool clear_cin() {
  if (!std::cin) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
  return true;
}
namespace fs = std::filesystem;

/**
 * @brief prints all files text files
 * in current working dir
 */
void print_possible_files() {
  std::string path = ".";
  std::cout << "Possible files: \n";

  for (const auto &entry : fs::directory_iterator(path)) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt") {
      std::cout << entry.path().filename() << '\n';
    }
  }
}
/**
 * @brief prints file contents.
 *  user can print other text files too
 * if they want
 * @return int 
 */
int print_file_contents() {
  std::string filename = {};
  std::cout << "Input file name: ";
  std::getline(std::cin >> std::ws, filename);
  std::fstream file_object(filename);

  if (!file_object.is_open()) {
    throw std::runtime_error("File couldnt be opened.");
    return INVALID_FILE;
  }
  std::string temp{};
  while(std::getline(file_object, temp))
  {
    std::cout << temp << '\n';
  }
  
  file_object.close();
  return 0;
}
