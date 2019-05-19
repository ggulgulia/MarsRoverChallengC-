#include "Rover.hpp"

MarsRover::Rover::Rover() noexcept{
    std::cout << "Constructing a default Rover located at (3,3), facing North\n";
    m_name= "r2d2";
    m_currPosition.first = 3.0;
    m_currPosition.second = 3.0;
    m_orientation = "N";
    m_explInstr = "MLMLMLM"; //a dummy exploration variable
    allocate_storage_for_path(m_path, m_explInstr);
}

MarsRover::Rover::Rover(const std::string& name, const std::string& posAndHead, 
                        const std::string& exploration, const point& corner2):
                        m_name(name), m_corner1(std::make_pair(0.0, 0.0)), 
                        m_corner2(corner2), m_explInstr(exploration){
        
    double xCoord, yCoord;
    std::string orient;
    std::stringstream ss(posAndHead);
    ss >> xCoord >> yCoord >> orient;
    
    if(!MarsRover::Rover::is_within_bounds(std::make_pair(xCoord, yCoord))){
        throw("invalid starting position\nthe rover is outside the permitted exploration boundaries\n");
    }
    if(cardinalDirections.find(orient) == std::string::npos){
        throw("invalid starting orientation of the rover head.\
          \nAllowed orientations are 'E' for East, 'W' for West, 'N' for North and 'S' for South");
    }
    
    m_currPosition.first = xCoord;
    m_currPosition.second = yCoord;
    m_orientation = orient;
    
    allocate_storage_for_path(m_path, m_explInstr);
    m_path[m_stepsMoved++] = m_currPosition;
    }
    
    MarsRover::Rover::~Rover(){
        m_path.resize(0);
}

//Rotate left
void MarsRover::Rover::rotateLeft() noexcept{
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","W"}, {"W","S"}, {"S","E"}, {"E", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
}

//Rotate right      
void MarsRover::Rover::rotateRight() noexcept{
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","E"}, {"E","S"}, {"S","W"}, {"W", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
}
            
//Move forward
void MarsRover::Rover::moveForward(){
     std::unordered_map<std::string, point> moveForwardResult{
                                                    {"N", std::make_pair(0,1)}, 
                                                    {"E", std::make_pair(1,0)}, 
                                                    {"S", std::make_pair(0,-1)}, 
                                                    {"W", std::make_pair(-1,0)}
                                                             };
     point move = moveForwardResult[m_orientation];
     m_currPosition.first += move.first;
     m_currPosition.second += move.second;
     if(!MarsRover::Rover::is_within_bounds(m_currPosition)){
         throw("ROVER MOVED OUT OF PERMITTED EXPLORATION REGION\
               \nCheck and correct the exploration directive or the exploration region\n");
    }
    m_path[m_stepsMoved++] = m_currPosition;
}

//general move function
void MarsRover::Rover::move(){

    std::cout << "\nRover "<< m_name << " begins its exploration now\n";
    for(const auto s:m_explInstr){
        switch(s){
            case 'L':MarsRover::Rover::rotateLeft();
                     break;
            case 'R':MarsRover::Rover::rotateRight();
                     break;
            case 'M': MarsRover::Rover::moveForward();
                      break;
            default: throw("invalid exploration directive, allowed characters for exploration are: \
                            \n'L' for left rotation, 'R' for right rotation and 'M' for forward motion\
                            \nCheck the input file or exploration directive\n");
        }
        //MarsRover::Rover::print_curr_pos();
    }
}

//helper function
const std::string MarsRover::Rover::get_name() noexcept{
return m_name;
}

point& MarsRover::Rover::get_curr_pos() noexcept{
    return m_currPosition;
}

const point& MarsRover::Rover::get_curr_pos() const noexcept {
    return m_currPosition;
}

void MarsRover::Rover::print_curr_pos() noexcept{
    std::unordered_map<std::string, std::string> directions;
    directions = {{"N", "North"}, {"S", "South"},{"W", "West"}, {"E", "East"}};
    std::cout << "current position and orientation of rover:\
                  \n("  << m_currPosition.first << "," << m_currPosition.second << ")" << m_orientation << "\n";
}

const size_t MarsRover::Rover::steps_moved() noexcept{
    return m_stepsMoved;
}

void MarsRover::Rover::print_rover_path_trail() noexcept{
    std::cout << "The rover " << m_name << " moved " << m_stepsMoved-1 << " steps\n";
    for(auto path : m_path){
    std::cout << "(" << path.first << "," << path.second <<")\n";
    }

}

void MarsRover::Rover::write_rover_trail_to_file(std::ofstream& outfile) noexcept{
    
    print_rover_path_trail();
    outfile << "\n===================================================================\n";
    outfile << "The rover " << m_name << " moved " << m_stepsMoved-1 << " steps\n";
    outfile << "Rover path trail:\n";
    for(auto path : m_path){
    outfile << "(" << path.first << "," << path.second <<")\n";
    }

    outfile << "Final position and orientation of rover:\n";
    outfile << m_currPosition.first << " " << m_currPosition.second << " " << m_orientation << "\n";
    
    outfile << "===================================================================\n";
    //outfile.close();
}
