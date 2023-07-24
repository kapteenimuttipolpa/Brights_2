#include "./include/union.hpp"
#include <cassert>
#include <iostream>
#include <string_view>
int main() {
  /*tgu::TaggedUnion test;
  test.set_value('C');
  assert(test.get_union_tag() == tgu::Type::human);
  test.set_value(1000);
  assert(test.get_union_tag() == tgu::Type::robot);
  test.set_value(10.2f);
  assert(test.get_union_tag() == tgu::Type::alien);

  test.set_value(100);
  test.print();

  test.set_value('B');
  test.print();

  test.set_value(10.32f);
  test.print();

  tgu::TaggedUnion test2("rauhhh");
  tgu::TaggedUnion test3(12.4f);
  tgu::TaggedUnion test4(23);
  test2.print();
  test3.print();
  test4.print();*/
  tgu::TaggedUnion test("104");
  assert(test.get_union_tag() == tgu::Type::robot &&
         test.get_int_value() == 103);
  tgu::TaggedUnion test2("124.23");
  tgu::TaggedUnion test3("bober");
  assert(test2.get_union_tag() == tgu::Type::alien &&
         test2.get_float_value() == 124.23f);
  assert(test3.get_union_tag() == tgu::Type::human &&
         test3.get_char_value() == 'b');

  return 0;
}