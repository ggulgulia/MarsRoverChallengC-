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
        m_orientation = posAndHead[4];
        allocate_storage_for_path(m_path, m_explInstr);
    }

void MarsRover::Rover::print_curr_pos(){
    std::cout << m_name << "s current position is (" << m_currPosition.first <<"," << m_currPosition.second <<")\n";
    std::cout << m_name << "is pointing towards " << m_orientation << "-ward direction\n"; 
}
