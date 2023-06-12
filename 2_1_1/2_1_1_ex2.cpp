#include<iostream>
#include<array>
#include<algorithm>
bool is_in_arr(std::array<int, 10> arr, int n)
{
    auto it = std::find(arr.begin(), arr.end(), n);
    return it != arr.end() ? true : false;
}
int main()
{
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    int i = 3;
    std::cout << is_in_arr(arr, 3) << "\n";
    std::cout << is_in_arr(arr, 11) << "\n";
    std::cout << is_in_arr(arr, 4) << "\n";
 return 0;
}