#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
    std::vector<int> ints {1,2,3,4,5,6,7,8,9,10};
    auto it = std::partition(ints.begin(), ints.end(),
     [](int i) {return i % 2 == 0;}); // Used lambda function for the partition
    for(auto& elem : ints){
        std::cout << elem << "\n";
    }

 return 0;
}