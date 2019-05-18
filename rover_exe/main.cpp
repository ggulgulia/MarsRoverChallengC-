#include <iostream>
#include <Rover.hpp>
#include <string>
#include <fstream>
#include <sstream>



int main(int argc, char *argv[])
{
    const std::string filename("../input.txt");
    
    
    MarsRover::Rover r1;
    MarsRover::Rover r2("c3po", "1 1 E", "MRMRMRM");

    r1.print_curr_pos();
    r2.print_curr_pos();
    //r2.move();
    return 0;

}
