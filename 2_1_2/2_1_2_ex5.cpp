#include<iostream>
#include<algorithm>
#include<random>

int main()
{
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<> dist(1, 100); // random in range of 1 to 100
 int size = dist(gen); // randomize size 1 to 100
 std::vector<int> ints(size); // initialize vector with random size in range 1 to 100
 std::generate(ints.begin(), ints.end(), [&](){return dist(gen); }); //generate random numbers in range 1 to 100
 for(int i : ints){
    std::cout << i << '\n';
 }

 return 0;
}