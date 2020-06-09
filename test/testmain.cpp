#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include "ConsoleProgram.h"

TEST_CASE(" app.wordsCount(file, word) return the number of words in a file ") {

    std::ifstream file("../../Test.tst");
    std::string word = "mother";
    ConsoleProgram app(0, nullptr);

    std::cout << std::boolalpha << (app.wordsCount(file, word) == 5) << std::endl;

    REQUIRE(" app.wordsCount(file, word) == 5 ");
}

TEST_CASE(" app.checksum(file) return 32-bit checksum calculated by the checksum = word1 + word2 + ... + wordN algorithm ") {

    std::ifstream file("../../Test.tst");
    ConsoleProgram app(0, nullptr);

    std::cout << std::boolalpha << (app.checksum(file) == 1876598351) << std::endl;

    REQUIRE(" app.checksum(file) == 1876598351 ");
}