//Battleship.h

//include statments
#pragma once
#include "Ship.h"

class Battleship : public Ship{
	//private Battleship variable
private:
	std::string name;
	//public Battleship functions
public:
	//Battleship constructor 
	Battleship(std::string n);

	//gets the name of the ship
	std::string getName() const;

	//sets the name of the ship
	void setName(std::string n);

	//checks to see if the ship sunk
	bool sunk();
};