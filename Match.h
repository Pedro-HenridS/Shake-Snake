#pragma once
#ifndef MATCH
#define MATCH

typedef struct MatchHist {

	int match_score;
	int match_time;

} MatchHist;

typedef struct MatchHistNode {

	MatchHist* match_hist;
	MatchHist* next_match_hist;

} MatchHistNode;

typedef struct MatchHistList {

	MatchHistNode* match_node;
	MatchHistNode* last_match_node;
	int total_score;

} MatchHistList;


MatchHist* create_match_hist(int score, int time);
MatchHistList* create_match_hist_list();
void add_hist();
void show_hist_node(MatchHist* hist);
void show_hist(MatchHistList* hist);

#endif // !MATCH_HIST
