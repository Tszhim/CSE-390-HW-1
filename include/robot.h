#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"

using std::pair, std::pair, std::string;

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
    Robot(const pair<int, int> starting_space);

    /* Calls private functions for instantiation of object fields. */
    bool robot_setup(const string input_file);
    
    /* Does not alter robot data. */
    int get_battery_left();
    pair<int, int> get_robot_loc();

    /* Alters robot data. */
    void move(const Direction dir);
    void decrement_battery();
    void finished_charge();

private:
    /* Reads input file to extract information about robot configurations. */
    bool validate_robot(const string input_file);
    bool store_robot_info(const string input_file);
};  

#endif
