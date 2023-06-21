#include "../includes/bankaccount.h"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <climits>

BankAccount::BankAccount(const std::string &name, const std::string &address,
                         const std::string &tele_number)
    : name_(name), address_(address), tele_number_(tele_number) {
  generate_iban(); // call generate iban function when creating new object
}

/*std::unordered_map<std::string, BankAccount>
    all_accounts_;*/                   // place to store all accounts
std::string input_file = "data.txt"; // default text file path
/**
 * Creates new bankaccount with user given values*/

void BankAccount::create_account(BankAccount account, std::unordered_map<std::string, BankAccount>& all_accounts_) {
    std::string name = "";
    std::string address = "";
    std::string tele_number = "";

    std::cout << "Input name: ";
    std::getline(std::cin, name);
    account.set_name(name);
    std::cout << "Input address: ";
    std::getline(std::cin, address);
    account.set_address(address);

    std::cout << "Input telephone number: ";
    std::getline(std::cin, tele_number);
    account.set_tele_num(tele_number);

  all_accounts_[iban_] = account;
  std::cout << "Account created with the IBAN number: " << account.iban_
            << std::endl;
  write_to_file(all_accounts_, input_file);
}
int BankAccount::get_money() const { return money_; }
/*Function overwrites file as new data is inputted*/
void BankAccount::write_to_file(
    const std::unordered_map<std::string, BankAccount> &all_accounts,
    const std::string &filename) {
  std::ofstream file_object(filename);
  if (!file_object) // if file cannot be opened
  {
    std::cout << "Error! The file couldn't be opened." << std::endl;
    return;
  }

  for (const auto &acc : all_accounts) {
    const std::string &iban = acc.first;
    const BankAccount &account = acc.second;

    file_object << "IBAN: " << iban << std::endl;
    file_object << "NAME: " << account.get_name() << std::endl;
    file_object << "ADDRESS: " << account.get_address() << std::endl;
    file_object << "PHONE NUM: " << account.get_tele_num() << std::endl;
    file_object << "MONEY: " << account.get_money() << std::endl;
    if (!account.other_accs_.empty()) {
      file_object << "OTHER ACCOUNTS: " << std::endl;
      for (auto acc : account.other_accs_) // loop writes the data if user has
                                           // multiple accounts
      {
        file_object << "NAME: " << acc.first << std::endl;
        file_object << "MONEY: " << acc.second << std::endl;
      }
    }
  }

  file_object.close();
}
/*function adds money*/
void BankAccount::save_money(int money, std::unordered_map<std::string, BankAccount>& all_accounts_) {
    if(money + money_ > INT_MAX){
        throw std::invalid_argument("Too large sum");
        return;
    }
  if (money >= 0) {
    money_ += money;
  } else{
    throw std::invalid_argument("Cant deposit negative amount");
  }
    
  write_to_file(all_accounts_, input_file);
}
/*function takes money from account*/
void BankAccount::take_money(int money, std::unordered_map<std::string, BankAccount>& all_accounts_) {
  if (money > money_) {
    throw std::invalid_argument("Cant withdraw more than account balance.");
  }
  if (money < 0) {
    throw std::invalid_argument("Cant withdraw negative amount!");
  }
  money_ -= money;
  write_to_file(all_accounts_, input_file);
}
/*Function prints account data*/
void BankAccount::print() const {
  std::cout << "Name: " << name_ << std::endl
            << "Address: " << address_ << std::endl
            << "Phone number: " << tele_number_ << std::endl
            << "Money: " << money_ << std::endl;
  for (auto acc : other_accs_) {
    std::cout << "Account name: " << acc.first << "\n"
              << "Money: " << acc.second << "\n";
  }
}
/*some setters and getters*/
void BankAccount::set_name(std::string name) {
  for (char c : name) {
    if (!std::isalpha(c)) {
      throw std::invalid_argument("Only alphabets allowed");
    }
  }
  name_ = name;
}
/**
 * @brief getter for name
 *
 * @return std::string
 */
std::string BankAccount::get_name() const { return name_; }
/**
 * @brief setter for address
 *
 * @param address
 */
void BankAccount::set_address(std::string address) { address_ = address; }
/**
 * @brief getter for address
 *
 * @return std::string
 */
std::string BankAccount::get_address() const { return address_; }
/**
 * @brief setter for tele number
 *
 * @param tele_number
 */
void BankAccount::set_tele_num(std::string tele_number) {
  for (char c : tele_number) {
    if (!isdigit(c)) {
      throw std::invalid_argument("Only digits allowed");
    }
  }
  tele_number_ = tele_number;
}
std::string BankAccount::get_tele_num() const { return tele_number_; }
std::string BankAccount::get_iban() const { return iban_; }
// creates other account for user ie. Savings account
void BankAccount::create_other_account(BankAccount *account) {
  std::string new_acc = "";
  int money = 0;
  std::cout << "Input id for your new account: ";
  std::getline(std::cin, new_acc);
  if (account->other_accs_.find(new_acc) != account->other_accs_.end()) {
    std::cout << "Account id has to be unique. \n";
    return;
  }
  std::cout
      << "How much money would you like to deposit to your new account? : ";
  std::cin >> money;
      if(!std::cin){ //another way to validate that user doesnt input too large sum
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Too large sum!\n";
        return;
    }
    std::cin.clear();
  if (money < 0) {
    std::cout << "Error! Cannot deposit a negative number. \n";
    return;
  }
  account->other_accs_[new_acc] = money;
}
/**
 * Function is used to put money on sub accounts or take money from them
 */
void BankAccount::manage_other_account(BankAccount *account, std::unordered_map<std::string, BankAccount>& all_accounts_) {
  std::string selected_acc = "";
  std::cout << "Please select what account you would like to modify. \n";
  for (auto account : account->other_accs_) {
    std::cout << account.first << "\n";
  }
  std::getline(std::cin, selected_acc);
  if (account->other_accs_.find(selected_acc) == account->other_accs_.end()) {
    std::cout << "No account found."
              << "\n";
    return;
  }
  std::string user_choise = "";
  std::cout << "Press 1 to put money into account. \n";
  std::cout << "Press 2 to take money from account. \n";
  std::getline(std::cin, user_choise);
  if (user_choise == "1") {
    int money = 0;
    std::cout << "Enter the amount: ";
    std::cin >> money;
    std::cin.ignore();
    if(!std::cin){ //another way to validate that user doesnt input too large sum
        std::cin.clear(); //if user inputs amount that is bigger than INT_MAX
        std::cin.ignore(); //std::cin will have numbers left and we know to return
        std::cout << "Too large sum!\n";
        return;
    }
    std::cin.clear();
    if(money < 0){
        std::cout << "Cant deposit negative amount. \n";
        return;
    }
    account->other_accs_[selected_acc] += money;
  }
  if (user_choise == "2") {
    int money = 0;
    std::cout << "Enter withdraw amount: ";
    std::cin >> money;
        if(!std::cin){ //another way to validate that user doesnt input too large sum
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Too large sum!\n";
        return;
    }
    std::cin.clear();
    if(money < 0){
        std::cout << "Cant withdraw negative amount. \n";
        return;
    }
    if (account->other_accs_[selected_acc] < money) {
      std::cout << "Cant withdraw more than you have. \n";
      return;
    }
    account->other_accs_[selected_acc] -= money;
  }
  write_to_file(all_accounts_, input_file);
}
/*Function for generatin iban*/
int BankAccount::running_number_ = 0;
void BankAccount::generate_iban() {
  ++running_number_;
  std::string suffix = "";
  if (running_number_ < 10) {
    suffix.append("0");
  } else if (running_number_ > 99) {
    std::cout << "Too many bank accounts" << std::endl;
  }
  suffix.append(std::to_string(running_number_));
  iban_ = "FI00 1234 ";
  iban_.append(suffix);
}
