#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
using log_vec = std::vector<std::string>;
static std::mutex log_mutex;

void print_logs(const log_vec &logs) noexcept
{
    for (const auto &log : logs)
    {
        std::cout << log << "\n";
    }
}
void read_inputs(log_vec &logs, std::atomic_bool &terminate)
{
    std::lock_guard<std::mutex> log_lock(log_mutex);
    std::string user_input;
    while (user_input != "quit")
    {
        std::cout << " > ";
        std::getline(std::cin, user_input);
        logs.emplace_back(user_input);
        if (user_input == "print")
        {
            print_logs(logs);
        }
    }
    terminate = !terminate; // flip terminate to exit peacefully
}
void log_timer(log_vec &logs, std::atomic_bool &terminate)
{
    while (!terminate)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        logs.emplace_back("One second passed.");
    }
}
int main()
{
    log_vec logs;

    std::atomic_bool terminate{false}; // for the log_timer

    std::thread timer_thread(log_timer, std::ref(logs), std::ref(terminate));
    std::thread log_thread(read_inputs, std::ref(logs), std::ref(terminate));

    timer_thread.join();
    log_thread.join();
    return 0;
}