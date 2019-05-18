#ifndef ROVER_H
#define ROVER_H

#include <string>
#include <memory>
#include <iostream>
#include <utility>
#include <vector>

namespace MarsRover{
    class Rover{
        private:
            std::string m_name;
            std::pair<double, double> m_currPosition;
            std::string m_orientation;
            //std::string m_explInstr;
            //std::vector<std::pair<double, double>> m_path;
        public:

            //default constructor
            Rover();
            //Rover(const std::string& name, const std::string& posAndHead, const std::string&exploration);
    };

}

#endif //ROVER_H
