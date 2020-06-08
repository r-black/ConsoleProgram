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

    size_t words(std::ifstream& ifs, std::string str);

    uint32_t checksum(std::ifstream& ifs);

private:
    // Описание доступных опций
    po::options_description m_desc {"Allowed options"};
    po::variables_map m_vm; // контейнер для сохранения выбранных опций программы

    // Требуемые в программе переменные для работы с опциями
    std::string m_inputFilePath;
    std::string m_inputWord;
};


#endif //CONSOLE_PROGRAM_H
