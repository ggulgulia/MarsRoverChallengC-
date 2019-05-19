#include "Rover.hpp"

MarsRover::Rover::Rover() noexcept{
    std::cout << "Constructing a default Rover located at (3,3), facing North\n";
    m_name= "r2d2";
    m_currPosition.first = 3.0;
    m_currPosition.second = 3.0;
    m_orientation = "N";
    m_explInstr = "MLMLMLM"; //a dummy exploration variable
    //
    ////count how many steps rover has to move
    allocate_storage_for_path(m_path, m_explInstr);
}


MarsRover::Rover::Rover(const std::string& name, const std::string& posAndHead, const std::string& exploration):
    m_name(name), m_explInstr(exploration){
        
        double xCoord, yCoord;
        std::string orient;
        std::stringstream ss(posAndHead);
        ss >> xCoord >> yCoord >> orient;
        if(xCoord < 0 || yCoord < 0){
            throw("invalid starting position\nthe bot is outside the permitted exploration boundaries\n");
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
                std::unordered_map<std::string, std::pair<double, double>> moveForwardResult{
                {"N", std::make_pair(0,1)}, 
                {"E", std::make_pair(1,0)}, 
                {"S", std::make_pair(0,-1)}, 
                {"W", std::make_pair(-1,0)}
                };
                std::pair<double, double> move = moveForwardResult[m_orientation];
                m_currPosition.first += move.first;
                m_currPosition.second += move.second;
                m_path[m_stepsMoved++] = m_currPosition;
            }
const std::string MarsRover::Rover::get_name() noexcept{
return m_name;
}
std::pair<double, double>& MarsRover::Rover::get_curr_pos() noexcept{
    return m_currPosition;
}

const std::pair<double, double>& MarsRover::Rover::get_curr_pos() const noexcept {
    return m_currPosition;
}

void MarsRover::Rover::print_curr_pos() noexcept{
    std::unordered_map<std::string, std::string> directions;
    directions = {{"N", "North"}, {"S", "South"},{"W", "West"}, {"E", "East"}};
    std::cout << m_name << "'s current position is (" << m_currPosition.first <<"," << m_currPosition.second <<")\n";
    std::cout << m_name << " is pointing towards " << directions[m_orientation] << "ward direction\n"; 
}

const size_t MarsRover::Rover::steps_moved() noexcept{
    return m_stepsMoved;
}

void MarsRover::Rover::move(){

    for(const auto s:m_explInstr){
        std::cout << "moving " << s << "\n";
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

void MarsRover::Rover::print_rover_path_trail() noexcept{
    std::cout << "The rover " << m_name << " moved " << m_stepsMoved-1 << " steps\n";
    for(auto path : m_path){
    std::cout << "(" << path.first << "," << path.second <<")\n";
    }

}
void MarsRover::Rover::write_rover_trail_to_file(const std::string& filePath) noexcept{
    
    print_rover_path_trail();
    std::cout << "Output written to file: " << filePath << "\n";
    std::ofstream outfile;
    outfile.open(filePath, std::ios_base::app);
    outfile << "\n===================================================================\n";
    outfile << "The rover " << m_name << " moved " << m_stepsMoved-1 << " steps\n";
    for(auto path : m_path){
    outfile << "(" << path.first << "," << path.second <<")\n";
    }
    outfile << "===================================================================\n";
    outfile.close();
}
