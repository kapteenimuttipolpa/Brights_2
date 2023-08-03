#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "counter.hpp"
#include "doctest.h"
TEST_CASE("test") {
  counter c1(0);
  counter c2 = std::move(c1);
  CHECK(counter::get_count() == 2);
  counter c3(1);
  c1 = std::move(c3);
  CHECK(c1.get_val() == 1); // true

  CHECK(counter::get_count() == 3);
  { // current count 3
    counter c4(2);
    CHECK(counter::get_count() == 4);
  } // count after this should be 3
  CHECK(counter::get_count() == 3);
}
