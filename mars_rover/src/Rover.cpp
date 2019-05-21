#include "Rover.hpp"

MarsRover::Rover::Rover() noexcept{
    m_name= "r2d2";
    m_currPosition.first = 3.0;
    m_currPosition.second = 3.0;
    m_orientation = "N";
    m_explInstr = "MLMLMLM"; //a dummy exploration variable
    allocate_storage_for_path(m_path, m_explInstr);
    m_corner2.first = 10; m_corner2.second = 10;
}

/*!
  User constructor that creates a Rover Object according
  to the input parameters passed to the constructor

  @param: name of rover (std::string),
          position and head of rover(std::string),
          exploraation command (std::string),
          second corner of the rectangular terrain (std::pair<int, int>)
  @returns: 
*/
MarsRover::Rover::Rover(const std::string& name, const std::string& posAndHead, 
                        const std::string& exploration, const point& corner2):
                        m_name(name), m_corner1(std::make_pair(0.0, 0.0)), 
                        m_corner2(corner2), m_explInstr(exploration){
        
    int xCoord, yCoord;
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

/*!
  Public method that rotates the rover head to left
  relative to its current head orientation
  @param:
  @returns:
*/
void MarsRover::Rover::rotate_left() noexcept{
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","W"}, {"W","S"}, {"S","E"}, {"E", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
}

/*!
  Public method that rotates the rover head to right
  relative to its current head orientation
  @param:
  @returns:
*/
void MarsRover::Rover::rotate_right() noexcept{
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","E"}, {"E","S"}, {"S","W"}, {"W", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
}
            
/*!
  Public method that moves the rover one step
  forward relative to its current head orientation
  @param:
  @returns:
*/
void MarsRover::Rover::move_forward(){

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

/*!
  Public method that explores the rectangular terrain
  based on a predefined exploration derective 
  @param:
  @returns:
*/
void MarsRover::Rover::explore_terrain(){

    std::cout << "\nRover "<< m_name << " begins its exploration now\n";
    for(const auto s:m_explInstr){
        switch(s){
            case 'L':MarsRover::Rover::rotate_left();
                     break;
            case 'R':MarsRover::Rover::rotate_right();
                     break;
            case 'M': MarsRover::Rover::move_forward();
                      break;
            default: throw("invalid exploration directive, allowed characters for exploration are: \
                            \n'L' for left rotation, 'R' for right rotation and 'M' for forward motion\
                            \nCheck the input file or exploration directive\n");
        }
        //MarsRover::Rover::print_curr_pos();
    }
}

//setter functions

/*!
  Public method that sets the orientation of the rover head
  based on a predefined exploration derective 
  @param: orientation(std::string) can be E, W, N or S
  @returns:
*/
void MarsRover::Rover::set_orientation(const std::string& orientation )noexcept {
    m_orientation = orientation;
}


/*!
  Public method that sets the position of rover 
  at a point on the rectangular terrain
  @param: x coordinate, y coordinate 
  @returns:
*/
void MarsRover::Rover::set_position(int x, int y) noexcept{
    m_currPosition.first = x;
    m_currPosition.second = y;
} 

void MarsRover::Rover::set_exploration_instruction(const std::string& expl){                                                                                
                m_explInstr = expl;
            } 

//getter functions


/*!
  Public method that returns the name of the rover
  @param: 
  @returns:
*/
const std::string MarsRover::Rover::get_name() noexcept{
return m_name;
}


/*!
  Public method that reads the number of steps 
  a rover has to move based on number of move 
  forward command in the exploration derictive
  @param: string of exploration derictive
  @returns: unsigned int of number that indicates how many steps rover 
            has to move
*/
const size_t MarsRover::Rover::get_num_steps_to_move(const std::string& explorationInstructions){
    const std::string expl(explorationInstructions);
    return std::count(expl.begin(), expl.end(), 'M');
}


/*!
  Public method that returns the orientation
  of rover head which can be aligned with one
  of the four cardinal directions. 
  "N": North, "S": south, "E": East, "W":West
  
  @param: 
  @returns: single charcter string indicating the rover head direction
*/
std::string MarsRover::Rover::get_orientation() const noexcept{
    return m_orientation;
}


/*!
  Public method that retuns the current position of 
  rover on a rectangular terrain
  @param: 
  @returns: std::pair<int, int> position, in which
            position.first indicates x-coordinate
            and position.second indicates y-coordinate
*/
point& MarsRover::Rover::get_curr_pos() noexcept{
    return m_currPosition;
}

/*!
  same as the above but returns a const qualified 
  position of the rover in the rectangular terrain
  @param: 
  @returns: std::pair<int, int> position, in which
            position.first indicates x-coordinate
            and position.second indicates y-coordinate
*/
const point& MarsRover::Rover::get_curr_pos() const noexcept {
    return m_currPosition;
}


/*!
 public method that prints the current position of the 
 rover and the orientation of the rover head 
  @param: 
  @returns: 
*/
void MarsRover::Rover::print_curr_pos() noexcept{
    std::unordered_map<std::string, std::string> directions;
    directions = {{"N", "North"}, {"S", "South"},{"W", "West"}, {"E", "East"}};
    std::cout << "current position and orientation of rover:\
                  \n("  << m_currPosition.first << "," << m_currPosition.second << ") " << m_orientation << "\n";
}


/*!
 public method returning the number of steps moved by 
 rover at the time this function has been invoked.
 This does not include left an right turning of the
 rover head
  @param: 
  @returns: unsigned ineteger indicating number of steps 
            moved by the rover
*/
const size_t MarsRover::Rover::steps_moved() noexcept{
    return m_stepsMoved;
}

/*!
 public method that prints the trail of the path
 traced by the rover while exploring the terrain
 till the point this function has bee invoked
  @param: 
  @returns:
*/
void MarsRover::Rover::print_rover_path_trail() noexcept{
    std::cout << "The rover " << m_name << " moved " << m_stepsMoved-1 << " steps\n";
    for(auto path : m_path){
    std::cout << "(" << path.first << "," << path.second <<")\n";
    }

}

/*!
 Public method that writes the trail of path traced by
 rover while exploring the terrain to a specified output 
 file. Additionally it indicates the final position and 
 rover's head orientation
  @param: ofstream outfile in which the data is to be written
  @returns: 
*/
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
}
