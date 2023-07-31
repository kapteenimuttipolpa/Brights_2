#include "animal.hpp"
#include <fstream>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace animals {
dog::dog(species type, std::string &name) : m_type(type), m_name(name) {}
cat::cat(species type, std::string &name) : m_type(type), m_name(name) {}
unknown::unknown(species type, std::string &name)
    : m_type(species::None), m_name("NO NAME") {}
void dog::make_noise() {
    std::cout << "Woof woof i am dog and my name is: " << m_name << "\n";
}
void cat::make_noise() {
    std::cout << "Meow i am cat and my name is: " << m_name << "\n";
}
void unknown::make_noise() { std::cout << "unknown animal type.\n"; }
/**
 * @brief read_from file
 * reads species and name from text file
 * creates unique ptr to corresponding animal
 * to all_animals vector
 * @param file_name
 * @return animal_vec
 */
animal_vec read_from_file(const std::string &file_name) {
    animal_vec all_animals;
    std::fstream file_object(file_name);
    if (!file_object) {
        throw std::runtime_error("Cannot open file");
    }
    std::string temp;
    while (std::getline(file_object, temp)) {
        std::istringstream iss(temp);
        std::string species;
        std::string name;

        std::getline(iss >> std::ws, species, ',');
        std::getline(iss >> std::ws, name);
        if (species == "Dog") {
            all_animals.push_back(std::make_unique<dog>(species::Dog, name));
        } else if (species == "Cat") {
            all_animals.push_back(std::make_unique<cat>(species::Cat, name));
        } else {
            all_animals.push_back(
                std::make_unique<unknown>(species::None, name));
        }
    }
    file_object.close();
    return all_animals;
}
void print_animals(const animal_vec &all_animals) {
    for (const auto &animal : all_animals) {
        animal->make_noise();
    }
}
} // namespace animals