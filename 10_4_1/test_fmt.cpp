#include "fmt/core.h"
#include <iostream>
#include <string>

struct person
{
    int age = 25;
    int weight = 200;
    int height = 140;
};
int main()
{
    person p;
    std::string asd = fmt::format("hello {} {} {}", p.age, p.weight, p.height);

    std::cout << asd;
    return 0;
}