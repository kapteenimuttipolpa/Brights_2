#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;
class foods
{
  public:
    std::vector<std::string> likes;
    std::vector<std::string> dislikes;

    foods(const json &foods_json)
    {
        likes = foods_json["likes"].get<std::vector<std::string>>();
        dislikes = foods_json["dislikes"].get<std::vector<std::string>>();
    }
};

class pet
{
  public:
    std::string name;
    std::string species;
    foods m_foods;

    pet(const json &pet_json) : name(pet_json["name"]),
                                species(pet_json["species"]),
                                m_foods(pet_json["foods"]) {}
};
int main()
{

    std::ifstream f("animals.json");
    json data = json::parse(f);

    std::vector<pet> all_pets;
    for (const auto &pet : data)
    {
        all_pets.emplace_back(pet);
    }

    for (const auto &pet : all_pets)
    {
        std::cout << "name: " << pet.name << "\n";
        std::cout << "species: " << pet.species << "\n";
        std::cout << "liked foods: \n";
        for (const auto &food : pet.m_foods.likes)
        {
            std::cout << " " << food << "\n";
        }
        std::cout << "disliked foods: \n";
        for (const auto &food : pet.m_foods.dislikes)
        {
            std::cout << " " << food << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}