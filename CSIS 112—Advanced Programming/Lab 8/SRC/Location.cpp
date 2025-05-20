//ShipLocation.cpp

//include statement
#include "Location.h"

using namespace std;

//Location default constructor
Location::Location(){}

//Location constructor
Location::Location(char one, int two) {
	setPointOne(one);
	setPointTwo(two);
}

//gets the first point
char Location::getPointOne() const {
	return pointOne;
}

//sets the first point
void Location::setPointOne(char one) {
	pointOne = one;
}

//gets the second point
int Location::getPointTwo() const {
	return pointTwo;
}

//sets the second point
void Location::setPointTwo(int two) {
	pointTwo = two;
}

//overloaded operator cout for displaying the information of the location
std::ostream& operator<<(std::ostream& output, Location& l)
{
	
	output << l.getPointOne() << ", " << l.getPointTwo();

	//returns the output
	return output;
}//end of overloaded << operator