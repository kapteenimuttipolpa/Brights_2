#include<iostream>
/*Exercise 3:
Create a program with two functions: main() 
and calculate(). Inside the calculate() function,
 declare a variable and assign a value to it.
  Print the value of the variable in both functions.
 Discuss with the students the difference between local and global scope.*/

 void calculate()
 {
    int i = 1;
    std::cout << i;
 }
int main()
{
    calculate();
    std::cout << i ; // i:tä ei pysty tulostamaan koska mitä main() funktioon tulee,
                    // se ei edes tiedä i:n olemassaoloa.
                    // sillä i:n elinkaari päättyy heti calculate funktion jälkeen.
 return 0;
}