#include <exception>
#include <iostream>
#include <stdexcept>
double divide(double &a, double &b) {
  if (b == 0) {
    throw std::runtime_error("Division by zero!");
  }
  return a / b;
}
int main() {
  double a = 123.234;
  double b = 0; // error is thrown
  try {
    divide(a, b);
    // Throw an exception when a problem arise
  } catch (std::runtime_error const &e) {
    // Block of code to handle errors
    std::cout << "Exception: " << e.what() << '\n';
  }
  return 0;
}