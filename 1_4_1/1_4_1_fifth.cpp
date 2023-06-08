#include<iostream>
//#define NDEBUG
#include<cassert>
#include<cmath>
float square_root(float num){
    assert((num > 0) && "Square root is not defined for negative numbers!"); //NDEBUG would just ignore the assert
    return std::sqrt(num);
}
int main()
{
  square_root(1);
  square_root(2);
  square_root(0);
  square_root(-1);  
 return 0;
}
/*
Write a C++ program that calculates the square root of a given number.
 Implement a function called square_root() that takes a non-negative 
 floating-point number as input and returns its square root. 
 Use an assert statement to check that the input number is non-negative.
  If the assertion fails, display an error message indicating that the square root is not defined for negative numbers.
 Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/