#include "state_machine.hpp"
#include <iostream>
void Order::print_current_state(order_state current_state) {
  switch (current_state) {
  case order_state::ordered: {
    std::cout << "Ordered.\n";
    break;
  }
  case order_state::handled: {
    std::cout << "handled.\n";
    break;
  }
  case order_state::in_delivery: {
    std::cout << "in delivery.\n";
    break;
  }
  case order_state::delivered: {
    std::cout << "Delivered.\n";
    break;
  }
  case order_state::last_state: {
  }
  }
}
void Order::advance_state(order_state &current_state) {
  if (current_state < order_state::last_state) {
    current_state =
        static_cast<order_state>(static_cast<int>(current_state) + 1);
  }
}