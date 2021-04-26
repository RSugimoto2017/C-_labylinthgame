#pragma once
//#include "pch.h" 
//#include "stdafx.h"
#include "InputOut.h"
#include "map.h"

/*

敵キャラクターの情報に関するヘッダーファイル

*/

#define Enemy1X enemy1.x/2 - MAP_X/2
#define Enemy1Y enemy1.y - MAP_Y

#define Enemy2X enemy2.x/2 - MAP_X/2
#define Enemy2Y enemy2.y - MAP_Y

#define Enemy3X enemy3.x/2 - MAP_X/2
#define Enemy3Y enemy3.y - MAP_Y

#define Enemy4X enemy4.x/2 - MAP_X/2
#define Enemy4Y enemy4.y - MAP_Y

#define Enemy5X enemy5.x/2 - MAP_X/2
#define Enemy5Y enemy5.y - MAP_Y

int enemyExist[5] = { 0, 0, 0, 0, 0 };

Enemy enemy1;
Enemy enemy2;
Enemy enemy3;
Enemy enemy4;
Enemy enemy5;

int flag;

Enemy StatusSetA(int x, int y) {

	Enemy enemy;

	enemy.Strength = getIntFromINI("enemyA", "Strength", "%s\\setting.ini", -1);

	enemy.x = MAP_X + x * 2;
	enemy.y = MAP_Y + y;
	enemy.enemyType = 1;
	enemy.score = getIntFromINI("enemyA", "score", "%s\\setting.ini", -1);

	return enemy;
}

Enemy StatusSetB(int x, int y) {

	Enemy enemy;

	enemy.Strength = getIntFromINI("enemyB", "Strength", "%s\\setting.ini", -1);

	enemy.x = MAP_X + x * 2;
	enemy.y = MAP_Y + y;
	enemy.enemyType = 2;
	enemy.score = getIntFromINI("enemyB", "score", "%s\\setting.ini", -1);

	return enemy;
}

Enemy StatusSetC(int x, int y) {

	Enemy enemy;

	enemy.Strength = getIntFromINI("enemyC", "Strength", "%s\\setting.ini", -1);

	enemy.x = MAP_X + x * 2;
	enemy.y = MAP_Y + y;
	enemy.enemyType = 3;
	enemy.score = getIntFromINI("enemyC", "score", "%s\\setting.ini", -1);

	return enemy;
}

void enemymove() {

	switch (rand() % 4 + 1) {
	case 1:
		erase();
		if (map[Enemy1Y - 1][Enemy1X] == 0) {
			enemy1.y -= 1;
		}
		break;
	case 2:
		erase();
		if (map[Enemy1Y + 1][Enemy1X] == 0) {
			enemy1.y += 1;
		}
		break;
	case 3:
		erase();
		if (map[Enemy1Y][Enemy1X - 1] == 0) {
			enemy1.x -= 2;
		}
		break;
	case 4:
		erase();
		if (map[Enemy1Y][Enemy1X + 1] == 0) {
			enemy1.x += 2;
		}
		break;
	default:
		break;
	}

	// 戦闘
	if (player.x == enemy1.x && player.y == enemy1.y) {
		player.HP -= enemy1.Strength;
		if (enemy1.Strength == 2) {
			flag = 1;
		}
		else if (enemy1.Strength == 3) {
			flag = 2;
		}
		else if (enemy1.Strength == 5) {
			flag = 3;
		}
		player.score += enemy1.score;
		enemyExist[0] = 0;
	}

}

void enemymove2() {

	switch (rand() % 4 + 1) {
	case 1:
		erase();
		if (map[Enemy2Y - 1][Enemy2X] == 0) {
			enemy2.y -= 1;
		}
		break;
	case 2:
		erase();
		if (map[Enemy2Y + 1][Enemy2X] == 0) {
			enemy2.y += 1;
		}
		break;
	case 3:
		erase();
		if (map[Enemy2Y][Enemy2X - 1] == 0) {
			enemy2.x -= 2;
		}
		break;
	case 4:
		erase();
		if (map[Enemy2Y][Enemy2X + 1] == 0) {
			enemy2.x += 2;
		}
		break;
	default:
		break;
	}

	// 戦闘
	if (player.x == enemy2.x && player.y == enemy2.y) {
		player.HP -= enemy2.Strength;
		if (enemy2.Strength == 2) {
			flag = 1;
		}
		else if (enemy2.Strength == 3) {
			flag = 2;
		}
		else if (enemy2.Strength == 5) {
			flag = 3;
		}
		player.score += enemy2.score;
		enemyExist[1] = 0;
	}

}

void enemymove3() {

	switch (rand() % 4 + 1) {
	case 1:
		erase();
		if (map[Enemy3Y - 1][Enemy3X] == 0) {
			enemy3.y -= 1;
		}
		break;
	case 2:
		erase();
		if (map[Enemy3Y + 1][Enemy3X] == 0) {
			enemy3.y += 1;
		}
		break;
	case 3:
		erase();
		if (map[Enemy3Y][Enemy3X - 1] == 0) {
			enemy3.x -= 2;
		}
		break;
	case 4:
		erase();
		if (map[Enemy3Y][Enemy3X + 1] == 0) {
			enemy3.x += 2;
		}
		break;
	default:
		break;
	}

	// 戦闘
	if (player.x == enemy3.x && player.y == enemy3.y) {
		player.HP -= enemy3.Strength;
		if (enemy3.Strength == 2) {
			flag = 1;
		}
		else if (enemy3.Strength == 3) {
			flag = 2;
		}
		else if (enemy3.Strength == 5) {
			flag = 3;
		}
		player.score += enemy3.score;
		enemyExist[2] = 0;
	}

}

void enemymove4() {

	switch (rand() % 4 + 1) {
	case 1:
		erase();
		if (map[Enemy4Y - 1][Enemy4X] == 0) {
			enemy4.y -= 1;
		}
		break;
	case 2:
		erase();
		if (map[Enemy4Y + 1][Enemy4X] == 0) {
			enemy4.y += 1;
		}
		break;
	case 3:
		erase();
		if (map[Enemy4Y][Enemy4X - 1] == 0) {
			enemy4.x -= 2;
		}
		break;
	case 4:
		erase();
		if (map[Enemy4Y][Enemy4X + 1] == 0) {
			enemy4.x += 2;
		}
		break;
	default:
		break;
	}

	// 戦闘
	if (player.x == enemy4.x && player.y == enemy4.y) {
		player.HP -= enemy4.Strength;
		if (enemy4.Strength == 2) {
			flag = 1;
		}
		else if (enemy4.Strength == 3) {
			flag = 2;
		}
		else if (enemy4.Strength == 5) {
			flag = 3;
		}
		player.score += enemy4.score;
		enemyExist[3] = 0;
	}

}

void enemymove5() {

	switch (rand() % 4 + 1) {
	case 1:
		erase();
		if (map[Enemy5Y - 1][Enemy5X] == 0) {
			enemy5.y -= 1;
		}
		break;
	case 2:
		erase();
		if (map[Enemy5Y + 1][Enemy5X] == 0) {
			enemy5.y += 1;
		}
		break;
	case 3:
		erase();
		if (map[Enemy5Y][Enemy5X - 1] == 0) {
			enemy5.x -= 2;
		}
		break;
	case 4:
		erase();
		if (map[Enemy5Y][Enemy5X + 1] == 0) {
			enemy5.x += 2;
		}
		break;
	default:
		break;
	}

	// 戦闘
	if (player.x == enemy5.x && player.y == enemy5.y) {
		player.HP -= enemy5.Strength;
		if (enemy5.Strength == 2) {
			flag = 1;
		}
		else if (enemy5.Strength == 3) {
			flag = 2;
		}
		else if (enemy5.Strength == 5) {
			flag = 3;
		}
		player.score += enemy5.score;
		enemyExist[4] = 0;
	}

}