#include <bit>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <system_error>
#include <type_traits>
constexpr static uint8_t IS_FUZZY = 0b1;
constexpr static uint8_t IS_LARGE = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES = 0b100;
constexpr static uint8_t IS_CUTE = 0b1000;
constexpr static uint8_t HAS_TEETH = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY = 0b1000000;
constexpr static uint8_t IS_SPIDER = 0b10000000;
// function to print bits
template <typename T> void print_bits(const T &value) {
  using decay_type = std::decay<T>;

  std::cout << "0b";

  for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i) {
    std::cout << ((value & (1 << i)) ? 1 : 0);
  }
  std::cout << "\n";
}
// ex 1 check if nth bit is set
constexpr bool check_Nth_bit_set(const uint8_t bit, const uint8_t n) {
  return bit & (1 << n);
}

// ex2 swap byte order
template <typename T> constexpr T swap_byte_order(T value) {
  static_assert(std::is_unsigned_v<T>);
  static_assert(std::is_integral_v<T>);

  uint8_t *bytes = reinterpret_cast<uint8_t *>(&value);
  size_t size = sizeof(T);

  for (size_t i = 0; i < size / 2; ++i) {
    std::swap(bytes[i], bytes[size - 1 - i]);
  }

  return value;
}

// ex3 what
constexpr void print_ex3_flags(const uint8_t flags) {
  if (flags & IS_FUZZY) {
    std::cout << "Fuzzy ";
  }
  if (flags & IS_LARGE) {
    std::cout << "Large ";
  }
  if (flags & HAS_GOOGLY_EYES) {
    std::cout << "Googly eyes ";
  }
  if (flags & IS_CUTE) {
    std::cout << "cute ";
  }
  if (flags & HAS_TEETH) {
    std::cout << "Teeth ";
  }
  if (flags & IS_ABOUT_TO_EAT_YOU) {
    std::cout << "About to eat you ";
  }
  if (flags & IS_FRIENDLY) {
    std::cout << "Friendly ";
  }
  if (flags & IS_SPIDER) {
    std::cout << "Spider ";
  }
}
// ex4
constexpr void print_ex4_combo(const uint8_t flags) {
  if ((flags & (IS_SPIDER | IS_ABOUT_TO_EAT_YOU | IS_CUTE)) ==
      (IS_SPIDER | IS_ABOUT_TO_EAT_YOU | IS_CUTE)) {
    std::cout << "HELP ME ";
  }
  if ((flags & (IS_CUTE | IS_FRIENDLY)) == (IS_CUTE | IS_FRIENDLY)) {
    std::cout << "OKAY ";
  }
}
void bitmask() {
  uint8_t result = 0;
  std::string input;
  std::cout << "Input string: ";
  std::getline(std::cin, input);
  size_t size = input.size();
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == ',') {
      result |= (1ULL << i);
    }
  }
  print_bits(result);
}
int main() {
  uint8_t test = 0b01;
  uint32_t test2 = 0xabcd;
  print_bits(test);
  std::cout << std::boolalpha << check_Nth_bit_set(test, 0) << '\n';
  std::cout << std::hex << swap_byte_order(test2) << "\n";
  uint8_t flags = IS_SPIDER | IS_ABOUT_TO_EAT_YOU | IS_CUTE;
  uint8_t flag2 = IS_CUTE | IS_FRIENDLY;
  uint8_t flag3 = IS_SPIDER | IS_FUZZY;
  print_ex4_combo(flags);
  bitmask();
  return 0;
}