#include "hello.hpp"

void Hello::say_hello(){
    std::cout << "Hello cmake\n";
    std::cout << "Hello rover from version " << SAY_HELLO_VERSION <<" \n";
}
