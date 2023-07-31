#include <array>
#include <deque>
#include <ios>
#include <iostream>
#include <list>
#include <memory>
#include <vector>
int print_address() {
    int test = 10;
    return test;
}
namespace ex2 {
void print_vector() {
    std::vector<int> vec{0, 1, 2, 3, 4, 5};
    std::cout << "vectors address: " << &vec << '\n';
    for (int i = 0; i < vec.size(); i++) {
        std::cout << "Vector at " << i << " address: " << std::addressof(vec[i])
                  << '\n';
    }
}
} // namespace ex2

namespace ex3 {
template <typename T> bool is_contiguous(const T &container) {
    if (container.empty()) {
        return true;
    }

    auto left_side_it = container.begin();
    auto right_side_it = std::next(left_side_it);

    while (right_side_it != container.end()) {
        if (&(*right_side_it) != &(*left_side_it) + 1) {
            return false;
        }
        ++left_side_it;
        ++right_side_it;
    }

    return true;
}
} // namespace ex3

int main() {
    // just doing something since the idea of ex1 was really unclear imo
    int value = 5;
    int value2 = 6;
    std::cout << "Value created in main: " << std::addressof(value) << '\n';
    int (*func_ptr)() = std::addressof(print_address);

    std::cout << "Function address: " << reinterpret_cast<void *>(func_ptr)
              << '\n';
    std::cout << reinterpret_cast<int *>(std::addressof(func_ptr)) -
                     reinterpret_cast<int *>(std::addressof(value))
              << '\n';

    auto deq = std::deque<int>(100000);
    auto list = std::list<int>(100000);
    auto arr = std::array<int, 10000>();
    auto vec = std::vector<int>(10);
    std::cout << std::boolalpha << ex3::is_contiguous(deq) << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(list) << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(arr) << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(vec) << '\n';
    std::vector<std::vector<int>> vec2d{
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15},
    };
    std::cout << std::boolalpha << ex3::is_contiguous(vec2d);
    // ex5, I did try different variations and it always returned true.
    // but i think it isnt always contiguous
}
