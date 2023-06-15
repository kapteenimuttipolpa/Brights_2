#include "../includes/print_file_data.h"
#include <iostream>
#include <fstream>
/**
 * @brief print_file_data
 *  prints every words in the
 * user given .txt file
 * 
 * @param res files name
 */
void print_file_data(std::string &res)
{
  std::ifstream file_object(res);
  if (!file_object)
  {
    std::cout << "File cannot be opened.\n";
    return;
  }
  std::string temp{};
  while (std::getline(file_object, temp))
  {
    std::cout << temp;
  }
  file_object.close();
}