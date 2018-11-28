#include "stdafx.h"
#include "Type.h"


type::type()
{
	MemRef = 0;
	type_ = "";

}


type::~type()
{
	MemRef = 0;
	type_ = "";
}

void type::random1(int P)
{
	srand(time(NULL));
	int res = rand() % 100 + 0;
	if (res > P)
	{
		if (P == 90)
			MemRef = 2;
		else if (P == 80)
			MemRef = 5;
		else if (P == 60)
			MemRef = 10;

	}
	else MemRef = 1;
}

void type::random2(int P)
{
	srand(time(NULL));
	int res = rand() % 100 + 0;
	if (res > P)
	{
		if (P == 90)
			MemRef = 4;
		else if (P == 70)
			MemRef = 8;
		else if (P == 50)
			MemRef = 16;

	}
	else MemRef = 1;
}

void type::setType1(int P)
{
	random1(P);
	if (MemRef == 1)
		type_ = "register";
	else type_ = "address";
}

void type::setType2(int P)
{
	random2(P);
	type_ = "";
}

int type::getMemRef()
{
	return MemRef;
}

string type::getType()
{
	return type_;
}