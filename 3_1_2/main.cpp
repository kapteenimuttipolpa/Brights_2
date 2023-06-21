#include "./includes/weather.h"
#include <cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include <exception>
int main()
{
    std::vector<Weather> all_readings;

    generate_random_data(all_readings);


    while(true){
        std::string choise{};
        std::cout << "Would you like to \n (1)Add new weather \n (2)Check current weather \n";
        std::cout << " (3)Print all readings \n";
        std::getline(std::cin >> std::ws, choise);
        
        if(choise == "1"){
            create_reading_manually(all_readings);
        }
        else if(choise == "2"){
            get_current_weather(all_readings);
        }
        else if(choise == "3"){
            print_readings(all_readings);
        }
        else if(choise == "4" or choise == "Q" 
        or choise == "q" or choise == "QUIT"){
            return EXIT_SUCCESS;
        }
        else{
            std::cout << "Invalid choise.\n ";
        }
    }
    return 0;
}