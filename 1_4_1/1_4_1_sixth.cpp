#include<iostream>
#include<cassert>
void play_game(int num)
{
    assert((num >= 1 && num <= 100) && "Num is not in range!");
}
int main()
{
 play_game(100);
 std::cout << "Num in range! \n";
 play_game(1);
 std::cout << "Num in range! \n";
 play_game(0); //not in range
 play_game(101); //not in range
 
    
 return 0;
}
/*
Exercise 6
Write a C++ program that simulates a simple game. Implement a function called play_game() 
that takes a number as input and checks if it is within a certain range.
 Use assert statements to check if the number is within the range of 1 to 100 (inclusive). 
 If the assertion fails, display an error message indicating that the number is out of range.
 Compile the program both with and without the NDEBUG macro defined and observe the behaviour when the assertion fails in each case.
*/
