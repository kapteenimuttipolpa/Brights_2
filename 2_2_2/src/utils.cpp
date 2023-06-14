#include "../includes/utils.h"
//#define NDEBUG
#include <cassert>
#include <iostream>
#include <string>
/**
 * @brief addition adds 2 values together
 * 
 * @param a double val
 * @param b double val
 * @return double 
 */
double addition(double a, double b)
{
    assert((2+2==4) && "Addition failed!");
    return a + b;
}
/**
 * @brief subtraction subtracts 2 values
 * 
 * @param a double val
 * @param b double val
 * @return double 
 */
double subtraction(double a, double b)
{
    assert((2-2==0) && "Subtraction failed!");
    return a - b;
}
/**
 * @brief multiplies 2 values
 * 
 * @param a double val
 * @param b double val
 * @return double 
 */
double multiplication(double a, double b)
{   assert((2*2==4) && "Multiplication failed!");
    return a * b;
}
/**
 * @brief divides 2 values
 * 
 * @param a double val
 * @param b double val
 * @return double 
 */
double division(double a, double b)
{
    assert((4/2==2) && "Division failed!");
    if(a <= 0 or b <= 0){
        return 0;
    }
    return a / b;
}
/**
 * @brief encrypts message
 * 
 * @param s string to be encrypted
 * @param i how many moves
 * @return std::string 
 */
std::string encrypt(std::string& s, int i)
{
    std::string encrypted{};
    for (char& c : s) {
        if (std::isupper(c)) {
            c = ((c - 'A' + i) % 26 + 'A'); // E_{n}(x)=(x+n)\mod {26}. basically
            encrypted += c;
        } else if (std::islower(c)) {
            c = ((c - 'a' + i) % 26 + 'a'); //D_{n}(x)=(x-n)\mod {26}. basically
            encrypted += c;
        } else {
            // Non-alphabetic characters are ignored
            encrypted += c;
        }
    }
    return encrypted;
}
/**
 * @brief Decrypts message
 * Moves alphabets to opposite direction
 * @param s message to decrypt
 * @param i decryption key
 * @return std::string 
 */
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
