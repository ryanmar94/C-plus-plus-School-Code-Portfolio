/*Ryan Marcum
CSIS 112-<002>
<Lab_7> This program uses polymorphism to create an array of 5 dynamically created mammals chosin by the user. The user also sets the 
name of each mammal object as there being created. The weight of each mammal is set by a random number generator function.
Then after all 5 mammals are created the program prints out the 5 mammal information then deletes them.
*/

//include statements
#include "Cat.h"
#include "Dog.h"
#include "Horse.h"
#include "Pig.h"

using namespace std;

//function prototypes
int mammalWeight();


int main() {
	//ininitialize varriables
	string name;             //takes in the name of the mammal entered in by the user
	Mammal* mammalArray[5];  //mammal array takes in up to 5 diffrent mammals choosin by the user
	char choice;             //takes in the selection from user of the type of mammal
	int i = 0;               //index and counter variable to keep track of how many mammal have been created
	srand(100);              //seed for random number generator set with a seed of 100
	
	//while loop continues to run untill 5 mammal are succefully created by the user from the selction below
	while(i < 5){
		cout << "Please Choose A Mammal From The List Below To Add To The Array!!!" << endl;
		cout << "1.   Dog." << endl;
		cout << "2.   Cat." << endl;
		cout << "3.   Horse." << endl;
		cout << "4.   Pig." << endl;
		cin >> choice;
		
		 //if the user selects 2 take in a name for the Dog from the user and creates a Dog object
		if (choice == '1')
		{
			//ask user to enter in a name for the dog
			cout << endl << "Please Type In A Name For The Dog." << endl;
			cin >> name;
			cout << endl;
			//creates a dog object dynamically and adds it to the array at the curent index/counter
			mammalArray[i] = new Dog(name, mammalWeight());
			//Increments the index/counter
			i++;
		}//end of if staement
		 //if the user selects 1 take in a name for the Cat from the user and creates a Cat object
		else if (choice == '2') {
			 //ask user to enter in a name for the cat
			 cout << endl << "Please Type In A Name For The Cat." << endl;
			 cin >> name;
			 cout << endl;
			 //creates a cat object dynamically and adds it to the array at the curent index/counter
			 mammalArray[i] = new Cat(name, mammalWeight());
			 //Increments the index/counter
			 i++;
		 }//end of else if statement
		 //if the user selects 3 take in a name for the Horse from the user and creates a Horse object
		else if (choice == '3') {
			//ask user to enter in a name for the horse
			cout << endl << "Please Type In A Name For The Horse." << endl;
			cin >> name;
			cout << endl;
			//creates a horse object dynamically and adds it to the array at the curent index/counter
			mammalArray[i] = new Horse(name, mammalWeight());
			//Increments the index/counter
			i++;
		}//end of else if staement
		 //if the user selects 4 take in a name for the Pig from the user and creates a Pig object
		else if (choice == '4') {
			//ask user to enter in a name for the pig
			cout << endl << "Please Type In A Name For The Pig." << endl;
			cin >> name;
			cout << endl;
			//creates a pig object dynamically and adds it to the array at the curent index/counter
			mammalArray[i] = new Pig(name, mammalWeight());
			//Increments the index/counter
			i++;
		}//end of else if staement
		// catchs if an invailid input has been entered and lets the user know and clears any errors and the cin buffer
		else {
			cout << endl << "Invalid Choice please choose again!!!!\a" << endl << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}//end of else statement
		cout << endl;
		
	}//end of while loop
	cout << endl;
	//for loop prints out the type of mammal, name weight, and what it says at the current index within the array then 
	//deletes the current object at that index 
	for (int i = 0; i < 5; i++) {
		cout << "Type of Mammal: " << mammalArray[i]->getType() << endl;
		cout << "Name:           " << mammalArray[i]->getName() << endl;
		cout << "Weight:         " << mammalArray[i]->getWeight() << endl;
		cout << "Says:           "; mammalArray[i]->speak();
		cout << endl << endl;
		delete mammalArray[i];
	}//end of for loop

	//Closing program statements
	system("pause");
	return 0;
}//end of main

//generates a random number between 0 and 150 and returns it to main to be used as the weight of the mammal
int mammalWeight() {
	return rand() % 150;
}//end of mammalWeight function