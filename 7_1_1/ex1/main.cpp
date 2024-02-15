#include <ios>
#include <iostream>
#include <type_traits>
namespace ex1 {
template <typename T, typename U>
constexpr bool is_same_type(const T &, const U &) {
    return false;
}
template <typename T> constexpr bool is_same_type(const T &, const T &) {
    return true;
}
} // namespace ex1
namespace ex2 {
template <typename T> constexpr bool can_be_decayed() {
    // checks if the decayed version is the same with the original
    // if it is, it cannot be decayed
    return std::is_same_v<T, typename std::decay<T>::type>;
}
} // namespace ex2

int main() {
    static_assert(ex1::is_same_type(10.4, 11.2));            // true
    static_assert(!ex1::is_same_type<int, float>(11, 19.4)); // false

    static_assert(ex2::can_be_decayed<int>(),
                  "Int cannot decay"); // cant be decayed
    static_assert(!ex2::can_be_decayed<int[]>(), "int[] decays to int*");
    return 0;
}
