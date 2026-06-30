#include "keyboard.h"
#include "snake.h"

void detect_key(Snake* snake) {
	if (_kbhit()) {
		int key = _getch();

		if (key == 0 || key == 224) {
			key = _getch();
		}

		switch (key) {
		case 72:
			snake->direction = UP;
			//printf("CIMA \n");
			break;

		case 80:
			snake->direction = DOWN;
			//printf("BAIXO \n");
			break;

		case 75:
			snake->direction = LEFT;
			//printf("ESQUERDA \n");
			break;

		case 77:
			snake->direction = RIGHT;
			//printf("DIREITA \n");
			break;

		default:
			snake->direction = snake->direction;
			break;
		}
	}
}
int detect_enter() {
	if (_kbhit()) {
		int key = _getch();

		if (key == 0 || key == 224) {
			key = _getch();
		}

		switch (key) {
		case 13:
			return 1;
			break;
		
		default:
			return 0;
			break;
		}
	}
}