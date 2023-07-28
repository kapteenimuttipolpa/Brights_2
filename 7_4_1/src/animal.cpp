#include "../include/animal.hpp"
#include <ios>
#include <memory>
dog::dog() { name = "buddy"; }
cat::cat() { name = "garfield"; }
monke::monke() { name = "george"; }
snake::snake() { name = "lidl snake"; }

bool animal::is_fluffy() const { return true; }
bool animal::is_venomous() const { return false; }
void dog::make_sound() const { std::cout << "woof woof\n"; }
void cat::make_sound() const { std::cout << "meow\n"; }
void monke::make_sound() const { std::cout << "u u a a a\n"; }
void snake::make_sound() const { std::cout << "hissss\n"; }
bool snake::is_fluffy() const { return false; }
bool snake::is_venomous() const { return true; }
void info(const animal &any_animal) {
    any_animal.make_sound();
    std::cout << "Name: " << any_animal.name << '\n';
    std::cout << std::boolalpha << "is fluffy?: " << any_animal.is_fluffy()
              << '\n';
    std::cout << std::boolalpha << "is venomous?: " << any_animal.is_venomous()
              << '\n';
}
