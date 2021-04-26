#pragma once

struct Player {		//プレイヤーの構造体データ
	int HP;
	int x;
	int y;
	int score;
};

struct Enemy {		//敵キャラクターの構造体データ
	int HP;
	int Speed;
	int Strength;
	int x;
	int y;
	int enemyType;
	int score;
};

/*void makeP();
void makeE();

void makeP() {
Player p;

p.HP = 0;
};

void makeE() {
Enemy e;

e.HP = 0;
e.Speed = 0;
e.Strength = 0;
};*/