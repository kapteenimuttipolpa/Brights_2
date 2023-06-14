#include <string>
#include <vector>
#ifndef DATAREADS_H
#define DATAREADS_H

struct Dataread
{
    float timestamp_;
    std::string sensor_id_;
    float reading_;
    void generate_random_datareadings();
    std::vector<Dataread *> filter_out_data(const std::vector<Dataread *> &all_data, std::string sensor_id);
    std::vector<Dataread *> sort_filtered_data(const std::vector<Dataread *> &filtered_data);
    std::vector<Dataread *> find_outlier_from_data(const std::vector<Dataread *> &filtered_data, float total_reading_filtered, int deviation_percentage);
    std::pair<std::string, int> find_highest_freq_sensor(const std::vector<Dataread *> &filtered_data);
    void print_data(std::vector<Dataread *> &data_vec);
    void delete_data(std::vector<Dataread *> &all_data);
};
std::vector<Dataread *> all_data;
float total_reading_all{0.0};
float total_reading_filtered{0.0};
constexpr static int deviation_percentage = 20;

#endif // DATAREADS_H
