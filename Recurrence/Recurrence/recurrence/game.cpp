#include "game.h"

void MainClass::Draw_Main() {
	cout << "." << endl << "." << endl << "." << endl << "." << endl << "." << endl;
	cout << "The Hollow." << endl << "Level: " << player.level << endl << "Experience: " << player.experience << "/" << player.max_exp << endl << "Health: " << player.health << "/" << player.max_health << endl << "MP: " << player.magic_points << "/" << player.max_magic_points << endl << "." << endl;
	cout << "Commands:   " << "Menu   " << "Fight   " << endl;
	cin >> command;
	while (1) {
	if (command == "Menu") {
		Draw_Menu();
		break;
	}
	else if (command == "menu") {
		Draw_Menu();
		break;
	}
	else if (command == "Fight") {
		Draw_Fight();
		break;
	}
	else if (command == "fight") {
		Draw_Fight();
		break;
	}
	else {
		cout << "Please input a command." << endl;
		cin >> command;
	}
}
}

void MainClass::mainsub() {
	player.StartingStats();
	player.Select();
	player.health = player.max_health;
	player.magic_points = player.max_magic_points;
	Draw_Main();
}

void MainClass::Draw_Menu() {
	cout << "WIP" << endl;
}

void MainClass::Draw_Fight() {
	cout << "WIP" << endl;
}