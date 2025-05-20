//PTBoat.cpp

//include statments
#include "PTBoat.h"

using namespace std;

//PTBoat constructor
PTBoat::PTBoat(string n) : Ship(2, 0, "PT Boat") {

	setName(n);
}

//gets the ships name
std::string PTBoat::getName() const {
	return name;
}

//sets the name of the ship
void PTBoat::setName(string n) {
	name = n;
}

//checks to see if the ship sunk
bool PTBoat::sunk() {
	bool shipSunk = false;
	if (getSize() == getHits()) {
		shipSunk = true;
	}
	return shipSunk;
}
