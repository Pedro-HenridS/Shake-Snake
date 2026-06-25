#ifndef MAP_H
#define MAP_H

#include "snake.h"
#include "stats.h"

typedef struct Map {
	char** map;
} Map;

void print_map(char** map, Snake* snake);
Map* create_map(Snake* snake, Stats* stats);
void generate_apple(Map* map, Snake* snake, Stats* stats);

#endif