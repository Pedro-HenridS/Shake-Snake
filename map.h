#pragma once
#ifndef MAP_H
#define MAP_H

typedef struct Map {
	char** map;
} Map;

void print_map(char** map, struct Snake* snake);
Map* create_map(struct Snake* snake, struct MatchStats* stats);
int has_conflited(char** map, struct Snake* snake, int a_x, int a_y);

#endif
