/*Ryan Marcum
CSIS 112-<002>
<Lab_1> This program calculates the number of boxes of tiles that will be needed for a 
particular job. Also calculates how many tiles will be needed for eaach room, extra
tiles left after the job is done, and the total nmber of tiles that will be used in 
the job.
*/

//Include statements
#include <iostream>
#include <string>
using namespace std;

int main() {

	//initialize variables
	const int TOTAL_IN_BOX = 20; //number of tiles per box
	double totalBoxs = 0;        //total number of boxes that will be needed for the job
	int totalUsedTiles = 0;      //total tiles used in the job
	double tilesLength = 0;      //number of tiles used in the width
	double tilesWidth = 0;       //number of tiles used in the length
	int numTileInRoom = 0;       //number of tiles used in one room
	int extraTiles = 0;          //number of unused tiles after the job is done
	double numRoom = 0;          //number of rooms to be tiled
	double tileSizeSqr = 0;      //the size of a square tile in inches
	double roomWft = 0;          //room width feet
	double roomWin = 0;          //room width inchs
	double roomLft = 0;          //room length feet
	double roomLin = 0;          //room length inchs
	string isTrue = "y";         //used as a boolean to anwser a question asked by the program 
	int feet = 0;				 //temporary place holder for feet
	int inch = 0;				 //temporary place holder for inches

	//requests number of rooms to be tiled
	cout << "Enter number of rooms: ";
	cin >> numRoom;

	//checks for a vaild response from user
	while (cin.fail() || numRoom < 0 || int(numRoom) != numRoom)
	{
		//checks to make the number is positive
		if (numRoom < 0)
			cout << "Response must be a positive number please try again!!\a" << endl;
		//checks to make sure the number is an integer
		else if (int(numRoom) != numRoom) {
			cout << "Response must be an integer please try again!!\a" << endl;
			numRoom = 0;
		}
		//checks for an invailed entry like a non-numeral value
		else
			cout << "Response can not be a letter or symbol please try again!!\a" << endl;
		
		//clears any errors and requsts the number of rooms again from the user
		cout << "Enter number of rooms: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> numRoom;
	}

	//requests the tile size in inchs from user
	cout << "Enter size of tile in inches: ";
	cin >> tileSizeSqr;

	//checks for a vaild response from user
	while (cin.fail() || tileSizeSqr < 1 || int(tileSizeSqr) != tileSizeSqr)
	{
		//check to see if a negative number was entered
		if (tileSizeSqr < 0)
			cout << "Response must be a positive number please try again!!\a" << endl;
		//checks for an invailed entry like a non-numeral value was entered
		else if (cin.fail())
			cout << "Response can not be a letter or symbol please try again!!\a" << endl;
		//checks to see if an integer was entered if not tells the user
		else if (int(tileSizeSqr) != tileSizeSqr) {
			cout << "Response must be an integer please try again!!\a" << endl;
			tileSizeSqr = 0;
		}
		//let the user know that they entered in a 0 size tile
		else
			cout << "Response can not be zero please try again:\a" << endl;

		//clears any errors and requsts the size of the tile again in inches from the user
		cout << "Enter size of tile in inches: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> tileSizeSqr;
	}

	//loops for how many rooms that were entered in by the user
	for (int x = 0; x < numRoom; x++) {

		//Requests the rooms width in feet and inchs from user
		cout << "Enter room width (feet and inches, separated by a space): ";
		cin >> roomWft >> roomWin;

		//checks for a vaild response from user
		while (cin.fail() || roomWft < 0 || int(roomWft) != roomWft || roomWin < 0 || roomWin > 11 || int(roomWin) != roomWin)
		{
			//checks for an invailed entry like a non-numeral value was entered
			if (cin.fail()) {
				cout << "Response can not be a letter or a symbol try again!!!\a" << endl;
				//asks the user to reenter the width feet and inchs after a non-numeral value was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter room width (feet and inches, separated by a space): ";
				cin >> roomWft >> roomWin;
			}
			//check to make sure an integer was entered
			else if (int(roomWin) != roomWin || int(roomWft) != roomWft){
				cout << "Response must be an integer try again!!!\a" << endl;
				//asks the user to reenter the width feet and inchs after a non-integer number was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter room width (feet and inches, separated by a space): ";
				cin >> roomWft >> roomWin;
			}
			//check to see if 12 or more inches were entered and asks the user if they ment to do that 
			else if (roomWin > 11) {
				//temporary place holders for feet and inches
				feet = roomWft + roomWin/12;
				inch = int(roomWin) % 12;
				//asks the user if they ment to enter inches value 12 inches higher or higher and puts it
				//into the correct format for feet ad inches
				do {
					cout << "Did you mean to enter " << feet << "ft " << inch << "in?" << endl;
					cout << "If yes type y for yes and n for no." << endl;
					cin >> isTrue;
					//checks to make sure the user entered in a char and not a string
					if (isTrue.size() > 1) {
						cout << "Invalid response must be a charcter!!!\a" << endl;
					}
					//checks for a yes response and resets the width feet and inches values
					else if (isTrue == "y" || isTrue == "Y") {
						roomWft = feet;
						roomWin = inch;
					}
					//checks if the response is a no and asks the user to reenter in the width feet and inches
					else if (isTrue == "n" || isTrue == "N"){
						cout << "Please reenter room width (feet and inches, separated by a space): ";
						cin >> roomWft >> roomWin;
					}
					//this else lets the user know that they entered in an invalid char
					else {
						cout << "Invalid response charcter must be a 'y' or a 'n'!!!\a" << endl;
					}
				} while (isTrue != "y" && isTrue != "n" && isTrue != "Y" && isTrue != "N");//end do-while loop
			}
			//checks that the input on the width feet and inches to see if they are negative
			else if (roomWft < 0 || roomWin < 0) {
				if (roomWft < 0) {
					cout << "Room width feet can not be negative!!\a" << endl;
				}
				else {
					cout << "Room width inchs can not be negative!!\a" << endl;
				}
				//asks the user to reenter the width feet and inchs after a negative number was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Reenter room width (feet and inches, separated by a space): ";
				cin >> roomWft >> roomWin;
			}
		}//end while loop

		//Requests the rooms length in feet and inchs from user
		cout << "Enter room length (feet and inches, separated by a space): ";
		cin >> roomLft >> roomLin;
		
		//Checks for a vaild response from user
		while (cin.fail() || roomLft < 0 || int(roomLft) != roomLft || roomLin < 0 || roomLin > 11 || int(roomLin) != roomLin)
		{
			//checks for an invailed entry like a non-numeral value was entered
			if (cin.fail()) {
				cout << "Response can not be a letter or a symbol try again!!!\a" << endl;
				//asks the user to reenter the length feet and inchs after a non-numeral value was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter room legth (feet and inches, separated by a space): ";
				cin >> roomLft >> roomLin;
			}
			//check to make sure an integer was entered
			else if(int(roomLft) != roomLft || int(roomLin) != roomLin){
				cout << "Response must be an integer try again!!!\a" << endl;
				//asks the user to reenter the length feet and inchs after a non integer number was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter room length (feet and inches, separated by a space): ";
				cin >> roomLft >> roomLin;
			}
			//check to see if 12 or more inches were entered and asks the user if they ment to do that 
			else if (roomLin > 11) {
				//temporary place holders for feet and inches
				feet = roomLft + roomLin / 12;
				inch = int(roomLin) % 12;
				//asks the user if they ment to enter inches value 12 inches higher or higher and puts it
				//into the correct format for feet ad inches
				do {
					cout << "Did you mean to enter " << feet << "ft " << inch << "in?" << endl;
					cout << "If yes type y for yes and n for no." << endl;
					cin >> isTrue;
					//checks to make sure the user entered in a char and not a string
					if (isTrue.size() > 1) {
						cout << "Invalid response must be a charcter!!!\a" << endl;
					}
					//checks for a yes response and resets the length feet and inches values
					else if (isTrue == "y" || isTrue == "Y") {
						roomLft = feet;
						roomLin = inch;
					}
					//checks if the response is a no and asks the user to reenter in the length feet and inches
					else if (isTrue == "n" || isTrue == "N") {
						cout << "Please reenter room length (feet and inches, separated by a space): ";
						cin >> roomLft >> roomLin;
					}
					//this else lets the user know that they entered in an invalid char
					else {
						cout << "Invalid response charcter must be a 'y' or a 'n'!!!\a" << endl;
					}
				} while (isTrue != "y" && isTrue != "n" && isTrue != "Y" && isTrue != "N");//end do-while loop
			}
			//checks that the input on the length feet and inches to see if they are negative
			else if (roomLft < 0 || roomLin < 0) {
				if (roomLft < 0) {
					cout << "Room length feet can not be negative!!" << endl;
				}
				else {
					cout << "Room length inchs can not be negative!!" << endl;
				}
				//asks the user to reenter the length feet and inchs after a negative number was used
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Enter room length (feet and inches, separated by a space): ";
				cin >> roomLft >> roomLin;
			}
		}//end while loop

		//calculates number of tiles used in the room
		roomWin += (roomWft * 12);
		roomLin += (roomLft * 12);
		tilesWidth = roomWin / tileSizeSqr;
		tilesLength = roomLin / tileSizeSqr;
		numTileInRoom = (ceil(tilesWidth)) * (ceil(tilesLength));
		//adds number of tiles used in the room to a total keeper
		totalUsedTiles += numTileInRoom;

		//displays to the user how many tiles are used in the room
		if (numTileInRoom == 1)
			cout << "Room requires " << numTileInRoom << " tile." << endl;
		else
			cout << "Room requires " << numTileInRoom << " tiles." << endl;

	}//end for loop

	//Calculates extra tiles left after the job is done and number boxes of tiles needed for the job
	totalBoxs = totalUsedTiles / TOTAL_IN_BOX;
	extraTiles = TOTAL_IN_BOX - (totalUsedTiles % TOTAL_IN_BOX);
	if (totalUsedTiles > 0 && totalUsedTiles < 20) {
		totalBoxs++;
	}
	else if (extraTiles > 0 && totalBoxs != 0) {
		totalBoxs++;
	}

	//displays the final resalts
	cout << "Total tiles required is " << totalUsedTiles << "." << endl;
	cout << "Number of boxes needed is " << totalBoxs << "." << endl;
	cout << "There will be " << extraTiles << " extra tiles." << endl;
	
	//Closing program statements
	system("pause");
	return 0;
}// end of main