//Display.h

//include staments
#pragma once
#include <iostream>

class Display {
	//Display public functions
public:

	//fills the array with ~ to look like water
	void fillArray(char a[25][25]);

	//displays game field
	void displayField(char a[25][25], char b[25][25]);

	//displays a single board used for placeing ship on the board
	void playerDisplay(char a[25][25]);

	//converts char to a int
	int convertToNum(char);

	//converts int to char
	char convertToChar(int);

};