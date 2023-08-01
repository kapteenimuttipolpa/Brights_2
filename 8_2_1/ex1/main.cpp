#include <iostream>
#include <type_traits>
template <typename T> void foo(T &&) {
    if (std::is_lvalue_reference_v<T>) {
        std::cout << "l value\n";
    } else if (std::is_rvalue_reference_v<T &&>) {
        std::cout << "r value\n";
    }
}

int main() {
    int i = 10;
    foo(i);
    foo(10);
}