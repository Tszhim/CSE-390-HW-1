/* Implements all functions for house class declared in Mission namespace. */

/*
   Let the format of the house follow the below rules: 
   If valid space: denote with numeric value from 0-9.
   If wall: denote with X
   If charging space: denote with O.

   This format will be presented after the second line in the input file. 

   e.g.
   X X X X X X X X
   X 9 1 3 X 5 6 X
   X 3 X 2 8 2 1 X
   X 1 X 0 X X X X
   X 0 3 1 4 6 X X
   X X X X X X X X

       X
     X 9 X
     X 1 2 3 X X X X X X X 
   X 0 3 5 1 3 4 6 7 8 X
     X X X 8 1 4 7 2 1 X
           X X X X X X

   Think of corridor spaces as a connected graph. Traversing the nodes is the primary objective.
*/

#include "house.h"

/* 
    Constructor for house class, no parameters. 
*/
House::House() {}

/* 
    Attempts to instantiate house object fields. Return 0 on success, else -1. 
*/
int House::house_setup(string input_file) 
{
    if((validate_house(input_file)) == -1) 
    {
        return -1;
    }
    if((store_house_info(input_file)) == -1) 
    {
        return -1;
    }
    return 0;
}

/*
    Read input file, if I/O error or if denoted house does not follow aforementioned format (e.g. unknown characters such as ?, !, @) or if denoted house is not a connected graph, return -1. Otherwise, return 0.
*/
int House::validate_house(string input_file)
{

}

/* 
    Extract relevant house data from input file and instantiate house object fields. 
*/
int House::store_house_info(string input_file)
{

}

/*
    Check if provided coordinate is a valid space within the house (i.e. not a wall). Return 0 if valid, otherwise -1. 
*/
int House::is_valid_space(pair<int, int> space) 
{

}

/* 
    Returns location of charging dock within the house.
*/
pair<int, int> House::get_dock_loc() 
{

}

/*
    Returns total amount of dirt left in the house.
*/
int House::get_total_dirt() 
{

}

/*
    Check if the house is completely clean (i.e. no dirt left). Return 0 is clean, otherwise -1.
*/
int House::is_house_clean() 
{

}

/*
    Cleans a particular space in the house (i.e. decrement dirt level). 
*/
void House::clean_space(pair<int, int> space) {

}
