//Cat.h

//include statements
#pragma once
#include "Mammal.h"

class Cat : public Mammal {

private:
	std::string name;

	//public cass functions of the cat class
public:
	//cat constructor takes in name and weight sets them and sets type to cat
	Cat(std::string n, int w);
	
	//gets the name of the cat and returns it
	std::string getName() const;

	//takes in the string for the name of the cat and sets it
	void setName(std::string n);

	//speak function that that says the sound the cat makes 
	void speak();
};//end of cat class