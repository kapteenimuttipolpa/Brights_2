#pragma once
#include <vector>
// clang-format off
enum class order_state {
  ordered,
  handled,
  in_delivery,
  delivered,
  last_state
};
// clang-format on
struct Order {
  order_state current_state = order_state::ordered;
  void print_current_state(order_state current_state);
  void advance_state(order_state &current_state);
};