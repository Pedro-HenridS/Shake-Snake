#ifndef MAP_H
#define MAP_H

#include "snake.h"

typedef struct Map {
	char** map;
	int apple_x;
	int apple_y;
} Map;

void print_map(char** map, Snake* snake);
Map* create_map(Snake* snake);

#endif