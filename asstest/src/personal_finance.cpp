#include "../includes/personal_finance.h"
// include "../external/doctest.h"
#include "../includes/utils.h"
#include <algorithm>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief add_transaction
 *  adds a new transaction
 * @param all_transactions 
 * @param totals 
 * @return int 
 */
int add_transaction(std::vector<Transaction> &all_transactions, std::unordered_map<std::string, std::pair<float,float>>& totals) {
    
  std::string sender{};
  std::string receiver{};
  float money{};

  while (true) {
    std::cout << "Input sender id: ";
    std::getline(std::cin >> std::ws, sender);
    std::cout << "Input receiver id: ";
    std::getline(std::cin >> std::ws, receiver);
    std::cout << "Input the amount: ";
    std::cin >> money;
    if (!clear_cin()) {
      return INVALID_FORMAT;
    } else
      break;
  }

  //gets the current time
  std::time_t t = std::time(0);
  std::tm *now = std::localtime(&t);
  std::string hours = std::to_string(now->tm_hour);
  std::string minutes = std::to_string(now->tm_min);
  std::string time_s = hours + ":" + minutes;

  Transaction new_transaction{money, sender, receiver, time_s};
  all_transactions.push_back(new_transaction);

    //some book keeping
  totals[sender].first -= money;
  totals[receiver].second +=money;

  try {
    write_transactions_to_file(all_transactions);
  } catch (std::runtime_error const &e) {
    std::cout << "Exception: " << e.what() << '\n';
    return INVALID_FILE;
  }

  return true;
}
/**
 * @brief prints all transactions
 * 
 * @param all_transactions 
 */
void print_transactions(std::vector<Transaction> &all_transactions) {
  for (auto &transaction : all_transactions) {
    std::cout << transaction.sender << " sent " << transaction.money
              << " euros to " << transaction.receiver << " at "
              << transaction.time << '\n';
  }
}
/**
 * @brief write_transactions_to_file
 * writes all transactions to file if
 * valid file is given
 * @param all_transactions 
 * @return int 
 */
int write_transactions_to_file(std::vector<Transaction> &all_transactions) {
  std::string filename = {};
  std::cout << "Input file name to save data: ";
  std::getline(std::cin >> std::ws, filename);
  std::fstream file_object(filename);

  if (!file_object.is_open()) {
    throw std::runtime_error("File couldnt be opened.");
    return INVALID_FILE;
  }

  for (auto &transaction : all_transactions) {
    file_object << transaction.sender << " sent " << transaction.money
                << " euros to " << transaction.receiver << " at "
                << transaction.time << '\n';
  }
  file_object.close();
  return 0;
}
/**
 * @brief print_totals
 *  prints the total amount someone sent
    and received
 * @param all_transactions 
 * @param totals 
 */
void print_totals(std::vector<Transaction> &all_transactions, std::unordered_map<std::string, std::pair<float,float>>& totals)
{
    for(auto transaction : totals){
        std::cout << transaction.first << " sent total of " 
                  << transaction.second.first << " euros and received "
                  << transaction.second.second << " euros.\n"
                  << "Total amount is: " << transaction.second.first + transaction.second.second << '\n';

    }
}
