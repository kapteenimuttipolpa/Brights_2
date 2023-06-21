#include<iostream>
#include<string>
/*Exercise 1
Write a recursive function that takes a string as 
input and returns the string reversed.*/

std::string reversed(std::string& s, std::string& new_s)
{
    if(s.empty()){
        return new_s;
    }
    new_s.push_back(s.back());
    s.pop_back();
    return reversed(s, new_s);

}
int main()
{   
    std::string s = "woofer";
    std::string new_s = "";
    reversed(s, new_s);
    std::cout << new_s;
}