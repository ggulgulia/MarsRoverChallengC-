#include "InitializeRovers.hpp"

static const std::vector<std::string> get_rover_names(){
        std::vector<std::string> rover_names{"R2D2", "C3PO", "T1000", "T5000","WallE", "Eva", "Mechagodzilla", "HansSolo", "Captain_Kirk", "MrSpock","Luke", "BladeRunner", "MrSulu", "Aniken", "Palpatine", "Phenias", "Ferbs", "Perry", "MrChekov", "Captain_Uhura"};

            return rover_names;
}

MarsRover::InitializeRovers::InitializeRovers(const std::string& input){

    std::ifstream inputFile;
        inputFile.open(input);
        if(!inputFile.is_open()){
            throw("FILE NOT FOUND. Check the file path or file acess\n");
        }
    

    std::string line;
    size_t lineCount{};

    //store the second corner of the grid
    point corner2; 
    std::getline(inputFile, line);
    std::stringstream ss(line);
    ss >> corner2.first >> corner2.second;
    std::cout <<"Second corner read from input file (" << corner2.first << " " << corner2.second << ")\n";

    //std::cout << "printing remaining lines of input file\n";
    std::string roverName{"dummyRover"};
    std::string startPosAndOrient, explorationInstructions;
    
    std::vector<std::string> rover_names = get_rover_names();
    //create and initialize remaining rovers
    while(std::getline(inputFile, line)){
        
        ++lineCount;
        if(lineCount%2==1)
            startPosAndOrient = line;
        if(lineCount%2==0){
            explorationInstructions = line;
            //std::cout << "start pos " << startPosAndOrient << "\nExploration instrs: " << explorationInstructions <<"\n";
            //calling rovers with appropriate parameters
            roverName = rover_names[lineCount/2];   
            std::shared_ptr<MarsRover::Rover> tempRover(new MarsRover::Rover(roverName, startPosAndOrient, explorationInstructions, corner2));
            m_roverContainer.push_back(tempRover);

        }
    }
}
    
    std::vector<std::shared_ptr<MarsRover::Rover>>& MarsRover::InitializeRovers::get_rovers(){
        return m_roverContainer;
    }
