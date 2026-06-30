#include <stdio.h>
#include <stdlib.h>

#include "global_stats.h"

MatchHistList* create_match_hist_list() {
	MatchHistList* match_hist_list = calloc(1, sizeof(MatchHistList));

	if (match_hist_list == NULL) {
		return NULL;
	}

	match_hist_list->total_score = 0;

	return match_hist_list;
}

MatchHist* create_match_hist() {
	MatchHist* match_hist = calloc(1, sizeof(MatchHist));

	if (match_hist == NULL) {
		return NULL;
	}

	match_hist->match_score = 0;
	match_hist->match_time = 0;

	return match_hist;
};

GlobalStats* create_global_stats() {
	GlobalStats* global_stats = calloc(1, sizeof(GlobalStats));

	if (global_stats == NULL) {
		return NULL;
	}

	
};