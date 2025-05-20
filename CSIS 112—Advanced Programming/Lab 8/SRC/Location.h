//Location.h

//include statments 
#pragma once
#include<iostream>

class Location {
	//Location class friend functions]
	friend std::ostream& operator<<(std::ostream&, Location&);
	//private Location class variables
private:
	char pointOne;
	int pointTwo;
	//public Loction class functions
public:

	//Location default constructor 
	Location();

	//Location constructor
	Location(char one, int two);

	//gets the first point
	char getPointOne() const;

	//sets the second point
	void setPointOne(char one);

	//gets point two
	int getPointTwo() const;

	//sets point two
	void setPointTwo(int two);
};

//overloaded operator cout for displaying the information of the location
std::ostream& operator<<(std::ostream& output, Location&);