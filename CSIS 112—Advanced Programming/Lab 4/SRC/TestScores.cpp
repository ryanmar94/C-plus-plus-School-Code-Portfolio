//TestScores.cpp

//include statements
#include "TestScores.h"

using namespace std;

//default constructor
TestScores::TestScores(){}
//destructor
TestScores::~TestScores(){}
//getScores returns the testscore in the vector at index i
int TestScores::getScores(int i) const{
	return scores.at(i);
}//end of getScores
//setScores adds a testscore to the end of the vector
void TestScores::setScores(int score) {
	scores.push_back(score);
}//end of setScores
 //setScores adds a testscore at index i
void TestScores::setScores(int score, int i) {
	scores.at(i) = score;
}//end of setScores
 //addScore lets the user add a testscore to the vector
void TestScores::addScore() {
	//initialize variable
	int s;
	//asks user to enter in a test score to save in s
	cout << "Type a score to add to the vector." << endl;
	cin >> s;
	//calls setScore function and passes it s
	setScores(s);
}//end of addScore
 //sortVector sorts the vector in ascending order
void TestScores::sortVector() {
	//checks to make sure there is more then 1 test score in the vector
	if (scores.size() > 1) {
		//initialize variable
		bool found = true;
		//while loop continues to run until the vector is sorted into ascending order
		while (found == true) {
			found = false;
			//for loop goes through the vector 2 numbers at a time
			for (int i = 0; i < scores.size() - 1; i++) {
				//sets temporary variables for the testscores at the curent and next index values
				int a = getScores(i);
				int b = getScores(i + 1);
				//if statement checks to see if b is less then a if so then testscores in those two positions are flipped
				if (b < a) {
					found = true;
					setScores(b, i);
					setScores(a, i + 1);
				}//end if statement
			}//end for loop
		}//end while loop
	}//end if statement 
}//end of sortVector
 //computeAverage calculates the average of the testscores in the vector and then displays it
void TestScores::computeAverage() {
	//initialize variables
	int sum = 0;
	double average;
	//checks to make sure that there are testscores in the vector
	if (scores.size() > 0) {
		//for loop adds all the testscores together
		for (int i = 0; i < scores.size(); i++) {
			sum += getScores(i);
		}
		//calculates the average by taking the total of the testscores and deviding it by the size of the vector
		average = sum / scores.size();
		//displays the average of the testscores to the user
		cout << "The average of the scores is " << average << endl;
	}
	//lets the user know that there are no testscore to compute the average
	else {
		cout << "There are corently no test scores in the vector.\a" << endl;
	}
}//end of computeAverage
 //print function prints the scores in the vector
void TestScores::print() {
	//checks to make sure that there are testscores in the vector
	if (scores.size() > 0) {
		cout << "The Testscores" << endl;
		//for loop displays the testscores in the vector
		for (int i = 0; i < scores.size(); i++) {
			cout << getScores(i) << " ";
		}
		cout << endl;
	}//end if statement
	//lets the user know that there are no testscores in the vector
	else {
		cout << "There are curently no testscores in the vector!\a" << endl;
	}//end else statement
}//end of print
 //readFile function reads in testscores from a file
void TestScores::readFile() {
	//initialize variables
	int x = 0;
	ifstream inFile;
	string fileType{ ".txt" };
	string fileName;

	//askes the user to enter in the name of the text file that has testscores in it
	cout << "Please type in a file name. (.txt will be added automaticaly)" << endl;
	cin >> fileName;

	//add .txt to the file name
	fileName += fileType;

	cout << endl;

	//attempts to open the file
	inFile.open(fileName);
	//if file not found lets the user know
	if (!inFile) {
		cout << "File not found!\a" << endl;
	}
	//else it reads in the text file 1 line at a time and adds it to the vector and then lets the user know the file was
	//loaded successfully
	else {
		//while runs until it gets to the end of the text file one line at a time and adds it to the vector
		while (inFile >> x) {
			setScores(x);
		}//end while loop
		cout << "File loaded successfully." << endl;
	}
	//closes the open file
	inFile.close();
}//end of readFile