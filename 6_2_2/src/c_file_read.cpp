#include "../include/c_file_read.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

CFileRead::CFileRead() {
  file_handle = fopen("dog.txt", "r");
  if (file_handle == NULL) {
    throw std::runtime_error("Cannot open file");
  }
}
CFileRead::~CFileRead() {
  fclose(file_handle);
  file_handle = nullptr;
}
void CFileRead::print_next_line() {
  int symbol;
  std::string line;
  while ((symbol = std::fgetc(file_handle)) != EOF) {
    char ch = static_cast<char>(symbol);
    if (ch != '\n') {
      line += ch;
    } else
      break;
  }
  std::cout << line << '\n';
}
void CFileRead::print_size() const {
  size_t file_size = fs::file_size("dog.txt");
  std::cout << file_size << '\n';
}