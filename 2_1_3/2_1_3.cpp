#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<std::string> students{"VILLE", "KARRI", "OSKAR", "HEIDI",
                                      "ELISA", "ANNA", "KIRSI", "MIKKO", "JUHO"}; //list of all the students

    std::shuffle(students.begin(), students.end(), g); //mix it up a little
    std::vector<std::pair<std::string, std::string>> reviews; // vector of pairs
    for (int i = 0; i < students.size() - 1; i++)
    {
        auto review = std::make_pair(students[i], 
        students[i + 1]); // reviews the next person on list
        reviews.push_back(review);
    }
    if (students.size() > 2)
    {
        reviews.push_back(std::make_pair(students.at(students.size() - 1)
        , students.at(0))); // last person on the list reviews the first one
    }
    for (auto review : reviews)
    {
        std::cout << review.first << " reviews " << review.second << "'s"
                  << " assignment."
                  << "\n";
    }
    return 0;
}