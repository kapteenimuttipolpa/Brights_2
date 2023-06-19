#include <cctype>
#include<iostream>
#include<exception>
#include <stdexcept>
/*4. Overload a function called process_data().
 One version should accept an integer and the other a string. 
If the integer is negative or the string contains any 
non-alphabet characters, throw an exception.*/
void process_data(const int number){
    if(number < 0){
        throw std::invalid_argument("Negative number!");
    }
}
void process_data(const std::string& user_input){
    for(char c : user_input){
        if(!std::isalpha(c)){ // checks for non alphabet char
            throw std::invalid_argument("non-alphabet character found!");
        }
    }
}
int main()
{
    int number = 1;
    std::string input = "saippuakauppias";
    int number2 = -123;
    std::string input2 = "chicken123";
    //some tests
    try{
        process_data(number);
    }
    catch(std::invalid_argument const &e){
        std::cout << "Exception: " <<  e.what() << '\n';
    }

    try{
        process_data(input);
    }
    catch(std::invalid_argument const &e){
        std::cout << "Exception: " <<  e.what() << '\n';
    }
    try{
        process_data(number2);
    }
    catch(std::invalid_argument const &e){
        std::cout << "Exception: " <<  e.what() << '\n';
    }
     try{
        process_data(input2);
    }
    catch(std::invalid_argument const &e){
        std::cout << "Exception: " <<  e.what() << '\n';
    }
    return 0;
}