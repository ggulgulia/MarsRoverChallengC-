cmake_minimum_required(VERSION 3.2.3) 
project(mars_rover CXX) 


add_subdirectory(mars_rover) #this is path to library and needs compilation first before
# the library is passed to the executable code that links the library
add_subdirectory(rover_exe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "compiling the ${PROJECT_NAME} with CXX ${CMAKE_CXX_STANDARD} standard")
set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -fno-elide-constructors")
#message("Your C++ compiler supports these C++ features:")
#foreach(i ${CMAKE_CXX_COMPILE_FEATURES})
#      message("${i}")
#endforeach()
#set(VARIABLE "I am a variable")
#message(STATUS "variable name: ${VARIABLE}")

