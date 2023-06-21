
#include "doctest.h"
#include "pascal.h"
#include <iostream>
int main()
{
    int rows{};
    std::cout << "Input rows: ";
    std::cin >> rows;
    pascal(rows);
    return 0;
}