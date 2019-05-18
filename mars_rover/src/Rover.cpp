#include "Rover.hpp"

MarsRover::Rover::Rover(){
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

        std::stringstream ss(posAndHead);
        ss >> m_currPosition.first >> m_currPosition.second >> m_orientation;
        allocate_storage_for_path(m_path, m_explInstr);
    }

const std::string MarsRover::Rover::get_name(){
return m_name;
}
std::pair<double, double>& MarsRover::Rover::get_curr_pos(){
    return m_currPosition;
}

const std::pair<double, double>& MarsRover::Rover::get_curr_pos() const {
    return m_currPosition;
}

void MarsRover::Rover::print_curr_pos(){
    std::unordered_map<std::string, std::string> directions;
    directions = {{"N", "North"}, {"S", "South"},{"W", "West"}, {"E", "East"}};
    std::cout << m_name << "s current position is (" << m_currPosition.first <<"," << m_currPosition.second <<")\n";
    std::cout << m_name << " is pointing towards " << directions[m_orientation] << "ward direction\n"; 
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
        }
        MarsRover::Rover::print_curr_pos();
    }
}
