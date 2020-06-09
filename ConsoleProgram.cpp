#include "ConsoleProgram.h"

#include <iostream>
#include <fstream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

ConsoleProgram::ConsoleProgram(int argc, const char **argv)
{
    // Добавляем пункты меню
    m_desc.add_options()
            ("help,h", "prints information about the program and a description of the parameters")  // печатает информацию о программе и описание параметров
            ("file,f",  po::value<std::string>(&m_inputFilePath)->composing(), "set input file path, the '-m' option is required") // Входной файл
            ("method,m", po::value<std::string>(&m_nameMethod)->composing(), "set method: 'checksum' (prints a 32-bit checksum calculated by the checksum = word1 + word2 + ... + wordN algorithm (word1..wordN - 32-bit words representing the contents of a file)) or 'words' (count all words in input file), the '-f' option is required") // Метод
            ("count,v", po::value<std::string>(&m_inputWord)->composing(), "count occurrences of a word, the '-f' and '-m words' options is required") // Вызов метода words - используется с параметром -v и словом, количество вхождений которого нужно определить
            ;
    po::store(po::parse_command_line(argc, argv, m_desc), m_vm);
    po::notify(m_vm);
}

size_t ConsoleProgram::wordsCount(std::ifstream& ifs, const std::string str = {})
{
    size_t num = 0;
    if(str.empty())
    {
        num = std::distance(
            std::istream_iterator<std::string>(ifs), 
            std::istream_iterator<std::string>()
        ); 
    }
    else
    {
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
    
    if (m_vm.count("file") && m_vm.count("method"))
    {
        std::ifstream file(m_inputFilePath);
        if (m_nameMethod == "checksum")
        {
            std::cout << checksum(file) << std::endl;
        }
        if (m_nameMethod == "words" && m_vm.count("count"))
        {
            std::cout << wordsCount(file, m_inputWord) << std::endl; 
        }
        else if (m_nameMethod == "words")
        {
            std::cout << wordsCount(file) << std::endl;
        }
    }
    // Если есть запрос на справку
    else if (m_vm.count("help"))
    {
        // выводим описание меню
        std::cout << m_desc << std::endl;
        return 1;
    }
    else
    {
        // предлагаем посмотреть справку
        std::cout << "Please, use -h option for information" << std::endl;
        return 1;
    }

    return 0;
}
