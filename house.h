#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
using namespace std;

class House 
{
    pair<int, int> dock;                      /* Charging dock location. */
    pair<pair<int, int>, int> spaces[];       /* An array of valid spaces (array[i] -> (coordinate, dirt_level) that the robot can reach. */

public:
    /* Constructor. */
    House();

    /* Calls private functions for instantiation of object fields. */  
    int house_setup(string input_file);                           

    /* Does not alter house data.*/
    int is_valid_space(pair<int, int> space); 
    pair<int, int> get_dock_loc();
    int get_total_dirt();
    int is_house_clean();

    /* Alters house data. */
    void clean_space(pair<int, int> space);

private:
    /* Reads input file to extract information about house layout. */                
    int validate_house(string input_file);
    int store_house_info(string input_file);
};  

#endif