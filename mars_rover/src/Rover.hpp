#ifndef ROVER_H
#define ROVER_H

#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <sstream>

namespace MarsRover{
    class Rover{
        private:
            std::string m_name;
            std::pair<double, double> m_currPosition;
            std::string m_orientation;
            std::string m_explInstr;
            std::vector<std::pair<double, double>> m_path;
            
            void allocate_storage_for_path(std::vector<std::pair<double, double>> &path, const std::string& expl){
                size_t count = std::count(expl.begin(), expl.end(), 'M');
                std::cout << "number of steps to move: "<< count<< "\n";
                path.resize(count);
            }
        public:

            //default constructor
            Rover();
            Rover(const std::string& name, const std::string& posAndHead, const std::string&exploration);

            void print_curr_pos();
    };

}

#endif //ROVER_H
