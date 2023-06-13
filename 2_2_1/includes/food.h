#ifndef FOOD_H
#define FOOD_H
#include<string>
#include<vector>
//Creating a structure for food
struct Food{
    
        std::string name_;
        float price_;
        std::vector<std::string> ingredients_;
        void print_food_info(Food& food);
        void add_to_menu(Food* food);
        void print_menu();
        void create_food_and_add_to_menu();
        Food(const std::string& name, double price, const std::vector<std::string>& ing); //Constructor for food object
};
#endif // FOOD_H