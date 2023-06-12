#include<iostream>
#include<algorithm>
#include<vector>
void remove_value(std::vector<int>& ints, int val)
{
      int size = ints.size();
      ints.erase(std::remove(ints.begin(), ints.end(), val), ints.end());
      if(size == ints.size()){
        std::cout << "No values found.";
      }
      else std::cout << "Values found and removed. ";
}
int main()
{
    std::vector<int> ints {1,2,3,4,5};
    std::cout << "Input value: ";
    int val {0};
    std::cin >> val;
    remove_value(ints, val);
    return 0;
}