
#include <string>
#include <iostream>
#include "house.h"
#include "robot.h"
#include "output.h"
using namespace std;

string input_file;
int mission_success;

int main(int argc, char* argv[]) 
{   
    /* Get input file name. */
    if(argc < 2) 
    {
        cout << "Too few arguments.";
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
        /* Ask algorithm what queries it wants to make. Pass results onto algorithm. */

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