#include <iostream>
#include <exception>

#include "ConsoleProgram.h"

int main(int argc, const char* argv[])
{
    try {
        ConsoleProgram app(argc, argv);
        return app.exec();
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
        return 1;
    }
}