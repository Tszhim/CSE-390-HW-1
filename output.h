#ifndef OUTPUT_H
#define OUTPUT_H

#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"
using namespace std;

#define OUTPUT_FILE "output.txt"

/* Functions to record mission details. */
int write_step(Direction dir, pair<int, int> new_space);
int write_step_count(int total_steps);
int write_dirt_count(int total_dirt);
int write_robot_status(int battery_left);
int write_mission_failure();
int write_mission_success();

#endif