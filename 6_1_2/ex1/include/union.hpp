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
  Type get_union_type() const noexcept;
  void set_type(const int &int_val) noexcept;
  void set_type(const char ch) noexcept;
  void set_type(const float &float_val) noexcept;
  void print() const;

private:
  Type union_type;
  union {
    int int_val_;
    char char_val_;
    float float_val_;
  };
};
