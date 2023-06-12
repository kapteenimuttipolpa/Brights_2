#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
int main()
{
    std::vector<int> ints1 {1, 4, 7, 19, 20, 70, 18, 25};
    std::vector<int> ints2 {1, 4, 7, 18, 60, 222, 70};
    std::vector<int> intersection {};
    std::sort(ints1.begin(), ints1.end()); //sorting the vectors so set_intersection works correctly
    std::sort(ints2.begin(), ints2.end());

    std::set_intersection(ints1.begin(), ints1.end(), 
    ints2.begin(), ints2.end(), std::back_inserter(intersection));

    for(int& i : intersection){
        std::cout << i << "\n";
    }
 return 0;
}