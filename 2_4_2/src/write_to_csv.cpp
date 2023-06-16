#include <fstream>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <iostream>
#include "../includes/device.h"
#include "../includes/write_to_csv.h"

const std::string filename_all{"data.csv"};
const std::string filename_reg{"registers.csv"};
/**
 * @brief write_to_csv_master
 * function writes values from all_devices vector to .csv file
 * writes every devices id and master/slave status to data.csv
 * writes slave devices id, register address and register data to registers.csv
 * @param all_devices vector of pointers containing all devices
 */
void write_to_csv_master(std::vector<Device*> &all_devices)
{

    std::fstream file_object(filename_all);
    if (!file_object.is_open())
    {
        std::cout << "Cannot open file.\n";
        return;
    }
    std::fstream file_object_2(filename_reg);
    if (!file_object_2.is_open())
    {
        std::cout << "Cannot open file.\n";
        return;
    }

    for (auto &device : all_devices)
    {
        file_object << device->id << ',' << device->is_master << '\n';
        {
            file_object_2 << device->id;
            for (auto &pair : device->slave_data_register)
            {
                file_object_2 << ',' << pair.first << ',' << pair.second << '\n';
            }
        }
    }

    file_object.close();
    file_object_2.close();
}
