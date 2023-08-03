#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror3.hpp"
TEST_CASE("test mem3") {
  CHECK_NOTHROW(auto wrapped2 = build_wrapper(););
  auto wrapped2 = build_wrapper();
  CHECK_NOTHROW(wrapped2.do_stuff(););
}