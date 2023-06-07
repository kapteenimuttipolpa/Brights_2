#include<iostream>
void func(){
  static int i = 0; // i määritellään staattisena, joten sen 
                    //elinkaari päättyy vasta kun ohjelma päättyy
  std::cout << i;   // vaikka mainin sisällä tehdään useita funktiokutsuja
  i++;
}
int main()
{
   for(int i = 0; i < 10; i++){
    func();
   } //tulostaa 0123456789

 return 0;
}
/*Exercise 9:
Create a program that uses static variables inside a function 
and demonstrates their lifetime across multiple function calls. 
Discuss with the students the lifetime and scope of static variables.*/