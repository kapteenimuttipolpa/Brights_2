#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <exception>

/*
 * Here I create a BankAccount Class
 */
 

class BankAccount
{
public:
    BankAccount(const std::string &name = "", const std::string &address = "", const std::string &tele_number = "");

    void print() const;
    std::string get_iban() const;
    void take_money(int money, std::unordered_map<std::string, BankAccount>& all_accounts_);
    void save_money(int money, std::unordered_map<std::string, BankAccount>& all_accounts_);
    void set_name(std::string name);
    std::string get_name() const;
    void set_address(std::string address);
    std::string get_address() const;
    void set_tele_num(std::string tele_number);
    std::string get_tele_num() const;
    void create_account(BankAccount account, std::unordered_map<std::string, BankAccount>& all_accounts_);
    void write_to_file(const std::unordered_map<std::string, BankAccount> &all_accounts, const std::string &filename);
    int get_money() const;
    void create_other_account(BankAccount *account);
    void manage_other_account(BankAccount *account, std::unordered_map<std::string, BankAccount>& all_accounts_);

private:
    std::string iban_;
    std::string name_;
    std::string address_;
    std::string tele_number_;
    std::unordered_map<std::string, int> other_accs_;
    static int running_number_;
    int money_ = 0;
    void generate_iban();
};

#endif // BANKACCOUNT_H