#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "math_utils.h"

TEST_CASE("Test math operations")
{
    SUBCASE("Test addition")
    {
        CHECK(add(1.25, 1.25) == 2.5);
        CHECK(add(0, 1) == 1);
    }
    SUBCASE("Test subtract")
    {
        CHECK(subtract(1.5, 1.5) == 0);
        CHECK(subtract(-1.5, -1.5) == 0);
    }
    SUBCASE("Test multiply")
    {
        CHECK(multiply(5.1, 2) == 10.2);
        CHECK(multiply(5.0, -1) == -5.0);
    }
    SUBCASE("Test division")
    {
        CHECK_THROWS_AS(divide(10.0, 0.0), std::runtime_error);
        CHECK(divide(10.0, 2.0) == 5.0);
    }

}