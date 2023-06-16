#include "../includes/read_from_csv.h"
#include "../includes/write_to_csv.h"
#include "../includes/device.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
/**
 * @brief read_from_csv
 *  reads data from .csv file
 *  user gives bool val if he wants to edit
 *  or just read data from the file
 *  edit_val is used to edit the register value
 *  from given slave id and register address
 * 
 * @param edit_val 
 * @param all_devices 
 */
void read_from_csv(bool edit_val, std::vector<Device *> &all_devices)
{
    std::string new_val{};
    const std::string data{"data.csv"};
    const std::string registers{"registers.csv"};

    std::ifstream file_object(registers);
    //try to open the file, if file cannot be opened, return to main
    if (!file_object.is_open())
    {
        std::cout << "Cannot open file!";
        return;
    }
    std::cout << "Input the slaves id : ";
    std::string slave_id{};
    std::getline(std::cin >> std::ws, slave_id);
    std::cout << "Input the register address: ";

    std::string reg_ad{};
    std::getline(std::cin >> std::ws, reg_ad);
    std::string line{};
    //if edit_val is true, user wants to edit slaves register address
    if (edit_val) 
    {

        std::cout << "Input new val: ";
        std::getline(std::cin >> std::ws, new_val);
    }

    while (std::getline(file_object, line))
    {
        std::stringstream ss(line);
        std::string stored_id{}; //stores slaves id
        std::string stored_ad{}; //stores slaves address
        std::string stored_adval{}; //stores slavess addres value
        if (std::getline(ss, stored_id, ',')  // remove commas from values and 
        and std::getline(ss, stored_ad, ',')  // check for match
        and std::getline(ss, stored_adval, ','))
        {
            if (stored_id == slave_id and stored_ad == reg_ad) // if id and stored address
            // match the user given values
            { 
                if (!edit_val) //check if user wants to edit value
                {
                    file_object.close();
                    std::cout << "Value read from the address: " << stored_adval << '\n';
                    return;
                }
                //if user wants to edit value, change values stored in all_devices vector
                for (auto &device : all_devices)
                {
                    if (device->id == std::stoi(slave_id)
                     and device->slave_data_register.at(std::stoi(reg_ad)))
                    {
                        device->slave_data_register[std::stoi(reg_ad)] = std::stoi(new_val);
                    }
                }

                file_object.close();
                write_to_csv_master(all_devices); //rewrite the entire file
                std::cout << "New value set to address " 
                          << stored_ad << "->" 
                          << new_val << '\n';
                return;
            }
        }
    }
    std::cout << "No stored value found with given id or address.\n";
}
