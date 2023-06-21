#include <fstream>
#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../includes/bankaccount.h"
#include <unordered_map>
#include <string>

TEST_CASE("test_bank_account") {
    BankAccount account1("bob", "test st", "1234");
    BankAccount account2("bober", "123 st", "545454545454");
    std::unordered_map<std::string, BankAccount> all_accounts;
    all_accounts.emplace(account1.get_iban(), account1);

    SUBCASE("test_money")
    {
        account1.save_money(100, all_accounts);
        CHECK(account1.get_money() == 100);
        account1.take_money(100, all_accounts);
        CHECK(account1.get_money() == 0);
        CHECK_THROWS_AS(account1.take_money(100, all_accounts), std::invalid_argument);

    }

    SUBCASE("test_print") {
        std::stringstream output;
        std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf()); // reads the buffer
        std::string money = std::to_string(account1.get_money());
        std::string other_accs{};
        account1.print();

        std::cout.rdbuf(old_cout);
        std::string expected_output = "Name: bob\nAddress: test st\nPhone number: 1234\nMoney: " + money + '\n';
        CHECK(output.str() == expected_output);

    }

    SUBCASE("Test file")
    {
        // test writing to file
        std::string filename = "accounts.txt";
        account1.write_to_file(all_accounts, filename);
        std::string iban = account1.get_iban();
        std::string name = account1.get_name();
        std::string address = account1.get_address();
        std::string num = account1.get_tele_num();
        std::string money = std::to_string(account1.get_money());

        std::ifstream file_object(filename);
        std::string line {};
        std::string file_contents;
        while (std::getline(file_object, line)) {
            file_contents += line + "\n";
        }
        file_object.close();

        std::string expected_file_contents = 
        "IBAN: " + iban + '\n' + 
        "NAME: " + name +'\n' +
        "ADDRESS: " + address + '\n' +
        "PHONE NUM: " + num + '\n'+
        "MONEY: " + money + '\n';
        CHECK(file_contents == expected_file_contents);
    }
    
}