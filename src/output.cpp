#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "output.h"
#include "direction.h"

/* 
    Writes current step made by robot into output file. Return true if successful, otherwise false. 
*/
bool write_step(const Direction dir, const pair<int, int> new_space) 
{

}

/* 
    Writes total steps made by robot into output file. Return true if successful, otherwise false. 
*/
bool write_step_count(const int total_steps) 
{

}

/*
    Write how much dirt is left in the house into output file. Return true if successful, otherwise false. 
*/
bool write_dirt_count(const int total_dirt)
{

}

/*
    Write if robot is out of battery into output file. RReturn true if successful, otherwise false.
*/
bool write_robot_status(const int battery_left) 
{

}

/* 
    Write that the mission failed into output file. Return true if successful, otherwise false. 
*/
bool write_mission_failure()
{

}

/* 
    Write that the mission succeeded into output file. Return true if successful, otherwise false. 
*/
bool write_mission_success() 
{

}