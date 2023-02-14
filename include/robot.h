#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <fstream> 
#include <string>
#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"

using std::pair, std::string, std::ifstream;

class Robot 
{   
    int battery_size;                        /* Max steps robot can take on fully-charged battery. */
    int mission_budget;                      /* # of steps allocated for mission before robot must stop. */
    
    int steps;                               /* Total number of steps made by robot. */
    int battery_left;                        /* # of steps robot can take on current battery capacity. */
    bool charging_status;                    /* True if charging, false if not. */
    int charging_length;                     /* Amount of time robot has been on charging dock. */
    pair<int, int> space;                    /* Current location of robot. */

public:
    /* Constructor. */
    Robot();

    /* Calls private functions for instantiation of object fields. */
    bool robot_setup(const string infile_name);
    
    /* Does not alter robot data. */
    int get_battery_left();
    pair<int, int> get_robot_loc();

    /* Alters robot data. */
    void move(const Direction dir);

private:
    /* Reads input file to extract information about robot configurations. */
    bool store_robot_info(ifstream& file);

    /* Alter charging state information. */
    void start_charge();
    void charge();
    void finished_charge();
};  

#endif
