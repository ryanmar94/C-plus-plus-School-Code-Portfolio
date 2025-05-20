//Pig.h

//include statements
#pragma once
#include "Mammal.h"

class Pig : public Mammal {

private:
	std::string name;
	//public cass functions of the pig class
public:
	//pig constructor takes in name and weight sets them and sets type to pig
	Pig(std::string n, int w);

	//gets the name of the pig and returns it
	std::string getName() const;

	//takes in the string for the name of the pig and sets it
	void setName(std::string n);

	//speak function that that says the sound the pig makes 
	void speak();
};//end of pig class