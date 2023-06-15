#include <iostream>
#include <filesystem>
#include <string>
#include "../includes/calculate_file_size.h"

/**
 * @brief calculate_file_size
 * loops the user given directory
 * and prints the name of every .txt ending file
 * and calculates the total size in bytes
 * 
 * @param dir user given directory
 */
void calculate_file_size(const std::string& dir)
{
    fs::path file_path = dir;
    int total_size {};

    for(const auto& file : fs::directory_iterator(dir)){
        if(file.path().extension() == ".txt"){ //check if the file ends with .txt
            total_size += fs::file_size(file); // add its size to total
            std::cout << file.path().filename().string() << '\n'; // print file name

        }
    }
    std::cout << "Total size of text files: " << total_size << " bytes\n";
}