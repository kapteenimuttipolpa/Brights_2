#include "include/c_file_read.hpp"
#include <iostream>
#include <string>
#include <vector>
int main() {
  c_file_read::line_read test;
  // test.print_next_line();
  test.print_next_line();

  std::vector<new_line_read> all_lines = test.loop_all_lines();
  c_file_read::print_all_lines(all_lines);
  test.print_next_line();
  std::vector<new_line_read> all_lines2 = test.loop_all_lines();
  c_file_read::print_all_lines(all_lines2);
  return 0;
}