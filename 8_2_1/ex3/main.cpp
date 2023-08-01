#include "counter.hpp"
#include <iostream>
int main() {
  counter c1("c1");
  std::cout << "instances: " << counter::get_count() << '\n';
  {
    counter c3("c3");
    std::cout << "instances: " << counter::get_count() << '\n';
    {
      counter c4(std::move(c3));
      std::cout << "instances: " << counter::get_count() << '\n';
      counter c5(std::move(c4));
      std::cout << "instances: " << counter::get_count() << '\n';
    }
    std::cout << "instances: " << counter::get_count() << '\n';
  }
  std::cout << "instances: " << counter::get_count() << '\n';
}