#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H
#include "../external/cxxopts/include/cxxopts.hpp"
#include <string>

cxxopts::Options get_options();

cxxopts::ParseResult parse_arguments(int argc, char *argv[], cxxopts::Options &options);


#endif // PARSE_ARGMENTS_H