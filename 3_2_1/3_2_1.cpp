#include <iostream>
#include <string>
#include <vector>

/*void permutate(std::vector<std::string> &route, int l, int r) {
  if (l == r) {
    for (auto &route1 : route) {
      std::cout << route1 << ' ';
    }
    std::cout << '\n';
  } else {
    for (int i = l; i <= r; i++) {
      std::swap(route[l], route[i]);
      permutate(route, l + 1, r);
      std::swap(route[l], route[i]);
    }
    
  }
}*/

void permutate(std::vector<std::string> &route, int l, int r) {
  if (l == r) {
    for (auto &route1 : route) {
      std::cout << route1 << ' ';
    }
    std::cout << '\n';
  } else {
    for (int i = l; i <= r; i++) {
      std::swap(route[l], route[i]);
      permutate(route, l + 1, r);
      std::swap(route[l], route[i]);
    }
    
  }
}

int main() {
  std::vector<std::vector<std::string>> all_routes;
  std::vector<std::string> routes{"Panama", "New York", "Amsterdam", "Helsinki",
                                  "Durdan"};
  permutate(routes, 1, routes.size() - 1);

  return 0;
}
