#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../include/grid2d.hpp"

TEST_CASE("Test grid2d functionality") {
  utils::grid2d<int> grid(2, 2);
  utils::grid2d<float> grid2(3, 3);
  SUBCASE("test init") {
    CHECK(grid.size() == 4);
    CHECK(grid2.size() == 9);
  }
  SUBCASE("test assigning values") {
    grid(0, 0) = 1;
    auto it = grid.begin();
    CHECK(*it == 1);
    grid(1, 1) = 40;
    CHECK(grid(1, 1) == 40);
    grid2(0, 0) = 1.23f;
    CHECK(grid2(0, 0) == 1.23f);
  }
  SUBCASE("test resize") {
    grid(0, 0) = 1;
    grid(0, 1) = 2;
    grid(1, 0) = 3;
    grid(1, 1) = 4;
    grid.resize(3, 3);
    CHECK(grid(0, 0) == 1);
    CHECK(grid(0, 1) == 2);
    CHECK(grid(0, 2) == 0);

    CHECK(grid(1, 0) == 3);
    CHECK(grid(1, 1) == 4);
    CHECK(grid(1, 2) == 0);

    CHECK(grid(2, 0) == 0);
    CHECK(grid(2, 1) == 0);
    CHECK(grid(2, 2) == 0);
    CHECK(grid.size() == 9);
    grid.resize(2, 1);
    CHECK(grid(0, 0) == 1);
    CHECK(grid(0, 1) == 2);
    CHECK(grid.size() == 2);
  }
  SUBCASE("Test bounds") {
    CHECK_THROWS_AS((grid(3, 4) = 5), std::out_of_range);
    CHECK_THROWS((utils::grid2d<int>(1000000000000, 1000000000000)));
    CHECK_THROWS((utils::grid2d<float>(-1, 10)));
    CHECK_THROWS(grid.resize(10000000000, 100000000));
    CHECK_THROWS(grid(-1, -1) = 3);
  }
  SUBCASE("Test empty()") {
    utils::grid2d<int> temp_grid;
    CHECK(temp_grid.empty() == true);
    utils::grid2d<int> temp_grid2(1, 1);
    CHECK(temp_grid2.empty() == false);
  }
  SUBCASE("Test .at()") {
    grid(0, 0) = 1;
    CHECK(grid.at(0, 0) == 1);
    CHECK_THROWS(grid.at(100, 100));
  }
  SUBCASE("Test moving") {
    utils::grid2d<int> grid_to_move{2, 2};
    grid_to_move(0, 0) = 1;
    grid_to_move(0, 1) = 1;
    grid_to_move(1, 0) = 1;
    grid_to_move(1, 1) = 1;
    utils::grid2d<int> new_grid = std::move(grid_to_move);
    CHECK(new_grid.at(0, 0) == 1);
    CHECK(new_grid.at(0, 1) == 1);
    CHECK(new_grid.at(1, 0) == 1);
    CHECK(new_grid.at(1, 1) == 1);
    utils::grid2d<int> copied_grid = new_grid;
    CHECK(new_grid.at(0, 0) == 1);
    CHECK(new_grid.at(0, 1) == 1);
    CHECK(new_grid.at(1, 0) == 1);
    CHECK(new_grid.at(1, 1) == 1);

    CHECK(copied_grid.at(0, 0) == 1);
    CHECK(copied_grid.at(0, 1) == 1);
    CHECK(copied_grid.at(1, 0) == 1);
    CHECK(copied_grid.at(1, 1) == 1);
  }
}