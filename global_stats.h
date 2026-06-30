#pragma once
#ifndef GLOBAL_STATS
#define GLOBAL_STATS

#include "stats.h"
#include "Match.h"


typedef struct GlobalStats{
	MatchHistList* match_node;
} GlobalStats;


GlobalStats* create_global_stats();
int calc_total_score();

#endif // !GLOBAL_STATS

