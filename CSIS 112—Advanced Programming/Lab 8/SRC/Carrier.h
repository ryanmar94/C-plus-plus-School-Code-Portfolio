//Carrier.h

//include statments
#pragma once
#include "Ship.h"

class Carrier : public Ship {
	//priavte Carrier variable
private:
	std::string name;
	//public Carrier functions
public:
	//Carrier constructor
	Carrier(std::string n);

	//gets the ships name
	std::string getName() const;

	//sets the ships name
	void setName(std::string n);

	//checks to see if the ship sunk
	bool sunk();
};