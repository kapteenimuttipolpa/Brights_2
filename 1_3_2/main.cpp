#include "bankaccount.cpp"
#include "bankaccount.h"
#include <string>
#include <iostream>
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

            int money = 0;
            if (current_account != nullptr)
            {
                std::cout << "How much money would you like to save?: ";
                std::cin >> money;
                std::cin.ignore();

                current_account->save_money(money);
            }
            else
            {
                std::cout << "Please sign in first." << std::endl;
            }
        }
        else if (user_input == "4")
        {
            int money = 0;
            if (current_account != nullptr)
            {
                std::cout << "How much money would you like to take?: ";
                std::cin >> money;
                std::cin.ignore();
                current_account->take_money(money);
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
