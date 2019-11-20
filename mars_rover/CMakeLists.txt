#add appropriate path to src code from which the lib is to be made
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

##creating a list of flags
list(APPEND _flags "-fpic" "-Wall" "-Werror" "-Wpedantic" "-Wextra")
if(${DEBUG})
    message(STATUS "Mode = Debug")
    list(APPEND _flags "-g")
else()
    list(APPEND _flags "-O3")
endif()

##creating list of source file
list(APPEND _rover_src
    src/Rover.hpp
    src/Rover.cpp
    src/InitializeRovers.hpp
    src/InitializeRovers.cpp
    )
set(USE_LIBRARY ON)
set(BUILD_SHARED_LIBRARY OFF)
if(BUILD_SHARED_LIBRARY)
    message(STATUS "CONFIGURING SHARED LIBRARY FROM ROVER SOURCE")
    add_library(
        rover
        SHARED
        ${_rover_src}
        )
else()
    message(STATUS "CONFIGURING STATIC LIBRARY FROM ROVER SOURCE")
    add_library(
        rover
        STATIC
        ${_rover_src}
        )
endif()

set_target_properties(rover
                      PROPERTIES
                      POSITION_INDEPENDENT_CODE 1
                      )
target_compile_options(rover
                       PRIVATE
                       ${_flags}
                       )

#rover refers to the target library and not a directory
#make the library PUBLIC
target_include_directories(rover PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
