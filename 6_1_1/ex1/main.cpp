#include "status.hpp"
#include <iostream>
#include <vector>

int main() {

  status current_status = random_status();

  switch (current_status) {
  case status::Success: {
    std::cout << "Success!";
    break;
  }
  case status::Failure: {
    std::cout << "Failure!";
    break;
  }
  case status::Nice_try: {
    std::cout << "Nice try.";
    break;
  }
  case status::Almost: {
    std::cout << "ALMOST :D";
    break;
  }
  }
  return 0;
}