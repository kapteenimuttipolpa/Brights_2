#include <string>
#include <iostream>
#include <vector>
#include "datareads.h"
#include "../src/datareads.cpp"

int main()
{

    // generate random datareagins
    for (int i = 0; i < 1000; i++)
    {
        generate_random_datareadings();
    }
    std::cout << "All data: \n";
    print_data(all_data);

    std::cout << "\nFiltered data :\n";
    std::vector<Dataread *> filtered_data = filter_out_data(all_data, "Turbo_B_Sensor");
    print_data(filtered_data);

    std::cout << "Data sorted by time: \n";
    std::vector<Dataread *> data_sorted_by_time = sort_filtered_data(filtered_data);
    print_data(data_sorted_by_time);

    std::vector<Dataread *> outlier_data = find_outlier_from_data(data_sorted_by_time, total_reading_filtered, 20);
    std::cout << "\nOutliers:\n";
    print_data(outlier_data);

    std::pair<std::string, int> most_freq = find_highest_freq_sensor(filtered_data);
    std::cout << "\nSensor that has the highest frequency of readings: " << most_freq.first << '\n';
    std::cout << "Sensor had a total of " << most_freq.second << " readings.\n";
    delete_data(all_data);
    return 0;
}
