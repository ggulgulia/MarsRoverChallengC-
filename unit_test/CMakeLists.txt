cmake_minimum_required(VERSION 3.2.3)
project(mars_rover CXX) 
enable_testing()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -fno-elide-constructors")

find_package(PkgConfig REQUIRED)
pkg_check_modules(gtest REQUIRED gtest>=1.8.1)
include_directories(${gtest_INCLUDE_DIRS})

add_executable(test_mars_rover 
                main_test.cpp 
               ../mars_rover/src/InitializeRovers.hpp
               ../mars_rover/src/InitializeRovers.cpp
               ../mars_rover/src/Rover.hpp
               ../mars_rover/src/Rover.cpp)
target_link_libraries(test_mars_rover ${gtest_LIBRARIES})
add_test(NAME test COMMAND test_mars_rover)
