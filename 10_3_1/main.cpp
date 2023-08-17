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

    std::vector<std::string, allocator<std::string, 1024>> vec;
    vec.push_back("asdf");
    vec.push_back("asdfgasasf");

    for (const auto &elem : vec)
    {
        std::cout << elem << " ";
    }
    return 0;
}