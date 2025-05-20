//Wave.cpp
//not my code found on stackoverflow.com and modified it to work in my code to play sounds

#include "Wave.h"

using namespace std;

Wave::Wave(string filename)
{
	ok = false;
	buffer = 0;
	HInstance = GetModuleHandle(0);

	ifstream infile(filename, ios::binary);

	infile.seekg(0, ios::end);   // get length of file
	int length = infile.tellg();
	buffer = new char[length];    // allocate memory
	infile.seekg(0, ios::beg);   // position to start of file
	infile.read(buffer, length);  // read entire file

	infile.close();
	ok = true;
}

Wave::~Wave()
{
	PlaySound(NULL, 0, 0); // STOP ANY PLAYING SOUND
	delete[] buffer;      // before deleting buffer.
}
void Wave::play(bool async)
{
	if (!ok)
		return;

	if (async)
		PlaySound(buffer, HInstance, SND_MEMORY | SND_ASYNC);
	else
		PlaySound(buffer, HInstance, SND_MEMORY);
}

bool Wave::isok()
{
	return ok;
}