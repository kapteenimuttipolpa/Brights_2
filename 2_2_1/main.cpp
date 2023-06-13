#include<iostream>
#include<string>
#include"food.h"
#include"food.cpp"


int main()
{
    std::string food_name = "Pizza";
    double price = 9.99;
    std::vector<std::string> ingredients = {"viina", "johannes", "teline"};
    Food pizza(food_name, price, ingredients);
    print_food_info(pizza);
    add_to_menu(&pizza);
    Food pasta("pasta", 10.20, {"muttipolpa", "spaghetti", "sika-nauta 20%"});
    add_to_menu(&pasta);
    print_menu();
    ask_user_order();

    

 return 0;
}