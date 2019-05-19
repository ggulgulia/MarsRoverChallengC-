#include "Rover.hpp"
#include <memory>
//#include "rover_names.hpp"

namespace MarsRover{
    class InitializeRovers{
        private:
            point m_corner1;
            point m_corner2;
            std::vector<std::shared_ptr<Rover>> m_roverContainer;
            std::string m_fileName;
        public:
            InitializeRovers();
            explicit InitializeRovers(const std::string& input);


    };

}
