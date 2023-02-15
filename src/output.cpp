#include <iostream>
#include <fstream> 
#include <string>
#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "output.h"
#include "direction.h"

using std::ofstream, std::endl, std::ios;


/*
    Separates the result output from the robot movement output. Return true if successful, otherwise false.
*/
bool write_output_header() 
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;
    
    file << "Results: " << endl;
    file << "-----------------------" << endl;  
    return true;
}

/* 
    Writes current step made by robot into output file. Return true if successful, otherwise false. 
*/
bool write_step(const Direction dir, const pair<int, int> new_space) 
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;

    if(dir == North)
        file << "Robot headed north." << endl;
    if(dir == West)
        file << "Robot headed west." << endl;
    if(dir == South)
        file << "Robot headed south." << endl;
    if(dir == East)
        file << "Robot headed east." << endl;
    if(dir == Stasis)
        file << "Robot remained in place." << endl;

    file << "Robot now resides in space: " << new_space.first << "," << new_space.second << endl;
    return true;
}

/* 
    Writes total steps made by robot into output file. Return true if successful, otherwise false. 
*/
bool write_step_count(const int total_steps) 
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;

    file << "Total Steps: ";
    file << total_steps << endl;
    return true;
}

/*
    Write how much dirt is left in the house into output file. Return true if successful, otherwise false. 
*/
bool write_dirt_count(const int total_dirt)
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;

    file << "Remaining dirt: ";
    file << total_dirt << endl;
    return true;
}

/*
    Write if robot is out of battery into output file. Return true if successful, otherwise false.
*/
bool write_robot_status(const int battery_left) 
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;

    if(!battery_left) 
        file << "No battery remaining." << endl;
    else 
        file << "Battery remaining: " << battery_left << endl;
    return true;
}

/* 
    Write that the mission failed into output file. Return true if successful, otherwise false. 
*/
bool write_mission_failure()
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;
    
    file << "Result: Mission Failed." << endl;
    return true;
}

/* 
    Write that the mission succeeded into output file. Return true if successful, otherwise false. 
*/
bool write_mission_success() 
{
    ofstream file = ofstream(OUTPUT_FILE, ios::app);
    if(file.fail()) 
        return false;
    
    file << "Result: Mission Succeeded." << endl;
    return true;
}