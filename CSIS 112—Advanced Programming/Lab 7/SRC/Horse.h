//Horse.h

//include statements
#pragma once
#include "Mammal.h"

class Horse : public Mammal {

private:
	std::string name;

	//public cass functions of the horse class
public:
	//horse constructor takes in name and weight sets them and sets type to horse
	Horse(std::string n, int w);

	//gets the name of the horse and returns it
	std::string getName() const;

	//takes in the string for the name of the horse and sets it
	void setName(std::string n);

	//speak function that that says the sound the horse makes 
	void speak();
};//end of horse class