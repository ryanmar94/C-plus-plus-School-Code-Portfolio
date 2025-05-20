/*Ryan Marcum
CSIS 112 - <002>
<Lab_8> This program is a text basied game of Battleship
*/

//include statments
#include <array>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
#include <array>
#include "Location.h"
#include "Wave.h"
#include "Display.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Destroyer.h"
#include "PTBoat.h"
#include "Submarine.h"
#include "InvalidEntryException.h"
#pragma comment(lib, "Winmm.lib")

using namespace std;

//function prototypes
void playBattleship(char a [25][25], char b [25][25], Ship *s [5], Ship *se[5]);
template<typename T>
bool gameover(T *s [5]);
bool shipHit(Ship *s[5], char f, int sec);
string shipType(Ship *s[5], char f, int sec);
bool shipSunk(Ship *s[5], string type);
int numCheck(int num);
char letterCheck(char l);
char choiceCheck(char l);

int main() {

	//initialized variables
	Display d;
	char field1 [25][25];
	char field2 [25][25];
	Ship* playerShips[5];
	Ship* enemyShips[5];
	Wave general("generalQuarters.wav");
	char choice;
	bool invalid;

	//creates ships and add them to an array of ships
	playerShips[0] = new Carrier ("USS Kittyhawk");
	playerShips[1] = new Battleship ("USS Beowulf");
	playerShips[2] = new Destroyer ("USS Monterrey");
	playerShips[3] = new Submarine ("USS Seawolf");
	playerShips[4] = new PTBoat ("USS Astra");
	enemyShips[0] = new Carrier ("");
	enemyShips[1] = new Battleship ("");
	enemyShips[2] = new Destroyer ("");
	enemyShips[3] = new Submarine ("");
	enemyShips[4] = new PTBoat ("");

	//fillarray fills the fields with ~ "water"
	d.fillArray(field1);
	d.fillArray(field2);

	//lets the user decide if they want to manually set the ships or auto generate the ships
	cout << "Welcome to Battleship" << endl;
	do {
		invalid = false;
		cout << "Would you like to Manual set your ships or Auto generated ship (M = manual and A = Auto)" << endl;
		cin >> choice;
		choice = toupper(choice);
		try {
			choice = choiceCheck(choice);
		}
		catch (const InvalidEntryException& inval) {
			cout << "Exception occurred: "
				<< inval.what() << endl;
			invalid = true;
			system("pause");
			system("cls");
		}
	} while (invalid);
	if (choice == 'M') {
		for (int i = 0; i < 5; i++) {
			playerShips[i]->placeShips(field1);
		}
	}
	srand(time(0));
	if (choice == 'A') {
		for (int i = 0; i < 5; i++) {
			playerShips[i]->placeEnemyShips(field1);
		}
	}
	//sets the enemy ships on the board
	for (int i = 0; i < 5; i++) {
		enemyShips[i]->placeEnemyShips(field2);
	}

	//plays sound 
	general.play(0);
	//calls the play battleship function
	playBattleship(field1, field2, playerShips, enemyShips);

	//Closing program statements
	system("pause");
	return 0;
}

//playBattle ship is the turn basied portion of the code each person takes a turn to try and hit the oppsing sides ships
//the computer uses random numbers to try to find a ship then once a ship is found will make random hits around where it 
//hit the ship to sink it
void playBattleship(char a[25][25], char b[25][25], Ship *s[5], Ship *se[5]) {
	//initialized variables
	Display d;
	bool comHit = false;
	bool used;
	bool invalid;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	char firstCord;
	int secondCord;
	int first;
	char tempFirst;
	int tempSec;
	char tempF;
	int tempS;
	int direction;
	int index = 0;
	string type;
	Location l;
	array<Location, 625> playerMoves;
	vector<Location> comMoves;
	Wave hit("soundEffectsExplosion.wav");
	Wave miss("waterSplash.wav");

	//while loop keeps looping till ethier player loses all thier ships
	while (true) {
		//player turn
		do {
			invalid = false;
			d.displayField(a, b);
			cout << "Enter in a coordinate you want to attack (letter first then number)" << endl;
			cin >> firstCord >> secondCord;

			firstCord = toupper(firstCord);
			try {
				firstCord = letterCheck(firstCord);
				secondCord = numCheck(secondCord);
			}
			catch (const InvalidEntryException& inval) {
				cout << "Exception occurred: "
					<< inval.what() << endl;
				invalid = true;
				system("pause");
				system("cls");
			}
		} while (invalid);
		//checks for a hit
		if (shipHit(se, firstCord, secondCord)) {
			first = d.convertToNum(firstCord);
			b[secondCord - 1][first] = 'H';
			system("cls");
			d.displayField(a, b);
			l.setPointOne(firstCord);
			l.setPointTwo(secondCord);
			playerMoves[index] = l;
			index++;
			cout << "You got a hit at point " << l << "!" << endl;
			hit.play(0);
		}
		//if the player misses
		else {
			first = d.convertToNum(firstCord);
			b[secondCord - 1][first] = 'M';
			system("cls");
			d.displayField(a, b);
			l.setPointOne(firstCord);
			l.setPointTwo(secondCord);
			playerMoves[index] = l;
			index++;
			cout << "You missed at point " << l << "!"<< endl;
			miss.play(0);
		}
		//checks to see if the enemy ships have all sunk
		if (gameover(se)) {
			cout << "All enemy ships sunk" << endl;
			cout << "You win congratulations Admiral!!!" << endl;
			break;
		}
		system("pause");
		system("cls");
		
		//enemey turn
		d.displayField(a, b);
		//if statments runs everyturn till the computer gets a het
		if (comHit == false) {
			do {
				used = false;
				first = rand() % 25;
				secondCord = rand() % 25 + 1;
				firstCord = d.convertToChar(first);
				for (int i = 0; i < comMoves.size(); i++) {
					if (comMoves.at(i).getPointOne() == firstCord && comMoves.at(i).getPointTwo() == secondCord) {
						used = true;
					}
				}
			} while (used == true);
			//checks for a hit
			if (shipHit(s, firstCord, secondCord)) {
				first = d.convertToNum(firstCord);
				a[secondCord - 1][first] = 'H';
				system("cls");
				d.displayField(a, b);
				l.setPointOne(firstCord);
				l.setPointTwo(secondCord);
				cout << "Computer got a hit at " << l << "!!!" << endl;
				hit.play(0);
				comMoves.push_back(l);
				tempFirst = firstCord;
				tempF = firstCord;
				tempSec = secondCord;
				tempS = secondCord;
				type = shipType(s, firstCord, secondCord);
				comHit = true;
			}
			//if computer misses
			else {
				first = d.convertToNum(firstCord);
				a[secondCord - 1][first] = 'M';
				system("cls");
				l.setPointOne(firstCord);
				l.setPointTwo(secondCord);
				comMoves.push_back(l);
				d.displayField(a, b);
				cout << "Computer missed at " << l << "!!!" << endl;
				miss.play(0);
			}
		}
		//if computer got a hit find the rest of the ship
		else {
			up = false;
			down = false;
			left = false;
			right = false;
			do {
				used = false;
				direction = rand() % 4;
				if (up == true && down == true && left == true && right == true) {
					tempFirst = tempF;
					tempSec = tempS;
					up = false;
					down = false;
					left = false;
					right = false;
				}
				//up
				else if (direction == 0) {
					if (tempSec -1 > 0) {
						firstCord = tempFirst;
						secondCord = tempSec - 1;
						up = true;
					}
					else { 
						used = true;
						up = true;
					}
				}
				//down
				else if (direction == 1) {
					if (tempSec + 1 <= 25) {
						firstCord = tempFirst;
						secondCord = tempSec + 1;
						down = true;
					}
					else { 
						used = true; 
						down = true;
					}
				}
				//left
				else if (direction == 2) {
					first = d.convertToNum(tempFirst);
					if (first - 1 >= 0) {
						firstCord = d.convertToChar(first - 1);
						secondCord = tempSec;
						left = true;
					}
					else { 
						used = true;
						left = true;
					}
				}
				//right
				else if (direction == 3) {
					first = d.convertToNum(tempFirst);
					if (first + 1 < 25) {
						firstCord = d.convertToChar(first + 1);
						secondCord = tempSec;
						right = true;
					}
					else {
						used = true; 
						right = true;
					}
				}
				for (int i = 0; i < comMoves.size(); i++) {
					if (comMoves.at(i).getPointOne() == firstCord && comMoves.at(i).getPointTwo() == secondCord) {
						used = true;
					}
				}
			} while (used == true);
			//hit
			if (shipHit(s, firstCord, secondCord)) {
				first = d.convertToNum(firstCord);
				a[secondCord - 1][first] = 'H';
				system("cls");
				d.displayField(a, b);
				l.setPointOne(firstCord);
				l.setPointTwo(secondCord);
				cout << "Computer got a hit at " << l << "!!!" << endl;
				tempFirst = firstCord;
				tempSec = secondCord;
				comMoves.push_back(l);
				hit.play(0);
				if (shipSunk(s, type)) {
					comHit = false;
				}
			}
			//miss
			else {
				first = d.convertToNum(firstCord);
				a[secondCord - 1][first] = 'M';
				system("cls");
				d.displayField(a, b);
				l.setPointOne(firstCord);
				l.setPointTwo(secondCord);
				comMoves.push_back(l);
				cout << "Computer missed at " << l << "!!!" << endl;
				miss.play(0);
			}
		}
		//checks to see if computer won
		if (gameover(s)) {
			cout << "All of your ships sunk you lose!!!" << endl;
			cout << "Gameover!!!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

//checks to see if all ships have been sunk
template<typename T>
bool gameover(T *s[5]) {
	bool end = false;
	int numSunk = 0;
	for (int i = 0; i < 5; i++) {
		if (s[i]->sunk()) {
			numSunk++;
		}
	}
	if (numSunk == 5) {
		end = true;
	}
	return end;
}

//checks to see if you or the computer got a hit
bool shipHit(Ship *s[5], char f, int sec) {
	bool hit = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s[i]->getSize(); j++) {
			if (s[i]->getShipLocation(j).getPointOne() == f && s[i]->getShipLocation(j).getPointTwo() == sec) {
				s[i]->setHits();
				hit = true;
			}
		}
	}
	return hit;
}

//returns the ship type used for computer hit code
string shipType(Ship *s[5], char f, int sec) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s[i]->getSize(); j++) {
			if (s[i]->getShipLocation(j).getPointOne() == f && s[i]->getShipLocation(j).getPointTwo() == sec) {
				return s[i]->getType();
			}
		}
	}
}

//checks to see if the ship sunk used in computer hit code
bool shipSunk(Ship *s[5], string type) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < s[i]->getSize(); j++) {
			if (s[i]->getType() == type) {
				return s[i]->sunk();
			}
		}
	}
}

//invaled entry check
int numCheck(int num) {
	if (num < 1 || num > 25) {
		throw InvalidEntryException{}; // terminate function
	}
	return num;
}

//invaled entry check
char letterCheck(char l) {
	if (l < 'A' || l > 'Y') {
		throw InvalidEntryException{}; // terminate function
	}
	return l;
}

//invaled entry check
char choiceCheck(char l) {
	if (l != 'M' && l != 'A') {
		throw InvalidEntryException{}; // terminate function
	}
	return l;
}