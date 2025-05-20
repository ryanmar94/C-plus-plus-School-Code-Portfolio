//StudentInfo.h

//include statements
#pragma once
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

class StudentInfo {
	//private data members of the StudentInfo class
private:
	std::string* studentName;
	std::string studentID;
	std::string major;
	//public functions in the StudentInfo class
public:
	//empty studentInfo constructor
	StudentInfo();

	//studentInfo constructor takes in the name of the student and sets it as the name
	StudentInfo(std::string name);

	//destructor
	~StudentInfo();

	//gets the name of the student
	std::string getStudentName() const;

	//sets the name of the student
	void setStudentName(std::string na);

	//gets the ID number of the student
	std::string getStudentID() const;

	//sets the ID number of the student
	void setStudentID(std::string id);

	//gets the major of the student
	std::string getMajor() const;

	//sets the major of the student
	void setMajor(std::string major);
};//end of StudentInfo class
