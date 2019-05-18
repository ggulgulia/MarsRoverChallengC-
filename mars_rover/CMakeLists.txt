#add appropriate path to src code from which the lib is to be made
add_library(
    rover SHARED
    src/say_hello/hello.hpp
    src/say_hello/hello.cpp
    )

#rover refers to the target library and not a directory
#make the library PUBLIC
target_include_directories(rover PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_compile_definitions(rover PUBLIC SAY_HELLO_VERSION=4)
