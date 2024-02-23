#include <iostream>
#include "static_class.hpp"

int main(){
    
    static_class s = static_class::create();
    s.hello();

    return 0;
}