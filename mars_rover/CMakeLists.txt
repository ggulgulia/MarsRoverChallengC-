#add appropriate path to src code from which the lib is to be made
set(CMAKE_CXX_STANDARD 11)
add_library(
    rover SHARED
    src/Rover.hpp
    src/Rover.cpp
    src/InitializeRovers.hpp
    src/InitializeRovers.cpp
    )

#rover refers to the target library and not a directory
#make the library PUBLIC
target_include_directories(rover PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
