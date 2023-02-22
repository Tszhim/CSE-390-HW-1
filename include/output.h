#ifndef OUTPUT_H
#define OUTPUT_H

#include <utility> 
#include "direction.h"

#define OUTPUT_FILE "output.txt"

/* Functions to record mission details. */
bool setup_output();
bool write_step(const Direction dir, const std::pair<int, int> new_space, int battery_left);
bool write_output_header();
bool write_step_count(const int total_steps);
bool write_dirt_count(const int total_dirt);
bool write_robot_status(const int battery_left);
bool write_mission_failure();
bool write_mission_success();

#endif