//Dog.cpp

//include statements
#include "Dog.h"

using namespace std;

//dog constructor takes in name and weight sets them and sets type to dog
Dog::Dog(string n, int w) : Mammal("Dog", w){
	cout << "Invoking Dog Constructor" << endl;
	setName(n);
}//end of dog constructor

 //gets the name of the dog and returns it
string Dog::getName() const {
	return name;
}//end of getName function

 //takes in the string for the name of the dog and sets it
void Dog::setName(string n) {
	name = n;
}//end of setName function

//speak function that that says the sound the dog makes 
void Dog::speak() {
	cout << "Woof" << endl;
}//end of speak function