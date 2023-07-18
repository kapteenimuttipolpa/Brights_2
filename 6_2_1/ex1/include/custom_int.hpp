#ifndef CUSTOM_INT_H
#define CUSTOM_INT_H
#include <cstdint>
class CustomInt {
public:
  CustomInt();
  ~CustomInt();
  int64_t& operator=(CustomInt const &obj);
  int64_t& operator=(const int val);
  int64_t& operator+(CustomInt const &obj);
  int64_t& operator+(const int val);
  int64_t& operator+=(CustomInt const &obj);
  int64_t& operator+=(const int val);
  int64_t& operator-(CustomInt const &obj);
  int64_t& operator-(const int val);
  int64_t& operator-=(CustomInt const &obj);
  int64_t& operator-=(const int val);

  void set_value(const int value);
  const int64_t& get_value()const;
  void print()const;
  void print_counter_value() const;
private:
  int64_t m_value;
  static int counter;
};
#endif