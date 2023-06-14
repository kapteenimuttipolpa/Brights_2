#include "../includes/datareads.h"
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <unordered_map>
/**
 * @brief generate_random_datareadings
 *  Generates random datareadings  
 *  and creates new object with said readings
 *  then adds object to vector 
 */
void generate_random_datareadings()
{   //random names for sensors
    const std::vector<std::string> sensors = {
        "Wing_A_Sensor",
        "Turbo_B_Sensor",
        "Flame_C_Sensor",
        "Echo_D_Sensor",
        "Aero_E_Sensor",
        "Opti_F_Sensor",
        "Pulse_G_Sensor",
        "Bio_H_Sensor",
        "Flex_I_Sensor",
        "Motion_J_Sensor",
        "Aqua_K_Sensor",
        "Heat_L_Sensor",
        "Force_M_Sensor",
        "Robo_N_Senso",
        "Solar_P_Sensor",
        "Speed_R_Sensor"};
    //random
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution<int> hours_dist{0, 23};   // Distribution for hours (0-23)
    std::uniform_int_distribution<int> minutes_dist{0, 59}; // Distribution for minutes (0-59)
    std::uniform_int_distribution<int> sensor_dist{0, 15};
    std::uniform_real_distribution<float> sensor_value_dist{0, 999999}; // Distribution for sensors

    int hours = hours_dist(mt);
    int minutes = minutes_dist(mt);
    float time = static_cast<float>(hours) + static_cast<float>(minutes) / 100.0f;
    std::string sensor_name = sensors[sensor_dist(mt)];
    float sensor_value = sensor_value_dist(mt);
 
    Dataread *new_data = new Dataread; //dynamically allocated this just to practice memory management
    new_data->timestamp_ = time;
    new_data->sensor_id_ = sensor_name;
    new_data->reading_ = sensor_value;
    all_data.push_back(new_data);
    total_reading_all += new_data->reading_;
}
/**
 * @brief Filter_out_data
 *  creates another vector and inserts elements
 * that are not equal to param2
 * @param all_data vector of pointers that hold all_data
 * @param sensor_id sensor_id we want to filter out
 * @return std::vector<Dataread *> 
 */
std::vector<Dataread *> filter_out_data(const std::vector<Dataread *> &all_data, std::string sensor_id)
{
    std::vector<Dataread *> filtered_data{};
    filtered_data.reserve(all_data.size()); //reserve space for vector to avoid making copies
    for (auto &data_reading : all_data)
    {
        if (data_reading->sensor_id_ != sensor_id)
        {
            filtered_data.push_back(data_reading);
            total_reading_filtered += data_reading->reading_;
        }
    }
    return filtered_data;
}
/**
 * @brief sort_filtered_data
 *  sorts data in ascending order
 *  according to timestamp
 * @param filtered_data vector of pointers 
 *  containing filtered data
 * @return std::vector<Dataread *> 
 */
std::vector<Dataread *> sort_filtered_data(const std::vector<Dataread *> &filtered_data)
{
    std::vector<Dataread *> data_sorted_by_time = filtered_data;
    //sorting the vector, I dont actually know if using [&]-capture here is good or bad 
    std::sort(data_sorted_by_time.begin(), data_sorted_by_time.end(), 
    [&](Dataread *a, Dataread *b)
              { return a->timestamp_ < b->timestamp_; });

    return data_sorted_by_time;
}
/**
 * @brief find_outlier_from_data
 *  finds data_readings that exceed given limit
 * @param filtered_data vector of pointers
 * @param total_reading_filtered total reading amount of filtered data
 * @param deviation_percentage constexpr value user can decide
 * @return std::vector<Dataread *> 
 */
std::vector<Dataread *> find_outlier_from_data(const std::vector<Dataread *> 
&filtered_data, float total_reading_filtered, int deviation_percentage)
{
    float mean = total_reading_filtered / filtered_data.size();
    float outlier_threshold = mean + 
    (mean * (static_cast<float>(deviation_percentage) / 100.0f)); //calculate the threshold
    std::cout << "Mean: " << mean << '\n';
    std::cout << "Outlier treshold: " << outlier_threshold << '\n';
    std::vector<Dataread *> outliers = {};
    for (auto &data_reading : filtered_data)
    {
        if (data_reading->reading_ >= outlier_threshold)
        {
            outliers.push_back(data_reading);
        }
    }
    return outliers;
}
/**
 * @brief find_highest_freq_sensor
 * finds the sensor that outputs highest amount
 * of signals.
 * 
 * @param filtered_data vector of pointers containing filtered data
 * @return std::pair<std::string, int> Sensors name and how many times
 * it sent a signal
 */
std::pair<std::string, int> find_highest_freq_sensor
(const std::vector<Dataread *> &filtered_data)
{
    std::pair<std::string, int> most_freq{};
    std::unordered_map<std::string, int> data_map;

    //Loop the vector and if ID is not in map, add it and 1
    for (auto &data : filtered_data)
    {
        if (data_map.find(data->sensor_id_) != data_map.end())
        {
            data_map.at(data->sensor_id_)++; // if its in map, increase value by one
        }
        else
        {
            data_map[data->sensor_id_] = 1;
        }
    }
    //Find the most frequent value using std::max_element and lambda function
    //Again im not sure if reference-& should be inside lambda capture or in the argumets we give
    //Or does it even make any difference
    std::unordered_map<std::string, int>::iterator it =
        std::max_element(data_map.begin(), data_map.end(),
         [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
                         { return a.second < b.second; });

    most_freq = std::make_pair(it->first, it->second);
    return most_freq;
}
/**
 * @brief delete_data
 * loops trough the all_data vector
 * and deletes every object we created dynamically
 * 
 * @param all_data vector with all data
 */
void delete_data(std::vector<Dataread *> &all_data)
{
    //since we allocated memory for the Dataread objects, we need
    // to manually delete it
    for (auto &data : all_data)
    {
        data->sensor_id_ = "";
        data->reading_ = 0;
        data->timestamp_ = 0;
        delete data;
    }
    all_data.clear();
}
/**
 * @brief print_data prints data
 * 
 * @param data_vec vector we want to print
 */
void print_data(std::vector<Dataread *> &data_vec)
{
    for (auto &data : data_vec)
    {
        std::cout << data->timestamp_ << '\t';
        std::cout << data->sensor_id_ << '\t';
        std::cout << data->reading_ << '\n';
    }
}