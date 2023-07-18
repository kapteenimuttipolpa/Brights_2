#include "./include/union.hpp"
#include <cassert>
#include <iostream>
int main() {
  TaggedUnion test;
  test.set_value('C');
  assert(test.get_union_tag() == Type::human);
  test.set_value(1000);
  assert(test.get_union_tag() == Type::robot);
  test.set_value(10.2f);
  assert(test.get_union_tag() == Type::alien);

  test.set_value(100);
  test.print();

  test.set_value('B');
  test.print();

  test.set_value(10.32f);
  test.print();

  TaggedUnion test2("rauhhh");
  TaggedUnion test3(12.4f);
  TaggedUnion test4(23);
  test2.print();
  test3.print();
  test4.print();

  return 0;
}