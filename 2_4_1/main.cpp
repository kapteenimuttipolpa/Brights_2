#include <iostream>
#include "./includes/print_file_data.h"
#include "./includes/parse_arguments.h"
#include "./external/cxxops/include/cxxopts.hpp"

int main(int argc, char* argv[])
{
    cxxopts::Options options = get_options();
    auto result = parse_arguments(argc, argv, options);
    
    if(argc - 1 == 0)
    {
        auto res = static_cast<std::string>(argv[1]);
        print_file_data(res);
    }
    
    return 0;
}