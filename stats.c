#include <stdlib.h>
#include <time.h>

#include "stats.h"
#include "map.h"
#include "snake.h"

void generate_apple(Map* map_struct, Snake* snake, MatchStats* stats) {
	if (stats->generated_apple == snake->eaten_apples) {
		srand(time(NULL));

		int apple_row = rand() % 7;
		int apple_column = rand() % 7;

		while (has_conflited(map_struct->map, snake, apple_row, apple_column) == 1) {
			apple_row = rand() % 7;
			apple_column = rand() % 7;
		}


		stats->apple_x = apple_row;
		stats->apple_y = apple_column;

		map_struct->map[stats->apple_x][stats->apple_y] = '#';

		stats->generated_apple++;
	}
	else {
		map_struct->map[stats->apple_x][stats->apple_y] = '#';
	}
}

MatchStats* create_stats() {
	MatchStats* stats = calloc(1, sizeof(MatchStats));

	if (stats == NULL) {
		return NULL;
	}

	stats->generated_apple = 0;
	stats->ended = 0;

	return stats;
}

void show_match_stats() {

}