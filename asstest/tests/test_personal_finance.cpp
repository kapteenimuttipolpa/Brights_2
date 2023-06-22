#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../includes/personal_finance.h"
#include "../includes/utils.h"
#include <string>

TEST_CASE("Test add_transaction") {
  std::vector<Transaction> all_transactions;
  std::unordered_map<std::string, std::pair<float, float>> totals;

  SUBCASE("Valid transaction") {
    std::istringstream input("woofer\nmeower\n100\n");
    std::cin.rdbuf(input.rdbuf());

    bool result = add_transaction(all_transactions, totals);

    CHECK(result == true);
    CHECK(all_transactions.size() == 1);
    CHECK(totals["woofer"].first == -100.0f);
    CHECK(totals["meower"].second == 100.0f);
  }
}
TEST_CASE("Test print_totals") {
  std::vector<Transaction> all_transactions;
  std::unordered_map<std::string, std::pair<float, float>> totals;
  /**
   * @brief test printing empty totals 
   *  with reading std::cout buffer
   */
  SUBCASE("Empty totals") {
    std::ostringstream oss;
    std::streambuf *cout_sbuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf()); 

    print_totals(all_transactions, totals);

    std::cout.rdbuf(cout_sbuf); 

    std::string output = oss.str();
    CHECK(output.empty());
  }
  /**
   * @brief tests sending money and receiving
   *  money with readings the std::cout buffer
   */
  SUBCASE("Non empty totals") {
    all_transactions.push_back({100.0f, "doggo", "woofer", "10:00"});
    totals["doggo"] = {0.0f, 100.0f};
    totals["woofer"] = {100.0f, 0.0f};
    std::ostringstream oss;
    std::streambuf *cout_sbuf = std::cout.rdbuf(); 
    std::cout.rdbuf(oss.rdbuf()); 

    print_totals(all_transactions, totals);

    std::cout.rdbuf(cout_sbuf); 

    std::string output = oss.str();
    std::string expected_output =
        "woofer sent total of 0 euros and received 100 euros.\n"
        "Total amount is: 100\n"
        "doggo sent total of -100 euros and received 0 euros.\n"
        "Total amount is: -100\n";
       
  }
}