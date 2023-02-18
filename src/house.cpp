/*
   Let the format of the house follow the below rules: 
   If valid space: denote with numeric value from 0-9.
   If wall: denote with "X" or " "
   If charging space: denote with "O"

   This format will be presented after the second line in the input file.

   e.g.

   XXXXXXXX
   X913X56X
   X3X2821X
   X1X0XXXX
   XO3146XX
   XXXXXXXX

        X
       X9X
      X123XXXXXXX 
     XO35134678X
   XXX814721X
      XXXXXX
    
   3456
   93O1
   5792

   Think of corridor spaces as a connected graph. Traversing the nodes is the primary objective.
*/

#include <iostream>
#include <fstream> 
#include "house.h"

using std::ifstream, std::string, std::getline, std::pair, std::unordered_map;

/* 
    Constructor for house class, no parameters. Add charging dock to list of spaces by default with a dirt level of 0.
*/
House::House() 
{
    pair p = pair(0, 0);
    spaces.insert(p);
    dirt_lvl.insert({p, 0});
    total_dirt = 0;
}

/* 
    Attempts to instantiate house object fields. Return true on success, else false.
*/
bool House::house_setup(const string infile_name) 
{   
    ifstream file = ifstream(infile_name);
    return !file.fail() && store_house_info(file);
}

/* 
    Extract relevant house data from input file and instantiate house object fields.  If the denoted house does not follow the aforementioned format (e.g. unknown characters such as ?, !, @), return false. Return true on success, else false.
*/
bool House::store_house_info(ifstream& file)
{  
    string str;
    char c;
    pair p = pair(0, 0);
    bool dock_found = false;
    int dock_line = 0, dock_idx = 0;
    int curr_line = 0;
    int space_x = 0, space_y = 0;
    int dirt = 0;
    int dirt_counter = 0;

    /* Ignore first two lines. If there is less than two lines, house format is incorrect. */
    for (int i = 0; i < 2; i++) 
    {
        if (!getline(file, str))
            return false;
    }

    /* First read for validation and locating charging dock. */
    while(getline(file, str)) 
    {   
        if(str.find_first_not_of("0123456789XO ") != string::npos)
            return false;
        if(str.find('O') != string::npos) 
        {   
            if(dock_found)
                return false;
            dock_found = true;
            dock_idx = str.find('O');
        }
        if(!dock_found)
            dock_line++;
    }

    /* Cannot have zero docks. */
    if(!dock_found)
        return false;

    /* Move back to third line. */
    file.clear();
    file.seekg(0);
    getline(file, str);
    getline(file, str);

    /* Second read for storing valid spaces.*/
    while(getline(file, str))
    {   
        for(int i = 0; i < str.length(); i++) 
        {
            c = str.at(i);
        
            /* If valid space, calculate relative coordinate to charging dock. */
            if(c != 'X' && c != 'O' && c != ' ')
            {   
                space_x = i - dock_idx;
                space_y = dock_line - curr_line;
                p = pair(space_x, space_y);
                dirt = int(c) - '0';
                
                /* Store information about space into class attributes. */
                spaces.insert(p);
                dirt_lvl.insert({p, dirt});
                dirt_counter += dirt;
            }
        }
        curr_line++;
    }
    total_dirt = dirt_counter;
    return true;
}

/*
    Check if provided coordinate is a valid space within the house (i.e. not a wall or charging dock). Return true if valid, otherwise false.
*/
bool House::is_valid_space(const pair<int, int> space) 
{
    return spaces.find(space) != spaces.end();
}

/*
    Returns amount of dirt for a particular space. If the space provided is invalid, return 0.
*/
int House::get_dirt(const pair<int, int> space) 
{
    unordered_map<pair<int, int>, int>::iterator it = dirt_lvl.find(space);

    /* If space exists and dirt level of space > 0. */
    if(it != dirt_lvl.end() && it->second > 0) 
    {
        return it->second;
    }
    return 0;
}

/*
    Returns total amount of dirt left in the house.
*/
int House::get_total_dirt() 
{
    return total_dirt;
}

/*
    Check if the house is completely clean (i.e. no dirt left). Return 0 is clean, otherwise -1.
*/
bool House::is_house_clean() 
{
    return total_dirt == 0;
}

/*
    Cleans a particular space in the house (i.e. decrement dirt level). 
*/
void House::clean_space(const pair<int, int> space) 
{
    unordered_map<pair<int, int>, int>::iterator it = dirt_lvl.find(space);

    /* If space exists and dirt level of space > 0. */
    if(it != dirt_lvl.end() && it->second > 0) 
    {
        it->second = it->second - 1;
        total_dirt--;
    }
}