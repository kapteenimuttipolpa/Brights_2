#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
void print_min_max(const std::vector<int>& vec)
{
     std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> min_max =
        std::minmax_element(vec.begin(), vec.end());
        
        std::cout << "MIN: " << *min_max.first << "\n";
        std::cout << "MAX: " << *min_max.second << "\n";
}
int main()
{
    std::vector<int> vec {1,2,3,4,5};
    print_min_max(vec);
 return 0;
}