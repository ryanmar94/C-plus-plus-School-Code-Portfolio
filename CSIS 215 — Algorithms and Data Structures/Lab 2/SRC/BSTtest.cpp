/*Ryan Marcum
CSIS 215-<002>
<ThreadedBST_Assignment> This program test the use of KVpairs <int, string> to create a 
threaded BST and prints in inorder and then in reverse order.
*/
#include <iostream>
#include "BST.h"

int main() {
	//calls BST constructor and creates root node passing a key value of infinity
	BST<int, string> tree(INFINITY, "");

	//insercts key value pairs of the threaded BST to the tree
	tree.insert(77, "seventy - seven");
	tree.insert(70, "seventy");
	tree.insert(75, "seventy-five");
	tree.insert(66, "sixty-six");
	tree.insert(79, "seventy-nine");
	tree.insert(68, "sixty-eight");
	tree.insert(67, "sixty-seven");
	tree.insert(69, "sixty-nine");
	tree.insert(90, "ninety");
	tree.insert(85, "eighty-five");
	tree.insert(83, "eighty-three");
	tree.insert(87, "eighty-seven");
	tree.insert(65, "sixty - five");
	
	//tests insert function to see if the nodes were added
	cout << "Testing insert function to build my tree." << endl;
	cout << "My BST tree size is " << tree.size() << endl;
	
	//tests print function
	cout << "My tree's structure is (tests my changes to the print function)" << endl;
	tree.print();
	
	//tests inorder print function
	cout << endl << "Inorder printing of my tree." << endl;
	cout << "(Tests my right threads and printInorder function)" << endl;
	tree.printInorder();

	//tests reverse order print function
	cout << endl << "Reverse order printing of my tree." << endl;
	cout << "(Tests my left threads and printReverse function)" << endl;
	tree.printReverse();

	system("pause");
	return 0;
}