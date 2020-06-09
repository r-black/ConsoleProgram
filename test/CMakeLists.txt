project(app_tests)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.65.1 REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# The test program
add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE ${Boost_LIBRARIES} app_lib catch)
target_compile_definitions(tests PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)
