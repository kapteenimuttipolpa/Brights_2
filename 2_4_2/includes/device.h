#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#ifndef DEVICE_H
#define DEVICE_H

struct Device
{
    int id;
    bool is_master;
    std::unordered_map<int, int> slave_data_register;
};
void generate_device(std::vector<Device *> &all_devices);
void delete_all_devices(std::vector<Device*> &all_devices);

#endif