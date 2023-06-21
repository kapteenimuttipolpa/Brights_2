#include <iterator>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string_utils.h"
#include <string>

TEST_CASE("Test reversing a string")
{
    CHECK(reverse("Moi") == "ioM");
}

TEST_CASE("Test converting to uppercase")
{
    CHECK(to_upper("moI") == "MOI");
}

TEST_CASE("Test is_palindrome")
{
    CHECK(is_palindrome("saippuakauppias") == true);
    CHECK(is_palindrome("a race car") == false);
    CHECK(is_palindrome("abba") == true);
    CHECK(is_palindrome("aa") == true);
    CHECK(is_palindrome("a") == true);
    CHECK(is_palindrome("A man, a plan, a canal: Panama") == false); // would be true if i removed all non alphabets
}