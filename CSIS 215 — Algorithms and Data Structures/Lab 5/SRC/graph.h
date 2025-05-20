//graph.h
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"book.h"
#include"visit.h"

using namespace std;

class graph {
private:
	int vert = 0;
	int startGraph[6][6];
	int mstGraph[6][6] = { 0 };
	visited mst[6];
	ifstream input;
	ofstream output;

public:
	//constructor takes in a text file and inilizes the graph and the visit MST array
	graph(string filename) {
		string str;
		input.open(filename);
		int i = 0;
		while (getline(input, str)) {
			bool isWord = false;
			int j = 0;
			for (int k = 0; k < str.length(); k++) {

				if (str.at(k) != ',') {
					isWord = true;
					startGraph[i][j] = str.at(k) - 48;
					j++;
				}
			}
			i++;
		}

		for (int i = 0; i < std::size(mst); i++) {
			mst[i].setNum(INFINITY);
			mst[i].setVisit('u');
		}
	}
	//destructor
	~graph() { input.close(); }

	//finds the number of vertices and sets it
	void setVert() {
		for (int i = 0; i < std::size(startGraph); i++) {
			for (int j = i; j < std::size(startGraph); j++) {
				if (startGraph[i][j] > 0) {
					vert++;
				}
			}
		}
	}

	//returns the number of vertices
	int getVert() { return vert; }

	//prints the starting graph
	void printGraph() {
		setVert();
		cout << "Number of vertices is " << getVert() << endl << "Number of edges is " << getVert() - 1 << endl 
			<< "Matrix is:" << endl;
		for (int i = 0; i < std::size(startGraph); i++) {
			for (int j = 0; j < std::size(startGraph); j++) {
				cout << startGraph[i][j] << ", ";
			}
			cout << endl;
		}
		cout << endl;
	}

	//prints the graph of the mst
	void printMST(string filename) {
		output.open(filename);
		cout << endl;
		for (int i = 0; i < std::size(mstGraph); i++) {
			for (int j = 0; j < std::size(mstGraph); j++) {
				cout << mstGraph[i][j] << ", ";
				output << mstGraph[i][j] << ",";
			}
			cout << endl;
			output << endl;
		}
		cout << endl;
	}

	//finds the mst using recurtion
	void findMST(int startVert, bool start) {
		if (start == true) {
			mst[startVert].setNum(0);
		}
		int nextVert = INFINITY;
		int min = INFINITY;
		int location;

		//sets the visit to the current vert
		mst[startVert].setVisit('v');
		//sets the distances of the current vert in the visit array if the are lower then the current if it hasi=nt been visited yet
		for (int i = 0; i < std::size(startGraph); i++) {
			if (startGraph[startVert][i] > 0 && mst[i].getNum() > startGraph[startVert][i] && mst[i].getVisit() == 'u') {
				mst[i].setNum(startGraph[startVert][i]);
			}

		}

		//finds the next vert in the graph
		for (int i = 0; i < std::size(mst); i++) {
			if (mst[i].getVisit() == 'v') {
				for (int j = 0; j < std::size(startGraph); j++) {
					if (mst[j].getVisit() == 'u' && mst[j].getNum() != INFINITY && startGraph[i][j] < min && startGraph[i][j] > 0) {
						min = startGraph[i][j];
						nextVert = j;
						location = i;
					}
				}
			}
		}

		//add the edges to MST graph and recursivly calls the next vert in the MST
		if (nextVert != INFINITY) {
			cout << "Add edge " << location << " to " << nextVert << endl;
			mstGraph[location][nextVert] = startGraph[location][nextVert];
			mstGraph[nextVert][location] = startGraph[nextVert][location];
			findMST(nextVert, false);
		}
	}

};