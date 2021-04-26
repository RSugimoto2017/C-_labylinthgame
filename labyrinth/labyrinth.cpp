// labyrinth.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"
#include <iostream>

#include "stdafx.h"
#include <curses.h>
#include <stdlib.h>
#include <vector>
#include <random>
#include <future>

#include "InputOut.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "screen.h"
#include "draw.h"

// 関数のプロトタイプ宣言
void play_loop();
void titleSet();

// グローバル変数定義
bool title = true;
bool playing = true;
bool CLEAR = false;
int Mapflag;

int main()
{

	if (initscr() == NULL) {	//初期化
		return 1;
	}

START:
	erase();
	playing = true;
	title = true;

	// 色の準備
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);


	//特殊キーの受け付け準備
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);

	//TITLE:
	while (title) {

		// タイトル画面の表示と選んだキーによる初期設定
		titleSet();

	}


	//GAME:
	auto th_game = std::thread([] {play_loop(); });
	std::mt19937 mt;
	std::uniform_real_distribution<double> ud(0.0, 1.0);

	while (true) {

		DrawAll();
		Control();		// キー操作

		if (map[Y][X] == 3) {
			map[Y][X] = 0;
			player.score += 1000;

		}

						//　ゲームクリアテスト
		if (map[Y][X] == 2) {
			CLEAR = true;
			Output("score.txt", player.score);
			break;
		}

		// 簡易的にゲームオーバーテスト
		if (player.HP <= 0) {

			playing = false;
			th_game.join();

			erase();
			DrawGameover();
			Output("score.txt", player.score);

			while (1) {
				int key2 = getch();
				if (key2 == 'q') {
					goto START;
				}
			}
		}

	}

	playing = false;
	th_game.join();

	//CLEAR:
	if (CLEAR == true) {
		erase();
		DrawGameclear();

		while (1) {
			int key = getch();
			if (key == 'q') {
				CLEAR = false;
				goto START;
			}
			else if (key == 'w') {
				break;
			}
		}
	}

	endwin();

	return 0;
}



void play_loop() {
	while (playing) {
		if (enemyExist[0] == 1) {
			enemymove();
		}
		if (enemyExist[1] == 1) {
			enemymove2();
		}
		if (enemyExist[2] == 1) {
			enemymove3();
		}
		if (enemyExist[3] == 1) {
			enemymove4();
		}
		if (enemyExist[4] == 1) {
			enemymove5();
		}

		DrawAll();
		std::this_thread::sleep_for(std::chrono::milliseconds(70));
	}
}

void titleSet() {
	//初期化
	Mapflag = 0;
	DrawTitle();
	

	//キー受け付け
	int key = getch();

	switch (key) {
	case '1':
		MapChange1();
		title = false;
		Mapflag = 1;

		//ステータスのセット
		player = StatusSet();
		enemy1 = StatusSetA(28, 18);
		enemy2 = StatusSetA(28, 1);
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 0;
		enemyExist[3] = 0;
		enemyExist[4] = 0;
		break;

	case '2':
		MapChange2();
		title = false;
		Mapflag = 2;

		//ステータスのセット
		player = StatusSet();
		enemy1 = StatusSetB(28, 18);
		enemy2 = StatusSetB(28, 1);
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 0;
		enemyExist[3] = 0;
		enemyExist[4] = 0;
		break;

	case '3':
		MapChange3();
		title = false;
		Mapflag = 3;

		//ステータスのセット
		player = StatusSet();
		enemy1 = StatusSetC(28, 18);
		enemy2 = StatusSetC(28, 1);
		enemy3 = StatusSetB(2, 18);
		enemyExist[0] = 1;
		enemyExist[1] = 1;
		enemyExist[2] = 1;
		enemyExist[3] = 0;
		enemyExist[4] = 0;
		break;

	default:
		refresh();
		break;

	}
}