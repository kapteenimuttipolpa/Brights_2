#include<iostream>

int main()
{   
    int i = 0;
    std::cout << i;
     if(1==1){ // jos ehtolause on tosi, muuttujan arvo muuttuu
        i = 1;  // jos ehtolause on epätosi, arvo ei muutu
    }
    std::cout << i;
    
 return 0;
}
/*Exercise 5:
Create a program that declares a variable inside a function 
and modifies its value inside an if statement. 
Print the value of the variable before and after the if statement. 
Discuss with the students the concept of scope and 
how it affects variable modifications.*/