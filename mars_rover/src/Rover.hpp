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

static const std::string cardinalDirections{"NESW"};

namespace MarsRover{
    class Rover{
        private:
            std::string m_name;
            std::pair<double, double> m_currPosition;
            std::string m_orientation;
            std::string m_explInstr;
            std::vector<std::pair<double, double>> m_path;
            size_t m_stepsMoved{}; //rover has not moved when it is initialized
            
            void allocate_storage_for_path(std::vector<std::pair<double, double>> &path, const std::string& expl){
                m_stepsMoved = 0;
                size_t count = std::count(expl.begin(), expl.end(), 'M');
                std::cout << "number of steps to move: "<< count<< "\n";
                path.resize(count+1); //+1 for starting position

            }

        public:

            //default constructor
            Rover() noexcept;
            Rover(const std::string& name, const std::string& posAndHead, const std::string&exploration);
            ~Rover();
            Rover(const Rover& ) = delete; //prevent implicit copy constructors
            Rover operator=(Rover&) = delete; //prevent implicit assignment operator 
            
            //rover movements
            void rotateLeft() noexcept;
            void rotateRight() noexcept;
            void moveForward();

            //helper functions
            const std::string get_name() noexcept;
            std::pair<double, double>& get_curr_pos()noexcept;
            const std::pair<double, double>& get_curr_pos() const noexcept;
            void print_curr_pos() noexcept;
            const size_t steps_moved() noexcept;
            void move();
            void print_rover_path_trail() noexcept;

            void write_rover_trail_to_file(const std::string& filename ) noexcept;
    };

}

#endif //ROVER_H
