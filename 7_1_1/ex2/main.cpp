#include "./include/grid2d.hpp"
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    utils::grid2d<int> grid{2, 2};
    grid(0, 0) = 1;
    grid(0, 1) = 2;
    grid(1, 0) = 3;
    grid(1, 1) = 4;
    grid.print();
    return 0;
}