//StudentGradeInfo.h

//include statements
#pragma once
#include "StudentInfo.h"

class StudentGradeInfo : public StudentInfo {
	//friend functions for StudentGradeInfo class
	friend std::ostream& operator<<(std::ostream&, StudentGradeInfo&);
	//private data members of the StudentGradeInfo class
private:
	std::array<double, 5> grades;
	//public functions in the StudentGradeInfo class
public:
	//StudentGradeInfo empty constructor
	StudentGradeInfo();

	//StudentGradeInfo constructor takes in the name of the the student and calls the StudentInfo constructor 
	//and passes it the student name
	StudentGradeInfo(std::string);

	//destructor
	~StudentGradeInfo();

	//gets the grade of the student at index i
	double getGrades(int i) const;

	//sets the grade of the student at index i
	void setGrades(double grade, int i);

	//overloaded equals operator checks to see if any 2 studentID variables are equal
	bool operator==(StudentGradeInfo s);

};//end of StudentGradeInfo class

//overloaded operator cout for displaying the information of the student
std::ostream& operator<<(std::ostream& output, StudentGradeInfo&);
