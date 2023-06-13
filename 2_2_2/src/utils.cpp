#include "../includes/utils.h"
//#define NDEBUG
#include <cassert>
#include <iostream>
#include <string>

double addition(double a, double b)
{
    assert((2+2==5) && "Addition failed!");
    return a + b;
}
double subtraction(double a, double b)
{
    assert((2-2==0) && "Subtraction failed!");
    return a - b;
}
double multiplication(double a, double b)
{   assert((2*2==4) && "Multiplication failed!");
    return a * b;
}
double division(double a, double b)
{
    assert((4/2==2) && "Division failed!");
    if(a <= 0 or b <= 0){
        return 0;
    }
    return a / b;
}
std::string encrypt(std::string& s, int i)
{
    std::string encrypted{};
    for (char& c : s) {
        if (std::isupper(c)) {
            c = ((c - 'A' + i) % 26 + 'A');
            encrypted += c;
        } else if (std::islower(c)) {
            c = ((c - 'a' + i) % 26 + 'a');
            encrypted += c;
        } else {
            // Non-alphabetic characters are ignored
            encrypted += c;
        }
    }
    return encrypted;
}
std::string decrypt(std::string& s, int i)
{
     std::string encrypted{};
    for (char& c : s) {
        if (std::isupper(c)) {
            c = ((c - 'A' - i + 26) % 26 + 'A');
            encrypted += c;
        } else if (std::islower(c)) {
            c = ((c - 'a' - i + 26) % 26 + 'a');
            encrypted += c;
        } else {
            // Non-alphabetic characters are ignored
            encrypted += c;
        }
    }
    return encrypted;
}
