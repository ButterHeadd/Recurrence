#include "validation.h"

int Integer_Validation(const int& higher, const int& lower) {
	int input;
	while (1) {
		cin >> input;
		if (cin.fail() || input < lower) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "You have entered the wrong input." << endl;
		}
		else {
			break;
		}
	}
	return input;
}

bool String_Validation(const string& stringinput) {
	if (stringinput.empty()) {
		return false;
	} for (char c : stringinput) {
		if (!isalpha(c) && c!= ' ') {
			return false;
		}
	}
	return true;
}

bool Command_Validation(const string& stringinput, const string& capital, const string& lowercase) {
	if (stringinput.empty()) {
		return false;
	} for (char c : stringinput) {
		if (!isalpha(c) && c!= ' ') {
			return false;
		}
	}
	if (stringinput == capital || stringinput == lowercase) {
		return true;
	}
}