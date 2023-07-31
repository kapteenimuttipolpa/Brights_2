#include "animal.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

int main() {
    animals::animal_vec all_animals = animals::read_from_file("data.txt");

    animals::print_animals(all_animals);

    return 0;
}