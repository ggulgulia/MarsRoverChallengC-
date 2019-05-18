set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wall -Werror -fno-elide-constructors")
add_executable(Rover main.cpp)
target_link_libraries(Rover PRIVATE rover)
