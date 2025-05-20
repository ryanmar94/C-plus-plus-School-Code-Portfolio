/*Ryan Marcum
CSIS 112-<002>
<Lab_4> This program uses a menu to let the user decide what they want to do. Starting with loading in testscores from 
a file or typing them in from the keyboard. lets the user sort the vector in ascending order, calculate the average of the
testscores, or print the testscores all from the menu options.
*/

//include statements
#include "TestScores.h"

using namespace std;

//function prototypes
void menu(TestScores);

int main() {
	//initialize variables
	TestScores s;
	TestScores *ptr = &s;
	//menu function call passing a pointer variable of TestScores 
	menu(*ptr);

	//Closing program statements
	system("pause");
	return 0;
}//end main

//menu function that takes in an object of testscores and displays a menu for options the user can
//use in the program
void menu(TestScores score) {
	//initialize variable
	int choice = 0;
	//while loop continues till the user types option 6 to end the program. Also displays the menu options that the
	//user can do.
	while (choice != 6) {

		//displays the menu options
		cout << endl;
		cout << "Test Scores Menu" << endl << endl;
		cout << "1.	Read scores from a file." << endl;
		cout << "2.	Add a score from the keyboard." << endl;
		cout << "3.	Sort the scores." << endl;
		cout << "4.	Compute the average score." << endl;
		cout << "5.	Print the scores to the screen." << endl;
		cout << "6.	Exit the program." << endl;
		cout << "Please pick a item number." << endl;
		cin >> choice;
		cout << endl;

		//switch statement picks the option the user picked from the menu and runs it.
		switch (choice) {
			//case 1 call the readFile function in TestScores class and reads in a file of testscores and adds them to the vector
		case 1: {
			score.readFile();
			break;
		}//end case 1
		//case 2 adds calls the addScore funtion in TestScores class and lets the user type in a testscore to add to the vector
		case 2: {
			score.addScore();
			break;
		}//end case 2
		//case 3 calls the sortVector function in TestScores class that sorts the vector in ascending order 
		case 3: {
			score.sortVector();
			break;
		}//end case 3 calls the computeAverage function in TestScores class that averages the test scores and displays the average
		//case 4 calls compute
		case 4: {
			score.computeAverage();
			break;
		}//end case 4 calls the print function in TestScores class that prints the testscores in the vector
		//case 5
		case 5: {
			score.print();
			break;
		}//end case 5
		//case 6 thanks the user for using the program before the program ends
		case 6: {
			cout << "Thank you for using testscores program!" << endl;
			break;
		}//end case 6
		//default case lets the user know they entered in an invalid option choice
		default: {
			cout << "Invalid input try again!\a" << endl;
			break;
		}//end default case
		}//end switch statement
	}//end while loop
}//end menu function

