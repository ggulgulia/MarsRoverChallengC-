#include <iostream>
#include <say_hello/hello.hpp>
#include <string>
#include <fstream>


int main(int argc, char *argv[])
{
    const std::string filename("../../Input.txt");

    std::ifstream inputFile;
    int smVr;
    inputFile.open(filename.c_str());
    if(inputFile){
        std::cout << "File read successfullyi\n";
        inputFile.close();
    } 
    else
        std::cout << "File not found\n";
        
    //Hello::say_hello();
    //std::cout << "The say hello library version is " << SAY_HELLO_VERSION << "\n";
    return 0;
}
