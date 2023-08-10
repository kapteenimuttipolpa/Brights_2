#include <iostream>
#include <string>
#include <variant>
template <class> inline constexpr bool always_false_v = false;
// helper type for the visitor #4
template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};
// explicit deduction guide (not needed as of C++20)
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

void print_type(const std::variant<int, std::string, float> &type) {
  std::visit(
      overloaded{
          [](const int x) { std::cout << "Robot, value: " << x; },
          [](const std::string &x) { std::cout << "human, value: " << x; },
          [](const float x) { std::cout << "alien, value: " << x; },
      },
      type);
}

int main() {
  using var_t = std::variant<int, std::string, float>;
  var_t type = 123.0f;
  print_type(type);

  return 0;
}