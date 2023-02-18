#include <string>
#include <random>
#include "algorithm.h"

using std::stack, std::pair, std::string, std::random_device, std::mt19937, std::uniform_int_distribution;

/* 
    Constructor for algorithm class, no parameters. 
*/
Algorithm::Algorithm()
{
    wall_north = wall_west = wall_south = wall_east = true;
    space = pair(0,0);
    dirt = 0;
    battery_left = 0;
    battery_size = -1;
}

/*
    Sets whether the wall north of current position is a wall. 
*/
void Algorithm::set_wall_north(const bool w) 
{
    wall_north = w;
}

/*
    Sets whether the wall west of current position is a wall.
*/
void Algorithm::set_wall_west(const bool w) 
{
    wall_west = w;
}

/*
    Sets whether the wall south of current position is a wall.
*/
void Algorithm::set_wall_south(const bool w) 
{
    wall_south = w;
}

/*
    Sets whether the wall east of current position is a wall.
*/
void Algorithm::set_wall_east(const bool w) 
{
    wall_east = w;
}

/*
    Sets the amount of dirt at current position.
*/
void Algorithm::set_dirt(const int d) 
{
    dirt = d;
}

/* 
    Sets the amount of battery the robot currently has.
*/
void Algorithm::set_battery(const int b) 
{
    battery_left = b;
}

/*
    Returns true if robot is on charging dock (i.e. 0,0), otherwise false.
*/
bool Algorithm::on_charging_dock()
{
    return space.first == 0 && space.second == 0;
}

/*
    Bulk of the algorithm. Returns the direction the robot should move next.
*/
Direction Algorithm::get_move()
{   
    pair<int, int> prev_space;
    pair<int, int> next_space;
    string rand_str;
    char rand_dir;
    random_device rd;
    mt19937 eng = mt19937(rd());
    uniform_int_distribution<> dist;

    /* First move. Maintain max battery for robot for later usage. */
    if(battery_size = -1)
        battery_size = battery_left;

    /* If on charging dock and robot isn't fully charged, remaining on the dock to charge.*/
    if(on_charging_dock() && battery_left != battery_size)
        return Stasis;

    /* If robot has just enough battery to traverse back to charging dock, it MUST return. */
    /* Note that moving forward one space will cost 1 battery step, and returning will cost another 1. */
    /* Therefore, a battery buffer of 1 should be left open to return. */
    if(!path_stack.empty() && battery_left - 1 <= path_stack.size())
    {
        prev_space = path_stack.top();
        path_stack.pop();

        if(prev_space.first < space.first)
        {
            space.first--;
            return West;
        }
        if(prev_space.first > space.first)
        {
            space.first++;
            return East;
        }
        if(prev_space.second < space.second)
        {
            space.second--;
            return South;
        }
        if(prev_space.second > space.second)
        {
            space.second++;
            return North;
        }
    }

    /* Robot still has enough battery for additional moves. */

    /* If there is dirt at the current spot, stay in place and clean. */
    if(dirt > 0)
        return Stasis;
    
    /* Sanity check: Blocked by wall on all sides, no move possible. */
    if(wall_north && wall_west && wall_south && wall_east) 
        return Stasis;

    /* Generate a random possible direction to move. */
    rand_str = "";
    if (!wall_north) rand_str += "n";
    if (!wall_west) rand_str += "w";
    if (!wall_south) rand_str += "s";
    if (!wall_east) rand_str += "e";
    dist = uniform_int_distribution<>(0, rand_str.length() - 1);
    rand_dir = rand_str[dist(eng)];

    /* Determine next space. */
    if(rand_dir == 'n')
        next_space = pair(space.first, space.second + 1);
    if(rand_dir == 'w')
        next_space = pair(space.first - 1, space.second);
    if(rand_dir == 's')
        next_space = pair(space.first, space.second - 1);
    if(rand_dir == 'e')
        next_space = pair(space.first + 1, space.second);

    /* If stack is empty, push space before movement into stack to trace traversal. */
    if(path_stack.empty())
        path_stack.push(prev_space);
    else
    {
        /* If the next space is the same as the top item in the stack, pop the item. */
        /* If not, push space before movement into stack. */
        prev_space = path_stack.top();
        if(prev_space == next_space)
            path_stack.pop();
        else
            path_stack.push(prev_space);
    }

    /* Finish up by updating position and returning direction. */
    if(rand_dir == 'n') {space.second++; return North;}
    if(rand_dir == 'w') {space.first--; return West;}
    if(rand_dir == 's') {space.second--; return South;}
    if(rand_dir == 'e') {space.first++; return East;}
    
    /* Unexpected error.*/
    return Stasis;
}   