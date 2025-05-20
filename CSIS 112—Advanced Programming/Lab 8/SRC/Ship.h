//ship.h

//incude statments
#pragma once
#include "Display.h"
#include "Location.h"
#include "InvalidEntryException.h"
#include <string>
#include <vector>
#include <iostream>

class Ship {
	//ship friend functions
	friend char letterCheck(char l);
	friend int numCheck(int num);
	friend char letterCheck(char l, char one, char two, char three, char four);
	friend char letterCheck(char l, char one, char two, char three);
	friend char letterCheck(char l, char one, char two);

	//ship privat variables
private:
	int size;
	int hits;
	std::string type;
	std::vector <Location> shipLocation;

	//ship public functions
public:

	//ship defualt constructor
	Ship();

	//ship constuctor
	Ship(int s, int h, std::string t);

	//ship destructor
	virtual ~Ship();

	//gets ship size
	int getSize() const;

	//sets ship size
	void setSize(int s);

	//gets ship hits
	int getHits() const;

	//sets ship hits
	void setHits(int h);

	//incruments ship hits by 1
	void setHits();

	//gets type of ship
	std::string getType();

	//sets the type of ship
	void setType(std::string t);

	//gets the location at index i 
	Location getShipLocation(int i);

	//sets the ship location in the location vector
	void setShipLocation(Location l);

	//delets the location at index i
	void deleteShipLocation(int i);

	//gets the name of the ship
	virtual std::string getName() const;

	//this function lets the user manually set their ships
	void placeShips(char a[25][25]);

	//this function uses random number generators to randomly set the ships on the board
	void placeEnemyShips(char a[25][25]);

	//polymorphic function that checks to see if the ship sunk
	virtual bool sunk();
};

//checks to see if an exception has happened
char letterCheck(char l);
//checks to see if an exception has happened
int numCheck(int num);
//checks to see if an exception has happened
char letterCheck(char l, char one, char two, char three, char four);
//checks to see if an exception has happened
char letterCheck(char l, char one, char two, char three);
//checks to see if an exception has happened
char letterCheck(char l, char one, char two);