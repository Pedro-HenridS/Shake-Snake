#include <stdlib.h>
#include <stdio.h>

#include "snake.h"
#include "map.h"
#include "stats.h"

SnakeNode* create_snakenode() {

	SnakeNode* node = malloc(sizeof(SnakeNode));

	if (node == NULL) {
		return NULL;
	}

	node->x = 0;
	node->y = 0;
	node->next = NULL;
	node->previous = NULL;

	return node;
};

Snake* create_snake() {
	Snake* snake = malloc(sizeof(Snake));

	if (snake == NULL) {
		return NULL;
	}

	SnakeNode* head = create_snakenode();

	if (head == NULL) {
		return NULL;
	}

	head->x = 0;
	head->y = 0;

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

	if (new_node == NULL) {
		return snake;
	}

	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	new_node->previous = snake->tail;
	snake->tail->next = new_node;
	snake->tail = new_node;

	snake->lenght++;

	return snake;
}

int crossed_border(Snake* snake, int c_x, int c_y) {

	for (SnakeNode* snake_node = snake->head->next; snake_node != NULL; snake_node = snake_node->next) {
		if (snake_node->x == c_x && snake_node->y == c_y) {
			return 1;
		}
	}

	return 0;
}

void* move_one(Map* map, Snake* snake, GameStats* stats) {
	SnakeNode* snake_node = snake->head;
	int previous_x = snake->head->x;
	int previous_y = snake->head->y;
	int moved = 0;

	switch (snake->direction) {
	case UP:
		if (snake_node->x > 0) {

			if (crossed_border(snake, snake->head->x-1, snake->head->y) == 1) {
				stats->ended = 1;
				return;
			}
			snake->head->x--;
			moved = 1;
		}
		else {
			stats->ended = 1;
			return;
		}
		break;

	case DOWN:
		if (snake_node->x < 6) {

			if (crossed_border(snake, snake->head->x + 1, snake->head->y) == 1) {
				stats->ended = 1;
				return;
			}

			snake->head->x++;
			moved = 1;
		}
		else {
			stats->ended = 1;
			return;
		}

		break;

	case LEFT:
		if (snake_node->y > 0) {
			if (crossed_border(snake, snake->head->x, snake->head->y - 1) == 1) {
				stats->ended = 1;
				return;
			}

			snake->head->y--;
			moved = 1;
		}
		else {
			stats->ended = 1;
			return;
		}

		break;

	case RIGHT:
		if (snake_node->y < 6) {
			if (crossed_border(snake, snake->head->x, snake->head->y+1) == 1) {
				stats->ended = 1;
				return;
			}
			snake->head->y++;
			moved = 1;
		}
		else {
			stats->ended = 1;
			return;
		}

		break;
	}

	if (!moved) {
		return NULL;
	}

	for (snake_node = snake->head->next; snake_node != NULL; snake_node = snake_node->next) {
		int current_x = snake_node->x;
		int current_y = snake_node->y;

		snake_node->x = previous_x;
		snake_node->y = previous_y;

		previous_x = current_x;
		previous_y = current_y;
	}

	snake->last_node_x = previous_x;
	snake->last_node_y = previous_y;

	if (snake->head->x == stats->apple_x && snake->head->y == stats->apple_y) {
		snake->eaten_apples++;
		snake_growth(snake, snake->last_node_x, snake->last_node_y);
		generate_apple(map, snake, stats);
	}

	return NULL;
}


