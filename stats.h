#pragma once	
#ifndef  STATS_H
#define STATS_H

typedef struct MatchStats {
	int generated_apple;
	int apple_x; 
	int apple_y;
	int ended;
} MatchStats;

void generate_apple(struct Map* map_struct, struct Snake* snake, MatchStats* stats);

MatchStats* create_stats();

#endif
