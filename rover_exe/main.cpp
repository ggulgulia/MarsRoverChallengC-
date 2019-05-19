#include <iostream>
//#include <Rover.hpp>
#include <InitializeRovers.hpp>
#include <string>
#include <fstream>
#include <sstream>



int main(int argc, char *argv[])
{
    const std::string filename("../input.txt");
    try{
    MarsRover::InitializeRovers init(filename);
    std::vector<std::shared_ptr<MarsRover::Rover>> roverContainer = init.get_rovers();
    std::cout << "number of rovers exploring the lonely red planet: "\
              << roverContainer.size() << "\n"; 

    for(std::shared_ptr<MarsRover::Rover> rover : roverContainer){
        rover->move();
            rover->write_rover_trail_to_file("../output.txt");
    }
   // MarsRover::Rover r2("c3po", "1 1 N", "MRMRMRM");
   // r2.print_curr_pos();
   // r2.move();

   // r2.write_rover_trail_to_file("../output.txt");
    }

    catch(const char* error){
        std::cout << "ERROR:" << error;
        std::cout << "ABORTING THE PROGRAM!\n";
        exit(0);
    }
    return 0;
}
