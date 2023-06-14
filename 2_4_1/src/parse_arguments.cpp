#include "../includes/parse_arguments.h"
#include "../external/cxxops/include/cxxopts.hpp"
#include <string>

cxxopts::Options get_options()
{
    cxxopts::Options options("SELECT OPERATION");

    auto option_adder{options.add_options()};
    option_adder("Input filename", "Prints files content", cxxopts::value<std::string>());
    return options;
}
cxxopts::ParseResult parse_arguments(int argc, char *argv[], cxxopts::Options &options)
{
    return options.parse(argc, argv);
}