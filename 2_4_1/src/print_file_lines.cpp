#include "../includes/print_file_lines.h"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
/**
 * @brief print_file_lines
 *  prints the amount of lines
 *  in user given file
 * @param filename name of the user given file
 */
void print_file_lines(const std::string& filename)
{
  std::ifstream file_object(filename); //create file object
  if(!file_object){ //if object doesnt exist, file isnt open.
    std::cout << "File cannot be opened.\n";
    return;
  }
  std::string temp{};
  int counter{};
  file_object >> std::noskipws; // disables skipping whitespaces, see #include <iomanip>
  while(std::getline(file_object, temp))
  {
    counter++;
  }
  file_object.close();
  std::cout << "File " << filename << " has " << counter << " lines.\n";
}