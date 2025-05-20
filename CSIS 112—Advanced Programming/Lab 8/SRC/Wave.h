//wave.h 
//not my code found on stackoverflow.com and modified it to work in my code

#pragma once
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <conio.h>

class Wave {

public:
	Wave(std::string filename);
	~Wave();
	void play(bool async = true);
	bool isok();

private:
	char * buffer;
	bool ok;
	HINSTANCE HInstance;
};

