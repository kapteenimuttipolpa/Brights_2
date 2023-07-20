#include "overloads.hpp"
#include <ios>
#include <limits>
#include <stdexcept>
int main() {
  int max = std::numeric_limits<int>::max();
  oma::point3d point_a(3, 3, 3);
  oma::point3d point_b(100, 100, 100);
  oma::point3d big(max, max, max);

  // big += point_a; overflow
  // big = big + point_a; overflow
  // point_a = point_a - point_b; underflow
  // point_a -= point_b; underflow
  point_a += point_b;
  std::cout << point_a; // 103, 103, 103

  point_a -= point_b;
  std::cout << point_a; // 3, 3, 3

  bool smaller = point_a < point_b;
  std::cout << std::boolalpha << smaller; // true

  return 0;
}