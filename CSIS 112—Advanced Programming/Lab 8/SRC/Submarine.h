//ship.h

//include statments
#pragma once
#include "Ship.h"

class Submarine : public Ship {
	//private Submarine class variable
private:
	std::string name;
	//Public Submarine class functions
public:

	//Submarine constructor
	Submarine(std::string n);

	//gets the name of the ship
	std::string getName() const;

	//sets the name of the ship
	void setName(std::string n);

	//checks to see if the ship has sunk
	bool sunk();
};