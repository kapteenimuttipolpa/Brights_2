#include "bankaccount.cpp"
#include "bankaccount.h"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include <limits>
// defining some helper functions
void print_help();
std::string ask_iban();
/*
 * in main function im just asking user what commands to do
 * and call functions accordingly.
 */
int main()
{
    std::string user_input = "";
    std::cout << "Welcome to the bank!" << std::endl;
    BankAccount *current_account = nullptr; // pointer that points to the current account user is signed into
    //if current_account pointer points to nothing (nullptr)
    //user isnt signed into any account.
    //made this so user doesnt need to input iban every time 
    //they want to access some account
    while (true)
    {

        std::cout << std::endl;
        print_help();
        std::getline(std::cin, user_input);
        if (user_input == "1")
        {
            BankAccount account;
            account.create_account(account);
        }
        else if (user_input == "2")
        {
            std::string iban = ask_iban();
            auto it = all_accounts_.find(iban);
            if (it != all_accounts_.end())
            {
                current_account = &it->second; // switch account
                std::cout << "Signed into : " << current_account->get_iban();
            }
        }
        else if (user_input == "3")
        {

            //int money {};
            long long value{}; // if user tries to deposit more than this
            std::string money_s{};
            if (current_account != nullptr)
            {
                std::cout << "How much money would you like to save?: ";
                std::getline(std::cin >> std::ws, money_s);
                try{
                    value = std::stoll(money_s);
                    if(value > std::numeric_limits<int>::max()){ //check that value fits into integer
                        std::cout << "Too large sum\n";
                        continue;
                    }
                }
                catch(std::exception const& e){
                    std::cout << "Too large sum\n";
                }
                int money = static_cast<int>(value); // cast long long int to int

                try{
                    current_account->save_money(money);
                }
                catch(std::invalid_argument const &e){
                    std::cout << "Exception: " << e.what();
                    continue;
                }
                
            }
            else
            {
                std::cout << "Please sign in first." << std::endl;
            }
        }
        else if (user_input == "4")
        {
            int money {};
            if (current_account != nullptr)
            {
                std::cout << "How much money would you like to take?: ";
                std::cin >> money;
                if(!std::cin){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Too large sum.";
                    continue;
                }
                try{
                    current_account->take_money(money);
                }
                catch(std::invalid_argument const &e){
                    std::cout << "Exception: " << e.what();
                    continue;
                }
                
            }

            else
            {
                std::cout << "Please sign in first." << std::endl;
            }
        }
        else if (user_input == "5")
        {

            if (current_account != nullptr)
            {
                current_account->print();
            }
            else
            {
                std::cout << "Account not found." << std::endl;
            }
        }
        else if (user_input == "6")
        {
            if (current_account != nullptr)
            {
                current_account->create_other_account(current_account);
            }
        }
        else if (user_input == "7")
        {
            current_account->manage_other_account(current_account);
        }
        else if (user_input == "Q" or user_input == "q")
        {
            return EXIT_SUCCESS;
        }
    }

    return 0;
}
/*
 * Separate function to print help text.
 */
void print_help()
{
    using std::cout;
    using std::endl;

    cout << "Press 1 to create a new account." << endl;
    cout << "Press 2 to sign into a new account." << endl;
    cout << "Press 3 to put money into account." << endl;
    cout << "Press 4 to withdraw money from account." << endl;
    cout << "Press 5 to print account information." << endl;
    cout << "Press 6 to add new account to your current." << endl;
    cout << "Press 7 to manage your other accounts." << endl;
    cout << "Press Q or q to quit the program." << endl;
}
/*
 * Function for asking user what account they want to access
 */
std::string ask_iban()
{
    std::string iban = "";
    std::cout << "Input iban of the account you want to access: ";
    std::getline(std::cin, iban);
    return iban;
}
