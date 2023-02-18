#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <fstream> 
#include <string>
#include <utility>     
#include "direction.h"

class Robot 
{   
    int battery_size;                        /* Max steps robot can take on fully-charged battery. */
    int mission_budget;                      /* # of steps allocated for mission before robot must stop. */
    
    int steps;                               /* Total number of steps made by robot. */
    int battery_left;                        /* # of steps robot can take on current battery capacity. */
    std::pair<int, int> space;                    /* Current location of robot. */

public:
    /* Constructor. */
    Robot();

    /* Calls private functions for instantiation of object fields. */
    bool robot_setup(const std::string infile_name);
    
    /* Does not alter robot data. */
    int get_battery_left();
    int get_total_steps();
    std::pair<int, int> get_robot_loc();
    bool on_charging_dock();
    bool budget_exceeded();

    /* Alters robot data. */
    void move(const Direction dir);

private:
    /* Reads input file to extract information about robot configurations. */
    bool store_robot_info(std::ifstream& file);
};  

#endif
