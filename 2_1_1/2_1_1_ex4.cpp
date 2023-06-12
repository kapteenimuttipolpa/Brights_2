#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
void product_of_vec(const std::vector<int>& vec)
{
    std::cout << std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
    // 1*2*3
}
int main()
{
    std::vector<int>  vec {1,2,3};
    product_of_vec(vec);

 return 0;
}