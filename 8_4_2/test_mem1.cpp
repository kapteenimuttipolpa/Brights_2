#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "memerror1.hpp"

TEST_CASE("test mem1") {
  large_object a;
  CHECK(object_storage.size() == 1);
  large_object b = a;
  CHECK(object_storage.size() == 2);
  CHECK(object_storage[1].name == std::string("object number 0"));
}