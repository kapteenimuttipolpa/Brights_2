#include "../include/custom_int.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>

int CustomInt::counter = 0;
CustomInt::CustomInt() {
  m_value = 0;
  if (m_value < 0) {
    throw std::runtime_error("Negative integer constructed");
  }
  ++counter;
}
// Operation overloads
int64_t &CustomInt::operator=(CustomInt const &obj) {
  this->m_value = obj.m_value;
  return this->m_value;
}
int64_t &CustomInt::operator=(const int val) {
  this->m_value = val;
  return this->m_value;
}
int64_t &CustomInt::operator+(CustomInt const &obj) {
  this->m_value += obj.m_value;
    
  return this->m_value;
}

int64_t &CustomInt::operator+(const int val) { return this->m_value += val; }
int64_t &CustomInt::operator+=(CustomInt const &obj) {
  this->m_value += obj.m_value;
  return this->m_value;
}

int64_t &CustomInt::operator+=(const int val) {
  this->m_value += val;
  return this->m_value;
}
int64_t &CustomInt::operator-(CustomInt const &obj) {
   this->m_value -= obj.m_value;
   if(this->m_value < 0){
    this->m_value = 0;
   }
   return this->m_value;
}

int64_t &CustomInt::operator-(const int val) {
   this->m_value -= val;
   if(this->m_value < 0){
    this->m_value = 0;
   }
   return this->m_value;
}
int64_t &CustomInt::operator-=(CustomInt const &obj) {
   this->m_value -= obj.m_value;
   if(this->m_value < 0){
    this->m_value = 0;
   }
   return this->m_value;
}
int64_t &CustomInt::operator-=(const int val) {
   this->m_value -= val;
   if(this->m_value < 0){
    this->m_value = 0;
   }
   return this->m_value;
}
// end Operation overloads
void CustomInt::set_value(const int value) { m_value = value; }
const int64_t &CustomInt::get_value() const { return m_value; }
void CustomInt::print() const { std::cout << m_value << '\n'; }
void CustomInt::print_counter_value() const { std::cout << counter << '\n'; }

CustomInt::~CustomInt() { --counter; };
