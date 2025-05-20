//StudentInfo.cpp

//include statements
#include "StudentInfo.h"

using namespace std;

//empty studentInfo constructor
StudentInfo::StudentInfo(){}

//studentInfo constructor takes in the name of the student and sets it as the name
StudentInfo::StudentInfo(string name) {
	setStudentName(name);
}//end of studentInfo constructor

//studentInfo destructor
StudentInfo::~StudentInfo() {}

//gets the name of the student
string StudentInfo::getStudentName() const {
	return *studentName;
}

//sets the name of the student
void StudentInfo::setStudentName(string name) {
	studentName = new string (name);
}

//gets the ID number of the student
string StudentInfo::getStudentID() const {
	return studentID;
}

//sets the ID number of the student
void StudentInfo::setStudentID(string id) {
	studentID = id;
}

//gets the major of the student
string StudentInfo::getMajor() const{
	return major;
}

//sets the major of the student
void StudentInfo::setMajor(string program) {
	major = program;
}
