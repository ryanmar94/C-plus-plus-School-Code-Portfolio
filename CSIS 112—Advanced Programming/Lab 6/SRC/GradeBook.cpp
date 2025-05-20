//GradeBook.cpp

//include statments
#include "GradeBook.h"

using namespace std;

//GradeBook constructor takes in the name of the gradebook and sets it as the name
GradeBook::GradeBook(string name) {
	setGradeBookName(name);
}//end of GradeBook constructor

//GradeBook destructor
GradeBook::~GradeBook(){}
//gets the name of the gradebook

string GradeBook::getGradeBookName() const {
	return gradeBookName;
}//end of GetGradeBookName function

//sets the name of the gradebook
void GradeBook::setGradeBookName(string name) {
	gradeBookName = name;
}//end of setGradeBookName function

//gets the student at index i
StudentGradeInfo GradeBook::getStudents(int i) const{
	return students.at(i);
}//end of getStudents function

//sets the studentGradeinfo object into the vector
void GradeBook::setStudents(StudentGradeInfo s) {
	students.push_back(s);
}//end of setStudents function

//sets the studentGradeInfo object into the vector at index i
void GradeBook::setStudents(StudentGradeInfo s, int i) {
	students.at(i) = s;
}//end of setStudents function

//this function takes in information from the user to create a studentGradeInfo object
//and then calls the setStudent function to place it in the studentGradeInfo vector.
//Only 3 students are able to be created.
void GradeBook::addStudent() {
	//initialize variables
	string name;
	string id;
	string program;
	double grade = 0;
	bool isUsed{ false };

	//checks to make sure there are less then 3 students in the vector
	//if so then the user can create a student objcet
	if (students.size() < 3) {
		//requests the name of the student uses getline to allow the user to enter 
		//a first and last name in if wanted
		cout << "What is the students name?" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
		StudentGradeInfo s(name);
		cout << endl;
		//do while loop continues to run until the user enters in a student id that is not already used
		do {
			//sets the isUsed boolean to false and then asks the user to enter in a studentID
			isUsed = false;
			cout << "What is the students ID?" << endl;
			getline(cin, id);
			s.setStudentID(id);
			//if satement checks to see if there are any students in the vector 
			if (students.size() > 0) {
				//for loop goes through each student in the vector
				for (int i = 0; i < students.size(); i++) {
					//if statment checks to see if the curent studentGradeinfo being created is equal to the
					//studentGradeInfo at index i are equal if they are it lets the user know that that studentID variable
					//aready exists and sets the booloean to true
					if (s == getStudents(i)) {
						isUsed = true;
						cout << "That Student ID Is Already Used In The Gradebook Please Try Again!!!!!\a" << endl << endl;
					}//end of if 
				}//end of for loop
			}//end of if statment
		} while (isUsed);//end of do while loop
		//asks the user for the major that the student is studying
		cout << endl;
		cout << "What is the students major?" << endl;
		getline(cin, program);
		s.setMajor(program);
		cout << endl;
	
		//the for loop lets the user enter up to 5 grades for the student. The user can type 
		//-1 to stop entering in grades if they do not need to enter in 5 grades then sets the remaining 
		//points in the array to -1
		cout << "Enter up to 5 grades for " << s.getStudentName() << "." << endl;
		for (int i = 0; i < 5; i++) {
			//allows a user to enter in grades up to 5 unless -1 is entered to exit and the grade can only be from 0 to 100
			if (grade != -1) {
				do {
					cout << "Enter in a grade number " << i + 1 << "(type -1 to stop entering grades): ";
					cin >> grade;
					//checks to see if the grade is over 100 or negative except for -1 
					if (grade < -1 || grade > 100) {
						cout << "Grade can not be negative or greater then 100 please try again!!!\a" << endl;
					}
				} while (grade < -1 || grade > 100);//end do while loop
				//calls the setGrades from student and passes it the grade and index to place it in
				s.setGrades(grade, i);
			}//end of if statement
			else {
				//calls the setGrades from student and passes it the grade and index to place it in
				//and sets it to -1
				s.setGrades(grade, i);
			}//end of else statement
		}//end for loop
		//once student name and grades have been entered places the student object into the student vector
		setStudents(s);
	}//end of if statement
	//lets the user know that the gradebook is full
	else {
		cout << "Gradebook is full can not add anymore students!\a" << endl;
	}//end of else statment
}//end of addStudent function

//this function displays the students info and grades in the student vector
void GradeBook::showGrades() {
	//calls the empty constructor of the student class
	StudentGradeInfo s;
	//checks to make sure that there is a student in the student vector and if so 
	//displays all students in the vector
	if (students.size() >= 1) {
		//this for loop goes through each student in the vector and calls the overloaded operator displaying info for
		//each student
		for (int i = 0; i < students.size(); i++) {
			//gets the student at index i and places it in the student object
			s = getStudents(i);
			cout << s;
		}//end for loop
	}//end of if statement
	//lets the user know that there are curently no students in the student vector
	else
		cout << "The gradebook currently contains no students please add a student to list!!!\a" << endl;
}//end of showGrades function

//sorts the students in accending order by there student id
void GradeBook::sortStudents() {
	//checks to make sure that there is a student in the vector
	if (students.size() >= 1) {
		//creates a boolean variable found and sets it to true
		bool found{ true };
		//while loop continues to run until all the studnets in the vector are in accending order by there studentID
		while (found) {
			found = false;
			//for loop goes through each of the students in the vector
			for (int i = 0; i < students.size() - 1; i++) {
				//temp storage for the students at index i and i+1
				StudentGradeInfo s1 = getStudents(i);
				StudentGradeInfo s2 = getStudents(i + 1);
				//checks to see the studentID in s1 is greater then the studentID in s2 if so sets the boolean to true
				//and calls the setStudents function and swaps the indexs of s1 and s2
				if (s1.getStudentID() > s2.getStudentID()) {
					found = true;
					setStudents(s1, i + 1);
					setStudents(s2, i);
				}//end of if statement
			}//end of for loop
		}//end of while loop
	}//end if statment
}//end of sortStudents