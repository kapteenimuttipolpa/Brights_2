#include <iostream>
#include "./includes/print_file_data.h"
#include "./includes/parse_arguments.h"
#include "./includes/print_file_lines.h"
#include "./includes/print_file_wordcount.h"
#include "./includes/print_file_chars.h"
#include "./includes/calculate_file_size.h"
#include "./external/cxxopts/include/cxxopts.hpp"

int main(int argc, char* argv[])
{
    cxxopts::Options options = get_options();
    auto result = parse_arguments(argc, argv, options);
    if(argc == 2) //if user gave only 2 arguments
    // prints the files content
    {
        auto res = static_cast<std::string>(argv[1]);
        print_file_data(res);
        return EXIT_SUCCESS;
    }
     else if(result.count("lines") or result.count("l"))
    {
        auto res = static_cast<std::string>(argv[2]);
        print_file_lines(res);
    }
    else if(result.count("words") or result.count("w"))
    {
        auto res = static_cast<std::string>(argv[2]);
        print_file_wordcount(res);
    }
    else if(result.count("chars") or result.count("c"))
    {
        auto res = static_cast<std::string>(argv[2]);
        print_file_chars(res);
    }
    else if(result.count("size") or result.count("s"))
    {
        auto res = static_cast<std::string>(argv[2]);
        calculate_file_size(res);
    }

    return 0;
}