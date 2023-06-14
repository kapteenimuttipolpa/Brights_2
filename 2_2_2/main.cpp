#include <iostream>
#include <string>
#include <vector>
#include "./includes/utils.h"
struct Command
{
    std::string s;
    double(*action)(double, double); //function pointer
    //action could point to addition in example
};

    //Created a command vector so user can input
    //different commands for the same thing
    const std::vector<Command> COMMANDS = 
{
    {"+", addition},
    {"plus", addition},
    {"-", subtraction},
    {"minus", subtraction},
    {"*", multiplication},
    {"multiply", multiplication},
    {"divide", division},
    {"/", division}
};

int main(int argc, char *argv[])
{
    int operand_int {};
    double operand1{};
    double operand2{};
    //if user inputs wrong amount of parameters, prints error message
    if(argc != 4){
        std::cout << "Wrong amount of params";
    }
    std::string operand1_str = static_cast<std::string>(argv[1]); //cast C style strings to std::string
    std::string operator_str = static_cast<std::string>(argv[2]);
    std::string operand2_str = static_cast<std::string>(argv[3]);
    bool is_for_encrypt = false;
    //checks if user inputted something else than numbers
    //if he did, program assumes it is a string for encryption
    for(char& c : operand1_str)
    {
        if(!isdigit(c))
        {
            is_for_encrypt = true;
        }
    }
    //if both operands were numbers, program assumes
    //that user wants to do math operations
    if(!is_for_encrypt)
    {
         operand1 = std::stod(operand1_str);
         operand2 = std::stod(operand2_str);
    }
    else{
        
        operand_int = std::stoi(operand2_str);

    }
    //loop command vector and findout what user function to call
    for(auto& command : COMMANDS)
    {
        if(operator_str == command.s)
        {
            std::cout << command.action(operand1, operand2) << '\n';
        }
    }
    if(is_for_encrypt && operator_str == "encrypt")
    {

        std::cout << encrypt(operand1_str, operand_int);
    }
    if(is_for_encrypt && operator_str == "decrypt")
    {
        std::cout << decrypt(operand1_str, operand_int);
    }




    return 0;
}