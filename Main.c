#include <stdio.h>
#include <windows.h>
#include "map.h"

int main() {
	char** map = create_map();
	print_map(map);

	while (1) {
		printf("\033[2J");

		char** map = create_map();
		print_map(map);

		Sleep(1000);

		printf("\033[H");
	}

	return 0;
}