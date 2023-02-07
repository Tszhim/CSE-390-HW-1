#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stack>
#include <queue>
#include <unordered_set>
#include <utility>       /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"
#include "hash.h"
using namespace std;

class Algorithm 
{   
    int wall_north;  /* 0 if there is a wall north, -1 if there is no wall north. */
    int wall_west;   /* 0 if there is a wall west, -1 if there is no wall west. */
    int wall_south;  /* 0 if there is a wall south, -1 if there is no wall south. */
    int wall_east;   /* 0 if there is a wall east. -1 if there is no wall east. */
    int dirt;        /* Dirt level of current location. */
    int battery;     /* Battery of robot. */
    
    // Naive algorithm. 
    stack<pair<int, int>> path_stack;                            /* Each time the robot moves away from the charging port, the algorithm tracks the entire path it traverses. Push a pair when moving forward, pop a pair when moving backward. */

    // Smart algorithm. 
    // pair<int, int> robot_loc;                                 /* Tracks location of the robot relative to the charging dock (i.e. the origin). */
    // unordered_set<pair<int, int>, pair_hash> visited_spaces;  /* Algorithm's view of the house. Expands as robot traverses house. */
    // stack<pair<int, int>> path_stack;                         /* Each time the robot moves away from the charging port, the algorithm tracks the entire path it traverses. Push a pair when moving forward, pop a pair when moving backward. */
    // queue<pair<int, int>> visit_queue;                        /* Algorithm will visit spaces in DFS manner. Upon checking the spaces nearby in the order N, W, S, E, it will push the first valid, unvisited space into the queue. */

    public:
        /* Constructor. */
        Algorithm();

        /* Setters for "querying" data. Called in main(). */
        void set_wall_north(int w);
        void set_wall_west(int w);
        void set_wall_south(int w);
        void set_wall_east(int w);
        void set_dirt(int d);
        void set_battery(int b);

        /* Primary function of the class. */
        Direction get_move();
};

#endif