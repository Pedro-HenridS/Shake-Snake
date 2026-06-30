#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "game_options.h"
#include "snake.h"
#include "stats.h"
#include "map.h"
#include "Match.h"
#include "keyboard.h"

#define TICK 500

void* init_game(MatchHistList* hist_list){

	Snake* snake = create_snake();
	MatchStats* stats = create_stats();
	Map* map = create_map(snake, stats);
	MatchHist* match_hist = create_match_hist_list();

	DWORD lastTick = GetTickCount64();

	print_map(map->map, snake);

	while (1) {
		detect_key(snake);

		if (stats->ended == 0) {
			DWORD now = GetTickCount64();

			if (now - lastTick >= TICK) {
				system("cls");

				move_one(map, snake, stats);

				if (stats->ended == 1) {
					match_hist->match_score = snake->eaten_apples;
					// Por enquanto, não conto o tempo
					match_hist->match_time = 0;

					if (hist_list != NULL) {
						add_hist(hist_list, match_hist);
					}

					break;
				}

				Map* map = create_map(snake, stats);
				print_map(map->map, snake);

				lastTick = now;
			}

			DWORD nowNow = GetTickCount64();
			Sleep(10);
		}
	}

	return NULL;
}

void* game_menu() {
	MatchHistList* hist_list = create_match_hist_list();

	while (1) {
		printf("1. Jogar \n");
		printf("2. Ver historico \n");
		printf("3. Sair \n");

		int opt;
		scanf_s("%d", &opt);

		if (opt == 1) {
			void* result = init_game(hist_list);
		}
		if (opt == 2) {
			show_hist(hist_list);

			int enter_pressed = 0;

			while (enter_pressed != 1) {
				enter_pressed = detect_enter();
			}
		}
		if(opt==3) {
			break;
		}
	}
};