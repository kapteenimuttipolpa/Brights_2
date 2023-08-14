#include <iostream>
#include <thread>
void hello()
{
    std::cout << "hello ";
}
void world()
{
    std::cout << " world\n";
}
int main()
{

    std::thread t1(hello);
    std::thread t2(world);
    t2.join();
    t1.join();

    return 0;
}