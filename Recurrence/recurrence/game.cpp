#include "game.h"

void MainClass::Draw_Main() {
	string command;
	while (1) {
		cout << endl << endl  << endl << endl << endl;
		cout << "The Hollow." << endl << "Level: " << player.level << endl << "Experience: " << player.experience << "/" << player.max_exp << endl << "Health: " << player.health << "/" << player.max_health << endl << "MP: " << player.magic_points << "/" << player.max_magic_points << endl << endl;
		cout << "Commands:   Menu   Fight   " << endl;
		getline(cin, command);
		if (Command_Validation(command, "Menu", "menu")) {
			Draw_Menu();
		}
		else if (Command_Validation(command, "Fight", "fight")) {
			Draw_Fight();
		}
		else {
			cout << "You have entered the wrong input." << endl;
		}
	}
}

void MainClass::Draw_StartMenu() {
	string command;
	cout << "Recurrence." << endl << endl << endl << endl << "New Game." << endl << endl << "Load Game." << endl << endl;
	while (true) {
		getline(cin, command);
		if (Command_Validation(command, "New Game", "new game")) {
			cout << endl << endl;
			break;
		}
		else if (Command_Validation(command, "Load Game", "load game")) {
			cout << "Saving not implemented yet, so new game." << endl << endl;
			break;
		}
		else {
			cout << "You have entered the wrong input." << endl;
		}
	}
}

void MainClass::Draw_Menu() {
	string command;
	cout << endl << endl << player.name << "   LVL: " << player.level << "   EXP:   " << player.experience << "/" << player.max_exp << endl << "Health: " << player.health << "/" << player.max_health << endl << "MP: " << player.magic_points << "/" << player.max_magic_points << endl << "Strength: " << player.strength << endl << "Defence: " << player.defence << endl << "Speed: " << player.speed << endl << "Magic Attack / Defence: " << player.magic_attack << "/" << player.magic_defence << endl;
	cout << endl << endl << "Enemies Defeated: " << player.enemies_killed << endl << endl << "Commands:   Back   " << endl;
	while (true) {
		getline(cin, command);
		if (Command_Validation(command, "Back", "back")) {
			break;
		}
		else {
			cout << "You entered the wrong input." << endl;
		}
	}
}

void MainClass::Level_Up() {
	player.stat_points = 10;
	player.experience = player.experience - player.max_exp;
	player.max_exp = player.max_exp + 5;
	player.level = player.level + 1;
	player.Select();
	Draw_Main();
}

void MainClass::Draw_Fight() {
	int levelrand;
	enemy.EnemyStartingStats();
	srand(time(NULL));
	levelrand = (1 + (rand() % 3));
	if (levelrand == 1) {
		enemy.elevel = player.level - 1;
	}
	else if (levelrand == 2) {
		enemy.elevel = player.level;
	}
	else if (levelrand == 3) {
		enemy.elevel = player.level + 1;
	}
	if (enemy.elevel <= 0) {
		enemy.elevel == 1;
	}
	else {
		enemy.elevel = enemy.elevel;
	}
	enemy.Enemy_Spawn();
	while (1) {
		//Created a loop so that it doesn't send the player back to the main screen.
	enemy.ehealth = enemy.emax_health;
	cout << enemy.ename << "   LVL: " << enemy.elevel << endl << endl << "Commands:   Attack   Run   Scan   " << endl;
	if (player.speed > enemy.espeed) {
		//Player_Turn();
	}
	else if (player.speed < enemy.espeed) {
		//Enemy_Turn();
	}
}
}

void MainClass::mainsub() {
	Draw_StartMenu();
	player.StartingStats();
	player.Select();
	player.health = player.max_health;
	player.magic_points = player.max_magic_points;
	Draw_Main();
}