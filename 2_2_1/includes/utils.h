#include<limits>
#include<iostream>
inline void clear_cin()
{
    std::cin.clear();                  // Clear the error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  

}