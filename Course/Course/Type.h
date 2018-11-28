#pragma once
#include "stdafx.h"
using namespace std;

class type
{
private:
	int MemRef;
	string type_;
public:
	type();
	~type();
	void random1(int P);
	void random2(int P);
	void setType1(int P);
	void setType2(int P);
	int getMemRef();
	string getType();
};


