cmake_minimum_required(VERSION 3.2.3) 
project(mars_rover CXX) 


add_subdirectory(mars_rover) 
add_subdirectory(rover_exe)
add_subdirectory(unit_test)
#if (${WITH_UNIT_TESTS})
#    message(STATUS "Building with Unit Tests")
#    add_subdirectory(unit_test)
#endif()


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if(${DEBUG})
    message(STATUS "compiling in debug mode")
    set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -fno-elide-constructors")
else()
    set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -fno-elide-constructors")
endif()

message(STATUS "compiling the ${PROJECT_NAME} with CXX ${CMAKE_CXX_FLAGS}")
#message("Your C++ compiler supports these C++ features:")
#foreach(i ${CMAKE_CXX_COMPILE_FEATURES})
#      message("${i}")
#endforeach()
#set(VARIABLE "I am a variable")
#message(STATUS "variable name: ${VARIABLE}")



