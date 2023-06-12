#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
#include<numeric>
int accum_vector(const std::vector<int>& vec)
{
    int vec_sum = std::accumulate(vec.begin(), vec.end(), 0);
    return vec_sum;
}
int main()
{
    std::vector<int> vec {1,2,3,4,5};
    int sum = accum_vector(vec);
    std::cout << sum;
    
 return 0;
}