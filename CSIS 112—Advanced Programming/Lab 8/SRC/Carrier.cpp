//Carrier.cpp

//include statments
#include "Carrier.h"

using namespace std;

//Carrier constructor
Carrier::Carrier(string n) : Ship(5, 0, "Aircraft Carrier") {
	setName(n);
}

//gets the ships name
std::string Carrier::getName() const {
	return name;
}

//sets the ships name
void Carrier::setName(string n) {
	name = n;
}

//checks to see if the ship sunk
bool Carrier::sunk() {
	bool shipSunk = false;
	if (getSize() == getHits()) {
		shipSunk = true;
	}
	return shipSunk;
}