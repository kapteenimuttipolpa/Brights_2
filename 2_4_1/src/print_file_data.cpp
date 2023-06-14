#include "../includes/print_file_data.h"
#include <iostream>
#include <fstream>
void print_data(std::string& res)
{
  std::ifstream file_object(res);
  if(!file_object){
    std::cout << "File cannot be opened.\n";
    return;
  }
  std::string temp{};
  while(std::getline(file_object, temp))
  {
    std::cout << temp;
  }
  file_object.close();
}