#ifndef HOUSE_H
#define HOUSE_H

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>          /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "hash.h"

using std::pair, std::unordered_set, std::unordered_map, std::string;

class House 
{
    pair<int, int> dock;                                     /* Charging dock location. This will be considered the origin (0,0). */
    unordered_set<pair<int, int>, pair_hash> spaces;         /* A unordered set of valid spaces that the robot can reach. Spaces are relative to the charging dock. */
    unordered_map<pair<int, int>, int, pair_hash> dirt;      /* An unordered map of valid space : dirt level. */

public:
    /* Constructor. */
    House();

    /* Calls private functions for instantiation of object fields. */  
    bool house_setup(const string input_file);                           

    /* Does not alter house data.*/
    bool is_valid_space(const pair<int, int> space); 
    pair<int, int> get_dock_loc();
    int get_total_dirt();
    bool is_house_clean();

    /* Alters house data. */
    void clean_space(const pair<int, int> space);

private:
    /* Reads input file to extract information about house layout. */                
    bool validate_house(const string input_file);
    bool store_house_info(const string input_file);
};  

#endif