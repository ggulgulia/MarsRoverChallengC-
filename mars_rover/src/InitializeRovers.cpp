#include "InitializeRovers.hpp"

//#include "rover_names.hpp"

MarsRover::InitializeRovers::InitializeRovers(const std::string& input){
    m_corner1.first = 0.0;
    m_corner1.second = 0.0;

    std::ifstream inputFile;
        inputFile.open(input);
        if(!inputFile.is_open()){
            throw("FILE NOT FOUND. Check the file path or file acess\n");
        }
    

    std::string line;
    size_t lineCount;
    point corner2; 
    std::getline(inputFile, line);
    std::stringstream ss(line);
    ss >> corner2.first >> corner2.second;
    std::cout <<"Second corner read from input file (" << corner2.first << " " << corner2.second << ")\n";

    std::cout << "printing remaining lines of input file\n";
    std::string roverName{"dummyRover"};
    std::string startPosAndOrient, explorationInstructions;
    while(lineCount%2==0 and !inputFile.eof()){

        std::getline(inputFile, startPosAndOrient);
        std::getline(inputFile, explorationInstructions);
        std::cout << "start pos " << startPosAndOrient << "\nExploration instrs: " << explorationInstructions <<"\n";

        std::shared_ptr<MarsRover::Rover> tempRover(new MarsRover::Rover(roverName, startPosAndOrient, explorationInstructions));
        m_roverContainer.push_back(tempRover);
    }
    if(inputFile.is_open()){
    std::cout << "File read successfully\n";
    inputFile.close();
        } 
    
    else
        std::cout << "File not found\n";
                
                }
