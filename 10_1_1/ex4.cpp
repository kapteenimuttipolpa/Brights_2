#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
static std::atomic_int var = 0;
static std::mutex m;

constexpr static int t_count = 100;
void add(int increment, int times)
{
    std::lock_guard<std::mutex> m_lock(m);
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
        threads.emplace_back(add, 5, 5);
    }
    for (int i = 0; i < t_count; ++i)
    {
        threads[i].join();
    }
    std::cout << var << "\n";
    return 0;
}