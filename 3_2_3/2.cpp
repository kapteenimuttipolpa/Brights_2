#include <iostream>

/*Write a recursive function that finds
the Greatest Common Divisor of two numbers.
Hint:  you can use the Euclidean algorithm.*/

int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); } 
// IF a == 0 returns b else goes for the recursion

int main() {
  int a{15};
  int b{10};

  std::cout << gcd(a, b);

  return 0;
}