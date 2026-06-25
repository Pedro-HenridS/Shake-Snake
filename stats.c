#include <stdlib.h>
#include <time.h>

#include "stats.h"
#include "map.h"
#include "snake.h"

void generate_apple(Map* map_struct, Snake* snake, Stats* stats) {
	if (stats->generated_apple == snake->eaten_apples) {
		srand(time(NULL));

		int apple_row = rand() % 7;
		int apple_column = rand() % 7;

		while (has_conflited(map_struct->map, snake, apple_row, apple_column) == 1) {
			int apple_row = rand() % 7;
			int apple_column = rand() % 7;
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


Stats* create_stats() {
	Stats* stats = calloc(1, sizeof(Stats));

	if (stats == NULL) {
		return NULL;
	}

	stats->generated_apple = 0;

	return stats;
}
