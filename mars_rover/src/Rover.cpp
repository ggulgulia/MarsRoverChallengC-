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
    size_t count =  std::count(m_explInstr.begin(), m_explInstr.end(), 'M');
    std::cout << "number of steps to move: "<< count<< "\n";
}
