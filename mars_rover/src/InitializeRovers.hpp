#include "Rover.hpp"
#include <memory>
//#include "rover_names.hpp"

namespace MarsRover{
    class InitializeRovers{
        private:
            std::vector<std::shared_ptr<Rover>> m_roverContainer;
            std::string m_fileName;
        public:
            InitializeRovers();
            explicit InitializeRovers(const std::string& input); 

            //preventing implicit copy semantics
            InitializeRovers(const InitializeRovers& ) = delete;
            InitializeRovers& operator=(InitializeRovers&) = delete;
            
            //return reference to rover container 
            std::vector<std::shared_ptr<Rover>>& get_rovers();

    };

}