#include "./include/custom_int.hpp"
#include <iostream>
#include <cassert>
int main(){
    CustomInt c_int1;
    CustomInt c_int2;
    CustomInt c_int3;
    c_int1.set_value(10);
    c_int2.set_value(20);
    c_int1 = c_int2;
    c_int1 += 10;
    assert(c_int1.get_value() == 30);
    c_int1 -= 10;
    assert(c_int1.get_value() == 20);
    c_int1.print_counter_value();
    c_int1.print();
    


    return 0;
}