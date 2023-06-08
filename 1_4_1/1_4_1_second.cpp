#include<iostream>
#include<string>
#include<cassert>
int factorial(int val)
{
    if(0 > val) return -1;

    if (val > 1) return val*factorial(val-1);
    else return 1;  
}
int main()
{
    assert(factorial(5) == 120 && "Calculations are wrong!");
    assert(factorial(-10) > 0 && "Factorial is not defined for negative numbers!");
     
 return 0;
}
/*Write a C++ program that calculates the factorial of a given number. 
Implement a function called factorial() that takes an integer as input and returns its factorial.
 Use an assert statement to check that the input number is non-negative. If the assertion fails, 
 display an error message indicating that the factorial is not defined for negative numbers. 
Test your program with various input values, including both positive and negative numbers.*/