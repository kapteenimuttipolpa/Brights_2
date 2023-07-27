#include "./include/animal.hpp"

int main() {
    all_animals.push_back(std::make_unique<dog>());
    all_animals.push_back(std::make_unique<cat>());
    all_animals.push_back(std::make_unique<monke>());
    all_animals.push_back(std::make_unique<snake>());
    for (auto &animal : all_animals) {
        info(*animal);
    }
    print_all();
    return 0;
}