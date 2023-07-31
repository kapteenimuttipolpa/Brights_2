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
template <typename T> auto is_contiguous(T first, T last) {
    auto const n = std::distance(first, last);
    for (auto i = 0; i < n; ++i) {
        if (*(std::next(first, i)) != *(std::next(std::addressof(*first), i))) {
            return false;
        }
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
    auto vec = std::vector<int>(100);
    std::vector<std::vector<int>> vec2d(1000000);
    std::cout << std::boolalpha << ex3::is_contiguous(deq.begin(), deq.end())
              << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(list.begin(), list.end())
              << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(arr.begin(), arr.end())
              << '\n';
    std::cout << std::boolalpha << ex3::is_contiguous(vec.begin(), vec.end())
              << '\n';

    // ex5, I did try different variations and it always returned true.
    // but i think it isnt always contiguous
    std::cout << "vec 2d: " << std::boolalpha
              << ex3::is_contiguous(vec2d.begin(), vec2d.end()) << '\n';
}
