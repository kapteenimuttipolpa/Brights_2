#include<iostream>
//#define NDEBUG
#include<cassert>
int sum(int a, int b)
{
    return a + b;
}
int main()
{
    assert((sum(1, 1) == 2) && "Incorrect calculations!"); //Checks if 1+1 returns correct aswer
    std::cout << "Passed \n";
    assert((sum(1, 2) >= 0) && "Sum is negative!"); // Makes sure result isnt negative
    std::cout << "Passed \n";
    assert((sum(1, 100) == 101) && "Incorrect calculations!");
    std::cout << "Passed! \n";
 return 0;
}
/*
Exercise 3
Write a C++ program that calculates the sum of two integers.
 Implement a function called sum() that takes two integers as input and returns their sum.
 Use an assert statement to check that the sum is positive. 
 If the assertion fails, display an error message indicating that the sum is not positive.
 Compile the program with the NDEBUG macro defined and observe the behaviour when the assertion fails.
*/