#include "../includes/print_file_wordcount.h"
#include <string>
#include <fstream>
#include <iostream>
/**
 * @brief print_file_wordcount
 *  prints how many words are in the file
 * @param filename 
 */
void print_file_wordcount(const std::string& filename)
{
    std::ifstream file_object(filename); // create object of the file

    if(not file_object){ //checks if object exists (is the file open)
        std::cout <<  "Cannot open file.\n";
        return;
    }
    std::string word{};
    int counter{};
    while(file_object >> word) //loop the file and add words to counter 
    {
        counter++;
    }
    std::cout << "The file contained: " << counter << " words.\n";
}