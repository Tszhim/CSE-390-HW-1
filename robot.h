#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"
using namespace std;

class Robot 
{   
    int battery_size;                        /* Max steps robot can take on fully-charged battery. */
    int mission_budget;                      /* # of steps allocated for mission before robot must stop. */
    
    int steps;                               /* Total number of steps made by robot. */
    int battery_left;                        /* # of steps robot can take on current battery capacity. */
    int charging_status;                     /* 0 if not charging, 1 if charging. */
    int charging_length;                     /* Amount of time robot has been on charging dock. */
    pair<int, int> space;                    /* Current location of robot. */

public:
    /* Constructor. */
    Robot(pair<int, int> starting_space);

    /* Calls private functions for instantiation of object fields. */
    int robot_setup(string input_file);
    
    /* Does not alter robot data. */
    int get_battery_left();
    pair<int, int> get_robot_loc();

    /* Alters robot data. */
    void move(Direction dir);
    void decrement_battery();
    void finished_charge();

private:
    /* Reads input file to extract information about robot configurations. */
    int validate_robot(string input_file);
    int store_robot_info(string input_file);
};  

#endif
