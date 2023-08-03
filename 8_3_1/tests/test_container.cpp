#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../include/container.hpp"

TEST_CASE("test oma::array") {
  SUBCASE("Test constructing") {
    oma::array<int, 4> test{0, 1, 2, 3};
    CHECK(test.size() == 4);
    CHECK(*test.begin() == 0);
    CHECK(test.end() == (&test[3] + 1));
    oma::array<const char *, 3> test_str{"my", "name", "jeff"};
    CHECK(test_str.size() == 3);
    CHECK(*test_str.begin() == "my");
  }
  SUBCASE("Test copy and move constructor") {
    oma::array<int, 2> test{1, 2};
    oma::array<int, 2> test2{3, 4};
    test = test2;
    CHECK(test[0] == 3);
    CHECK(test2[0] == 3);
    oma::array<int, 2> test3 = std::move(test2);
    CHECK(test3[0] == 3);
  }
  SUBCASE("test overloads") {
    oma::array<int, 2> arr1{1, 2};
    oma::array<int, 2> arr2{3, 4};
    CHECK_FALSE(arr1 == arr2);
    CHECK((arr1 != arr2) == true);
    CHECK(arr1 == arr1);
  }
  SUBCASE("MoveAssignmentAndEmpty") {
    oma::array<int, 3> arr1{1, 2, 3};
    oma::array<int, 3> arr2;
    arr2 = std::move(arr1);
    CHECK_FALSE(arr2.empty());
  }
  SUBCASE("SwapFunction") {
    oma::array<int, 3> arr1{1, 2, 3};
    oma::array<int, 3> arr2{4, 5, 6};
    swap(arr1, arr2);
    CHECK(arr1[0] == 4);
    CHECK(arr2[0] == 1);
  }
  SUBCASE("SubscriptOperatorBoundary") {
    oma::array<int, 4> arr{1, 2, 3, 4};
    CHECK(arr[0] == 1);
    CHECK(arr[3] == 4);
    CHECK_THROWS_AS(arr[4],
                    std::runtime_error); // Expecting an out-of-range exception
  }
  // Test the const_iterator
  SUBCASE("ConstIterator") {
    const oma::array<int, 3> arr{1, 2, 3};
    int sum = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
      sum += *it;
    }
    CHECK(sum == 6);
  }
}