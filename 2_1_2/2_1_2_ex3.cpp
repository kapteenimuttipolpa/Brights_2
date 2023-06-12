#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
    auto print = [](const auto& i){std::cout << i << " ";}; // lambda function to print in for_each loop
    std::vector<int> ints {1,2,3,4,5,6,7,8,9,10};
    std::rotate(ints.begin(), ints.begin()+3, ints.end());
    for_each(ints.begin(), ints.end(), print);
 return 0;
}