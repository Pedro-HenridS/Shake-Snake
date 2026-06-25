#ifndef  STATS_H
#define STATS_H

typedef struct Stats {
	int generated_apple;
	int apple_x;
	int apple_y;
} Stats;

Stats* create_stats();

#endif