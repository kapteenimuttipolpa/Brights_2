#include "static_class.hpp"
#include <iostream>

static_class static_class::create(){
    static_class new_static_class;
    return new_static_class;
}
static_class::~static_class(){}

void static_class::hello(){
    std::cout << "Hello\n";
}