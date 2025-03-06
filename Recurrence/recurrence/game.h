#ifndef GAME_H
#define GAME_H
#include "stats.h"
#include "enemies.h"
#include "validation.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class MainClass {
	StatStruct player;
	Enemies enemy;
	int damage;
	int story_progress;
	string last_turn;

	void Draw_Main();
	void Draw_Menu();
	void Draw_StartMenu();
	void Level_Up();
	void Save();
	void Draw_Fight();
	void Player_Turn();
	void Enemy_Turn();
	void Enemy_Defeated();
	void Game_Over();
	void Fight_Attack();
	void Enemy_Attack();
	void Fight_Run();
	void Enemy_Run();
	void Fight_Scan();
	void Enemy_Scan();
	void Fight_Skills();
	void Enemy_Skills();
	void Magic_Heal();
	void Enemy_Magic_Heal();

public:
	void mainsub();
};

#endif
