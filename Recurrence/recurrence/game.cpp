#include "game.h"

void MainClass::Draw_Main() {
	string command;
	while(1) {
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
			Draw_Main();
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
	cout << "The Hollow is now level " << player.level << "!" << endl;
	player.Select();
}

void MainClass::Draw_Fight() {
	int levelrand;
	string last_turn = "None.";
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
	enemy.ehealth = enemy.emax_health;
	while (1) {
		//Created a loop so that it doesn't send the player back to the main screen.
		if (enemy.ehealth <= 0) {
			Enemy_Defeated();
			break;
		}
		else if (player.health <= 0) {
			Game_Over();
			break;
		}
		else {
			cout << enemy.ename << "   LVL: " << enemy.elevel << "   HP: " << enemy.ehealth << "/" << enemy.emax_health << endl << endl;
			if (last_turn == "None.") {
				if (player.speed > enemy.espeed) {
					last_turn = "Player.";
					Player_Turn();
				}
				else if (player.speed < enemy.espeed) {
					last_turn = "Enemy.";
					Enemy_Turn();
				}
			}
			else {
				if (last_turn == "Enemy.") {
					last_turn = "Player.";
					Player_Turn();
				}
				else if (last_turn == "Player.") {
					last_turn = "Enemy.";
					Enemy_Turn();
				}
			}
		}
	}
}

void MainClass::Player_Turn() {
	string command;
	cout << "Your turn." << endl << "Commands:   Attack   Run   Scan   " << endl << "HP: " << player.health << "/" << player.max_health << "   MP: " << player.magic_points << "/" << player.max_magic_points << endl;
	while (true) {
		getline(cin, command);
		if (Command_Validation(command, "Attack", "attack")) {
			Fight_Attack();
			break;
		}
		else if (Command_Validation(command, "Scan", "scan")) {
			Fight_Scan();
			break;
		}
		else if (Command_Validation(command, "Run", "run")) {
			Fight_Run();
			break;
		}
		else if (Command_Validation(command, "Skills", "Skills")) {
			Fight_Skills();
			break;
		}
		else {
			cout << "You entered the wrong input." << endl;
		}
	}
}

void MainClass::Enemy_Turn() {
	//Need to create ai for the enemies as they'll all have different patterns
	//Maybe make it so a function returns multiple probabilities? idk
	cout << enemy.ename << "'s turn." << endl;
	Enemy_Attack();
}

void MainClass::Enemy_Defeated() {
	int levelrand;
	string command;
	player.experience = player.experience + enemy.exp_gain;
	player.enemies_killed = player.enemies_killed + 1;
	cout << enemy.ename << " has been defeated!" << endl << "You have gained " << enemy.exp_gain << " experience." << endl;
	enemy.EnemyStartingStats();
	player.health = player.max_health;
	if (player.experience >= player.max_exp) {
		Level_Up();
	} 
	cout << "Next battle?" << endl << "Commands: " << "   Next" << "   Back" << endl;
	while (true) {
		getline(cin, command);
		if (Command_Validation(command, "Next", "next")) {
			Draw_Fight();
			break;
		}
		else if (Command_Validation(command, "Back", "back")) {
			break;
		} 
		else {
			cout << "You entered the wrong command." << endl;
		}
	}

}

void MainClass::Fight_Attack() {
	damage = (100 * player.strength) / (enemy.edefence + 100);
	enemy.ehealth = enemy.ehealth - damage;
	cout << "You did " << damage << "  damage." << endl << endl;
	damage = 0;
}

void MainClass::Enemy_Attack() {
	damage = (100 * enemy.estrength) / (player.defence + 100);
	player.health = player.health - damage;
	cout << enemy.ename << " did " << damage << " damage." << endl << endl;
	damage = 0;
}

void MainClass::Fight_Scan() {
	cout << "MP: " << enemy.emax_magic_points << "/" << enemy.emagic_points << endl << "Strength: " << enemy.estrength << endl << "Defence: " << enemy.edefence << endl << "Speed: " << enemy.espeed << endl << "Magic: " << enemy.emagic_attack << "/" << enemy.emagic_defence << endl;
}

void MainClass::Fight_Run() {
	int run;
	srand(time(NULL));
	run = 1 + rand() % (2);
	if (run == 2) {
		player.health = player.max_health;
		cout << "You got away safely!" << endl;
		Draw_Main();
	}
	else if (run == 1) {
		cout << "You tripped, and failed to get away." << endl;
	}
}

void MainClass::Fight_Skills() {
	string skillchoice;
	cout << "1. Heal" << endl;
	while (true) {
		getline(cin, skillchoice);
		if (Command_Validation(skillchoice, "Heal", "heal")) {
			Magic_Heal();
			break;
		}
		else {
			cout << "Please choose a spell." << endl;
		}
	}
}

void MainClass::Magic_Heal() {
	float healamount;
	healamount = round(0.75 * player.magic_attack);
	player.health = player.health + healamount;
	if (player.health > player.max_health) {
		player.health = player.max_health;
	}
}

void MainClass::Game_Over() {
	cout << "You have been defeated." << endl;
	player.health = player.max_health;
}

void MainClass::mainsub() {
	Draw_StartMenu();
	player.StartingStats();
	player.Select();
	player.health = player.max_health;
	player.magic_points = player.max_magic_points;
	Draw_Main();
}