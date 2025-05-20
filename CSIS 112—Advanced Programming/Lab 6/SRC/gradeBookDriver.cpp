/*Ryan Marcum
CSIS 112-<002>
<Lab_3> This program creates a gradebook with students. the user sets the name of the gradebook and can add up 
to 3 students with up to 5 grades for each student and displays it. using menu options to add students and 
display them.
*/

//include statements
#include "GradeBook.h"

using namespace std;

//function prototypes
void menu(GradeBook);

int main() {
	//ininitialize varriables
	string name;
	//askes the user to enter in a name for the gradebook
	cout << "Plaese enter in a name for the gradebook." << endl;
	cin >> name;
	//creates an object of the gradebook and passes it the name entered in by the user
	GradeBook g {name};
	//calls the menu function and passes it the gradebook object
	menu(g);

	//Closing program statements
	system("pause");
	return 0;
}//end of main

//this function is a menu that lets the user add students to the gradebook or display 
//student in the gradebook
void menu(GradeBook g) {
	//initialize variable
	char choice = ' ';
	//while loop continues until the user enters in a Q to quit and displays the menu
	while (choice != 'Q') {
		//asks the user what they want to do in the gradebook
		cout << endl;
		cout << g.getGradeBookName() << " Gradebook Menu" << endl;
		cout << "A. Add student" << endl;
		cout << "L. List students in gradebook" << endl;
		cout << "Q. Quit program" << endl;
		cout << "Please enter in a letter choice: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
		choice = toupper(choice);
		cout << endl;
		//switch statement takes in the choice from the menu that the user picked and activates 
		//the function from the gradebook class that the user picked from the menu
		switch (choice)
		{
		//this case calls the addStudent function in the GradeBook class
		case 'A':
		{
			g.addStudent();
			break;
		}
		//this case calls the showGrades function and sortStudents function in the GradeBook class 
		case 'L':
		{
			g.sortStudents();
			g.showGrades();
			break;
		}
		//this case quits the program
		case 'Q':
		{
			cout << "Exiting Gradebook." << endl << endl;
			break;
		}
		//default case lets the user know that they hit an invalid letter choice
		default:
		{
			cout << "Invalid input try again.\a" << endl;
			break;
		}
		}//end of switch statement
	}//end while
}//end of menu function