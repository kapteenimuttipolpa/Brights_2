#include "food.h"
#include "utils.h"
#include<string>
#include<iostream>
Food::Food(const std::string& name, double price, const std::vector<std::string>& ing):
name_(name), price_(price), ingredients_(ing){

}
//Vector of pointers that point to food objects
//using pointers to avoid making unnecessary copies
std::vector<Food*> menu; 

//prints info of singular food
void print_food_info(Food& food)
{
    std::cout << "Name: " <<  food.name_ << '\n';
    std::cout << "Price: " << food.price_ << '\n';
    std::cout << "Ingredients: " << '\n';
    for(auto& ing : food.ingredients_){
        std::cout << ing << '\n';
    }
    std::cout << '\n';
    
}
//function adds pointer to food object to vector (menu)
void add_to_menu(Food* food)
{
    menu.push_back(food);
}
void create_food_and_add_to_menu()
{
    Food food;
    std::string food_name{};
    float price {0};
    std::string ingredient{};

    std::cout << "Input foods name: ";
    std::getline(std::cin >> std::ws, food_name);
    std::cout << "Input price: ";
    std::cin >> price;
    while(true){
        //TODO: loop and ask for the ingredients
    }


}
//function loops the menu and and print it
void print_menu()
{
    for(auto& food : menu){
        print_food_info(*food);
    }
    std::cout << '\n';

}


            



    

