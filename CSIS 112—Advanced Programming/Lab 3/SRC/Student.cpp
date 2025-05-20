//Student.cpp

#include "Student.h"

using namespace std;

//empty student constructor
Student::Student(){}
//student constructor takes in the name of the student and sets it as the name
Student::Student(string name) {
	setStudentName(name);
}
//gets the name of the student
string Student::getStudentName() const {
	return studentName;
}
//sets the name of the student
void Student::setStudentName(string name) {
	studentName = name;
}
//gets the grade of the student at index i
double Student::getGrades(int i) const {

	return grades.at(i);
}
//sets the grade of the student at index i
void Student::setGrades(double grade, int i) {
	grades[i] = grade;
}