#include "./include/expected.h"
#include <cassert>
#include <iostream>
#include <ostream>
enum class error {
  error_0,
};

class test {
public:
  static tl::expected<test, error> create(bool give_error) {
    test new_test;
    if (give_error) {
      return tl::unexpected(error::error_0);
    } else
      return new_test;
  }
  void print_status() { std::cout << "ok.\n"; }

private:
  test() = default;
};

int main() {
  tl::expected<test, error> a = test::create(false);
  tl::expected<test, error> b = test::create(true);

  if (a)
    a->print_status();
  else
    std::cout << "Error number " << static_cast<int>(a.error()) << '\n';

  if (b)
    b->print_status();
  else
    std::cout << "Error number " << static_cast<int>(b.error()) << '\n';

  return 0;
}
