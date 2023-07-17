#include "state_machine.hpp"
#include <iostream>
int main() {
  Order new_order;

  while (new_order.current_state != order_state::last_state) {
    new_order.print_current_state(new_order.current_state);
    new_order.advance_state(new_order.current_state);
  }
  return 0;
}
