
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>

// only takes the first character after %,
// so it does not work with lets say %3d
std::string get_args_from_string(const std::string &fmt) {
    std::string args_in_string;
    for (size_t i = 0; i < fmt.size(); i++) {
        if (fmt[i] == '%' and i + 1 < fmt.size()) {
            args_in_string += fmt[i + 1];
        }
    }
    return args_in_string;
}

// overload templates for int float double char and string
// returns the specifier according for type
// i like this because its compile time
template <typename T> struct type_specifier;

template <> struct type_specifier<int> {
    static constexpr char value = 'i';
};
template <> struct type_specifier<double> {
    static constexpr char value = 'f';
};
template <> struct type_specifier<float> {
    static constexpr char value = 'f';
};
template <> struct type_specifier<char> {
    static constexpr char value = 'c';
};
template <> struct type_specifier<const char *> {
    static constexpr char value = 's';
};
template <typename T> constexpr char t_specifier = type_specifier<T>::value;

// base case for the recursion
template <typename... Ts> void parse_args(std::string &res) {}

// recursively calls the parse_arg function that returns
// characters while there are arguments in args
template <typename T, typename... Ts>
void parse_args(std::string &res, T arg, Ts... args) {
    res += t_specifier<T>;
    parse_args(res, args...);
}

// creates 2 strings. One for type_specifiers(Ts... args)
// and one for arguments in string (characters after %)
// if strings are equal, prints the string
// else throws
// would be really nice to do this compile time but that out of my league
template <typename... Ts> void safe_printf(const std::string &fmt, Ts... args) {
    std::string args_int_fmt = get_args_from_string(fmt);
    std::string type_specifiers;
    parse_args(type_specifiers, args...);
    if (type_specifiers == args_int_fmt) {
        std::printf(fmt.c_str(), args...);
    } else {
        throw std::runtime_error(
            "Type specifiers do not match the format string.");
    }
}
int main() {
    safe_printf("Cat jumped %c %i %f %s", 'c', 78, 30.32, "dog");
    return 0;
}
