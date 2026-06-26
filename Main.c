#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "map.h"
#include "snake.h"
#include "keyboard.h"
#include "stats.h"

#define TICK 500

int main() {

	Snake* snake = create_snake();
	Stats* stats = create_stats();
	Map* map = create_map(snake, stats);

	print_map(map->map, snake);

	DWORD lastTick = GetTickCount64();

	while (stats->ended == 0) {
		detect_key(snake);

		DWORD now = GetTickCount64();

		if (now - lastTick >= TICK) {
			system("cls");

			move_one(map, snake, stats);

			if (stats->ended == 1) {
				break;
			}

			Map* map = create_map(snake, stats);
			print_map(map->map, snake);

			lastTick = now;
		}

		DWORD nowNow = GetTickCount64();
		Sleep(10);
	}

	printf("[ GAME OVER ]");
	Sleep(1000000000);

	return 0;
}
