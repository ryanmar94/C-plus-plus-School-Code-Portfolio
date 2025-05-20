//GradeBook.h
//include statments
#pragma once
#include "Student.h"

class GradeBook {
	//private data members of the GradeBook class
private:
	std::string gradeBookName;
	std::vector <Student> students;
	//public functions of the GradeBook class
public:
	//GradeBook constructor takes in the name of the gradebook and sets it as the name
	GradeBook(std::string name);
	//gets the name of the gradebook
	std::string getGradeBookName() const;
	//sets the name of the gradebook
	void setGradeBookName(std::string name) ;
	//gets the student at index i
	Student getStudents(int i) const;
	//sets the student object into the vector
	void setStudent(Student s);
	//this function takes in information from the user to create a student object
	//and then calls the setStudent function to place it in the student vector.
	//Only 3 students are able to be created.
	void addStudent();
	//this function displays the students and grades in the student vector	
	void showGrades();
};//end of GradeBook class