/* 
    The two configurations the robot will have (battery size and mission budget) should be the first two lines in the input file.

    e.g.

    5 
    10
    X X X X X X X X
    X 9 1 3 X 5 6 X
    X 3 X 2 8 2 1 X
    X 1 X 0 X X X X
    X 0 3 1 4 6 X X
    X X X X X X X X
*/

#include "robot.h"

/* 
    Constructor for robot class. Takes one parameter: starting location (i.e. charging dock). 
*/
Robot::Robot(const pair<int, int> starting_space) 
{
    space = starting_space;
}

/* 
    Attempts to instantiate robot object fields. Return true on success, otherwise false.
*/
bool Robot::robot_setup(const string input_file) 
{
    if((validate_robot(input_file) == -1)) 
    {
        return -1;
    }
    if((store_robot_info(input_file) == -1)) 
    {
        return -1;
    }
    return 0;
}

/* 
    Read input file, if I/O error or if provided battery size and mission budget is not a numeric value, return false. Otherwise, return true.
*/
bool Robot::validate_robot(const string input_file) 
{

}

/* 
    Extract relevant robot data from input file and instantiate robot object fields. Return true on success, otherwise false. 
*/
bool Robot::store_robot_info(const string input_file) 
{
    
}

/*
    Returns remaining battery of robot (i.e. # of steps left). 
*/
int Robot::get_battery_left() 
{

}

/*
    Returns location of robot within the house.
*/
pair<int, int> Robot::get_robot_loc() 
{

}

/*
    Perform movement to new location depending on given direction.
*/
void Robot::move(const Direction dir) 
{

}

/*
    Reduce battery by one.
*/
void Robot::decrement_battery() 
{

}

/*
    Recalculate battery of the robot after it leaves charging dock according to following formula:
    (the amount of battery steps when getting onto the docking station) + (number of steps staying on the docking station) * (battery_size / 20)
*/
void Robot::finished_charge() 
{

}   
