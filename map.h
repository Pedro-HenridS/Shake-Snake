#ifndef MAP_H
#define MAP_H

typedef struct Snake Snake;
typedef struct Stats Stats;

typedef struct Map {
	char** map;
} Map;

void print_map(char** map, Snake* snake);
Map* create_map(Snake* snake, Stats* stats);

#endif
