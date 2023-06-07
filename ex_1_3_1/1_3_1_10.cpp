#include<iostream>
namespace Test{
    int i = 0;
}
int main()
{
    int i = 1;
    std::cout << Test::i; //Test nimiavaruuden alla olevilla muuttujilla on 
                          //eri elinkaari kuin tavallisilla muuttujilla
                          //niiden elinkaari päättyy vasta ohjelman päätyttyä..?
    std::cout << i;
 return 0; //ohjelma tulostaa 01
}
/*Exercise 10:
Write a program that declares a variable inside a namespace 
and another variable with the same name inside a function. 
Print the value of each variable and 
discuss with the students how scope resolution works in namespaces.*/