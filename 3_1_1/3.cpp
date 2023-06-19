#include<iostream>
#include<vector>
#include<string>
/*3. Create a program that will print out a list of names. 
The user can choose a person in the list by inputting 
the user index and their name gets printed out. 
If the user tries to choose a user that is outside of the index,
 throw an appropriate exception. */
int main()
{
    std::vector<std::string> names {
        "Aatu", "Beetu", "Ceetu",
        "Deeku", "Eetu"
    };

    std::cout << "Choose a persons index from the list: ";
    int index {};
    std::cin >> index;

    //vector .at() will check if the choise was in the bounds of the vector
    //if user inputs lets say 123, it will throw std::out_of_range exception
    std::cout << "Your choise was: " << names.at(index) << '\n';

    return 0;
}