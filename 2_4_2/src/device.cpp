#include <iostream>
#include <string>
#include <unordered_map>
#include <random>
#include <chrono>
#include "../includes/device.h"
#include "../includes/write_to_csv.h"

void generate_device(std::vector<Device*> &all_devices)
{
    static int device_id{}; // static int to make sure everyone get unique id
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution<int> reg_addres_val_dist{0, 999999};

    if (device_id % 11 != 0) //make 10 slaves to 1 master
    {
        Device *slave_device = new Device;
        slave_device->id = device_id;
        slave_device->is_master = false;
        //generate random values for register address and value
        slave_device->slave_data_register[reg_addres_val_dist(mt)] = reg_addres_val_dist(mt);
        all_devices.push_back(slave_device);
        device_id++;
    }
    else
    {
        Device *master_device = new Device;
        master_device->id = device_id;
        master_device->is_master = true;
        all_devices.push_back(master_device);
        device_id++;
    }
}
/**
 * @brief delete_all_devices
 * since we created the objects using new
 * we have to manually free the memory
 * 
 * @param all_devices 
 */
void delete_all_devices(std::vector<Device*> &all_devices)
{
    for(auto &device : all_devices)
    {
        delete device;
    }
    all_devices.clear();
}