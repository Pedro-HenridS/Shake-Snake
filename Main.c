#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "map.h"
#include "snake.h"
#include "keyboard.h"

#define TICK 200

int main() {

	Snake* snake = create_snake();
	char** map = create_map(snake);

	print_map(map, snake);

	DWORD lastTick = GetTickCount64();

	while (1) {
		detect_key(snake);

		DWORD now = GetTickCount64();

		if (now - lastTick >= TICK) {
			system("cls");

			move_one(snake);
			char** map = create_map(snake);
			print_map(map, snake);

			lastTick = now;
		}

		DWORD nowNow = GetTickCount64();
		Sleep(1);
	}

	return 0;
}