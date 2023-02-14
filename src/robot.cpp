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

#include <iostream>
#include <fstream> 
#include <string>
#include "robot.h"

using std::string, std::ifstream, std::getline, std::stoi, std::invalid_argument, std::out_of_range;

/* 
    Constructor for robot class, no parameters.
*/
Robot::Robot() 
{
    space = pair(0, 0);
    steps = 0;
    charging_status = 1;
    charging_length = 0;
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
    if (!getline(file, str))
        return false;

    try
    {
        battery_size = battery_left = stoi(str);
    }
    catch (invalid_argument&) {return false;} 
    catch (out_of_range&) {return false;}

    if (!getline(file, str))
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
    Returns location of robot within the house.
*/
pair<int, int> Robot::get_robot_loc() 
{
    return space;
}

/*
    Perform movement to new location depending on given direction. Note that this function does not check for out of bounds movement, as it is contingent on main() and thereby the algorithm class to operate correctly.
*/
void Robot::move(const Direction dir) 
{   
    bool docked_before = space.first == 0 && space.second == 0;
    bool docked_after;
    bool enter_dock, stay_docked, leave_dock;

    /* Sanity check. */
    if (battery_left <= 0 || steps >= mission_budget)
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
    
    /* Evaluate action taken. */
    docked_after = space.first == 0 && space.second == 0;
    enter_dock = !docked_before && docked_after;
    stay_docked = docked_before && docked_after;
    leave_dock = docked_before && !docked_after;
    
    /* Update attributes accordingly. */
    if(enter_dock)        
        start_charge();
    if(stay_docked)       
        charge();
    if(leave_dock)         
        finished_charge();

    steps++;
    battery_left = stay_docked ? battery_left : battery_left - 1;   // Don't decrement battery if staying on charging dock.
}

/* Reflect charging state. */
void Robot::start_charge() 
{
    charging_status = true;
}

/* Reflect one additional "step" of charging. */
void Robot::charge()
{
    charging_length++;
}

/*
    Recalculate battery of the robot after it leaves charging dock according to following formula:
    (the amount of battery steps when getting onto the docking station) + (number of steps staying on the docking station) * (battery_size / 20)
*/
void Robot::finished_charge() 
{   
    int new_battery = battery_left + charging_length * (battery_size / 20);
    battery_left = new_battery <= battery_size ? new_battery : battery_size;
    charging_status = false;
    charging_length = 0;
}   
