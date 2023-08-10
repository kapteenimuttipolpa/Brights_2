#pragma once
#include <cstddef>
#include <iterator>
#include <string>

class string_iterator {
public:
  using value_type = char32_t;
  using pointer = value_type *;
  using reference = value_type &;
  using difference_type = std::ptrdiff_t;

  string_iterator(std::string::iterator it) noexcept : _iter(it) {}

  string_iterator &operator++() {
    char first_byte = *_iter;
    std::string::difference_type offset = 1;
    if (first_byte & kFirstBitMask) {
      if (first_byte & kThirdBitMask) {
        if (first_byte & kFourthBitMask)
          offset = 4;
        else
          offset = 3;
      } else
        offset = 2;
    }
    _iter += offset;
    return *this;
  }

  string_iterator operator++(int) noexcept {
    string_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  const unsigned char kFirstBitMask = 128; // 1000000
  const unsigned char kSecondBitMask = 64; // 0100000
  const unsigned char kThirdBitMask = 32;  // 0010000
  const unsigned char kFourthBitMask = 16; // 0001000
  const unsigned char kFifthBitMask = 8;   // 0000100

  char32_t operator*() const {
    char32_t code_point = 0;

    char first_byte = *_iter;

    if (first_byte &
        kFirstBitMask) // This means the first byte has a value greater than
                       // 127, and so is beyond the ASCII range.
    {
      if (first_byte & kThirdBitMask) // This means that the first byte has a
                                      // value greater than 191, and so it must
                                      // be at least a three-octet code point.
      {
        if (first_byte & kFourthBitMask) // This means that the first byte has a
                                         // value greater than 224, and so it
                                         // must be a four-octet code point.
        {
          code_point = (first_byte & 0x07) << 18;
          char second_byte = *(_iter + 1);
          code_point += (second_byte & 0x3f) << 12;
          char third_byte = *(_iter + 2);
          code_point += (third_byte & 0x3f) << 6;
          ;
          char fourth_byte = *(_iter + 3);
          code_point += (fourth_byte & 0x3f);
        } else {
          code_point = (first_byte & 0x0f) << 12;
          char second_byte = *(_iter + 1);
          code_point += (second_byte & 0x3f) << 6;
          char third_byte = *(_iter + 2);
          code_point += (third_byte & 0x3f);
        }
      } else {
        code_point = (first_byte & 0x1f) << 6;
        char second_byte = *(_iter + 1);
        code_point += (second_byte & 0x3f);
      }
    } else {
      code_point = first_byte;
    }

    return code_point;
  }

  bool operator==(const string_iterator &other) const noexcept {
    return _iter == other._iter;
  }
  bool operator!=(const string_iterator &other) const noexcept {
    return !(*this == other);
  }

private:
  std::string::iterator _iter;
};

class string_adapter {
public:
  using value_type = std::string::value_type;
  using iterator = string_iterator;
  using const_iterator = const iterator;
  using size_type = std::size_t;

  string_iterator begin() { return string_iterator(_str.begin()); }

  const_iterator begin() const { return const_iterator(_str.begin()); }

  iterator end() { return _str.end(); }

  const_iterator end() const { return const_iterator(_str.end()); }

  size_t size() const { return _str.length(); }

  string_adapter(std::string &str) : _str(str) {}

private:
  std::string &_str;
};
