#pragma once	
#ifndef  STATS_H
#define STATS_H

#include "map.h"
#include "snake.h"

typedef struct Stats {
	int generated_apple;
	int apple_x; 
	int apple_y;
} Stats;

void generate_apple(Map* map_struct, Snake* snake, Stats* stats);

Stats* create_stats();

#endif
