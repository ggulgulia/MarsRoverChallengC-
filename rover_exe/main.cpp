#include <iostream>
//#include <Rover.hpp>
#include <InitializeRovers.hpp>
#include <string>
#include <fstream>
#include <sstream>



int main(int argc, char *argv[])
{
    if(argc != 3){
        std::cout << "number of input arguments is incorrect\n";
        std::cout << "format should be: <PATH TO EXECUTABLE> <PATH TO INPUT> <PATH TO OUTPUT>\n";
        std::cout << "ABORTING THE PROGRAM!\n";
        return 0;
    }

    const std::string inFileName(argv[1]), outFileName(argv[2]);
    try{
            MarsRover::InitializeRovers init(inFileName);
            std::vector<std::shared_ptr<MarsRover::Rover>> roverContainer = init.get_rovers();
            std::cout << "number of rovers exploring the lonely red planet: "\
                      << roverContainer.size() << "\n"; 
            
            std::ofstream outFile;
            outFile.open(outFileName, std::ios::out);
            for(std::shared_ptr<MarsRover::Rover> rover : roverContainer){
                rover->move();

                //rover->write_rover_trail_to_file("../output.txt");
                rover->write_rover_trail_to_file(outFile);
             }
            outFile.close();
    }

    catch(const char* error){
        std::cout << "ERROR:" << error;
        std::cout << "ABORTING THE PROGRAM!\n";
        exit(0);
    }
    return 0;
}
