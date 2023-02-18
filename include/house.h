#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <fstream> 
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>          /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "hash.h"

class House 
{
    std::unordered_set<std::pair<int, int>, pair_hash> spaces;             /* A unordered set of valid spaces that the robot can reach. Spaces are relative to the charging dock (origin).*/
    std::unordered_map<std::pair<int, int>, int, pair_hash> dirt_lvl;      /* An unordered map of valid space : dirt level. */
    int total_dirt;                                                        /* Remaining dirt across entire house. */

public:
    /* Constructor. */
    House();

    /* Calls private functions for instantiation of object fields. */  
    bool house_setup(const std::string infile_name);                           

    /* Does not alter house data.*/
    bool is_valid_space(const std::pair<int, int> space); 
    int get_dirt(const std::pair<int, int> space);
    int get_total_dirt();
    bool is_house_clean();

    /* Alters house data. */
    void clean_space(const std::pair<int, int> space);
    
private:
    /* Reads input file to extract information about house layout. */                
    bool store_house_info(std::ifstream& file);
};  

#endif