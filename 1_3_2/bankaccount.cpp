#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include "bankaccount.h"



BankAccount::BankAccount(const std::string& name, const std::string& address, const std::string& tele_number)
    : name_(name), address_(address), tele_number_(tele_number) {
    generate_iban();
}
std::unordered_map<std::string, BankAccount> all_accounts_;
std::string input_file = "data.txt";

void BankAccount::create_account(BankAccount account)
{
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
    std::cout << "Account created with the IBAN number: "
              << account.iban_ << std::endl;
    write_to_file(all_accounts_, input_file);

}
int BankAccount::get_money() const{
    return money_;
}
void BankAccount::write_to_file(const std::unordered_map<std::string, BankAccount>& all_accounts, const std::string& filename)
{
    std::ofstream file_object(filename);
    if (!file_object){
        std::cout << "Error! The file couldn't be opened." << std::endl;
        return;
    }

    for(const auto& acc : all_accounts){
        const std::string& iban = acc.first;
        const BankAccount& account = acc.second;

        file_object << "IBAN: "<<iban << std::endl;
        file_object << "NAME: "<<account.get_name() << std::endl;
        file_object << "ADDRESS: "<<account.get_address() << std::endl;
        file_object << "PHONE NUM: "<<account.get_tele_num() << std::endl;
        file_object << "MONEY: "<<account.get_money() << std::endl;
    }

    file_object.close();
}


void BankAccount::save_money(int money)
{
    money_ += money;
    write_to_file(all_accounts_, input_file);   
}
void BankAccount::take_money(int money)
{
    money_ -= money;
    write_to_file(all_accounts_, input_file);
}
void BankAccount::print() const {
    std::cout << "Name: " << name_ << std::endl
              << "Address: " << address_ << std::endl
              << "Phone number: " << tele_number_ << std::endl
              << "Money: " << money_ << std::endl;
}


void BankAccount::set_name(std::string name)
{
    name_ = name;
}
std::string BankAccount::get_name() const
{
    return name_;
}
void BankAccount::set_address(std::string address)
{
    address_ = address;
}
std::string BankAccount::get_address() const
{
    return address_;
}
void BankAccount::set_tele_num(std::string tele_number)
{
    tele_number_ = tele_number;
}
std::string BankAccount::get_tele_num() const
{
    return tele_number_;
}

int BankAccount::running_number_ = 0;
void BankAccount::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10){
        suffix.append("0");
    }
    else if(running_number_ > 99){
        std::cout << "Too many bank accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));
    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
