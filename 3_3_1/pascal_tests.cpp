#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pascal.h"
#include<string>
#include<iostream>
#include <sstream>



TEST_CASE("Factorial tests")
{    
    CHECK(find_factorial(0) == 1);
    CHECK(find_factorial(1) == 1);
    CHECK(find_factorial(5) == 120);
}
TEST_CASE("Combination tests")
{

    CHECK(combination(0,0) == 1);
    CHECK(combination(5, 2) == 10);

}
TEST_CASE("Pascal function tests")
{
    SUBCASE("Test pascal with 0")
    {
        std::stringstream output;
        std::streambuf* old = std::cout.rdbuf(output.rdbuf());

        pascal(0);

        std::cout.rdbuf(old);
        CHECK(output.str().empty());
    }
    SUBCASE("Test pascal with 4")
    {
        std::stringstream output;
        std::streambuf* old = std::cout.rdbuf(output.rdbuf());

        pascal(5);

        std::cout.rdbuf(old);

        // Define the expected output for 5 rows
        std::string expectedOutput =
            "1 \n"
            "1 1 \n"
            "1 2 1 \n"
            "1 3 3 1 \n"
            "1 4 6 4 1 \n";

        // Check that the output matches the expected output
        CHECK_EQ(output.str(), expectedOutput);
    }
        
}
