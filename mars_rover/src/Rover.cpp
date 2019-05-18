#include "Rover.hpp"

MarsRover::Rover::Rover(){
    m_name= "r2d2";
    m_currPosition.first = 3.0;
    m_currPosition.second = 3.0;
    m_orientation = "N";
    //m_explInstr = = "MLMLMLM"; //a dummy exploration variable
    //
    ////count how many steps rover has to move
    //size_t count = std::count_if( m_explInstr.begin(), m_explInstr.end(), []( char c   ){if(c =='M') return true; }  );
}
