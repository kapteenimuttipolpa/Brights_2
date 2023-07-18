#include "../include/union.hpp"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <type_traits>
TaggedUnion::TaggedUnion() : union_type(Type::none), m_int_val(0) {}
TaggedUnion::TaggedUnion(const int& i) : union_type(Type::robot), m_int_val(i){};
TaggedUnion::TaggedUnion(const std::string &s) : union_type(Type::human), m_char_val(s.front()){};
TaggedUnion::TaggedUnion(const float& f) : union_type(Type::alien), m_float_val(f){};
Type TaggedUnion::get_union_tag() const noexcept { return union_type; }

void TaggedUnion::set_value(const int &int_val) noexcept {
  union_type = Type::robot;
  m_int_val = int_val;
}
void TaggedUnion::set_value(const char ch) noexcept {
  union_type = Type::human;
  m_char_val = ch;
}
void TaggedUnion::set_value(const float &float_val) noexcept {
  union_type = Type::alien;
  m_float_val = float_val;
}
void TaggedUnion::print() const {
  switch (union_type) {
  case Type::robot: {
    std::cout << "Type: robot, value: " << get_int_value() << '\n';
    break;
  }
  case Type::human: {
    std::cout << "Type: human, value: " << get_char_value() << '\n';
    break;
  }
  case Type::alien: {
    std::cout << "Type: alien, value: " << get_float_value() << '\n';
    break;
  }
  case Type::none: {
    std::cout << "No type, no val\n";
    break;
  }
  }
}
const int &TaggedUnion::get_int_value() const {
  assert(union_type == Type::robot);
  return m_int_val;
}
const char &TaggedUnion::get_char_value() const {
  assert(union_type == Type::human);
  return m_char_val;
}
const float &TaggedUnion::get_float_value() const {
  assert(union_type == Type::alien);
  return m_float_val;
}
TaggedUnion::~TaggedUnion() {}