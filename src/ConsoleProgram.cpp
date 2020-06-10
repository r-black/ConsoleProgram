#include "ConsoleProgram.h"

#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

ConsoleProgram::ConsoleProgram(int argc, const char **argv)
{
    // add available options
    description_.add_options()
        (
            "help,h", 
            "prints information about the program and a description of the parameters"
        )  
        (
            "file,f",  
            po::value<std::string>(&inputFilePath_)->composing(), 
            "set input file path, the '-m' option is required"
        )
        (
            "method,m", 
            po::value<std::string>(&nameMethod_)->composing(), 
            "set method: 'checksum' (prints a 32-bit checksum calculated by the checksum = word1 + word2 + ... + wordN algorithm (word1..wordN - 32-bit words representing the contents of a file)) or 'words' (count all words in input file), the '-f' option is required"
        )
        (
            "count,v", 
            po::value<std::string>(&inputWord_)->composing(), 
            "count occurrences of a word, the '-f' and '-m words' options is required"
        );
    po::store(po::parse_command_line(argc, argv, description_), variablesMap_);
    po::notify(variablesMap_);
}

size_t ConsoleProgram::wordsCount(std::ifstream& ifs, const std::string str = {})
{
    size_t num = 0;
    if(str.empty()) {
        num = std::distance(
            std::istream_iterator<std::string>(ifs), 
            std::istream_iterator<std::string>()
        ); 
    } else {
        num = std::count_if(
            std::istream_iterator<std::string>(ifs), 
            std::istream_iterator<std::string>(), 
            [&str](std::string s){ return s == str;}
        );
    }
    return num;
}

uint32_t ConsoleProgram::checksum(std::ifstream& ifs) 
{
    uint32_t sum = 0;

    uint32_t word = 0;
    while (ifs.read(reinterpret_cast<char*>(&word), sizeof(word))) {
        sum += word;
        word = 0;
    }
    sum += word;

    return sum;
}

int ConsoleProgram::exec()
{
    if (variablesMap_.count("file") && variablesMap_.count("method")) {
        std::ifstream file(inputFilePath_);
        if (nameMethod_ == "checksum") {
            std::cout << checksum(file) << std::endl;
        }
        if (nameMethod_ == "words" && variablesMap_.count("count")) {
            std::cout << wordsCount(file, inputWord_) << std::endl; 
        } else if (nameMethod_ == "words") {
            std::cout << wordsCount(file) << std::endl;
        }
    } else if (variablesMap_.count("help")) {
        std::cout << description_ << std::endl;
    } else {
        std::cout << "Please, use -h option for information" << std::endl;
        return 1;
    }

    return 0;
}
