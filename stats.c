#include <stdlib.h>
#include "stats.h";

Stats* create_stats() {
	Stats* stats = calloc(1, sizeof(Stats));

	if (stats == NULL) {
		return NULL;
	}

	stats->generated_apple = 0;

	return stats;
}