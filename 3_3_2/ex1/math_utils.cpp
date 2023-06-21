#include "math.h"
#include "doctest.h"
#include <exception>
#include <stdexcept>
#include <iostream>

double add(double a, double b)
{
    return a + b;
}
double subtract(double a, double b)
{
    return a - b;
}
double multiply(double a, double b){
    return a * b;
}
double divide(double a, double b)
{
    if (b == 0.0) {
        throw std::runtime_error("Division by zero");
    }
    return a / b;
    
}