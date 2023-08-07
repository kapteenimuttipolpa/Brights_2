#include <iostream>
#include <tuple>
#include <utility>
// Exercise 1a b
template <typename R, typename... Args> class caller {

public:
  using function_type = R (*)(Args...);
  using return_type = R;
  static constexpr std::size_t Size = sizeof...(Args);
  using params = std::tuple<Args...>;
  template <std::size_t N>
  using Nth = typename std::tuple_element<N, params>::type;
  using First = Nth<0>;
  using Last = Nth<Size - 1>;
  caller(R (*)(Args... args)) noexcept {}
};

// Exercise 1c
constexpr int add(const int lhv, const double rhv) noexcept {
  return lhv + rhv;
}

constexpr double multi(const double lhv, const int rhv) noexcept {
  return lhv * rhv;
}

int main() {

  caller a(add);
  caller m(multi);

  std::cout << "Return type: "
            << typeid(typename decltype(a)::return_type).name() << "\n";
  std::cout << "Arity: " << decltype(a)::Size << "\n";
  std::cout << "Return type: "
            << typeid(typename decltype(m)::return_type).name() << "\n";
  std::cout << "Arity: " << decltype(m)::Size << "\n";
}