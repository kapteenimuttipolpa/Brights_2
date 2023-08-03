#include "./include/container.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>
int main() {
  oma::array<int, 2> arr1{1, 2};
  oma::array<int, 2> arr2{3, 4};

  oma::array<int, 2> test3 = std::move(arr2);
  if (arr2.empty()) {
    for (const auto &elem : arr2) {
      std::cout << elem;
    }
  }

  return 0;
}