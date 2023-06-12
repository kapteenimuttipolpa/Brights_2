#include<iostream>
#include<algorithm>
#include<list>
int main()
{
    std::list<int> list {1,2,3,4,5,6,7,8,9,9};
    auto it = std::adjacent_find(list.begin(), list.end());
    if(it != list.end()){
        std::cout << "First repeated pair at: " << *it << "\n"; // in this case, 9
    }
    else{
        std::cout << "No repeated adjecent elements.";
    }
 return 0;
}