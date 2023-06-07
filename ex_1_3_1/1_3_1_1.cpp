#include<iostream>
void print_declare_variable(){
    int i = 1;
    std::cout << i << std::endl;
}
int main()
{
    print_declare_variable();
 return 0;
}
    /*Exercise 1:
Write a program that declares a variable
 inside a function and prints its value. 
 Discuss with the students where the variable can be accessed 
 and explain the concept of local scope.*/

 // Variable can only be accessed inside the function