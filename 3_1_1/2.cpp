#include <algorithm>
#include <cstdlib>
#include<iostream>
#include<vector>
#define EMPTY_VECTOR 1
/*2. Write a program that reads in a list of 
integers and finds the maximum value. 
Return an error code if the list is empty.*/
int find_max(const std::vector<int>& vec){
    if(!vec.empty()){
        auto max = std::max_element(vec.begin(), vec.end()); // finds max elem
        return *max;
    }
    return EMPTY_VECTOR;

}
int main()
{
    std::vector<int> vec{4, 1, 0, 89, 12, 43};
    std::vector<int> vec2 {};
    int max = find_max(vec2); // will return the error code
    if(max == EMPTY_VECTOR){
        std::cout << "Error: vector is empty";
        return EXIT_FAILURE;
    }
    else std::cout << "Max value: " << max;

    return 0;
}