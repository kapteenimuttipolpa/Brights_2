#include <iostream>
#include <ostream>
#include <variant>
#include <vector>
namespace animal {
class dog {
public:
  void make_sound() const { std::cout << "woof\n"; }
};

class cat {
public:
  void make_sound() const { std::cout << "meow\n"; }

private:
};

class monke {
public:
  void make_sound() const { std::cout << "uga\n"; }
};

class snake {
public:
  void make_sound() const { std::cout << "hiss\n"; }
};
} // namespace animal

using var_t =
    std::variant<animal::dog, animal::cat, animal::monke, animal::snake>;
template <class> inline constexpr bool always_false_v = false;

// helper type for the visitor #4
template <class... Ts> struct overloaded : Ts... {
  using Ts::operator()...;
};
// explicit deduction guide (not needed as of C++20)
template <class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
  animal::dog dog;
  animal::cat cat;
  animal::monke monkey;
  animal::snake snake;

  var_t a1 = dog;
  var_t a2 = cat;
  var_t a3 = monkey;
  var_t a4 = snake;
  std::vector<var_t> animals{a1, a2, a3, a4};

  for (auto &animal : animals) {
    std::visit([](auto &&arg) { arg.make_sound(); }, animal);
  }

  for (auto &animal : animals) {
    std::visit(overloaded{[](animal::dog arg) { std::cout << "dog\n"; },
                          [](animal::cat arg) { std::cout << "cat\n"; },
                          [](animal::monke arg) { std::cout << "monkey\n"; },
                          [](animal::snake arg) { std::cout << "snake\n"; }},
               animal);
  }
}