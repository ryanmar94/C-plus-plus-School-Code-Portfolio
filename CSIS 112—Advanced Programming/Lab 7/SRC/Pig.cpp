//Pig.cpp

//include statements
#include "Pig.h"

using namespace std;

//pig constructor takes in name and weight sets them and sets type to pig
Pig::Pig(string n, int w) : Mammal("Pig", w){
	cout << "Invoking Pig Constructor" << endl;
	setName(n);
}//end of pig constructor

 //gets the name of the pig and returns it
string Pig::getName() const {
	return name;
}//end of getName function

 //takes in the string for the name of the pig and sets it
void Pig::setName(string n) {
	name = n;
}//end of setName function

//speak function that that says the sound the pig makes 
void Pig::speak() {
	cout << "Oink" << endl;
}//end of speak function