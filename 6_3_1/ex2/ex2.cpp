#include "ex2.hpp"
#include <iostream>
using std::cout;
Animal::Animal() { cout << "Animal created\n"; };
Animal::~Animal() { cout << "Animal destoryed\n"; };
Wings::Wings() { cout << "Wings created\n"; };
Wings::~Wings() { cout << "Wings destroyed\n"; };
Eyes::Eyes() { cout << "Eyes created\n"; };
Eyes::~Eyes() { cout << "Eyes destroyed\n"; };
Bird::Bird() { cout << "Bird created\n"; };
Bird::~Bird() { cout << "Bird destroyed\n"; };
Parrot::Parrot() { cout << "Parrot created\n"; };
Parrot::~Parrot() { cout << "Parrot destroyed\n"; };

void Animal::sleep() { cout << "sleeping..\n"; }
void Bird::eat() { cout << "Bird is eating!\n"; }
void Parrot::talk() { cout << " parrot says hello!\n"; }
void Eyes::blink() { cout << "blinking eyes\n"; }
void Wings::flap() { cout << "flap flap\n"; }