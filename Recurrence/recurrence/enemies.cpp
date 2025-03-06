#include "enemies.h"

void Enemies::EnemyStartingStats() {
	ename = "Null";
	elevel = 1;
	emax_health = 0;
	ehealth = 0;
	emax_magic_points = 0;
	emagic_points = 0;
	estrength = 0;
	edefence = 0;
	espeed = 0;
	emagic_attack = 0;
	emagic_defence = 0;
	exp_gain = 0;
}

void Enemies::Zombie() {
	elevel--;
	ename = "Zombie";
	emax_health = 8 + (elevel * 2);
	emax_magic_points = 0;
	estrength = 12 + (elevel * 4);
	edefence = round(5 + (elevel * 1.5));
	espeed = round(5 + (elevel * 1.1));
	emagic_attack = 0;
	emagic_defence = round(5 + (elevel * 1.5));
	srand(time(NULL));
	exp_gain = 3 + rand() % (2 - 6) + (elevel * 3);
	elevel++;
}

void Enemies::Haunted_Armour() {
	elevel--;
	ename = "Haunted Armour";
	emax_health = 8 + (elevel * 2);
	emax_magic_points = 0;
	estrength = 5 + (elevel * 2);
	edefence = 12 + (elevel * 4);
	espeed = 8 + (elevel * 1);
	emagic_attack = 0;
	emagic_defence = round(5 + (elevel * 1.5));
	srand(time(NULL));
	exp_gain = 3 + rand() % (2 - 6) + (elevel * 3);
	elevel++;
}

void Enemies::Arachnid() {
	elevel--;
	ename = "Arachnid";
	emax_health = round(5 + (elevel * 1.1));
	emax_magic_points = 0;
	estrength = 6 + (elevel * 2);
	edefence = round(4 + (elevel * 1.1));
	espeed = 12 * (elevel * 4);
	emagic_attack = 0;
	emagic_defence = round(5 + (elevel * 1.5));
	srand(time(NULL));
	exp_gain = 3 + rand() % (2 - 6) + (elevel * 3);
	elevel++;
}

int Enemies::Enemy_Spawn() {
	srand(time(NULL));
	int encounter = 1 + (rand() % 3);
	if (encounter == 1) {
		Zombie();
		return 0;
	}
	else if (encounter == 2) {
		Haunted_Armour();
		return 0;
	}
	else if (encounter == 3) {
		Arachnid();
		return 0;
	}
}