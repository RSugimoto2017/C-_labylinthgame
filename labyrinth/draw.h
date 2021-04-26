#pragma once

#include <curses.h>
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "screen.h"

/*

画面描写に関するヘッダーファイル

*/

// タイトル画面の表示
void DrawTitle() {

	Scr_start();
	mvaddstr(25, 30, "STAGE SELECT : Press 1(easy) Press2(normal) Press3(hard)");
}


//　ゲームオーバー画面の表示
void DrawGameover() {
	Scr_gameover();
	mvaddstr(25, 40, "qボタンを押すとタイトルに戻ります。");
}

// ゲームクリア画面の表示
void DrawGameclear() {
	Scr_gameclear();
	mvaddstr(25, 40, "qボタンを押すとタイトルに戻ります。");
	mvaddstr(26, 40, "wボタンを押すとゲームを終了します。");
}


//　ステータス表示
void DrawStatus(int playerHP) {
	for (int i = 0; i < playerHP; i++) {
		addstr("■");
	}
}

// マップの描写関数
void DrawMap() {
	for (int y = 0; y < MAP_H; y++) {
		for (int x = 0; x < MAP_W; x++) {
			if (map[y][x] == 1) {
				mvaddstr(MAP_Y + y, MAP_X + x * 2, "■");
			}
			else if (map[y][x] == 3) {
				attrset(COLOR_PAIR(4));
				mvaddstr(MAP_Y + y, MAP_X + x * 2, "＄");
				attrset(0);
			}
		}
	}
}

// タイトル等の描写関数
void DrawAscii() {
	for (int y = 0; y < ASCII_H; y++) {
		for (int x = 0; x < ASCII_W; x++) {
			if (scr[y][x] == 1) {
				mvaddstr(ASCII_Y + y, ASCII_X + x * 2, "■");
			}
		}
	}
}

//  ゲーム画面の表示
void DrawAll() {
	// 画面をクリア
	erase();

	// 画面の描写
	DrawMap();
	attrset(COLOR_PAIR(1));			// 色1 を使う
	mvaddstr(player.y, player.x, "●");
	attrset(0);

	mvaddstr(24, 6, "Dialog :");
	mvaddstr(2, 38 * 2, "Player HP ");
	attrset(COLOR_PAIR(2));
	DrawStatus(player.HP);

	attrset(COLOR_PAIR(0));
	mvaddstr(4, 38 * 2, "―――――――――――――――");
	mvaddstr(6, 43 * 2, "INFORMATION");

	attrset(COLOR_PAIR(1));
	mvaddstr(8, 38 * 2, "●");
	attrset(COLOR_PAIR(0));
	mvaddstr(8, 39 * 2, "：Player");
	attrset(COLOR_PAIR(3));
	mvaddstr(10, 38 * 2, "●");
	attrset(COLOR_PAIR(4));
	mvaddstr(12, 38 * 2, "●");
	attrset(COLOR_PAIR(5));
	mvaddstr(14, 38 * 2, "●");
	attrset(COLOR_PAIR(0));
	mvaddstr(10, 39 * 2, "：EnemyA　attack 2");
	mvaddstr(12, 39 * 2, "：EnemyB　attack 3");
	mvaddstr(14, 39 * 2, "：EnemyC　attack 5");

	attrset(COLOR_PAIR(0));
	mvaddstr(16, 39 * 2, "　↑　");
	mvaddstr(17, 39 * 2, "←　→　Move Player");
	mvaddstr(18, 39 * 2, "　↓　");

	mvaddstr(20, 39 * 2, "Avoid the enemies,");
	mvaddstr(22, 39 * 2, "and escape the Labyrinth.");
	mvprintw(24, 39 * 2, "score : %d" , player.score);

	mvaddstr(20, 33 * 2, "GOAL");
	if (enemyExist[0] == 1) {
		if (enemy1.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy1.y, enemy1.x, "●");
		}
		else if (enemy1.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy1.y, enemy1.x, "●");
		}
		else if (enemy1.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy1.y, enemy1.x, "●");
		}
	}

	if (enemyExist[1] == 1) {
		if (enemy2.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy2.y, enemy2.x, "●");
		}
		else if (enemy2.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy2.y, enemy2.x, "●");
		}
		else if (enemy2.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy2.y, enemy2.x, "●");
		}
	}

	if (enemyExist[2] == 1) {
		if (enemy3.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy3.y, enemy3.x, "●");
		}
		else if (enemy3.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy3.y, enemy3.x, "●");
		}
		else if (enemy3.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy3.y, enemy3.x, "●");
		}
	}

	if (enemyExist[3] == 1) {
		if (enemy4.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy4.y, enemy4.x, "●");
		}
		else if (enemy4.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy4.y, enemy4.x, "●");
		}
		else if (enemy4.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy4.y, enemy4.x, "●");
		}
	}

	if (enemyExist[4] == 1) {
		if (enemy5.enemyType == 1) {
			attrset(COLOR_PAIR(3));
			mvaddstr(enemy5.y, enemy5.x, "●");
		}
		else if (enemy5.enemyType == 2) {
			attrset(COLOR_PAIR(4));
			mvaddstr(enemy5.y, enemy5.x, "●");
		}
		else if (enemy5.enemyType == 3) {
			attrset(COLOR_PAIR(5));
			mvaddstr(enemy5.y, enemy5.x, "●");
		}
	}

	attrset(0);

	mvaddstr(24, 6, "Dialog :");
	attrset(0);

	if (player.HP <= 0) {
		mvaddstr(24, 14, "【 You died... Press AnyKey! 】");
		flag = 0;
	}
	else if (flag == 1) {
		mvprintw(24, 14, "【 プレイヤーは2ダメージ受けた! 】");
	}
	else if (flag == 2) {
		mvprintw(24, 14, "【 プレイヤーは3ダメージ受けた! 】");
	}
	else if (flag == 3) {
		mvprintw(24, 14, "【 プレイヤーは5ダメージ受けた! 】");
	}

	refresh();
}