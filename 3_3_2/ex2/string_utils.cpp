#include "string_utils.h"
#include "doctest.h"
#include <cctype>
#include <string>
#include <iostream>

std::string reverse(std::string s) {
    std::string temp;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        temp.push_back(*it);
    }
    return temp;
}

std::string to_upper(std::string s) {
    for (char& c : s) {
        c = std::toupper(c);
    }
    return s;
}
bool is_palindrome(std::string s)
{
    if(reverse(s) == s) {return true;}
    return false;
}