#include "food.h"
#include "menu.h"
#include<string>
#include<iostream>
Food::Food(const std::string& name, double price, const std::vector<std::string>& ing):
name_(name), price_(price), ingredients_(ing){

}
std::vector<Food*> menu;
void print_food_info(Food& food)
{
    std::cout << "Name: " <<  food.name_ << '\n';
    std::cout << "Price: " << food.price_ << '\n';
    std::cout << "Ingredients: " << '\n';
    for(auto& ing : food.ingredients_){
        std::cout << ing << '\n';
    }
    
}
//testaan
void add_to_menu(Food* food)
{
    menu.push_back(food);
}
void print_menu()
{
    for(auto& food : menu){
        std::cout <<"Foods name: "<<food->name_ << '\n';
        std::cout <<"Foods price: "<<food->price_ << '\n';
        /*std::cout << "Foods ingredients: " << '\n';
        for(auto& ing : food->ingredients_){
            std::cout << ing << '\n';
        }*/
    }

}
void ask_user_order()
{
    std::vector<Food*> current_order;
    float current_total_price = 0;
    while(true)
    {
        print_menu();
        std::string choise {};
        std::cout << "Please write the name of the food you would like to order. \n";
        std::getline(std::cin, choise);
        auto it = menu.begin();
        while(it != menu.end())
        {
            if((*it)->name_ == choise){
                current_order.push_back(*it);
                current_total_price += (*it)->price_;
                std::cout << (*it)->name_ << " added to order. \n";
                break;
            }
            ++it;
        }
        if(it == menu.end()){
            std::cout << "No matching food found. \n";
        }



    }
}
