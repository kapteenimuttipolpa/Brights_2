#include "./include/union.hpp"
#include <cassert>
#include <iostream>
int main() {
  TaggedUnion test;
  test.set_type('C');
  assert(test.get_union_type() == Type::human);
  test.set_type(1000);
  assert(test.get_union_type() == Type::robot);
  test.set_type(10.2f);
  assert(test.get_union_type() == Type::alien);

  test.set_type(100);
  test.print();

  test.set_type('B');
  test.print();

  test.set_type(10.32f);
  test.print();

  TaggedUnion test2;
  test2.print();

  return 0;
}