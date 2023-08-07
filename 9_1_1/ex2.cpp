#include <cctype>
#include <cstddef>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
constexpr double add(const double &lhv, const double &rhv) noexcept {
  return lhv + rhv;
}
constexpr double subtract(const double &lhv, const double &rhv) noexcept {
  return lhv - rhv;
}

constexpr double multiply(const double &lhv, const double &rhv) noexcept {
  return lhv * rhv;
}
constexpr double divide(const double &lhv, const double &rhv) {
  if (rhv <= 0) {
    throw std::runtime_error("division by zero.");
  }
  return lhv / rhv;
}

int main() {
  std::unordered_map<char, std::function<double(char, double)>> operations_map;
  operations_map['+'] = add;
  operations_map['-'] = subtract;
  operations_map['*'] = multiply;
  operations_map['/'] = divide;

  struct user_variable {
    std::string name;
    double value;
  };
  std::vector<user_variable> user_variables;

  while (true) {
    std::cout << "> ";
    std::string choice;
    std::getline(std::cin >> std::ws, choice);
    double param1 = 0.0;
    double param2 = 0.0;
    char operation = '\0';
    // currently supports +, -, * and /
    //  looks for those in the string
    for (char op : "+-*/=") {
      int pos = choice.find(op);
      if (pos != std::string::npos) {
        operation = op;
        break;
      }
    }
    if (operation == '\0') {
      std::cout << "invalid operation.\n";
      continue;
    }
    if (operations_map.find(operation) == operations_map.end() and
        operation != '=') {
      std::cout << "Invalid operation: " << operation << std::endl;
      continue;
    }
    if (operation == '=') {
      // Added this so user can make variables
      user_variable new_variable;
      new_variable.name = choice.substr(0, choice.find(operation));
      new_variable.value = std::stod(choice.substr(choice.find(operation) + 1));
      user_variables.push_back(new_variable);
      continue;
    }
    try {
      // splits everything before and after operation char
      // and tries to convert it to double
      param1 = std::stod(choice.substr(0, choice.find(operation)));
      param2 = std::stod(choice.substr(choice.find(operation) + 1));

    } catch (std::invalid_argument const &e) {
      std::cerr << "Invalid input: " << e.what() << '\n';
      continue;
    }

    auto res = operations_map[operation](param1, param2);
    std::cout << res << "\n";
  }

  return 0;
}
