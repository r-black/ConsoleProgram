project(app)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.65.1 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(app_lib STATIC ConsoleProgram.h ConsoleProgram.cpp)
target_include_directories(app_lib PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(app main.cpp)
target_link_libraries(app PRIVATE ${Boost_LIBRARIES} app_lib)