#ifndef ENEMIES_H
#define ENEMIES_H
#include "stats.h"
#include "items.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Enemies {
public:
	StatStruct enemystats;
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
	void Zombie();
	void Haunted_Armour();
	void Arachnid();
	int Enemy_Spawn();
	void Enemy_Reset();
};

#endif
