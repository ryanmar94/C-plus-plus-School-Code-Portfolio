#include <iostream>

using namespace std;

bool EndOfInputStream(istream &);

int main()
{
	float num;
		
	cout << "Enter a number (Ctrl-Z to exit):  ";
	cin >> num;

	while (!EndOfInputStream(cin)) //while the user did not enter Ctrl-Z
		{
			while (cin.fail() || num < 0) //Check for invalid data (non-numerics, negatives)
			{
				cout << "You must enter a number, and that number must be positive.  Please try again. " << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\nEnter a number (Ctrl-Z to exit):  ";
				cin >> num;
				if (EndOfInputStream(cin))
					break;
			}
			if (!EndOfInputStream(cin))
			{
				cout << num;
				cout << "\nEnter a number (Ctrl-Z to exit):  ";
				cin >> num;
			}
		}
		
		system("pause");
		return 0;

}
bool EndOfInputStream(istream &input)
{
	bool endOfInput{ false };
	if (input.eof())
		endOfInput = true;

	return endOfInput;
	
}