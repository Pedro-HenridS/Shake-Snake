#ifndef SNAKE_H
#define SNAKE_H

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
	Directions direction;
	int lenght;

} Snake;

SnakeNode* create_snakenode(SnakeNode* previous);

Snake* create_snake();

void* move_one(Snake* snake);

#endif
