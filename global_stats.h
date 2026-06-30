#pragma once
#ifndef GLOBAL_STATS
#define GLOBAL_STATS

#include "stats.h"

typedef struct MatchHistNode {

	MatchHist* match_hist;
	MatchHist* next_match_hist;

} MatchHistNode;

typedef struct MatchHistList {
	
	MatchHistNode* match_node;
	int total_score;

} MatchHistList;

typedef struct MatchHist {

	int match_score;
	int match_time;

} MatchHist;

typedef struct GlobalStats{
	MatchHistList* match_node;
} GlobalStats;

MatchHist* create_match_hist();
GlobalStats* create_global_stats();

#endif // !GLOBAL_STATS

