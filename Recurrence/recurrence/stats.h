#ifndef STATS_H
#define STATS_H
#include "validation.h"
#include <iostream>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

struct StatStruct {
	int selection, new_max_health, new_strength, new_speed, new_magic, new_max_mp;
	string name;
	int level;
	int experience;
	int max_exp;
	int stat_points;
	int max_health;
	int health;
	int strength;
	int defence;
	int speed;
	int magic;
	int magic_attack;
	int magic_defence;
	int max_magic_points;
	int magic_points;
	int enemies_killed;

	void StartingStats();
	void Select();
	void Max_Health_Allocation();
	void Max_MP_Allocation();
	void Strength_Allocation();
	void Speed_Allocation();
	void Magic_Allocation();
	void Check_Stats();
	int Finish_Allocation();
};

#endif