//TestScores.h

//include statements
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class TestScores {
	
	//private data members
private:
	std::vector <int> scores;

//public class functions
public:
	//default constructor
	TestScores();
	//destructor
	~TestScores();
	//getScores returns the testscore in the vector at index i
	int getScores(int i) const;
	//setScores adds a testscore to the end of the vector
	void setScores(int score);
	//setScores adds a testscore at index i
	void setScores(int score, int i);
	//addScore lets the user add a testscore to the vector
	void addScore();
	//sortVector sorts the vector in ascending order
	void sortVector();
	//computeAverage calculates the average of the testscores in the vector and then displays it
	void computeAverage();
	//print function prints the scores in the vector
	void print();
	//readFile function reads in testscores from a file
	void readFile();
};//end of TestScores Class