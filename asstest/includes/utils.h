#ifndef UTILS_H
#define UTILS_H
#include<string>
#include<filesystem>
constexpr int INVALID_FILE = -1;
constexpr int INVALID_FORMAT = -2;
bool clear_cin();
void print_possible_files();
int print_file_contents();
#endif