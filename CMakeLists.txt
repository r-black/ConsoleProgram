cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.58.0 COMPONENTS program_options)

set(SOURCE_FILES
        main.cpp
        ConsoleProgram.cpp
        ConsoleProgram.h)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(app ${SOURCE_FILES})
    target_link_libraries(app ${Boost_LIBRARIES})
endif()