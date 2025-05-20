//Student.h
//include statements
#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

class Student {
	//private data members of the Student class
private:
	std::string studentName;
	std::array<double, 5> grades;
	//public functions in the Student class
public:
	//empty student constructor
	Student();
	//student constructor takes in the name of the student and sets it as the name
	Student(std::string name);
	//gets the name of the student
	std::string getStudentName() const;
	//sets the name of the student
	void setStudentName(std::string na);
	//gets the grade of the student at index i
	double getGrades(int i) const;
	//sets the grade of the student at index i
	void setGrades(double grade, int i);
};//end os Student class
