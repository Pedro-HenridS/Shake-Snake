#include <stdlib.h>
#include <stdio.h>

#include "snake.h"
#include "stats.h"

SnakeNode* create_snakenode() {

	SnakeNode* node = malloc(sizeof(SnakeNode));

	if (node == NULL) {
		return NULL;
	}

	node->x = NULL;
	node->y = NULL;
	node->next = NULL;
	node->previous = NULL;

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
	snake->tail = snake->head;
	snake->last_node_x = 0;
	snake->last_node_y = 0;
	snake->direction = RIGHT;
	snake->eaten_apples = 0;

	return snake;
};

Snake* snake_growth(Snake* snake, int x, int y) {
	SnakeNode* new_node = create_snakenode();
	SnakeNode* last_node = snake->tail;

	if (new_node == NULL) {
		return;
	}

	new_node->next = NULL;
	new_node->previous = snake->tail;
	snake->tail = new_node;

	snake->last_node_x = snake->tail->x;
	snake->last_node_y = snake->tail->y;

	snake->lenght++;

}

void* move_one(Map* map, Snake* snake, Stats* stats) {
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

	snake->last_node_x = snake->tail->x;
	snake->last_node_y = snake->tail->y;

	if (snake->head->x == stats->apple_x && snake->head->y == stats->apple_y) {
		/*printf("COMEU COMEU COMEU COMEU COMEU COMEU COMEU COMEU");*/
		snake_growth(snake, snake->last_node_x, snake->last_node_y);
		snake->eaten_apples++;
		generate_apple(map, snake, stats);
	}

	return NULL;
}


