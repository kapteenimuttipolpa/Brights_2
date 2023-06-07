#include"bankaccount.cpp"
#include"bankaccount.h"
#include<string>
#include<iostream>
void print_help();
std::string ask_iban();
int main()
{
    std::string user_input = "";
    std::cout << "Welcome to varrock west bank!" << std::endl;
    while(true)
    {
        
        std::cout << std::endl;
        print_help();
        std::getline(std::cin, user_input);
        if(user_input == "1")
        {
            BankAccount account;
            account.create_account(account);
        }
        else if(user_input == "2")
        {   
            std::string iban = ask_iban();
            int money = 0;
             auto it = all_accounts_.find(iban);
             if (it != all_accounts_.end()) {
                std::cout << "How much money would you like to save?: ";
                std::cin>>money;
                std::cin.ignore(); 
                it->second.save_money(money);
            } else {
                std::cout << "Account not found." << std::endl;
            }
            
        }
        else if(user_input == "3")
        {
            int money = 0;
             std::string iban = ask_iban();
             auto it = all_accounts_.find(iban);
             if (it != all_accounts_.end()) {
                std::cout << "How much money would you like to take?: ";
                std::cin>>money;
                std::cin.ignore(); 
                it->second.take_money(money);
            } else {
                std::cout << "Account not found." << std::endl;
            }    

        }
        else if (user_input == "4")
        {
            std::string iban = ask_iban();
            auto it = all_accounts_.find(iban);
            if (it != all_accounts_.end()) {
                it->second.print();
            } else {
                std::cout << "Account not found." << std::endl;
            }
        }

        else if(user_input == "Q" or user_input == "q")
        {
            return EXIT_SUCCESS;
        }
 
    }
 return 0;
}

void print_help()
{
    using std::cout;
    using std::endl;

    cout << "Press 1 to create a new account." << endl;
    cout << "Press 2 to put money into account." << endl;
    cout << "Press 3 to withdraw money from account." << endl;
    cout << "Press 4 to print account information." << endl;
    cout << "Press Q or q to quit the program." << endl;
 
}
std::string ask_iban()
{
    std::string iban = "";
    std::cout << "Input iban of the account you want to access: ";
    std::getline(std::cin, iban);
    return iban;
}
