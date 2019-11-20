# Project Title
* **Mars Rover**
This is the task submitted for job application at a company by for junior C++ developer position. This project 
is a small code base and an associated unit test that checks the correctness of main kernel functions of Mars Rover movement
on a (2-dimensional) rectangular flat terrain with one of the corners of rectangle assumed to be at (0,0).   

*A sample input file named 'input.txt' is provided in the parent directory of the project*
*output file can be created by the *

The code has been developed on Ubuntu 16.04 based operating system and the author has compiled and tested the code with 
GNU GCC -5.4.0. 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for execution and testing purposes. 

### Prerequisites

* GNU GCC compiler preferably version 5.4.0 or higher (with C++11 support) 
* Google Test Framework headers and libraries installed on the machine presumably in the `/usr/local/includes` and `/usr/local/libs` 

### Building the project (step by step guide)

*Note: terminal commands are referred to within this document within quote are only for indicative purposes. Please be careful not to type the terminal commands with quotes while trying to build and run the project*

* In the parent directory of the project create a folder named 'build' (without quotes)
* cd into build directory and open a terminal in the same directory.
        * To build the project without unit tests,  type on the terminal: 'cmake ..'
        * Again type on terminal: 'make'
            (1) To run the exectuable browse to directory within the build directory: 'cd rover_exe/' 
            (2) On the terminal type (to execute): './Rover <PATH_TO_INPUT_FILE>  <PATH_TO_OUTPUT_FILE>'
         
        * to build the project with unit test type on the terminal: 'cmake .. -DWITH_UNIT_TESTS=ON'
        * Again type on terminal: 'make'
            (1) To run the executalbe follow the same steps in (1)  of build without unit tests
            (2) To run the unit test browse to directory in the build directory: 'cd unit_test/' 
            (3) On the  terminal type './test_mars_rover'

* Save the output file before re-executing the Rover (main exectuable) for further exploration of the terrain. The program overwrites the output file if same output file name is fed to the program for repeated executions
