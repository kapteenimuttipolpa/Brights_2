#include "../include/c_file_read.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
namespace c_file_read {
namespace fs = std::filesystem;
std::vector<new_line_read> all_lines;
line_read::line_read() {
  file_handle = fopen("dog.txt", "r");
  read_full_file = fopen("dog.txt", "r");
  if (!file_handle) {
    throw std::runtime_error("Cannot open file");
  }
}
line_read::~line_read() {
  fclose(file_handle);
  fclose(read_full_file);
  file_handle = nullptr;
  read_full_file = nullptr;
}
void line_read::print_next_line() {
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
void line_read::print_size() const {
  size_t file_size = fs::file_size("dog.txt");
  std::cout << file_size << '\n';
}
/**
 * @brief loop all lines and add to vector
 *
 * @return std::vector<new_line_read>
 */
std::vector<new_line_read> line_read::loop_all_lines() {
  all_lines.clear();
  int symbol;
  std::string line;
  while ((symbol = std::fgetc(read_full_file)) != EOF) {
    char ch = static_cast<char>(symbol);
    if (ch != '\n') {
      line += ch;
    } else {
      new_line_read new_line;
      new_line.file_contents = line;
      all_lines.push_back(new_line);
      line.clear();
    }
  }
  rewind(read_full_file);
  return all_lines;
}
/**
 * @brief prints all lines in vector
 *
 * @param all_lines
 */
void print_all_lines(const std::vector<new_line_read> &all_lines) {
  for (const auto &line : all_lines) {
    std::cout << line.file_contents << '\n';
  }
}
} // namespace c_file_read