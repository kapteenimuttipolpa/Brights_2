#pragma once
#include <cstddef>
#include <iostream>
#include <string>
class counter {
public:
  counter(int val) : _val(val) {
    std::cout << "created!\n";
    ++instance_count;
  }
  counter(const counter &other) = delete;
  counter &operator=(const counter &other) = delete;
  counter(counter &&other) {
    std::cout << "moved!\n";
    ++instance_count;
    other.is_moved_object = true;
    this->_val = other._val;
    other._val = 0;
  }
  ~counter() {
    std::cout << "destroyed!\n";
    if (!is_moved_object)
      --instance_count;
  }
  static size_t get_count() { return instance_count; }

  counter &operator=(counter &&other) {
    std::cout << "moved!\n";
    other.is_moved_object = true;
    this->_val = other._val;
    other._val = 0;
    return *this;
  }
  constexpr int get_val() const { return _val; }

private:
  inline static size_t instance_count;
  bool is_moved_object = false;
  int _val;
};