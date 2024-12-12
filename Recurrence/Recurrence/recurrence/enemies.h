#ifndef ENEMIES_H
#define ENEMIES_H
#include "items.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Enemies {
public:
	string ename;
	int emax_health;
	int ehealth;
	int emax_magic_points;
	int emagic_points;
	int estrength;
	int edefence;
	int espeed;
	int exp_gain;
	int elevel;
	int emagic_attack;
	int emagic_defence;

	void EnemyStartingStats();
	void Zombie();
	void Haunted_Armour();
	void Arachnid();
	int Enemy_Spawn();
};

#endif
