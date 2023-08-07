#include <cstddef>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
void func1() { std::cout << "func1\n"; }
void func2() { std::cout << "func2\n"; }
void func3() { std::cout << "func3\n"; }

int main() {
  std::vector<std::function<void()>> functions = {func1, func2, func3};
  int choice{};
  while (true) {

    std::cout << "Select function\n";
    std::cin >> choice;
    if (!std::cin) {
      if (std::cin.eof()) {
        std::abort();
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max());
      continue;
    }
    break;
  }
  --choice;
  functions[choice]();
}