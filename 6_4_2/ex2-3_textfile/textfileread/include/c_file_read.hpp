#ifndef C_FILE_READ_HPP
#define C_FILE_READ_HPP
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
struct new_line_read {
  std::string file_contents;
};
namespace c_file_read {
class line_read {
public:
  line_read();
  ~line_read();
  void print_next_line();
  std::vector<new_line_read> loop_all_lines();
  void print_size() const;

private:
  std::string_view line_contents;
  FILE *file_handle = nullptr;
  FILE *read_full_file = nullptr;
};
void print_all_lines(const std::vector<new_line_read> &all_lines);
} // namespace c_file_read

#endif
