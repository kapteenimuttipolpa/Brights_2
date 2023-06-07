#include<iostream>
#include<array>
void func(int* arr){
    for(int i = 0; i <= sizeof(arr); i++){
        std::cout << arr[i] << std::endl;
    }

}
int main()
{
    int *arr = new int(10); // varataan dynaamisesti tilaa 10 alkion arraylle
    func(arr);
    delete[] arr; //tuhotaan array, elinkaari päättyy
    //dynaamisesti varattujen olioiden elinkaari päättyy tietääkseni main funktion jälkeen
    //mutta kuuluu hyviin käytäntöihin tuhota se joka tapauksessa
 return 0;
}
/*Exercise 8:
Write a program that dynamically allocates memory for an array inside a function. 
Pass the array to another function and print its values.
 Remember to deallocate the memory at the end. 
 Discuss with the students the concept of dynamic memory allocation 
 and how it affects the lifetime of variables.
*/