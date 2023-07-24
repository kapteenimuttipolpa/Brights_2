#pragma once
#include <cassert>
#include <charconv>
#include <string>
namespace tgu {

enum class Type {
  none,
  robot,
  human,
  alien,
};

class TaggedUnion {
public:
  TaggedUnion();
  TaggedUnion(const std::string &s);
  TaggedUnion(const int &i);
  TaggedUnion(const float &f);
  ~TaggedUnion();
  Type get_union_tag() const noexcept;
  void set_value(const int &int_val) noexcept;
  void set_value(const char ch) noexcept;
  void set_value(const float &float_val) noexcept;

  const int &get_int_value() const;
  const char &get_char_value() const;
  const float &get_float_value() const;

  void print() const;
  friend std::ostream &operator<<(std::ostream &os, TaggedUnion &tag_un);
  // check if float
  inline static bool is_float(const std::string &input) {
    double val;
    auto [p, ec] =
        std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
  }
  // check if int
  inline static bool is_int(const std::string &input) {
    int val;
    auto [p, ec] =
        std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
  }

private:
  Type union_type;
  union {
    int m_int_val;
    char m_char_val;
    float m_float_val;
  };
};
std::ostream &operator<<(std::ostream &os, TaggedUnion &tag_un);
} // namespace tgu
