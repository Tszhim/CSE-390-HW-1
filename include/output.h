#ifndef OUTPUT_H
#define OUTPUT_H

#include <utility>      /* To use pairs. Pairs will be of type <int, int> to represent coordinate of a particular location, relative to the charging dock.*/
#include "direction.h"

using std::pair;

#define OUTPUT_FILE "output.txt"

/* Functions to record mission details. */
bool write_step(const Direction dir, const pair<int, int> new_space);
bool write_step_count(const int total_steps);
bool write_dirt_count(const int total_dirt);
bool write_robot_status(const int battery_left);
bool write_mission_failure();
bool write_mission_success();

#endif