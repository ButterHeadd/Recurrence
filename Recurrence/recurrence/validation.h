#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>

using namespace std;

int Integer_Validation(const int& higher, const int& lower);
bool String_Validation(const string& stringinput);
bool Command_Validation(const string& stringinput, const string& capital, const string& lowercase);

#endif
