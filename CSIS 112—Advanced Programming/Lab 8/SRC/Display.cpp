//Display.cpp

//include statment
#include "Display.h"

using namespace std;

//fills the array with ~ to look like water
void Display::fillArray(char a[25][25]) {
	char** field;
	field = new char*[25];
	for (int i = 0; i < 25; i++) {
		field[i] = new char[25];
	}
	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 25; col++) {
			field[row][col] = '~';
		}
	}
	for (int row = 0; row < 25; row++) {
		for (int col = 0; col < 25; col++) {
			a[row][col] = field[row][col];
		}
	}
	
}

//displays game board
void Display::displayField(char a[25][25], char b[25][25]) {
	char letter = 'A';
	cout << "   ";
	for (int i = 0; i < 25; i++) {
		cout << char(letter + i) << "  ";
	}
	cout << "         |             ";
	for (int i = 0; i < 25; i++) {
		cout << char(letter + i) << "  ";
	}
	cout << endl;
	for (int row = 0; row < 25; row++) {

		if (row < 9) {
			cout << " " << row + 1;
		}
		else {
			cout << row + 1;
		}
		for (int col = 0; col < 25; col++) {

			cout << " " << a[row][col] << " ";

		}
		if (row < 9) {
			cout << "          |           " << row + 1;
		}
		else {
			cout << "          |          " << row + 1;
		}
		for (int col = 0; col < 25; col++) {
			cout << " " << b[row][col] << " ";
		}
		cout << endl;
	}
}

//displays single board used in manual ship placement
void Display::playerDisplay(char a[25][25]) {
	char letter = 'A';
	cout << "   ";
	for (int i = 0; i < 25; i++) {
		cout << char(letter + i) << "  ";
	}
	cout << endl;
	for (int row = 0; row < 25; row++) {
		if (row < 9) {
			cout << " " << row + 1;
		}
		else {
			cout << row + 1;
		}
		for (int col = 0; col < 25; col++) {

			cout << " " << a[row][col] << " ";

		}
		cout << endl;
	}
}

//converts char to int
int Display::convertToNum(char letter) {
	int num;
	// if (letter >= 'A' && letter <= 'Y')
	//   num = (int)(letter - 'A')

	if (letter == 'A') {
		num = 0;
	}
	else if (letter == 'B') {
		num = 1;
	}
	else if (letter == 'C') {
		num = 2;
	}
	else if (letter == 'D') {
		num = 3;
	}
	else if (letter == 'E') {
		num = 4;
	}
	else if (letter == 'F') {
		num = 5;
	}
	else if (letter == 'G') {
		num = 6;
	}
	else if (letter == 'H') {
		num = 7;
	}
	else if (letter == 'I') {
		num = 8;
	}
	else if (letter == 'J') {
		num = 9;
	}
	else if (letter == 'K') {
		num = 10;
	}
	else if (letter == 'L') {
		num = 11;
	}
	else if (letter == 'M') {
		num = 12;
	}
	else if (letter == 'N') {
		num = 13;
	}
	else if (letter == 'O') {
		num = 14;
	}
	else if (letter == 'P') {
		num = 15;
	}
	else if (letter == 'Q') {
		num = 16;
	}
	else if (letter == 'R') {
		num = 17;
	}
	else if (letter == 'S') {
		num = 18;
	}
	else if (letter == 'T') {
		num = 19;
	}
	else if (letter == 'U') {
		num = 20;
	}
	else if (letter == 'V') {
		num = 21;
	}
	else if (letter == 'W') {
		num = 22;
	}
	else if (letter == 'X') {
		num = 23;
	}
	else if (letter == 'Y') {
		num = 24;
	}
	return num;
}

//converts int to char
char Display::convertToChar(int num) {

	char letter;

	if (num == 0) {
		letter = 'A';
	}
	else if (num == 1) {
		letter = 'B';
	}
	else if (num == 1) {
		letter = 'B';
	}
	else if (num == 2) {
		letter = 'C';
	}
	else if (num == 3) {
		letter = 'D';
	}
	else if (num == 4) {
		letter = 'E';
	}
	else if (num == 5) {
		letter = 'F';
	}
	else if (num == 6) {
		letter = 'G';
	}
	else if (num == 7) {
		letter = 'H';
	}
	else if (num == 8) {
		letter = 'I';
	}
	else if (num == 9) {
		letter = 'J';
	}
	else if (num == 10) {
		letter = 'K';
	}
	else if (num == 11) {
		letter = 'L';
	}
	else if (num == 12) {
		letter = 'M';
	}
	else if (num == 13) {
		letter = 'N';
	}
	else if (num == 14) {
		letter = 'O';
	}
	else if (num == 15) {
		letter = 'P';
	}
	else if (num == 16) {
		letter = 'Q';
	}
	else if (num == 17) {
		letter = 'R';
	}
	else if (num == 18) {
		letter = 'S';
	}
	else if (num == 19) {
		letter = 'T';
	}
	else if (num == 20) {
		letter = 'U';
	}
	else if (num == 21) {
		letter = 'V';
	}
	else if (num == 22) {
		letter = 'W';
	}
	else if (num == 23) {
		letter = 'X';
	}
	else if (num == 24) {
		letter = 'Y';
	}

	return letter;
}