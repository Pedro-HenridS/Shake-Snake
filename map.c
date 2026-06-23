#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#include "map.h"

#define ROW_LENGHT 7
#define COLUMN_LENGHT 7

void print_map(char** map) {

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

void populate_map(char** map) {

	srand(time(NULL));

	int apple_row = rand() % 7;
	int apple_column = rand() % 7;

	for (int i = 0; i < COLUMN_LENGHT; i++) {
		for (int j = 0; j < ROW_LENGHT; j++) {
			map[i][j] = '.';
		}
	}

	map[apple_row][apple_column] = '#';
}

char** create_map() {
	
	char** map = calloc(COLUMN_LENGHT, sizeof(char*));

	if (map == NULL) {
		return NULL;
	}

	for (int i = 0; i < COLUMN_LENGHT; i++) {
		char* vetor = create_vetor();

		if (vetor == NULL) {
			return NULL;
		}

		map[i] = vetor;
	}

	populate_map(map);

	return map;
}
