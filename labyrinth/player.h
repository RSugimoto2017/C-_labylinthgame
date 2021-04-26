#pragma once
//#include "stdafx.h"
#include "InputOut.h"

#include "map.h"

/*

プレイヤーの情報に関するヘッダーファイル

*/

#define X  player.x/2 - MAP_X/2
#define Y  player.y - MAP_Y

Player player;

Player StatusSet() {

	Player player;

	player.HP = getIntFromINI("player", "HP", "%s\\setting.ini", -1);

	player.x = MAP_X + 2;
	player.y = MAP_Y + 1;
	player.score = 0;

	return player;
}

// プレイヤーのキー操作
int Control() {
	//キー受け付け
	int key = getch();

	//ゲーム中断コマンド
	//if (key == 'q') break;

	//カーソル移動
	switch (key) {
	case KEY_UP:
		erase();
		if (map[Y - 1][X] == 0 || map[Y - 1][X] == 2 || map[Y - 1][X] == 3)
			player.y -= 1;
		break;
	case KEY_DOWN:
		erase();
		if (map[Y + 1][X] == 0 || map[Y + 1][X] == 2 || map[Y + 1][X] == 3) {
			player.y += 1;
		}
		break;
	case KEY_LEFT:
		erase();
		if (map[Y][X - 1] == 0 || map[Y][X - 1] == 2 || map[Y][X - 1] == 3) {
			player.x -= 2;
		}
		break;
	case KEY_RIGHT:
		erase();
		if (map[Y][X + 1] == 0 || map[Y][X + 1] == 2 || map[Y][X + 1] == 3) {
			player.x += 2;
		}
		break;
	default:
		refresh();
		break;
	}

	return key;
}