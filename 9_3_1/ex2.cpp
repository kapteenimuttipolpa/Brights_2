#include "ex2.hpp"
#include <iostream>
#include <string>
int main() {
  std::string test2 = "u8äöå🍍";

  std::cout << "Original values: \n";
  for (string_iterator it = test2.begin(); it != test2.end(); ++it) {
    std::cout << *it << "\n";
  }

  std::cout << "Adapter values: \n";
  for (auto val : string_adapter(test2)) {
    std::cout << val << "\n";
  }
}