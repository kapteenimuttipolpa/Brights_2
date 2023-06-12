#include<iostream>
#include<vector>
int main()
{
    std::cout << "Input vector size: ";
    int size = 0;
    std::cin >> size;
    std::vector<int> vec (size);

    std::cout << vec.size();
 return 0;
}