#include <stdio.h>
#include <stdlib.h>

#include "global_stats.h"

GlobalStats* create_global_stats() {
	GlobalStats* global_stats = calloc(1, sizeof(GlobalStats));

	if (global_stats == NULL) {
		return NULL;
	}

	
};
