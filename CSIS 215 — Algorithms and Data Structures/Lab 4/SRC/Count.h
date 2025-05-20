//Count.h
#pragma once
#include<iostream>

template <typename E>
class count{
private:
	E val;
	int num;
public:
	
	count() { setNum(0); }
	~count() {}

	E getVal() const { return val; }

	void setVal(E v) { val = v; }

	int getNum() const { return num; }

	void setNum(int n) { num = n; }
};