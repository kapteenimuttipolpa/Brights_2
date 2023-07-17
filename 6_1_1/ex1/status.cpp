#include "status.hpp"
#include <chrono>
#include <random>
#include <vector>

status random_status() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<std::size_t> distr(0, every_status.size() - 1);
  return every_status[distr(gen)];
}
