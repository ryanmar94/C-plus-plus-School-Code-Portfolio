//Ship.cpp

//include statements
#include "Ship.h"
#include "Display.h"

using namespace std;

//ship default constructor
Ship::Ship(){}

//ship constructor
Ship::Ship(int s, int h, string t) {
	setSize(s);
	setHits(h);
	setType(t);
}

//ship destructor
Ship::~Ship(){}

//gets the size of a ship
int Ship::getSize() const {
	return size;
}

//sets the size of a ship
void Ship::setSize(int s) {
	size = s;
}

//gets the number of hits on a ship
int Ship::getHits() const {
	return hits;
}

//sets the number of hits on a ship
void Ship::setHits(int h) {
	hits = h;
}

//adds one to the number of hits on a ship
void Ship::setHits() {
	hits++;
}

//gets the type of ship
string Ship::getType() {
	return type;
}

//sets the type of ship
void Ship::setType(std::string t) {
	type = t;
}

//gets the index of a ship in the location vector
Location Ship::getShipLocation(int i) {
	return shipLocation[i];
}

//adds a location to the location vector
void Ship::setShipLocation(Location l) {
	
	shipLocation.push_back(l);
}

//deletes the index of a location in the location vector
void Ship::deleteShipLocation(int i) {
	shipLocation.erase(shipLocation.begin() + i);
}

// gets the name of the ship
string Ship::getName() const {
	return NULL;
}

//this function lets the user manually set their ships
void Ship::placeShips(char a[25][25]) {
	bool done = false;
	bool invalid;
	Display d;
	char firstCord;
	int secondCord;
	char direction;
	Location l;
	int first;
	bool used = true;
	do {
		do {
			invalid = false;
			d.playerDisplay(a);
			cout << "What is the first coordinate that you want to place the " << getType()
				<< "(please enter the letter and then the number separated by a space)" << endl;
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
		first = d.convertToNum(firstCord);
		if (a[secondCord - 1][first] != '#') {
			l.setPointOne(firstCord);
			l.setPointTwo(secondCord);
			setShipLocation(l);
			a[secondCord - 1][first] = '#';
			used = false;
		}
		//lets the user know that a ship already exists at the point they selected
		else if (a[secondCord - 1][first] == '#') {
			cout << "A ship already exists in that location please try a diffrent coordinate!!!\a" << endl;
			system("pause");
			system("cls");
		}
	} while (used == true);
	//sets the rest of the ship baised on location of the first point and the user picks form the options of directions 
	//baised on where the first point is 
	while (!done) {
		//up, down, left, right
		if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, D=Down, L=Left, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'D', 'L', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//down
			else if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);

			}
		}
		//up, down, left
		else if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() >= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, D=Down, L=Left)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'D', 'L');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//down
			else if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//up, down, right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() <= 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, D=Down, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'D', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//down
			else if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//up, left, right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() >= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, L=Left, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'L', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//down, left, right
		else if (secondCord - getSize() <= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (D=Down, L=Left, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'D', 'L', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//down
			if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//down, right
		else if (secondCord - getSize() <= 0 && secondCord + getSize() <= 25 && first - getSize() <= 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (D=Down, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'D', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//down
			if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//up, right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() >= 25 && first - getSize() < 0 && first + getSize() <= 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, R=Right)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'R');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//right
			else if (direction == 'R') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//up, left
		else if (secondCord - getSize() >= 0 && secondCord + getSize() > 25 && first - getSize() >= 0 && first + getSize() > 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (U=up, L=Left)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'U', 'L');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//up
			if (direction == 'U') {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
						d.playerDisplay(a);
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		//down, left
		else if (secondCord - getSize() < 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() > 25) {
			do {
				invalid = false;
				d.playerDisplay(a);
				cout << "Which direction do you want the rest of the ship to face (D=Down, L=Left)" << endl;
				cin >> direction;
				direction = toupper(direction);
				try {
					direction = letterCheck(direction, 'D', 'L');
				}
				catch (const InvalidEntryException& inval) {
					cout << "Exception occurred: "
						<< inval.what() << endl;
					invalid = true;
					system("pause");
					system("cls");
				}
			} while (invalid);
			//down
			if (direction == 'D') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
			//left
			else if (direction == 'L') {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						cout << "There is a ship already in that direction please pick another direction!!\a" << endl;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
				d.playerDisplay(a);
			}
		}
		system("pause");
		system("cls");
	}
}

//this function uses random number generators to randomly set the ships on the board
void Ship::placeEnemyShips(char a[25][25]) {
	bool done = false;
	Display d;
	char firstCord;
	int secondCord;
	int direction;
	Location l;
	int first;
	bool used = true;
	//sets first point of the ship as long as another ship is not already there using random numbers to set the point
	do {
		first = rand() % 25;
		secondCord = (rand() % 25) + 1;
		if (a[secondCord - 1][first] != '#') {
			firstCord = d.convertToChar(first);
			l.setPointOne(firstCord);
			l.setPointTwo(secondCord);
			setShipLocation(l);
			a[secondCord - 1][first] = '#';
			used = false;
		}
	} while (used == true);
	//while loop sets the rest of the ship baised on the first points location 
	while (!done) {
		//up, down, left, right
		if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			direction = rand() % 4;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//down
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 2) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 3) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//up, down, left
		else if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() >= 25) {
			direction = rand() % 3;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//down
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 2) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//up, down right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() <= 25 && first - getSize() <= 0 && first + getSize() <= 25) {
			direction = rand() % 3;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//down
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 2) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//up, left, right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() >= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			direction = rand() % 3;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 2) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//down, left, right
		else if (secondCord - getSize() <= 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() <= 25) {
			direction = rand() % 3;
			//down
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 2) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//down, right
		else if (secondCord - getSize() <= 0 && secondCord + getSize() <= 25 && first - getSize() <= 0 && first + getSize() <= 25) {
			direction = rand() % 2;
			//down
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//up, right
		else if (secondCord - getSize() >= 0 && secondCord + getSize() >= 25 && first - getSize() < 0 && first + getSize() <= 25) {
			direction = rand() % 2;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//right
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first + (1 + i)] != '#') {
						a[secondCord - 1][first + (1 + i)] = '#';
						firstCord = d.convertToChar(first + (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first + (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first + j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//up, left
		else if (secondCord - getSize() >= 0 && secondCord + getSize() > 25 && first - getSize() >= 0 && first + getSize() > 25) {
			direction = rand() % 2;
			//up
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {

					if (a[secondCord - (2 + i)][first] != '#') {
						a[secondCord - (2 + i)][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord - (1 + i));
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - (2 + i)][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - (1 + j)][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
		//down, left
		else if (secondCord - getSize() < 0 && secondCord + getSize() <= 25 && first - getSize() >= 0 && first + getSize() > 25) {
			direction = rand() % 2;
			//down
			if (direction == 0) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord + i][first] != '#') {
						a[secondCord + i][first] = '#';
						firstCord = d.convertToChar(first);
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord + i + 1);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord + i][first] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord + j - 1][first] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
			//left
			else if (direction == 1) {
				for (int i = 0; i < getSize() - 1; i++) {
					if (a[secondCord - 1][first - (1 + i)] != '#') {
						a[secondCord - 1][first - (1 + i)] = '#';
						firstCord = d.convertToChar(first - (1 + i));
						l.setPointOne(firstCord);
						l.setPointTwo(secondCord);
						setShipLocation(l);
						done = true;
					}
					else if (a[secondCord - 1][first - (1 + i)] == '#') {
						done = false;
						for (int j = i; j > 0; j--) {
							a[secondCord - 1][first - j] = '~';
							deleteShipLocation(j);
						}
						break;
					}
				}
			}
		}
	}
}

//polymorphic function checks to see if the ship sunk
bool Ship::sunk() { return NULL; }

//chaecks for invaild entrys other then the chars supplyed when called
char letterCheck(char l, char one, char two, char three, char four) {
	if (l != one && l != two && l != three && l != four) {
		throw InvalidEntryException{}; // terminate function
	}
	return l;
}

//chaecks for invaild entrys other then the chars supplyed when called
char letterCheck(char l, char one, char two, char three) {
	if (l != one && l != two && l != three) {
		throw InvalidEntryException{}; // terminate function
	}
	return l;
}

//chaecks for invaild entrys other then the chars supplyed when called
char letterCheck(char l, char one, char two) {
	if (l != one && l != two) {
		throw InvalidEntryException{}; // terminate function
	}
	return l;
}