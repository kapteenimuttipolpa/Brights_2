#include <cstdlib>
#include<iostream>
#include "./includes/personal_finance.h"
#include "./includes/utils.h"
#include <stdexcept>
#include <tuple>
#include<vector>
#include <string>
#include <unordered_map>
int main()
{
    std::vector<Transaction> all_transactions;
    std::unordered_map<std::string, std::pair<float,float>> totals;
    while(true){
        std::string choise{};
        std::cout << "Please choose from the following: \n (1)add transaction\n (2)print all transactions\n (3)print totals\n (4)print file contents\n";
        std::cout << " (5)quit the program\n";
        std::cout << " > ";
        std::getline(std::cin >> std::ws, choise);
        if(choise == "1"){
           int res = add_transaction(all_transactions, totals);
           if(res == INVALID_FILE){
            std::cout << "The file doesnt exist.\n";
            print_possible_files();
            continue;
           }
           else if(res == INVALID_FORMAT){
            std::cout << "Money given in wrong format. \n";
            continue;
           }
        }
        else if(choise == "2"){
            print_transactions(all_transactions);
        }
        else if(choise == "3"){
            print_totals(all_transactions, totals);
        }
        else if(choise == "4"){
            try{
                int res = print_file_contents();
            }catch(std::runtime_error const&e){
                std::cout << "Exception: " << e.what() << '\n';
                print_possible_files();
                continue;
            }
        }
        else if (choise == "5" or choise == "q" or choise == "quit") {
            return EXIT_SUCCESS;
        }
        else{
            std::cout << "Invalid input.\n";
            continue;
        }
    }
    
    
    
    return 0;
}