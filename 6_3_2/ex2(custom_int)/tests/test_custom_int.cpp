#include <cstdint>
#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../include/custom_int.hpp"
#include <limits>

TEST_CASE("Test constructing") {
  SUBCASE("Construct negative number") {
    CustomInt c(-10);
    REQUIRE(c.get_value() == 0);
  }
  SUBCASE("Construct valid number") {
    CustomInt c(100);
    REQUIRE(c.get_value() == 100);
  }
  SUBCASE("Construct with empty args") {
    CustomInt c;
    REQUIRE(c.get_value() == 0);
  }
}
TEST_CASE("Test overloads") {
  CustomInt c(10);
  CustomInt c2(20);

  SUBCASE("Test = overload") {
    c = c2;
    REQUIRE(c.get_value() == 20);
  }
  SUBCASE("Test + overload") {
    c = c + c2;
    REQUIRE(c.get_value() == 30);
  }
  SUBCASE("Test + overload with int") {
    c = c + 10;
    REQUIRE(c.get_value() == 20);
  }
  SUBCASE("Test += overload") {
    c += 10;
    REQUIRE(c.get_value() == 20);
    c += c2;
    REQUIRE(c.get_value() == 40);
  }
  SUBCASE("test - overload"){
    c = c - c2;
    REQUIRE(c.get_value()==0);
    c2 = c2 - 1;
    REQUIRE(c2.get_value() == 19);
  }
  SUBCASE("test -= overload"){
    c2 -= c;
    REQUIRE(c2.get_value() == 10);
    c2 -= 9;
    REQUIRE(c2.get_value() == 1);
  }
}
TEST_CASE("Test limits") {
  CustomInt c = 10;
  CustomInt big(std::numeric_limits<int32_t>::max());
  SUBCASE("Test overflow") {
    CHECK_THROWS_AS(big = big + 1, std::overflow_error);
    CHECK_THROWS_AS(big += 1, std::overflow_error);
    CHECK_THROWS_AS(big = big + c, std::overflow_error);
    CHECK_THROWS_AS(big += c, std::overflow_error);
  }
  SUBCASE("Test underflow"){
    c -= 100;
    REQUIRE(c.get_value() == 0);
    c -= std::numeric_limits<int32_t>::min();
    REQUIRE(c.get_value() == 0);
    c -= 1;
    REQUIRE(c.get_value() == 0);
  }
}
TEST_CASE("Test counter"){
    CustomInt* c = new CustomInt;
    CHECK(c->print_counter_value() == 1);
    CustomInt* c2 = new CustomInt;
    CHECK(c->print_counter_value() == 2);
    delete c;
    CHECK(c2->print_counter_value() == 1);
    delete c2;
    CustomInt c3;
    CHECK(c3.print_counter_value() == 1);
}
TEST_CASE("Test friend functions"){
    CustomInt c = 10;
    CustomInt c2 = 20;
    SUBCASE("Friendly addition"){
      c2 = friendly_addition(c, c2);
      REQUIRE(c2.get_value() == 30);
    }
    SUBCASE("Friendly subtraction"){
        c2 = friendly_subtraction(c2, c);
        REQUIRE(c2.get_value() == 10);
    }
    
}