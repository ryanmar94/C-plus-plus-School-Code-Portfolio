//Battleship.cpp

//include statments
#include "Battleship.h"

using namespace std;

//Battleship constructor
Battleship::Battleship(string n) : Ship(4, 0, "Battleship"){

	setName(n);
}

//gets the ships name
std::string Battleship::getName() const {
	return name;
}

//sets the ships name
void Battleship::setName(string n) {
	name = n;
}

//checks to see if the ship sunk
bool Battleship::sunk() {
	bool shipSunk = false;
	if (getSize() == getHits()) {
		shipSunk = true;
	}
	return shipSunk;
}