#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"
using namespace std;

/* Writes current step made by robot into output file. Return 0 if successful, otherwise -1. */
int write_step(Direction dir, pair<int, int> new_space) 
{

}

/* Writes total steps made by robot into output file. Return 0 if successful, otherwise -1. */
int write_step_count(int total_steps) 
{


}

/* Write how much dirt is left in the house into output file. Return 0 if successful, otherwise -1. */
int write_dirt_count(int total_dirt)
{

}

/* Write if robot is out of battery into output file. Return 0 if successful, otherwise -1. */
int write_robot_status(int battery_left) 
{

}

/* Write that the mission failed into output file. Return 0 if successful, otherwise -1. */
int write_mission_failure()
{

}

/* Write that the mission succeeded into output file. Return 0 if successful, otherwise -1. */
int write_mission_success() 
{

}