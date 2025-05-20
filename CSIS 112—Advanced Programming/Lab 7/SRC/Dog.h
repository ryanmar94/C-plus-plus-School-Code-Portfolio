//Dog.h

//include statements
#pragma once
#include "Mammal.h"

class Dog : public Mammal {

private:
	std::string name;

	//public cass functions of the dog class
public:
	//dog constructor takes in name and weight sets them and sets type to dog
	Dog(std::string n, int w);

	//gets the name of the dog and returns it
	std::string getName() const;

	//takes in the string for the name of the dog and sets it
	void setName(std::string n);

	//speak function that that says the sound the dog makes 
	void speak();
};//end of dog class