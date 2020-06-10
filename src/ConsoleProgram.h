#ifndef CONSOLE_PROGRAM_H
#define CONSOLE_PROGRAM_H

#include <boost/program_options.hpp>
#include <fstream>
#include <string>

namespace po = boost::program_options;

class ConsoleProgram
{
public:
    explicit ConsoleProgram(int argc, const char** argv);

    int exec();

    size_t wordsCount(std::ifstream& ifs, const std::string str);

    uint32_t checksum(std::ifstream& ifs);

private:
    // Description of available options
    po::options_description description_ {"Allowed options"};
    // container for saving selected program options
    po::variables_map variablesMap_; 

    // Variables required for the program to work with options
    std::string inputFilePath_;
    std::string inputWord_;
    std::string nameMethod_;
};


#endif //CONSOLE_PROGRAM_H
