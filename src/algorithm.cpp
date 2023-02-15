#include <string>
#include <random>
#include "algorithm.h"

using std::stack, std::pair, std::string, std::random_device, std::mt19937, std::uniform_int_distribution;

/* 
    Constructor for algorithm class, no parameters. 
*/
Algorithm::Algorithm()
{
    space = pair(0,0);
    charging_length = 0;
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
    battery = b;
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
    
    /* If the robot is on the charging dock, allow 5 steps of charging before leaving (hardcoded). */
    if(space.first == 0 && space.second == 0)
    {
        /* Keep charging. */
        if(charging_length < 5)
        {
            charging_length++;
            return Stasis;
        }
        /* Stop charging. Clear charging duration and path stack to start anew. */
        else
        {
            charging_length = 0;
            while(!path_stack.empty())
                path_stack.pop();
        }
    }

    /* If robot has just enough battery to traverse back to charging dock, it MUST return. */
    if(!path_stack.empty() && battery <= path_stack.size())
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

    /* Otherwise, check if there is dirt at current spot. If there is dirt, stay in place and clean. */
    if(dirt > 0)  
        return Stasis;

    /* If no dirt at current spot, pick a random direction to move that is not a wall. */

    /* Blocked by wall on all sides, no move possible. */
    if(wall_north && wall_west && wall_south && wall_east) 
        return Stasis;

    /* Move random direction. */
    rand_str = "";
    if (!wall_north) rand_str += "n";
    if (!wall_west) rand_str += "w";
    if (!wall_south) rand_str += "s";
    if (!wall_east) rand_str += "e";
    dist = uniform_int_distribution<>(0, rand_str.length() - 1);
    rand_dir = rand_str[dist(eng)];

    /* If the next space is the same as the top item in the stack, pop the item. Otherwise, push the new space into the stack. */
    if(rand_dir == 'n')
    {      
        next_space = pair(space.first, space.second + 1);
        if(path_stack.empty())
            path_stack.push(prev_space); 
        else
        {
            prev_space = path_stack.top();
            if (prev_space == next_space)
                path_stack.pop();
            else
                path_stack.push(prev_space);
        }
        space.second++;
        return North;
    }
    if(rand_dir == 'w')
    {
        next_space = pair(space.first - 1, space.second);
        if(path_stack.empty())
            path_stack.push(prev_space); 
        else
        {
            prev_space = path_stack.top();
            if (prev_space == next_space)
                path_stack.pop();
            else
                path_stack.push(prev_space);
        }
        space.first--;
        return West;
    }
    if(rand_dir == 's')
    {
        next_space = pair(space.first, space.second - 1);
        if(path_stack.empty())
            path_stack.push(prev_space); 
        else
        {
            prev_space = path_stack.top();
            if (prev_space == next_space)
                path_stack.pop();
            else
                path_stack.push(prev_space);
        };
        space.second--;
        return South;
    }
    if(rand_dir == 'e')
    {
        next_space = pair(space.first + 1, space.second);
        if(path_stack.empty())
            path_stack.push(prev_space); 
        else
        {
            prev_space = path_stack.top();
            if (prev_space == next_space)
                path_stack.pop();
            else
                path_stack.push(prev_space);
        }
        space.first++;
        return East;
    }

    /* Unexpected error. */
    return Stasis;
}