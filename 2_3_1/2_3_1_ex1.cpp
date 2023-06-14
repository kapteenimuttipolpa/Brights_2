#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
/*Exercise 1:
Write a program that sorts an array of
 integers in ascending order using std::sort*/
void ex1()
{
    std::vector<int> int_vec {9,8,7,4,5,6,2,90,232};
    std::sort(int_vec.begin(), int_vec.end());
    for(const auto& elem : int_vec){
        std::cout << elem << ' ';
    }
}
/*Exercise 2:
Use std::sort with std::greater<int>()
 to sort an array of integers in descending order.*/

 void ex2()
 {
    std::vector<int> ints {5,3,1,6,7,3,2,1,7,10};
    std::sort(ints.begin(), ints.end(), std::greater<int>());
    for (const auto& elem : ints){
        std::cout << elem << ' ';
    }
 }
/*Exercise 3:
Create a vector of floating-point numbers and sort it. 
Experiment with different sizes of vectors and number ranges.*/

void ex3()
{
    std::vector<float> floats {12.3, 19.222, 49.21, 19, 1.2, 4.23};
    std::sort(floats.begin(), floats.end());
    for( const auto& elem : floats){
        std::cout << elem << ' ';
    }
}
/*Exercise 4:
Create a vector of strings and sort them in lexicographical order. 
Also, sort them based on the string length.*/

void ex4()
{
    std::vector<std::string> str_vec {
        "Koira", "Moira", "Soira",
        "Johannes", "Viina", "TeliNE",
        "SIBS", "XYYXZ", "AAABBB", "ABBA"
    };
    std::stable_sort(str_vec.begin(), str_vec.end());
    for (const auto& s : str_vec){
        std::cout << s << '\n';
    }
    //sortataan lambda funktion avulla.
    std::cout << "\n Sortataan koon mukaan \n";
    std::sort(str_vec.begin(), str_vec.end(), [](const std::string& first, const std::string& second){
        return first.size() < second.size();
    });
    for(const auto& s : str_vec){
        std::cout << s << '\n';
    }
}
/*Exercise 5:
Create a vector of pairs where each pair contains a string and an integer 
(like a name and an age). Sort the vector based on the integer.*/

void ex5()
{
    std::vector<std::pair<std::string, int>> pair_vec = {
        {"Kalle",25},
        {"Kissa", 10},
        {"Veeti", 16},
        {"Kalevi", 72},
        {"Sirpa", 70},
        {"Bob", 4}
        };
        //Sorting the vector again with using lambda function
        //that compares the age of 2 person
    std::sort(pair_vec.begin(), pair_vec.end(), 
    [](std::pair<std::string, int> a, std::pair<std::string, int> b){
        return a.second < b.second;
    });
    for( const auto& pair : pair_vec){
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
}
/*Exercise 7:

Use std::partial_sort to find the top 5 elements 
from a vector of integers. 
The vector should have at least 20 elements.*/
void ex7()
{
    std::vector<int> ints = {
        10, 15, 11, 2, 4, 5, 6,
        9, 1, 66, 12, 95, 2, 55,
        8, 101, 45454, 22, 15, 9
    };
    std::partial_sort(ints.begin(), ints.begin()+5, ints.end());

    for(const int i : ints){
        std::cout << i << ' ';
    }
}
/*Exercise 8:
Create a vector of pairs with repeating first elements. 
After sorting, check if the pairs with equal first elements 
maintain their relative order.*/

void ex8()
{
    std::vector<std::pair<int, std::string>> pairs = {
        {25, "sstr"},
        {12, "abba"},
        {5, "aaba"},
        {25, "bbbb"},
        {90, "cecar"},
        {25, "car"},
        {1, "abina"},
        {25, "AAAab"}
    };
    std::sort(pairs.begin(), pairs.end());

    for ( const auto& pair : pairs){
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
    //With the current vector it does keep the order
    //even though we are using std::sort instead of std::stable_sort
}
int main()
{
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex7();
    ex8();
    return 0;
}
