#include "dbgclass.hpp"
#include <iostream>
#include <utility>
int main() {
  dbg<true> debug;
  dbg<false> *debug_false = new dbg<false>;
  std::cout << "debug false destructor calls " << debug_false->destructor_calls
            << '\n';
  delete debug_false;
  dbg<true> debug1;
  dbg<true> debug2(std::move(debug1));
  std::cout << "debug 1 move calls " << debug1.move_calls << "\n";
  return 0;
}