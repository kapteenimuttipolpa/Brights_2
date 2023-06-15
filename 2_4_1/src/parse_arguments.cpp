#include "../includes/parse_arguments.h"
#include "../external/cxxopts/include/cxxopts.hpp"
#include <string>
#include <iostream>
/**
 * @brief Get the options object
 *  defines and configurates command-line
 * options using cxxopts library
 *
 * @return cxxopts::Options
 */
cxxopts::Options get_options()
{
    // creates an instance of options with a description
    cxxopts::Options options("SELECT OPERATION");
    // adds options to the options object
    auto option_adder{options.add_options()};
    option_adder("i,input", "Prints files content", cxxopts::value<std::string>());
    option_adder("l,lines", "Prints the number of lines", cxxopts::value<std::string>()),
        cxxopts::value<std::string>();
    option_adder("w,words", "Prints the number of words", cxxopts::value<std::string>()),
        cxxopts::value<std::string>();
    option_adder("c,chars", "Prints the number of chars", cxxopts::value<std::string>()),
        cxxopts::value<std::string>();
    option_adder("s, size", "Prints the size of text files in path", cxxopts::value<std::string>()),
        cxxopts::value<std::string>();
    return options;
}
/**
 * @brief parse_arguments
 *  parses command-line argumets using cxxopts library
 * @param argc
 * @param argv
 * @param options
 * @return cxxopts::ParseResult
 */
cxxopts::ParseResult parse_arguments(int argc, char *argv[], cxxopts::Options &options)
{
    cxxopts::ParseResult result = options.parse(argc, argv);
    return result;
}