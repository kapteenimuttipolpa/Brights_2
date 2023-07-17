#include "../include/union.hpp"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <type_traits>
TaggedUnion::TaggedUnion() : union_type(Type::none), int_val_(0) {}
Type TaggedUnion::get_union_type() const noexcept { return union_type; }

void TaggedUnion::set_type(const int &int_val) noexcept {
  union_type = Type::robot;
  int_val_ = int_val;
}
void TaggedUnion::set_type(const char ch) noexcept {
  union_type = Type::human;
  char_val_ = ch;
}
void TaggedUnion::set_type(const float &float_val) noexcept {
  union_type = Type::alien;
  float_val_ = float_val;
}
void TaggedUnion::print() const {
  switch (union_type) {
  case Type::robot: {
    std::cout << "Type: robot, value: " << int_val_ << '\n';
    break;
  }
  case Type::human: {
    std::cout << "Type: human, value: " << char_val_ << '\n';
    break;
  }
  case Type::alien: {
    std::cout << "Type: alien, value: " << float_val_ << '\n';
    break;
  }
  case Type::none: {
    std::cout << "No type, no val\n";
    break;
  }
  }
}
TaggedUnion::~TaggedUnion() {}