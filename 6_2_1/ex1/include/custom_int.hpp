#ifndef CUSTOM_INT_H
#define CUSTOM_INT_H
class CustomInt {
public:
  CustomInt();
  ~CustomInt();
  int& operator=(CustomInt const &obj);
  int& operator=(const int val);
  int& operator+(CustomInt const &obj);
  int& operator+(const int val);
  int& operator+=(CustomInt const &obj);
  int& operator+=(const int val);
  int& operator-(CustomInt const &obj);
  int& operator-(const int val);
  int& operator-=(CustomInt const &obj);
  int& operator-=(const int val);

  void set_value(const int value);
  const int& get_value()const;
  void print()const;
  void print_counter_value() const;
private:
  int m_value;
  static int counter;
};
#endif