#include <cstdint>
#include <iostream>
/*Exercise 3

Write a recursive function to calculate the power of a number.
Your recursive function should be able to handle any size of x to the power of
n.*/
int64_t pwr(int a, int b) {
  if (b == 0) {
    return 1;
  }

  else if (b < 0) {
    return 1 / pwr(a, -b);
  }

  else {
    return a * pwr(a, b - 1);
  }
}
int main() {
  int a{5};
  int b{3};

  std::cout << pwr(a, b);
  return 0;
}