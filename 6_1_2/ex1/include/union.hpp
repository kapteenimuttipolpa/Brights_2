#pragma once
#include <cassert>
#include <string>
enum class Type {
  none,
  robot,
  human,
  alien,
};

class TaggedUnion {
public:
  TaggedUnion();
  ~TaggedUnion();
  Type get_union_tag() const noexcept;
  void set_value(const int &int_val) noexcept;
  void set_value(const char ch) noexcept;
  void set_value(const float &float_val) noexcept;

  const int &get_int_value() const;
  const char &get_char_value() const;
  const float &get_float_value() const;

  void print() const;

private:
  Type union_type;
  union {
    int m_int_val;
    char m_char_val;
    float m_float_val;
  };
};
