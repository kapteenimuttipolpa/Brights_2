#include<iostream>
int func(int i){
    i = 2;
    return i;

}
int main()
{
    int i = 1;
    std::cout << i; // tulostaa 1
    func(i);
    std::cout << i; // tulostaa myös 1
    //jos funktion parametrin antaa referenssinä, se muokkaa alkuperäistä arvoa
    // int func(int& i) tulostaisi jälkimmäisessä 2
    // mutta tässä tapauksessa tulostuu alkuperäinen arvo, eli 1, koska elinkaari
    // päättyy funktion päätyttyä

 return 0;
}
/*Exercise 6:
Write a program that declares a variable inside a function,
 passes it as a parameter to another function, and modifies its value.
  Print the value of the variable before and after the function call. 
  Discuss with the students
 how the lifetime of the variable is affected by passing it as a parameter.*/