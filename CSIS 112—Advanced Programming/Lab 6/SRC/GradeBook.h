//GradeBook.h

//include statments
#pragma once
#include "StudentGradeInfo.h"

class GradeBook {
	//private data members of the GradeBook class
private:
	std::string gradeBookName;
	std::vector <StudentGradeInfo> students;
	//public functions of the GradeBook class
public:
	//GradeBook constructor takes in the name of the gradebook and sets it as the name
	GradeBook(std::string name);

	//gradeBook destructor
	~GradeBook();

	//gets the name of the gradebook
	std::string getGradeBookName() const;

	//sets the name of the gradebook
	void setGradeBookName(std::string name) ;

	//gets the studentGradeInfo at index i
	StudentGradeInfo getStudents(int i) const;

	//sets the studentGradeInfo object into the vector
	void setStudents(StudentGradeInfo s);

	//sets the studentGradeInfo object into the vector at index i
	void setStudents(StudentGradeInfo s, int i);

	//this function takes in information from the user to create a studentGradeInfo object
	//and then calls the setStudent function to place it in the studentGradeInfo vector.
	//Only 3 students are able to be created.
	void addStudent();

	//this function displays the students and grades in the studentGradeInfo vector	
	void showGrades();

	//sorts the students in accending order by there student id
	void sortStudents();
};//end of GradeBook class