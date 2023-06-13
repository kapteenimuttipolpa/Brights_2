#include <iostream>
#include <string>
#include <vector>
#include "./includes/utils.h"
struct Command
{
    std::string s;
    double(*action)(double, double);
};

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
    double operand1, operand2;
    if(argc != 4){
        std::cout << "Wrong amount of params";
    }
    std::string operand1_str = static_cast<std::string>(argv[1]);
    std::string operator_str = static_cast<std::string>(argv[2]);
    std::string operand2_str = static_cast<std::string>(argv[3]);
    bool is_for_encrypt = false;
    for(char& c : operand1_str)
    {
        if(!isdigit(c))
        {
            is_for_encrypt = true;
        }
    }
    if(!is_for_encrypt)
    {
        double operand1 = std::stod(operand1_str);
        double operand2 = std::stod(operand2_str);
    }
    else{
        
        operand_int = std::stoi(operand2_str);

    }


    for(auto& command : COMMANDS)
    {
        if(operator_str == command.s)
        {
            std::cout << command.action(operand1, operand2);
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