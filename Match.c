#include <stdio.h>
#include <stdlib.h>

#include "Match.h"

MatchHist* create_match_hist(int score, int time) {
	MatchHist* match_hist = calloc(1, sizeof(MatchHist));

	if (match_hist == NULL) {
		return NULL;
	}

	match_hist->match_score = score;
	match_hist->match_time = time;

	return match_hist;
};

int calc_total_score(MatchHistList* match_hist_list) {

	int total = 0;

	for(MatchHistNode* match_hist_node = match_hist_list->match_node; match_hist_node->next_match_hist != NULL; match_hist_node = match_hist_node->next_match_hist)
	{
		total += match_hist_node->next_match_hist->match_score;
	}

	return total;
}

MatchHistList* create_match_hist_list() {

	MatchHistList* match_hist_list = calloc(1, sizeof(MatchHistList));

	if (match_hist_list == NULL) {
		return NULL;
	}

	match_hist_list->match_node = NULL;
	match_hist_list->last_match_node = NULL;
	match_hist_list->total_score = 0;

	return match_hist_list;
}

void add_hist(MatchHistList* match_hist_list, MatchHist* match_hist) {

	if (match_hist_list->last_match_node == NULL) {
		match_hist_list->last_match_node = match_hist;
		match_hist_list->match_node = match_hist;

		return;
	}

	match_hist_list->last_match_node->next_match_hist = match_hist;
	match_hist_list->last_match_node = match_hist;
}

void results_header(int counter) {
	printf("======================\n");
	printf("%d. HISTORICO \n", counter);
	printf("======================\n");
}

void show_hist_node(MatchHist* hist) {
	
	printf("SCORE: %d \n", hist->match_score);
	printf("TIME: %d \n", hist->match_time);
	printf("======================\n");
}

void show_hist(MatchHistList* hist) {
	int counter = 1;
	for (MatchHistNode* match_hist_node = hist->match_node; match_hist_node->next_match_hist != NULL; match_hist_node = match_hist_node->next_match_hist)
	{
		results_header(counter);
		show_hist_node(match_hist_node->next_match_hist);

		counter++;
	}
}

