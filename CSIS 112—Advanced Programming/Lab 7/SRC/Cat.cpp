//Cat.cpp

//include statements
#include "Cat.h"

using namespace std;

//cat constructor takes in name and weight sets them and sets type to cat
Cat::Cat(string n, int w) : Mammal("Cat", w){
	cout << "Invoking Cat Constructor" << endl;
	setName(n);
}//end of cat constructor

 //gets the name of the cat and returns it
string Cat::getName() const {
	return name;
}//end of getName function

 //takes in the string for the name of the cat and sets it
void Cat::setName(string n) {
	name = n;
}//end of setName function

//speak function that that says the sound the cat makes 
void Cat::speak() {
	cout << "Meow" << endl;
}//end of speak function