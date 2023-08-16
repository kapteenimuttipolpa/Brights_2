#include "allocator.hpp"
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<int, allocator<int, 1024>> asd{1, 2, 3};

    for (const auto &val : asd)
    {
        std::cout << val << ' ';
    }
    return 0;
}