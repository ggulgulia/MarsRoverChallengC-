#include <gtest/gtest.h>
#include "../mars_rover/src/InitializeRovers.hpp"
#include "../mars_rover/src/Rover.hpp"
#include <utility>


/*! creating a test fixture for testing the  functionalities of 
    the mars rover so that we don't need to create and destroy 
    the MarsRover::Rover object for testing every method provided 
    by the MarsRover::Rover interface
*/
class RoverTest :public ::testing::Test{
    
    protected:
        MarsRover::Rover* dummyRover;

        virtual void SetUp(){
            dummyRover = new MarsRover::Rover();
        }

        virtual void TearDown(){
            delete dummyRover;
            dummyRover = nullptr;
        }
};

    
//test for turning left
TEST_F(RoverTest, TurnLeft){
    
    dummyRover->set_orientation("N");
    dummyRover->rotate_left();
    EXPECT_EQ("W", dummyRover->get_orientation());
}


TEST_F(RoverTest, TurnRight){
    
    dummyRover->set_orientation("N");
    dummyRover->rotate_right();
    EXPECT_EQ("E", dummyRover->get_orientation());
}

TEST_F(RoverTest, SetRoverPosition){
    dummyRover->set_position(1,1);
    EXPECT_EQ(std::make_pair(1,1), dummyRover->get_curr_pos());
}

TEST_F(RoverTest, NumberOfStepsToMove){
    EXPECT_EQ(5, dummyRover->get_num_steps_to_move("MLMLMLMLMLLLL"));
}

TEST_F(RoverTest, MoveForward){
    
    dummyRover->set_position(1,1);
    dummyRover->set_orientation("E");
    dummyRover->move_forward();
    std::pair<int, int> result(2,1);
    EXPECT_EQ(result, dummyRover->get_curr_pos());
}


TEST_F(RoverTest, ExploreTerrain){
    
    dummyRover->set_position(1,1);
    dummyRover->set_orientation("N");
    dummyRover->set_exploration_instruction("RMRMRMR");
    dummyRover->explore_terrain();
    std::pair<int, int> result1(1,0);
    EXPECT_EQ(result1, dummyRover->get_curr_pos());
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

