#pragma once
#include<iostream>

class visited {
private:
	int num;
	char visit;

public:
	visited() {}
	~visited() {}

	int getNum() const { return num; }
	void setNum(int n) { num = n; }
	char getVisit() { return visit; }
	void setVisit(char v) { visit = v; }
};