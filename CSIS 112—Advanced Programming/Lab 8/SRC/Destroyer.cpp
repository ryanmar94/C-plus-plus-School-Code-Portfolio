//Destroyer.cpp

//include statement
#include "Destroyer.h"

using namespace std;

//Destroyer constructor
Destroyer::Destroyer(string n) : Ship(3, 0, "Destroyer"){
	setName(n);
}

//gets the ships name
std::string Destroyer::getName() const {
	return name;
}

//sets the ships name
void Destroyer::setName(string n) {
	name = n;
}

//checks to see if the ship sunk
bool Destroyer::sunk() {
	bool shipSunk = false;
	if (getSize() == getHits()) {
		shipSunk = true;
	}
	return shipSunk;
}