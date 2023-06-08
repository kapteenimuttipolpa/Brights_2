#include<iostream>
#define NDEBUG
#include<cassert>
int divide(int a, int b)
{
    assert((b != 0) && "Division by zero isnt allowed!");
    std::cout << "Success!\n"; 
    return a / b;
}
int main()
{
  divide(10, 1);
  divide(10, 0); //fails, NDEBUG gives floating point exeption.
  divide(50, 50);
 return 0;
}
/*
Exercise 4
Write a C++ program that performs division of two numbers.
 Implement a function called divide() that takes two integers as input and returns their division result.
  Use an assert statement to check that the second number (denominator) is not zero.
   If the assertion fails, display an error message indicating that division by zero is not allowed.
 Compile the program both with and without the NDEBUG macro defined and observe the behavior when the assertion fails in each case.
*/