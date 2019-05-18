#include <iostream>
#include <say_hello/hello.hpp>
#include <string>
#include <fstream>
#include <sstream>



int main(int argc, char *argv[])
{
    const std::string filename("input.txt");
    
    std::ifstream *inputFile = new std::ifstream();
    //std::shared_ptr<std::ifstream> inputFile{new std::ifstream()};
     inputFile->open(filename);
     std::string line;
     while(std::getline(*inputFile, line)){
         std::cout << line << "\n";
     }
     if(inputFile->is_open()){
     std::cout << "File read successfully\n";
     inputFile->close();
        } 

    else
        std::cout << "File not found\n";
        
    //Hello::say_hello();
    //std::cout << "The say hello library version is " << SAY_HELLO_VERSION << "\n";
    return 0;
}
