#ifndef PERSONAL_FINANCE_H
#define PERSONAL_FINANCE_H
#include <string>
#include<vector>
#include <unordered_map>
struct Transaction{

    float money;
    std::string sender;
    std::string receiver;
    std::string time;
};

int add_transaction(std::vector<Transaction>& all_transactions, std::unordered_map<std::string, std::pair<float,float>>& totals);
void print_transactions(std::vector<Transaction>& all_transactions);
int write_transactions_to_file(std::vector<Transaction>& all_transactions);
void print_totals(std::vector<Transaction> &all_transactions, std::unordered_map<std::string, std::pair<float,float>>& totals);
#endif // PERSONAL_FINANCE





/*
Part 1.

Implement a struct called Transaction to store 
the necessary data for each financial transaction

Users should be able to add transactions and view them
Structure your code in multiple files
Your program needs to be built using CMake*/