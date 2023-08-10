#include <iostream>
#include <string>

int main() {
  std::string test = "banana🦍";
  // printing every character seems to work
  // even the gorilla is printed
  // when i print them as int,
  // gorilla is -16 -97 -90 -115
  for (char c : test) {
    std::cout << (int)c << "\n";
  }
}