#include<iostream>

//Declaring struct and functions;
struct Time{
  int hours;
  int minutes;  
};
int get_hour();
int get_minutes();
bool validate_hour(int hour);
bool validate_minutes(int minutes);
void calculate_time_difference(int total_starting_minutes, int total_ending_minutes);
void print_time_difference(int time_differece);


int main()
{
    Time starting_time;
    Time ending_time;
    starting_time.hours = get_hour();
    starting_time.minutes = get_minutes();
    ending_time.hours = get_hour();
    ending_time.minutes = get_minutes();

    int total_starting_minutes = starting_time.hours * 60 + starting_time.minutes;
    int total_ending_minutes = ending_time.hours * 60 + ending_time.minutes;
    calculate_time_difference(total_starting_minutes, total_ending_minutes);
 return 0;
}

//Asking user for input until valid number is inputted
int get_hour(){
    while(true){
        int hour = -1;
        std::cout << "Input hour : ";
        std::cin >> hour;
        if(validate_hour(hour)){
            return hour;
        }
    }
    return -1;
    

}
//Asking user for input until valid number is inputted
int get_minutes(){
    while(true){
        int minutes = 0;
        std::cout << "Input minutes : ";
        std::cin >> minutes;
        if(validate_minutes(minutes)){
            return minutes;
        }
    }
    return -1;

}
//Validate time 00:00 - 23.59
bool validate_hour(int hour){
    if(hour > 23 or hour < 0){
        std::cout << "Invalid hour" << std::endl;
        return false;
    }
    return true;
    
}
bool validate_minutes(int minutes){
    if(minutes < 0 or minutes > 59){
        std::cout << "Invalid minutes." << std::endl;
        return false;
    }
    return true;
    
}
void calculate_time_difference(int total_starting_minutes, int total_ending_minutes){
    int time_difference = 0;
    if(total_ending_minutes >= total_starting_minutes){
        time_difference = total_ending_minutes - total_starting_minutes;
    }
    else{
        time_difference = 1440 - (total_starting_minutes - total_ending_minutes);
    }
    print_time_difference(time_difference);
    
}
void print_time_difference(int time_differece){
    std::cout << "The time difference between starting and ending time is: "
              << time_differece / 60 << " hours and "
              << time_differece % 60 << " minutes." << std::endl;
}
