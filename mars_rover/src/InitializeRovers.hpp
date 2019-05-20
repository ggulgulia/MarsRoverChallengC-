#ifndef INITIALIZE_ROVERS_H
#define INITIALIZE_ROVERS_H

#include "Rover.hpp"
#include <memory>

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

#endif /* ifndef INITIALIZE_ROVERS_H */
