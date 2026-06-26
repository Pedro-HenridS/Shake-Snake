#pragma once	
#ifndef  STATS_H
#define STATS_H

typedef struct GameStats {
	int generated_apple;
	int apple_x; 
	int apple_y;
	int ended;
} GameStats;

void generate_apple(struct Map* map_struct, struct Snake* snake, GameStats* stats);

GameStats* create_stats();

#endif
