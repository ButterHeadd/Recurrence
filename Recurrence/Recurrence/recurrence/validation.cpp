#include "validation.h"

int Integer_Validation(const int& higher, const int& lower) {

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
		if (!isalpha(c)) {
			return false;
		}
	}
	if (stringinput != capital || stringinput != lowercase) {
		return false;
	}
	return true;
}