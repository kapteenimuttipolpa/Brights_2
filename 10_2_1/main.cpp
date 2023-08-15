
#include <array>
#include <atomic>
#include <chrono>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

struct Velocity
{
    int x;
    int y;
    int z;
};
struct Position
{
    int x;
    int y;
    int z;
    constexpr bool operator==(const Position &other) const noexcept
    {
        return (x == other.x && y == other.y && z == other.z);
    }
};
struct Planet
{
    Position org_pos;
    Position pos = org_pos;
    Velocity vel;
};
using Planets = std::vector<Planet>;

// if planet 1 has x coordinate smaller than planet 2 then the velocity of planet 1 increases and planet 2 decreases in x-direction
void velocity_step_x(Planet &lhs, Planet &rhs) noexcept
{
    if (lhs.pos.x > rhs.pos.x)
    {
        lhs.vel.x -= 1;
    }
    else if (lhs.pos.x < rhs.pos.x)
    {
        lhs.vel.x += 1;
    }
}
void velocity_step_y(Planet &lhs, Planet &rhs) noexcept
{
    if (lhs.pos.y > rhs.pos.y)
    {
        lhs.vel.y -= 1;
    }
    else if (lhs.pos.y < rhs.pos.y)
    {
        lhs.vel.y += 1;
    }
}
void velocity_step_z(Planet &lhs, Planet &rhs) noexcept
{
    if (lhs.pos.z > rhs.pos.z)
    {
        lhs.vel.z -= 1;
    }
    else if (lhs.pos.z < rhs.pos.z)
    {
        lhs.vel.z += 1;
    }
}
void update_coords(Planet &planet) noexcept
{
    planet.pos.x += planet.vel.x;
    planet.pos.y += planet.vel.y;
    planet.pos.z += planet.vel.z;
}

void step_x(Planets &planets, std::atomic<int> &x_count) noexcept
{
    while (true)
    {
        int originals = 0;
        for (auto &planet : planets)
        {
            for (auto &planet_inner : planets)
            {
                velocity_step_x(planet, planet_inner);
            }
        }
        for (auto &planet : planets)
        {
            planet.pos.x += planet.vel.x;
            if (planet.pos.x == planet.org_pos.x)
            {
                originals += 1;
            }
        }
        if (originals == 5)
        {
            ++x_count;
            break;
        }
        ++x_count;
    }
}
void step_y(Planets &planets, std::atomic<int> &y_count) noexcept
{
    while (true)
    {
        int originals = 0;
        for (auto &planet : planets)
        {
            for (auto &planet_inner : planets)
            {
                velocity_step_y(planet, planet_inner);
            }
        }
        for (auto &planet : planets)
        {
            planet.pos.y += planet.vel.y;
            if (planet.pos.y == planet.org_pos.y)
            {
                originals += 1;
            }
        }
        if (originals == 5)
        {
            ++y_count;
            break;
        }
        ++y_count;
    }
}
void step_z(Planets &planets, std::atomic<int> &z_count)
{
    while (true)
    {
        int originals = 0;
        for (auto &planet : planets)
        {
            for (auto &planet_inner : planets)
            {
                velocity_step_z(planet, planet_inner);
            }
        }
        for (auto &planet : planets)
        {
            planet.pos.z += planet.vel.z;
            if (planet.pos.z == planet.org_pos.z)
            {
                originals += 1;
            }
        }
        if (originals == 5)
        {
            ++z_count;
            break;
        }
        ++z_count;
    }
}

size_t second_main(Planets &planets)
{
    std::atomic<int> x_count{1};
    std::atomic<int> y_count{1};
    std::atomic<int> z_count{1};
    size_t result = 0;
    std::thread thread_x(step_x, std::ref(planets), std::ref(x_count));
    std::thread thread_y(step_y, std::ref(planets), std::ref(y_count));
    std::thread thread_z(step_z, std::ref(planets), std::ref(z_count));
    thread_x.join();
    thread_y.join();
    thread_z.join();
    return std::lcm(x_count.load(), std::lcm(y_count.load(), z_count.load()));
    return result;
}

int main()
{
    //
    Planets system{{{0, 5, 2}, {0, 5, 2}, {0, 0, 0}}, {{-10, 7, -94}, {-10, 7, -94}, {0, 0, 0}}, {{6042, 4, 8}, {6042, 4, 8}, {0, 0, 0}}, {{-42, 55, 92}, {-42, 55, 92}, {0, 0, 0}}, {{0, -54189072, 0}, {0, -54189072, 0}, {0, 0, 0}}};
    size_t steps =
        second_main(system);
    std::cout << "Final steps: " << steps << "\n";
    return 0;
}
