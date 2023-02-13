
#include <string>
#include <iostream>
#include "house.h"
#include "robot.h"
#include "output.h"

using std::string, std::cout;

string input_file;
int mission_success;

int main(int argc, char* argv[]) 
{   
    /* Get input file name. */
    if(argc < 2) 
    {
        cout << "Too few arguments.";
        return -1;
    }
    input_file = argv[1];
    

    /* Setup house and robot objects. */
    House h;
    h.house_setup(input_file);

    Robot r(h.get_dock_loc());
    r.robot_setup(input_file);

    /* Begin mission. */
    while(1) 
    {
        /* Update algorithm with fresh data after previous move. */
        
        /* Ask algorithm for next move. */

        /* Call move() on robot with calculated move. */

        /* Write calculated move into output file. */

        /* Check if house is fully cleaned AND robot is on charging port. */
            /* if yes -> mission success */
            /* break; */

        /* Check if mission budget has been depleted. */
            /* if yes -> mission failed */
            /* break; */
        break;
    }   

    /* print general logs */
    /* print results msg based on success or failure of the mission */

    return 0;
}