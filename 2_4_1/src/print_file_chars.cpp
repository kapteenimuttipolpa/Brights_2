#include<iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "../includes/print_file_chars.h"
/**
 * @brief print_file_chars
 * prints the count of characters
 * in user given file
 * 
 * @param filename 
 */
void print_file_chars(const std::string& filename)
{
    std::ifstream file_object(filename); //fstream creates an object from the file
    if(not file_object) //check if object exists. If it does it means it is open
    //if not, something went wrong and file is not open
    {
        std::cout << "Cant open file.\n";
        return;
    }
    char c{};
    int counter{};
    file_object >> std::noskipws; // disables skipping whitespaces, #include <iomanip>
    while(file_object >> c) // loop the file and add every character to counter
    {
        counter++;
    }
    std::cout << "File contained " << counter << "characters.\n";
    file_object.close();
}