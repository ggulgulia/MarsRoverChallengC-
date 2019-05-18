#ifndef ROVER_H
#define ROVER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

namespace MarsRover{
    class Rover{
        private:
            std::string m_name;
            std::pair<double, double> m_currPosition;
            std::string m_orientation;
            std::string m_explInstr;
            std::vector<std::pair<double, double>> m_path;
            size_t m_stepsMoved;
            
            void allocate_storage_for_path(std::vector<std::pair<double, double>> &path, const std::string& expl){
                m_stepsMoved = 0;
                size_t count = std::count(expl.begin(), expl.end(), 'M');
                std::cout << "number of steps to move: "<< count<< "\n";
                path.resize(count);

            }

        public:

            //default constructor
            Rover();
            Rover(const std::string& name, const std::string& posAndHead, const std::string&exploration);
            Rover(const Rover& ) = delete; //prevent implicit copy constructors
            
            void rotateLeft(){
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","W"}, {"W","S"}, {"S","E"}, {"E", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
            }

            void rotateRight(){
                std::unordered_map<std::string, std::string> rotateLeftResult{{"N","E"}, {"E","S"}, {"S","W"}, {"W", "N"}};
                m_orientation = rotateLeftResult[m_orientation];
            }

            void moveForward(){
                std::unordered_map<std::string, std::pair<double, double>> moveForwardResult{
            {"N", std::make_pair(0,1)}, 
            {"E", std::make_pair(1,0)}, 
            {"S", std::make_pair(0,-1)}, 
            {"W", std::make_pair(-1,0)}
            };
                std::pair<double, double> move = moveForwardResult[m_orientation];
                m_currPosition.first += move.first;
                m_currPosition.second += move.second;
                ++m_stepsMoved;
            }

            //helper functions
            const std::string get_name();
            std::pair<double, double>& get_curr_pos();
            const std::pair<double, double>& get_curr_pos() const;
            void print_curr_pos();
            void move();
    };

}

#endif //ROVER_H
