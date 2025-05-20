//Mammal.cpp

//include statements
#include "Mammal.h"
using namespace std;

//default constructor sets the weight to 0
Mammal::Mammal() : Mammal("type",  0) {
	cout << "Invoking Mammal Default Constructor" << endl;

}// end of default constructor

//mammal constructor takes in the type of mammal and weight and sets them
Mammal::Mammal(string t, int w){
	cout << "Invoking Mammal Constructor" << endl;
	setType(t);
	setWeight(w);
}// end of constructor

//gets the type of mammal and returns it
string Mammal::getType() const {
	return type;
}//end of getType function

//takes in the string for type of mammal and sets it 
void Mammal::setType(string t) {
	type = t;
}//end of setType function

 //polymorphic function to get the names from the derived classes returns null
string Mammal::getName() const {
	return NULL;
}//end of getName function

//gets the weight of the mammal and returns it
int Mammal::getWeight() const{
	return weight;
}//end of getWeight function

//takes in the int weight for the mammal and sets it
void Mammal::setWeight(int w) {
	weight = w;
}//end of setWeight function

//polymorphic function the will speak corect the type of mammal that is placed in an array of mammals
void Mammal::speak() {
	cout << "Mammal is speaking" << endl;
}//end of speak function