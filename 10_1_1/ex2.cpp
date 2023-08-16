#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
static int var = 0;
constexpr static int t_count = 100;
void add(int increment, int times)
{
    for (int i = 0; i < times; ++i)
    {
        var += increment;
    }
}

int main()
{
    std::vector<std::thread> threads;
    threads.reserve(t_count);
    for (int i = 0; i < t_count; ++i)
    {
        threads.emplace_back(add, 500, 50000);
    }
    for (int i = 0; i < t_count; ++i)
    {
        threads[i].join();
    }
    std::cout << var << "\n";
    return 0;
}