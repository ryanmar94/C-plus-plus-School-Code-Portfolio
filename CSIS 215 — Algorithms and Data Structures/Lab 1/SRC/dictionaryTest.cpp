/*Ryan Marcum
CSIS 215-<002>
<Bag_Assignment> This program test the use of KVpairs <int, string> and <string, int> in a dictionary bag.
*/

#include <iostream>
#include "kvpair.h"
#include "BDictionary.h"
#include "ABag.h"

using namespace std;



int main() {
	//variables
	BDictionary<int, string> dictIntString;
	BDictionary<string, int> dictStringInt;
	bool found;

	// KV Pair int string test
	cout << "Testing dictionary with <int, string> KV Pair" << endl;
	dictIntString.insert(10, "Ryan");
	dictIntString.insert(20, "Nicky");
	dictIntString.insert(30, "Catherine");
	cout << "INSERT: Size of dictIntString is " << dictIntString.size() << endl;
	dictIntString.print();
	string val = "Ryan";
	dictIntString.remove(10, val);
	cout << "REMOVE: Removed key 10 which was Ryan" << endl;
	cout <<	"Size of dictIntString is " << dictIntString.size() << endl;
	dictIntString.print();
	cout << "FIND: My data at key==20 is" << endl;
	val = "Nicky";
	dictIntString.find(20, val);
	cout << "REMOVEANY: " ;

	string val1;
	dictIntString.removeAny(val1);
	cout << val1 << endl;
	cout << "Size of dictIntString is " << dictIntString.size() << endl;
	dictIntString.clear();
	cout << "CLEAR: Size of dictIntString is " << dictIntString.size() << endl;
	dictIntString.print();

	cout << endl;

	// KV pair String int test
	cout << "Testing dictionary with <string, int> KV Pair" << endl;
	dictStringInt.insert("Ryan", 10);
	dictStringInt.insert("Nicky", 20);
	dictStringInt.insert("Catherine", 30);
	cout << "INSERT: Size of dictStringInt is " << dictStringInt.size() << endl;
	dictStringInt.print();
	int num = 10;
	dictStringInt.remove("Ryan", num);
	cout << "REMOVE: Removed key 10 which was Ryan" << endl;
	cout << "Size of dictStringInt is " << dictStringInt.size() << endl;
	dictStringInt.print();
	cout << "FIND: My data at key==20 is" << endl;
	num = 20;
	dictStringInt.find("Nicky", num);
	cout << "REMOVEANY: ";
	int val2;
	dictStringInt.removeAny(val2);
	cout << val2 << endl;
	cout << "Size of dictStringInt is " << dictStringInt.size() << endl;
	dictStringInt.clear();
	cout << "CLEAR: Size of dictStringInt is " << dictStringInt.size() << endl;
	dictStringInt.print();


	system("pause");
	return 0;
}