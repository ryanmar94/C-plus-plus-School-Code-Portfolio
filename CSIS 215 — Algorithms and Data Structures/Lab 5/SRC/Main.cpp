/*Ryan Marcum
CSIS 215-<002>
<Graph MST> This program starts at 3 diffrent vertices of a graph to find the MST. The Graph is read in from a text 
document and when it is done finding the MST it prints it out and puts it in a text document.
*/
#include<iostream>
#include"graph.h"
#include"visit.h"

using namespace std;

int main() {

	graph mst1("graph.txt");
	graph mst2("graph.txt");
	graph mst3("graph.txt");
	
	//MST1 start vertex 0
	mst1.printGraph();
	cout << "Begin MST 1 starting at Vertex 0" << endl;
	mst1.findMST(0, true);
	mst1.printMST("MST1.txt");
	
	//MST2 start vertex 4
	cout << endl;
	mst2.printGraph();
	cout << endl << "Begin MST 2 starting at Vertex 4" << endl;
	mst2.findMST(4, true);
	mst2.printMST("MST2.txt");

	//MST3 start vertex 2
	cout << endl;
	mst3.printGraph();
	cout << endl << "Begin MST 3 starting at Vertex 2" << endl;
	mst3.findMST(2, true);
	mst3.printMST("MST3.txt");


	system("pause");
	return 0;
}