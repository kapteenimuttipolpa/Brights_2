#ifndef FOOD_H
#define FOOD_H
#include<string>
#include<vector>

struct Food{
    
        std::string name_;
        float price_;
        std::vector<std::string> ingredients_;
        void print_food_info(Food& food);
        void add_to_menu(Food* food);
        void print_menu();
        void ask_user_order();
        Food(const std::string& name, double price, const std::vector<std::string>& ing);
};
#endif // FOOD_H