#ifndef ROVER_H
#define ROVER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include<fstream>
#include <cstdio>

//getting rid of cumbersome typename
typedef std::pair<double, double> point;

static const std::string cardinalDirections{"NESW"};
namespace MarsRover{
    class Rover{
        private:
            std::string m_name; //rover name
            point m_corner1; //bounds for rover exploration
            point m_corner2;
            point m_currPosition;         
            std::string m_orientation;    //orientation of the head of rover
            std::string m_explInstr;      //rover's exploration instructions
            std::vector<std::pair<double, double>> m_path; //stores the trail of path traversed by rover
            size_t m_stepsMoved{}; //rover has not moved when it is initialized
           
            //private functions for the rovers
            
            //this function precomputes the number of steps the rover moves 
            //and allocates the storage for rover path coordinates
            void allocate_storage_for_path(std::vector<point> &path, const std::string& expl){
                m_stepsMoved = 0;
                size_t count = std::count(expl.begin(), expl.end(), 'M');
                //std::cout << "number of steps to move: "<< count<< "\n";
                path.resize(count+1); //+1 for starting position

            }
            
            //this function checks if the rover is 
            //within the permitted exploration boundary
            bool is_within_bounds(const point& p){
                point c1{m_corner1}, c2{m_corner2};
                return (p.first >= c1.first && p.second >= c1.second && p.first <= c2.first && p.second <= c2.second);
            }

        public:

            //default constructor
            Rover() noexcept;

            //user constructor taking name, starting position and orientation, exploration instruction and second corner of 
            //flat plane to be explored as input. First corner is assumed to be at (0,0)
            Rover(const std::string& name, const std::string& posAndHead, 
                const std::string& exploration, const point& corner2);

            //same as above but takes both corner as user input for Rovers 
            //exploration bounds
            //Rover(const std::string& name, const std::string& posAndHead, 
            //    const std::string& exploration, const point& corner1, const point& corner2);

            ~Rover();
            Rover(const Rover& ) = delete; //prevent implicit copy constructors
            Rover operator=(Rover&) = delete; //prevent implicit assignment operator 
            
            //rover movements
            void rotateLeft() noexcept;
            void rotateRight() noexcept;
            void moveForward();
            void move();

            //helper functions
            const std::string get_name() noexcept;
            std::pair<double, double>& get_curr_pos()noexcept;
            const std::pair<double, double>& get_curr_pos() const noexcept;
            void print_curr_pos() noexcept;
            const size_t steps_moved() noexcept;
            void print_rover_path_trail() noexcept;

            void write_rover_trail_to_file(const std::string& filename ) noexcept;
    };

}

#endif //ROVER_H
