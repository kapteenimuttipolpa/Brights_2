#include <algorithm>
#include <array>
#include <cctype>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <vector>
// clang-format off
namespace ex1a {
/*Create a function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
overload resolution*/
template <typename T> 
void print_args(T arg) { 
    std::cout << std::boolalpha <<arg << '\n'; 
}

template <typename T, typename... Ts> 
void print_args(T arg, Ts... args) {
    std::cout << std::boolalpha << arg << ", ";
    print_args(args...);
}

} // namespace ex1a
namespace ex1b {
/*Create a function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
if contexpr*/
template <typename T, typename... Ts>
void print_first_int(T arg, Ts... args) {
    std::cout << std::boolalpha << arg << ',';
    if constexpr (sizeof...(args) > 0) {
        print_first_int(args...);
    } 
}
} // namespace ex1b
namespace ex2{
/*Create a function that takes arbitrary number of arguments and returns the sum of the
arguments.  How should you handle errors (such as argument not being a number) here?*/

 template<typename T, typename... Values>
 auto sum(T, Values&& ... val){
    static_assert(!std::is_same_v<T, char> and std::is_arithmetic_v<T>, "Wrong value types");
    return (val + ...);
 }
}
namespace ex3{
 /*In exercise 7.1.1. we created a function to check 
 if two types are the same.  Expand on this
to check if any number of types given are all the same.*/
template <typename T, typename U>
constexpr bool is_same_type(const T &, const U &) {
    return false;
}

template <typename T> constexpr bool is_same_type(const T &, const T &) {
    return true;
}

template <typename T, typename U, typename... Ts>
constexpr bool is_same_type(const T& arg1, const U& arg2, Ts... args) {
    return is_same_type(arg1, arg2) and is_same_type(arg1, args...);
}
}
namespace ex4{
    /*Create a function that takes arbitrary number 
    of arguments and return the product of the
    arguments times the number of arguments.*/
    template<typename... values>
    auto prod(values&&... t){
        return (t * ... * sizeof...(values));
    }
}
namespace ex5{
    /*Exercise 5.
Create a function that takes arbitrary n
umber of containers as arguments and creates a
concatenated container.  
(e.g. concatenate(std::vector{1, 2}, 
std::list{5, 8}) -> std::vector{1, 2, 5, 8};*/

template <typename Output_container, typename... Containers>
Output_container concatenate(Containers ... containers){
    Output_container result;
    static_assert((std::is_same_v<typename Output_container::value_type, typename Containers::value_type> && ...),
                      "All container value types must be the same as Output_container value type.");
    (std::copy(containers.begin(), containers.end(), std::back_inserter(result)), ...);
    return result;
}
}


int main() {
    //ex1a::print_args('C', 10.1, 10, "asdf");
    //ex1b::print_first_int(3.14, 13, "test", true, 42, 'a', 32);
    //std::cout << std::endl;
    //std::cout << ex2::sum(10, 20, 30, 54.4) << '\n';
    //std::cout << ex2::sum(10,20,30,54.4);
    //std::cout << std::boolalpha << ex3::is_same_type(10, 12, 13, 14, 5.3);
    static_assert(ex3::is_same_type(1, 2, 3) == true);
    static_assert(ex3::is_same_type(1, 23.3, 10, 20) == false);
    static_assert(ex3::is_same_type('a', 61) == false);
    //std::cout << ex4::prod(2, 2, 2, 7.3);
    auto result = 
    ex5::concatenate<std::vector<int>>(std::vector{1,2}, std::list{5,8}, std::list{21, 23});
    for(const auto& num : result){
        std::cout << num << " ,";
    }
    return 0;
}