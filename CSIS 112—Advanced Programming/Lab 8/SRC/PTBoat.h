//PTBoat.h

//include statement
#pragma once
#include "Ship.h"

class PTBoat : public Ship {
	//private PTBoat variables
private:
	std::string name;

	//public PTBoat functions
public:
	//PTBoat constructor
	PTBoat(std::string n);

	//gets the ship name
	std::string getName() const;

	//sets the ship name
	void setName(std::string n);

	//checks to see if the ship sunk
	bool sunk();
};