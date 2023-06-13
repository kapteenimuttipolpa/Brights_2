#include<iostream>
#include<string>
#include"includes/food.h"
#include"includes/food.cpp"


int main()
{
    Food pizza("pizza", 10.20, {"kinkku", "ananas", "kebab"});
    add_to_menu(&pizza);
    Food pasta("pasta", 10.20, {"muttipolpa", "spaghetti", "sika-nauta 20%"});
    add_to_menu(&pasta); // adding few examples to the menu
    std::vector<Food*> current_order;
    float current_total_price = 0;
    bool keep_looping = true;
    //User interface loop
    while(keep_looping)
    {
                    
            std::cout << "What would you like to do? \n";
            std::cout << "1. Add to order \n";
            std::cout << "2. Check current order \n";
            std::cout << "3. Check the menu\n";
            std::cout << "4. Checkout\n";
            int choice {};
            std::cin.clear();
            std::cin >> choice;

            switch (choice){
            case 1:
        {
            std::string food_choice {};
            std::cout << "Please input the name of the food you would like to order: ";
            std::getline(std::cin >> std::ws, food_choice);
            auto it = menu.begin();
            bool found = false;
            while (it != menu.end())
            {
                if ((*it)->name_ == food_choice) //iterating over the food vector
                // if food with matching name is found, adds it to the order
                // prints error message if not found
                {
                    current_order.push_back(*it);
                    current_total_price += (*it)->price_;
                    std::cout << '\n';
                    std::cout << (*it)->name_ << " added to order.\n";
                    std::cout << '\n';
                    found = true;
                    break;
                }
                ++it;
            }
            if (!found)
            {
                std::cout << "No matching food found.\n";
            }
            break;
        }
        case 2: // case 2 prints current order. Prints only name and price for simplicity
        {
            std::cout << "Current order:\n";
            for (auto food : current_order)
            {
                std::cout << food->name_ << '\n';
                std::cout << food->price_ << '\n';
            }
            std::cout << "Total price: " << current_total_price << '\n';
            break;
        }
        case 3: //case3 prints menu with ingredients
            print_menu(); 
            break;
        case 4: //case 4 quits the loop and prints current order for the user
        {
            std::cout << "You ordered:\n";
            for (auto& food : current_order)
            {
                std::cout << food->name_ << '\n';
            }
            std::cout << "Price of the order: " << current_total_price << '\n';
            current_order.clear();
            current_total_price = 0;
            keep_looping = false;
            continue;
        }
        default:
            std::cout << "Unknown command!\n";
            break;
                    
            }
    }

    

 return 0;
}