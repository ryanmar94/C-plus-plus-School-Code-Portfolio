//Mammal.h

//include statements
#pragma once
#include <iostream>
#include <string>

class Mammal {
	//private data members of the mammal class
private:
	std::string type;
	std::string name;
	int weight;

	//public cass functions of the mammal class
public:
	//default constructor sets the weight to 0
	Mammal();

	//mammal constructor takes in the type of mammal, name, and weight and sets them
	Mammal(std::string t, int w);

	//gets the type of mammal and returns it
	std::string getType() const;

	//takes in the string for type of mammal and sets it 
	void setType(std::string t);

	//gets the name of the mammal and returns it
	virtual std::string getName() const;

	//gets the weight of the mammal and returns it
	int getWeight() const;

	//takes in the int weight for the mammal and sets it
	void setWeight(int w);

	//polymorphic function the will speak corect the type of mammal that is placed in an array of mammals 
	virtual void speak();
};//end of mammal class