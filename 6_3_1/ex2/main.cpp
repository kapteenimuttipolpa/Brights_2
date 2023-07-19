#include "ex2.hpp"
#include <iostream>

int main() {
  Animal animal;
  Wings wings;
  Eyes eyes;
  Bird bird;
  Parrot parrot;
  parrot.eyes.blink();
  parrot.talk();
  parrot.sleep();
  parrot.eat();
  parrot.wings.flap();
  parrot.set_age(10);
  return 0;
}