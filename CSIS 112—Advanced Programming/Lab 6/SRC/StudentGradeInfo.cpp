//StudentGradeInfo.cpp

//include statements
#include "StudentGradeInfo.h"

using namespace std;

//studentGradeInfo empty constructor
StudentGradeInfo::StudentGradeInfo() {}

//StudentGradeInfo constructor takes in the name of the the student and calls the StudentInfo constructor 
//and passes it the student name
StudentGradeInfo::StudentGradeInfo(string name) : StudentInfo(name) {}

//studentGradeInfo destructor
StudentGradeInfo::~StudentGradeInfo() {}

//gets the grade of the student at index i
double StudentGradeInfo::getGrades(int i) const {

	return grades.at(i);
}//end of getGrades function

//sets the grade of the student at index i
void StudentGradeInfo::setGrades(double grade, int i) {
	grades[i] = grade;
}//end of setGrade function

//overloaded equals operator checks to see if any 2 studentID variables are equal
bool StudentGradeInfo::operator==(StudentGradeInfo s)
{
	//creates and sets the boolean to false
	bool returnVal{ false };

	//checks to see if the current studentID is equal to the passed in studentID
	if (this->getStudentID() == s.getStudentID()) {
		returnVal = true;
	}//end of if statement

	//return true or false if the 2 id's are equal or not
	return returnVal;
}//end of overloaded == operator

//overloaded << operator for displaying the information of the student
std::ostream& operator<<(std::ostream& output, StudentGradeInfo& s)
{
	//diplays the student info
	output << "Student Name:   " << s.getStudentName() << endl;
	output << "Student ID:     " << s.getStudentID() << endl;
	output << "Student Major:  " << s.getMajor() << endl;
	output << "Student Grades: ";
	//this for loop displays all grades that the student has unless it is a -1
	for (int j = 0; j < 5; j++) {
		//checks to see if the grade at index i is a -1 if not then displays the grade
		if (s.getGrades(j) > -1) {
			output << s.getGrades(j) << " ";
			//if -1 then exits the for loop
		}//end of if statement
		else {
			break;
		}//end of else statement

	}//end of for loop
	output << endl;
	output << endl;
	//returns the output
	return output;
}//end of overloaded << operator