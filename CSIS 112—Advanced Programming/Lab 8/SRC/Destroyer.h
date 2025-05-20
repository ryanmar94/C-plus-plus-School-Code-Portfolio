//Ship.h

//include statements
#pragma once
#include "Ship.h"

class Destroyer : public Ship {
	//private Destroyer 
private:
	std::string name;
	//public Destroyer functions 
public:

	//Destroyer constructor 
	Destroyer(std::string n);

	//gets the ship name
	std::string getName() const;

	//sets the ship name
	void setName(std::string n);

	//checks to see if the ship sunk
	bool sunk();
};