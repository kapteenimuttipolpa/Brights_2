#include<iostream>
#include<algorithm>
#include<array>
void min_max_arr(std::array<int, 10>& ints)
{
      std::pair<std::array<int, 10>::const_iterator, std::array<int,10>::const_iterator> min_max =
        std::minmax_element(ints.begin(), ints.end());
        
        std::cout << "MIN: " << *min_max.first << "\n";
        std::cout << "MAX: " << *min_max.second << "\n";

}
int main()
{
    std::array<int, 10> ints {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    min_max_arr(ints);

 return 0;
}