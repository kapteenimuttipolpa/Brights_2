#include <iostream>
#include "./includes/device.h"
#include "./includes/read_from_csv.h"
#include "./includes/write_to_csv.h"

int main()
{
    std::vector<Device *> all_devices;
    for (int i = 0; i < 100; i++)
    {
        generate_device(all_devices);
    }
    write_to_csv_master(all_devices);
    read_from_csv(false, all_devices);
    read_from_csv(true, all_devices);
    delete_all_devices(all_devices);

    return 0;
}
