#include <string>
#include <filesystem>
#ifndef CALCULATE_FILE_SIZE_H
#define CALCULATE_FILE_SIZE_H

namespace fs = std::filesystem;

void calculate_file_size(const std::string& dir);

#endif // CALCULATE_FILE_SIZE_H