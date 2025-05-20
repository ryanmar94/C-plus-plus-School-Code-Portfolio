//Horse.cpp

//include statements
#include "Horse.h"

using namespace std;

//horse constructor takes in name and weight sets them and sets type to horse
Horse::Horse(string n, int w) : Mammal("Horse", w) {
	cout << "Invoking Horse Constructor" << endl;
	setName(n);
}//end of horse constructor

 //gets the name of the horse and returns it
string Horse::getName() const {
	return name;
}//end of getName function

 //takes in the string for the name of the horse and sets it
void Horse::setName(string n) {
	name = n;
}//end of setName function

//speak function that that says the sound the horse makes
void Horse::speak() {
	cout << "I'm Mr. Ed" << endl;
}//end of speak function