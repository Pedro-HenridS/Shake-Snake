#include <stdlib.h>
#include <stdio.h>

#include "snake.h"

SnakeNode* create_snakenode(SnakeNode* previous) {

	SnakeNode* node = malloc(sizeof(SnakeNode));

	if (node == NULL) {
		return NULL;
	}

	node->x = NULL;
	node->y = NULL;
	node->next = NULL;
	node->previous = previous;

	return node;
};

Snake* create_snake() {
	Snake* snake = malloc(sizeof(Snake));

	if (snake == NULL) {
		return NULL;
	}

	SnakeNode* head = create_snakenode(NULL);

	head->x = 0;
	head->y = 0;

	if (head == NULL) {
		return NULL;
	}

	snake->head = head;
	snake->lenght = 0;
	snake->direction = RIGHT;

	return snake;
};

void* move_one(Snake* snake) {
	SnakeNode* snake_node = snake->head;

	switch (snake->direction) {
	case UP:
		if (snake_node->x > 0) {
			snake->head->x--;
		}
		break;

	case DOWN:
		if (snake_node->x < 6) {
			snake->head->x++;
		}
		break;

	case LEFT:
		if (snake_node->y > 0) {
			snake->head->y--;
		}
		break;

	case RIGHT:
		if (snake_node->y < 6) {
			snake->head->y++;
		}
		break;
	}

	return NULL;
}
