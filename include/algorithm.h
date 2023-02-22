#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stack>
#include <utility>     
#include "direction.h"
#include "hash.h"

class Algorithm 
{   
    bool wall_north;                /* if there is a wall north  */
    bool wall_west;                 /* 0 if there is a wall west, -1 if there is no wall west. */
    bool wall_south;                /* 0 if there is a wall south, -1 if there is no wall south. */
    bool wall_east;                 /* 0 if there is a wall east. -1 if there is no wall east. */

    std::pair<int, int> space;      /* Current location of robot, maintained by algorithm. */
    int dirt;                       /* Dirt level of current location. */
    int battery_left;               /* # of steps robot can take on current battery capacity. */
    int battery_size;               /* Max steps robot can take on fully-charged battery. */

    
    // Naive algorithm. 
    std::stack<std::pair<int, int>> path_stack;                       /* Each time the robot moves away from the charging port, the algorithm tracks the entire path it traverses. Push a pair when moving forward, pop a pair when moving backward. */

    // Smart algorithm. 
    // pair<int, int> robot_loc;                                 /* Tracks location of the robot relative to the charging dock (i.e. the origin). */
    // unordered_set<pair<int, int>, pair_hash> visited_spaces;  /* Algorithm's view of the house. Expands as robot traverses house. */
    // stack<pair<int, int>> path_stack;                         /* Each time the robot moves away from the charging port, the algorithm tracks the entire path it traverses. Push a pair when moving forward, pop a pair when moving backward. */
    // queue<pair<int, int>> visit_queue;                        /* Algorithm will visit spaces in DFS manner. Upon checking the spaces nearby in the order N, W, S, E, it will push the first valid, unvisited space into the queue. */

    public:
        /* Constructor. */
        Algorithm();

        /* Setters for "querying" data. Called in main(). */
        void set_wall_north(const bool w);
        void set_wall_west(const bool w);
        void set_wall_south(const bool w);
        void set_wall_east(const bool w);
        void set_dirt(const int d);
        void set_battery(const int b);

        /* Primary function of the class. */
        Direction get_move();
    
    private:
        /* For internal use. */
        bool on_charging_dock();
        Direction get_rand_dir();
        void clear_path_stack();
};

#endif