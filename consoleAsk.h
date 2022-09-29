#ifndef CONSOLEASK_H
#define CONSOLEASK_H

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

void ResetCin() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif CONSOLEASK_H