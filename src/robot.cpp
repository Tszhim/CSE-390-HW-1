/* 
    The two configurations the robot will have (battery size and mission budget) should be the first two lines in the input file.

    e.g.

    5 
    10
    XXXXXXXX
    X913X56X
    X3X2821X
    X1X0XXXX
    XO3146XX
    XXXXXXXX
*/

#include <iostream>
#include <fstream> 
#include <string>
#include "robot.h"

using std::ifstream, std::string, std::getline, std::stoi, std::invalid_argument, std::out_of_range, std::pair;

/* 
    Constructor for robot class, no parameters.
*/
Robot::Robot() 
{
    battery_size = 0;
    mission_budget = 0;

    steps = 0;
    battery_left = 0;
    space = pair(0, 0);
}

/* 
    Attempts to instantiate robot object fields. Return true on success, otherwise false.
*/
bool Robot::robot_setup(const string infile_name) 
{
    ifstream file = ifstream(infile_name);
    return !file.fail() && store_robot_info(file);
}

/* 
    Extract relevant robot data from input file and instantiate robot object fields. If the provided battery size and mission budget is not a numeric value, return false. Return true on success, otherwise false. 
*/
bool Robot::store_robot_info(ifstream& file) 
{   
    string str;
    if (!getline(file, str) || (str.find_first_not_of("1234567890") != string::npos))
        return false;

    try
    {
        battery_size = battery_left = stoi(str);
    }
    catch (invalid_argument&) {return false;} 
    catch (out_of_range&) {return false;}

    if (!getline(file, str) || (str.find_first_not_of("1234567890") != string::npos))
        return false;

    try 
    {
        mission_budget = stoi(str);
    }
    catch (invalid_argument&) {return false;} 
    catch (out_of_range&) {return false;}

    return true;
}

/*
    Returns remaining battery of robot (i.e. # of steps left). 
*/
int Robot::get_battery_left() 
{
    return battery_left;
}

/*
    Returns total number of steps robot has moved throughout entire mission duration.
*/
int Robot::get_total_steps()
{
    return steps;
}

/*
    Returns location of robot within the house.
*/
pair<int, int> Robot::get_robot_loc() 
{
    return space;
}

/*
    Returns true if robot is on charging dock (i.e. 0,0), otherwise false.
*/
bool Robot::on_charging_dock()
{
    return space.first == 0 && space.second == 0;
}

/*
    Returns true if budget exceeded (i.e. steps > mission_budget), otherwise false.
*/
bool Robot::budget_exceeded()
{
    return steps >= mission_budget;
}

/*
    Perform movement to new location depending on given direction. Note that this function does not check for out of bounds movement, as it is contingent on main() and thereby the algorithm class to operate correctly.
*/
void Robot::move(const Direction dir) 
{   
    int new_battery;
    
    /* Ensures mission will end. */
    steps++;

    /* Sanity check: robot cannot move if it has no battery and/or mission budget is exceeded. */
    if((battery_left <= 0) || budget_exceeded())
        return;
    
    /* Recalculate space. */
    if(dir == North)
        space.second += 1;
    if(dir == West)
        space.first -= 1;
    if(dir == South)
        space.second -= 1;
    if(dir == East)
        space.first += 1;
    // Do nothing if stasis.

    /* Check if new position is charging dock. If so, charge the robot. Charge cannot exceed max battery capacity. */
    if(on_charging_dock())
    {
        new_battery = battery_left + (battery_size / 20);
        battery_left = (new_battery > battery_size) ? battery_size : new_battery;
    }
}
