#include <iostream>
#include <Rover.hpp>
#include <string>
#include <fstream>
#include <sstream>



int main(int argc, char *argv[])
{
    const std::string filename("../input.txt");
    
    
    try{
    MarsRover::Rover r2("c3po", "1 1 N", "MRMRMRM");
    r2.print_curr_pos();
    r2.move();

    r2.write_rover_trail_to_file("../output.txt");
    }

    catch(const char* error){
        std::cout << "ERROR:" << error;
        std::cout << "ABORTING THE PROGRAM!\n";
        exit(0);
    }
    return 0;

}
