#include "stats.h"

void StatStruct::StartingStats() {
	cout << "Enter your character's name." << endl;
	cin >> name;
	stat_points = 40;
	level = 1;
	experience = 0;
	max_exp = 20;
	max_health = 0;
	new_max_health = 0;
	strength = 0;
	new_strength = 0;
	defence = 5;
	speed = 0;
	new_speed = 0;
	magic = 0; 
	new_magic = 0;
	magic_attack = 0;
	magic_defence = 0;
	max_magic_points = 0;
	new_max_mp = 0;
	enemies_killed = 0;
}

void StatStruct::Select() {
	cout << "Select which stat you would like to add to. You have " << stat_points << " stat points." << endl << "1. Max Health." << endl << "2. Max MP." << endl << "3. Strength." << endl << "4. Speed" << endl << "5. Magic." << endl << "6. Check Stats." << endl << "7. Done" << endl;
	cin >> selection;
	while (1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered the wrong input." << endl;
			cin >> selection;
		}
		else if (selection > 7) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered the wrong input." << endl;
			cin >> selection;
		}
		else if (selection < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered the wrong input." << endl;
			cin >> selection;
		}
		else if (selection == 1) {
			Max_Health_Allocation();
		}
		else if (selection == 2) {
			Max_MP_Allocation();
		}
		else if (selection == 3) {
			Strength_Allocation();
		}
		else if (selection == 4) {
			Speed_Allocation();
		}
		else if (selection == 5) {
			Magic_Allocation();
		}
		else if (selection == 6) {
			//Check_Stats();
		}
		else if (selection == 7) {
			//Finish_Allocation();
		}
		if (!cin.fail()) {
			break;
		}
	}
}

void StatStruct::Max_Health_Allocation() {
	if (new_max_health < 1) {
		stat_points = new_max_health + stat_points;
		max_health = max_health - new_max_health;
	}
	new_max_health = 0;
	cout << "Max Health is currently at " << max_health << endl;
	cin >> new_max_health;
	while (1) {
		if (new_max_health > stat_points) {
			cout << "You don't have enough stat points for that. You only have " << stat_points << ". Please try again." << endl;
			cin >> new_max_health;
		} else {
			break;
		}
	}
	stat_points = stat_points - new_max_health;
	max_health = max_health + new_max_health;
	Select();
}

void StatStruct::Max_MP_Allocation() {
	if (new_max_mp < 1) {
		stat_points = new_max_mp + stat_points;
		max_magic_points = max_magic_points - new_max_mp;
	}
	new_max_mp = 0;
	cout << "Max MP is currently at " << max_magic_points << endl;
	cin >> new_max_mp;
	while (1) {
		if (new_max_mp > stat_points) {
			cout << "You don't have enough stat points for that. You only have " << stat_points << ". Please try again." << endl;
			cin >> new_max_mp;
		}
		else {
			break;
		}
	}
	stat_points = stat_points - new_max_mp;
	max_magic_points = max_magic_points + new_max_mp;
	Select();
}

void StatStruct::Strength_Allocation() {
	if (new_strength < 1) {
		stat_points = new_strength + stat_points;
		strength = strength - new_strength;
	}
	new_strength = 0;
	cout << "Strength is currently at " << strength << endl;
	cin >> new_strength;
	while (1) {
		if (new_strength > stat_points) {
			cout << "You don't have enough stat points for that. You only have " << stat_points << ". Please try again." << endl;
			cin >> new_strength;
		}
		else {
			break;
		}
	}
	stat_points = stat_points - new_strength;
	strength = strength + new_strength;
	Select();
}

void StatStruct::Speed_Allocation() {
	if (new_speed < 1) {
		stat_points = new_speed + stat_points;
		speed = speed - new_speed;
	}
	new_speed = 0;
	cout << "Speed is currently at " << speed << endl;
	cin >> new_speed;
	while (1) {
		if (new_speed > stat_points) {
			cout << "You don't have enough stat points for that. You only have " << stat_points << ". Please try again." << endl;
			cin >> new_speed;
		}
		else {
			break;
		}
	}
	stat_points = stat_points - new_speed;
	speed = speed + new_speed;
	Select();
}

void StatStruct::Magic_Allocation() {
	if (new_magic < 1) {
		stat_points = new_speed + stat_points;
		magic_attack = magic_attack - new_magic;
		magic_defence = magic_defence - new_magic;
	}
	new_magic = 0;
	cout << "Magic Attack is currently at " << magic_attack << endl << "Magic Defence is currently at " << magic_defence << endl;
	cin >> new_magic;
	while (1) {
		if (new_magic > stat_points) {
			cout << "You don't have enough stat points for that. You only have " << stat_points << ". Please try again." << endl;
			cin >> new_magic;
		}
		else {
			break;
		}
	} 
	stat_points = stat_points - new_magic;
	magic_attack = magic_attack + new_magic;
	magic_defence = magic_defence + new_magic;
	Select();
}