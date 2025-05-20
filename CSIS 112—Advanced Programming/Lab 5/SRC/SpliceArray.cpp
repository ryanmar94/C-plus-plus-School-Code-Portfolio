/*Ryan Marcum
CSIS 112-<002>
<Lab_5> This program takes in the size for 2 arrays from the user and the number of elements from the first array 
to be spliced to the the second array using dynamicly allocated memory. the arrays are loaded withe random numbers 
from 1 to 100 and prints out the arrays in rows of 10's. The program also checks for vaild enterys from the user.
*/
//include statements
#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

//Function prototypes
void loadArray(int, int[]);
void printArray(int, int[]);
int* splice(int[], int[], int, int);
bool isValid(double);
bool isValid(double, double);

int main() {
	//inialize variables
	double sizeArray1;       //This variable holds the size of the first array set by the user
	double sizeArray2;       //This variable holds the size of the second array set by the user
	double sizeToBeSpliced;  //This variable is the number of elements to be spliced from the first array to the second set by the user
	int *ptr = NULL;         //this pointer variable will hold the spliced array once created and is inialized to NULL

	//prompts the user for the size of the first array the do while loop continues to run until the user enters in a vaild response
	do {
		cout << "Enter in the size of the first array." << endl;
		cin >> sizeArray1;
	} while (!isValid(sizeArray1));//end of do while
	//prompts the user for the size of the second array the do while loop continues to run until the user enters in a vaild response
	do {
		cout << "Enter in the size of the second array." << endl;
		cin >> sizeArray2;
	} while (!isValid(sizeArray2));//end of do while
	//prompts the user for number of elements from the first array to be spliced to the second array the do while loop 
	//continues to run until the user enters in a vaild response and a value that is equal or less then the number of 
	//elements in the first array 
	do {
		cout << "Enter in the number of elements of the first array to be spliced to the second array." << endl;
		cin >> sizeToBeSpliced;
	} while (!isValid(sizeToBeSpliced, sizeArray1));//end of do while

	//inializes the arrays first and second using dynamic memory allocation with sizes set by the user
	int *first = new int[sizeArray1];
	int *second = new int[sizeArray2];
	//creates the seed for the random number generator and then calls the loadArray function to fill the
	//arrays with a random number between 1 and 100
	srand((unsigned)time(0));
	loadArray(sizeArray1, first);
	loadArray(sizeArray2, second);
	//prints the elements in the first and second arrays
	cout << endl;
	cout << "First Array" << endl;
	printArray(sizeArray1, first);
	cout << endl;
	cout << "Second Array" << endl;
	printArray(sizeArray2, second);
	//calls the splice function passing in the first and second array and the size to be spliced and the size of the second array
	//and saves it into the pointer variable
	ptr = splice(first, second, sizeToBeSpliced, sizeArray2);
	
	//deletes the memory allocated for the first and second array
	delete[] first;
	delete[] second;
	//prints the elements in the pliced array held in the pointer variable
	cout << endl;
	cout << "Spliced Array" << endl;
	printArray(sizeToBeSpliced+sizeArray2, ptr);
	//deletes the memory allocated to the pliced array held in the pointer variable
	delete[] ptr;
	//Closing program statements
	system("pause");
	return 0;
}//end of main

//the loadArray function takes in the size of the array and the array and loads each element with a random number between 1 and 100 
void loadArray(int size, int a[]) {
	//for loop goes through each element in the array and sets it equal to a random number between 1 to 100
	for (int i = 0; i < size; i++) {
		
		a[i] = rand() % 100 + 1;
	}//end for loop
}//end loadArray function

//printArray function takes in the size and an array and prints the elements in an array and creates a new line after every 10 elements
void printArray(int size, int a[]) {
	//for loop prints out each of the elements in an array
	for (int i = 0; i < size; i++) {
		//if statement checks to for every 10th element and if it is creats a new line
		if (i % 10 == 0) {
			cout << endl;
		}//end if statement
		cout << a[i] << " ";
	}//end for loop
	cout << endl;
}//end printArray

//splice function takes in the 2 arrays the size to be spliced from the first array and the size of the secong array
//and splices them together into a new dynamic memory allocated array
int* splice(int f[], int s[], int sizeFirst, int sizeSecond) {
	//inialize variables
	int sizeArray = sizeFirst + sizeSecond; //adds the size to be spliced and the size of the second 
	                                        //array to create the size of the new array
	int *newArray = new int[sizeArray];     //creates a dynamic memory allocated array seting it to the size of the sizeArray variable
	//for loop adds the elements to be spliced from the first array to the second array into newArray
	for (int i = 0; i < sizeArray; i++) {
		//this if statement sets the elements that are being spliced from the first array into newArray
		if (i < sizeFirst) {
			newArray[i] = f[i];
		}//end if statement
		//this else statement adds all of the elements in the second array into newArray
		else {
			newArray[i] = s[i-sizeFirst];
		}//end else statement
	}//end of for loop
	//returns the newArray back to main
	return newArray;
}//end of splice function

//this function take in a vairable and checks to make sure that it is a valid entry
bool isValid(double var)
{
	//initializes variable boolean to true
	bool valid = true;
	//checks for an invailed entry like a non-numeral value
	if (cin.fail()) {
		cout << "Response can not be a letter or symbol please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to see if the variable is a negative number if so sets valid to false
	else if (var < 0) {
		cout << "Response must be a positive number please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to see if the variable is equal to zero if it is sets valid to false
	else if (var == 0) {
		cout << "Response can not be zero please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to make sure the number is an integer
	else if (int(var) != var) {
		cout << "Response must be an integer please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//returns boolean valid true or false back to main
	return valid;
}//end of isValid function

//this function take in a vairable and checks to make sure that it is a valid entry this overloaded function 
//also checks to make sure the user did not enter in a number that is biger then the number of elements in the first array
bool isValid(double var, double var2)
{
	//initializes variable boolean to true
	bool valid = true;
	//checks for an invailed entry like a non-numeral value
	if (cin.fail()) {
		cout << "Response can not be a letter or symbol please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to see if the variable is a negative number if so sets valid to false
	else if (var < 0) {
		cout << "Response must be a positive number please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to see if the variable is equal to zero if it is sets valid to false
	else if (var == 0) {
		cout << "Response can not be zero please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to make sure the number is an integer
	else if (int(var) != var) {
		cout << "Response must be an integer please try again!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//checks to make sure the number entered is not greater then the number of elements in the first array
	else if (var > var2) {
		cout << "Response can not be greater then the number of elements in the first array!!\a" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		valid = false;
	}
	//returns boolean valid true or false back to main
	return valid;
}//end of isValid function
