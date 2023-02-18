
#include <string>
#include <iostream>
#include "algorithm.h"
#include "house.h"
#include "robot.h"
#include "output.h"
#include "direction.h"

using std::pair, std::string, std::cout, std::endl;

string input_file;
bool mission_success;

int main(int argc, char* argv[]) 
{   
    House h;
    Robot r;
    Algorithm a;
    pair<int, int> r_loc;
    Direction next_dir;
    bool wall_north, wall_west, wall_south, wall_east;

    /* Get input file name. */
    if(argc < 2) 
    {
        cout << "Too few arguments." << endl;
        return -1;
    }
    input_file = argv[1];

    /* Setup house and robot objects. */
    if(!h.house_setup(input_file) || !r.robot_setup(input_file))
    {
        cout << "Input file format error or I/O error." << endl;
        return -1;
    }

    /* Setup output file for I/O. */
    if(!setup_output())
    {
        cout << "Unable to setup output file due to I/O error." << endl;
        return -1;
    }

    /* Begin mission. */
    while(1) 
    {
        /* Update algorithm with fresh data after previous move. */
        r_loc = r.get_robot_loc();
        wall_north = !h.is_valid_space(pair(r_loc.first, r_loc.second + 1));
        wall_west= !h.is_valid_space(pair(r_loc.first - 1, r_loc.second));
        wall_south = !h.is_valid_space(pair(r_loc.first, r_loc.second - 1));
        wall_east = !h.is_valid_space(pair(r_loc.first + 1, r_loc.second));

        a.set_wall_north(wall_north);
        a.set_wall_west(wall_west);
        a.set_wall_south(wall_south);
        a.set_wall_east(wall_east);

        a.set_dirt(h.get_dirt(r_loc));
        a.set_battery(r.get_battery_left());

        /* Ask algorithm for next move. */
        next_dir = a.get_move();

        /* Call move() on robot with calculated move. */
        r.move(next_dir);

        /* Clean space if stasis. No effect if current space is charging dock or is fully cleaned. */
        if(next_dir == Stasis)
            h.clean_space(r_loc);

        /* Write calculated move into output file. */
        if(!write_step(next_dir, r.get_robot_loc()))
        {
            cout << "Unable to write to output due to I/O error." << endl;
            return -1;
        }

        /* Check if house is fully cleaned AND robot is on charging port. If so, mission succeeded and break. */
        if(h.is_house_clean() && r.on_charging_dock())
        {
            mission_success = true;
            break;
        }

        /* Check if mission budget has been depleted. */
        if(r.budget_exceeded()) 
        {
            mission_success = false;
            break;
        }
    }   

    /* print general logs */
    if(!write_output_header() || !write_step_count(r.get_total_steps()) || !write_dirt_count(h.get_total_dirt()) || !write_robot_status(r.get_battery_left()))
    {
        cout << "Unable to write to output due to I/O error." << endl;
        return -1;
    }
    /* print results msg based on success or failure of the mission */
    if((mission_success && !write_mission_success()) || (!mission_success && !write_mission_failure()))
    {
        cout << "Unable to write to output due to I/O error." << endl;
        return -1;
    }
    return 0;
}