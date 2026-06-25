#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "stats.h"

typedef enum Directions {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Directions;

typedef struct SnakeNode {
	int x;
	int y;

	struct SnakeNode* next;
	struct SnakeNode* previous;

} SnakeNode;

typedef struct Snake {
	SnakeNode* head;
	SnakeNode* tail;
	Directions direction;
	int last_node_x;
	int last_node_y;
	int lenght;
	int eaten_apples;

} Snake;

SnakeNode* create_snakenode();

Snake* create_snake();

void* move_one(Map* map, Snake* snake, Stats* stats);

Snake* snake_growth(Snake* snake, int x, int y);

#endif
