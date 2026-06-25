#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "map.h"
#include "snake.h"
#include "stats.h"

#define ROW_LENGHT 7
#define COLUMN_LENGHT 7

void set_snake_on_map(char** map, Snake* snake) {

	SnakeNode* snake_node = snake->head;

	for (int c = 0; snake_node != NULL; c++) {
		int column = snake_node->x;
		int row = snake_node->y;

		if (c == 0) {
			map[column][row] = '@';
		}
		else {
			map[column][row] = '0';
		}

		snake_node = snake_node->next;
	}
}

void print_map(char** map, Snake* snake) {

	for (int i = 0; i < COLUMN_LENGHT; i++) {
		for (int j = 0; j < ROW_LENGHT; j++) {

			char cell = map[i][j];

			printf("%c", cell);
		}

		printf("\n");
	}
}

char* create_vetor() {

	char* vetor = calloc(ROW_LENGHT, sizeof(char));

	if (vetor == NULL) {
		return NULL;
	}

	return vetor;
}

int has_conflited(char** map, Snake* snake, int a_x, int a_y) {

	SnakeNode* snake_node = snake->head;


	for (int c = 0; snake_node != NULL; c++) {
		int column = snake_node->x;
		int row = snake_node->y;

		if (column == a_x && row == a_y) {
			return 1;
		}

		snake_node = snake_node->next;
	}

	return 0;
}

void populate_map(Map* map_struct, Snake* snake, Stats* stats) {

	for (int i = 0; i < COLUMN_LENGHT; i++) {
		for (int j = 0; j < ROW_LENGHT; j++) {
			map_struct->map[i][j] = '.';
		}
	}

	generate_apple(map_struct, snake, stats);

	set_snake_on_map(map_struct->map, snake);
}

void generate_apple(Map* map_struct, Snake* snake, Stats* stats) {
	if (stats->generated_apple == snake->eaten_apples) {
		srand(time(NULL));

		int apple_row = rand() % 7;
		int apple_column = rand() % 7;

		while (has_conflited(map_struct->map, snake, apple_row, apple_column) == 1) {
			int apple_row = rand() % 7;
			int apple_column = rand() % 7;
		}

		
		stats->apple_x = apple_row;
		stats->apple_y = apple_column;

		map_struct->map[stats->apple_x][stats->apple_y] = '#';

		stats->generated_apple++;
	}
	else {
		map_struct->map[stats->apple_x][stats->apple_y] = '#';
	}
}



Map* create_map(Snake* snake, Stats* stats) {
	
	Map* map_struct = calloc(1, sizeof(Map));

	if (map_struct == NULL) {
		return NULL;
	}

	char** map = calloc(COLUMN_LENGHT, sizeof(char*));

	if (map == NULL) {
		return NULL;
	}

	map_struct->map = map;

	for (int i = 0; i < COLUMN_LENGHT; i++) {
		char* vetor = create_vetor();

		if (vetor == NULL) {
			return NULL;
		}

		map[i] = vetor;
	}

	
	populate_map(map_struct, snake, stats);

	return map_struct;
}


