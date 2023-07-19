#include "../include/custom_int.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
#include <limits>
#include <stdexcept>

int CustomInt::counter = 0;
CustomInt::CustomInt(int32_t val) {
  if (val < 0) {
    m_value = 0;
  } else {
    m_value = val;
  }
  ++counter;
}
CustomInt::CustomInt() noexcept{
  ++counter;
}
// Operation overloads
CustomInt &CustomInt::operator=(const CustomInt &obj) {
  this->m_value = obj.m_value;
  return *this;
}
CustomInt &CustomInt::operator=(const int32_t &val) {
  this->m_value = val;
  return *this;
}
int32_t CustomInt::operator+(const CustomInt &obj) {
  if (!is_result_overflown(this->m_value, obj.m_value)) {
    return this->m_value += obj.m_value;
  }
  throw std::overflow_error("int32_t overflowed");
}

int32_t CustomInt::operator+(const int32_t &val) {
  if (!is_result_overflown(this->m_value, val)) {
    return this->m_value += val;
  }
  throw std::overflow_error("int32_t overflowed");
}
CustomInt &CustomInt::operator+=(const CustomInt &obj) {
  if (!is_result_overflown(this->m_value, obj.m_value)) {
    this->m_value += obj.m_value;
    return *this;
  }
  throw std::overflow_error("int32_t overflowed");
}

CustomInt &CustomInt::operator+=(const int32_t &val) {
  if (!is_result_overflown(this->m_value, val)) {
    this->m_value += val;
    return *this;
  }
  throw std::overflow_error("int32_t overflowed");
}
CustomInt &CustomInt::operator-(const CustomInt &obj) {
  this->m_value -= obj.m_value;
  if (this->m_value < 0) {
    this->m_value = 0;
  }
  return *this;
}

CustomInt &CustomInt::operator-(const int32_t &val) {
  this->m_value -= val;
  if (this->m_value < 0) {
    this->m_value = 0;
  }
  return *this;
}
CustomInt &CustomInt::operator-=(const CustomInt &obj) {
  this->m_value -= obj.m_value;
  if (this->m_value < 0) {
    this->m_value = 0;
  }
  return *this;
}
CustomInt &CustomInt::operator-=(const int32_t &val) {
  this->m_value -= val;
  if (this->m_value < 0) {
    this->m_value = 0;
  }
  return *this;
}
// end Operation overloads
CustomInt friendly_addition(CustomInt &obj1, CustomInt &obj2) {
  int64_t res =
      static_cast<int64_t>(obj1.m_value) + static_cast<int64_t>(obj2.m_value);
  if (res > std::numeric_limits<int32_t>::max()) {
    throw std::overflow_error("int32_t overflowed");
  }
  CustomInt temp;
  temp = obj1.m_value + obj2.m_value;
  return temp;
}
CustomInt friendly_subtraction(CustomInt &obj1, CustomInt &obj2) {
  CustomInt temp;
  if (obj1.m_value - obj2.m_value < 0) {
    temp = 0;
    return temp;
  }
  temp = obj1.m_value -= obj2.m_value;
  return temp;
}
void CustomInt::set_value(const uint32_t &value) { m_value = value; }
const int32_t &CustomInt::get_value() const { return m_value; }
// Checks if uint32_t overflows
bool CustomInt::is_result_overflown(const int32_t &first_val,
                                    const int32_t &second_val) const {
  int64_t res =
      static_cast<int64_t>(first_val) + static_cast<int64_t>(second_val);
  return res > std::numeric_limits<int32_t>::max();
}
void CustomInt::print() const { std::cout << m_value << '\n'; }
int CustomInt::print_counter_value() const {
  std::cout << counter << '\n';
  return counter;
}

CustomInt::~CustomInt() { --counter; };
