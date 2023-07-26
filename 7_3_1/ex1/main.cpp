
#include <iostream>
#include <string>
// EX 1
template <typename Derived> class base_class {
  protected:
    base_class() noexcept = default;
};

template <typename T> struct type_print {
    void printType() { std::cout << "Type: " << typeid(T).name() << '\n'; }
};
// EX 2 type, "final_product"
class final_product : public base_class<final_product>,
                      public type_print<final_product> {
  public:
    final_product() noexcept = default;
    final_product(int value) noexcept : _value(value){};
    bool operator<(const final_product &other) const {
        return _value < other._value;
    }

  private:
    int _value;
};
// just a test type to test how this whole thing works
struct test_type : public base_class<test_type>, public type_print<test_type> {
    test_type(std::string &s) : _name(s) {}

  private:
    std::string _name;
};
/***


*/
template <typename Derived>
bool operator==(const base_class<Derived> &lhs,
                const base_class<Derived> &rhs) noexcept {
    if (static_cast<const Derived &>(rhs) < static_cast<const Derived &>(lhs))
        return false;
    if (static_cast<const Derived &>(lhs) < static_cast<const Derived &>(rhs))
        return false;
    return true;
}

int main() {
    final_product a{10};
    final_product b{10};
    final_product c{20};

    std::string s1 = "dog";
    std::string s2 = "cat";

    test_type test{s1};
    test_type test2{s2};
    test_type test3{s2};

    std::cout << std::boolalpha << (a == b) << '\n';
    std::cout << std::boolalpha << (a == c) << '\n';
    std::cout << std::boolalpha << (a < c) << '\n';
    a.printType();
    b.printType();
    c.printType();
    test.printType();
    // std::cout << "test strings\n";
    // Okay this doesn't work with strings because == is overloaded with <
    // std::cout << std::boolalpha << (test == test2) << '\n';
    // std::cout << std::boolalpha << (test2 == test3) << '\n';

    return 0;
}