/*Ryan Marcum
CSIS 215-<002>
<Self-Organizing List> This program uses the 3 self organizing list Heuristics and tests them using a list of chars and 
a txt file with strings and organizes them.
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"CountOrderedList.h"
#include"MoveToFrontOrderedList.h"
#include"TransposeOrderedList.h"

using namespace std;

int main() {
	CountOrderedList<char> count;
	MoveToFrontOrderedList<char> move;
	TransposeOrderedList<char> transpose;
	CountOrderedList<string> countS;
	MoveToFrontOrderedList<string> moveS;
	TransposeOrderedList<string> transposeS;
	char findList[] = { 'F', 'D', 'F', 'G', 'E', 'G', 'F', 'A', 'D', 'F', 'G', 'E', 'H', 'I'};
	char list[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	vector<string> findListString;
	ifstream input;
	string filename = "test.txt";
	string str = "";
	string word;

	//count char
	for (int i = 0; i < 8; i++) {
		count.add(list[i]);
	}
	for (int i = 0; i < 14; i++) {
		count.find(findList[i]);
	}
	count.printlist();

	//move-to-front char
	for (int i = 0; i < 8; i++) {
		move.add(list[i]);
	}
	for (int i = 0; i < 14; i++) {
		move.find(findList[i]);
	}
	move.printlist();

	//Transpose char
	for (int i = 0; i < 8; i++) {
		transpose.add(list[i]);
	}
	for (int i = 0; i < 14; i++) {
		transpose.find(findList[i]);
	}
	transpose.printlist();

	//gets words from text document
	input.open(filename);
	while (getline(input, str)) {
		bool isWord = false;
		for (int i = 0; i < str.length(); i++) {
			
			if (str.at(i) != '.' && str.at(i) != ' ') {
				isWord = true;
				word += str.at(i);
				if (i == str.length()-1) {
					isWord = false;
					findListString.push_back(word);
					word = "";
				}
			}
			else if (isWord == true) {
				isWord = false;
				findListString.push_back(word);
				word = "";
			}
		}
		
	}

	//Count string
	for (int i = 0; i < findListString.size(); i++) {
		countS.find(findListString[i]);
	}
	countS.printlist(10);

	//move-to-front string
	for (int i = 0; i < findListString.size(); i++) {
		moveS.find(findListString[i]);
	}
	moveS.printlist(10);

	//Transpose String
	for (int i = 0; i < findListString.size(); i++) {
		transposeS.find(findListString[i]);
	}
	transposeS.printlist(10);

	system("pause");
	return 0;
}