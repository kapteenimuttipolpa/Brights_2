/*Write a program that 
declares a variable inside a loop 
and prints its value. 
Ask the students what will happen 
if they try to access 
the variable outside the loop.*/

#include<iostream>
int main()
{
    for(int i = 0; i < 10; i++){
        int j = 999;    // j:n elinkaari päättyy heti kun looppi loppuu.
    }
 return 0;
}
