#include <iostream>
#include <optional>
class test {
public:
  static std::optional<test> divide(const int value, const int divider) {
    if (divider == 0)
      return {};
    test new_test;
    new_test._result = value / divider;
    return new_test;
  }

private:
  test() = default;
  int _result;
};
int main() {

  if (test::divide(10, 1)) {
    std::cout << "works\n";
  }

  if (!test::divide(10, 0)) {
    std::cout << "fails\n";
  }

  return 0;
}