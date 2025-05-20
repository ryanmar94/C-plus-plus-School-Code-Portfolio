// Submarine.cpp

//include statment
#include "Submarine.h"

using namespace std;

//Submarine constructor
Submarine::Submarine(string n) : Ship(3, 0, "Submarine"){
	
	setName(n);
}

//gets the name of the ship
std::string Submarine::getName() const {
	return name;
}

//sets the name of the ships
void Submarine::setName(std::string n) {
	name = n;
}

//checks to see if the ship sunk
bool Submarine::sunk() {
	bool shipSunk = false;
	if (getSize() == getHits()) {
		shipSunk = true;
	}
	return shipSunk;
}