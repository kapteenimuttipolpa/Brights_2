#ifndef CUSTOM_INT_H
#define CUSTOM_INT_H
#include <cstdint>
class CustomInt {
public:
  //static CustomInt create(int32_t value);
   CustomInt() noexcept;
   CustomInt(int32_t val);
  ~CustomInt();
  CustomInt& operator=(const CustomInt &obj);
  CustomInt& operator=(const int32_t &val);
  int32_t operator+(const CustomInt &obj);
  int32_t operator+(const int32_t &val);
  CustomInt& operator+=(const CustomInt &obj);
  CustomInt& operator+=(const int32_t &val);
  CustomInt& operator-(const CustomInt &obj);
  CustomInt& operator-(const int32_t &val);
  CustomInt& operator-=(const CustomInt &obj);
  CustomInt& operator-=(const int32_t &val);
  friend CustomInt friendly_addition(CustomInt &obj1, CustomInt &obj2);
  friend CustomInt friendly_subtraction(CustomInt &obj1, CustomInt &obj2);
  void set_value(const uint32_t &value);
  const int32_t& get_value()const;
  void print()const;
  int print_counter_value() const;
  bool is_result_overflown(const int32_t &First_val, const int32_t &second_val) const;
private:
 // CustomInt() = default;
  int32_t m_value = 0;
  static int counter;
};
#endif