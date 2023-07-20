#include <iostream>
namespace test {
void hello() { std::cout << "Hello\n"; }
} // namespace test

struct test_type {
  static void ok() { std::cout << "ok\n"; }
};

int main() {
  test::hello();

  test_type type;
  type.ok();
  return 0;
}