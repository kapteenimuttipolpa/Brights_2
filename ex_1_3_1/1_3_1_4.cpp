/*Exercise 4:
Write a program that declares a 
variable inside a block and prints 
its value inside and outside the block. 
Discuss with the students the scope of
 variables declared inside blocks.*/

 #include<iostream>
 int main()
 {
    if(1 = 1){
        int i = 1;
        std::cout << i;
    }
    std::cout << i; // ei onnistu koska i on määritelty eri blokissa
   

  return 0;
 }