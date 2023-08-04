#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror2.hpp"
#include <string>

TEST_CASE("test mem2") {
  std::string test{"asdf"};
  flawed_array<std::string, 2> arr;
  CHECK_THROWS(arr[0] = test);
}