// Course.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Command.h"
#include "Pipeline.h"

using namespace std;

int main()
{
	int commands;
	cout << "Number of commands:";
	cin >>commands;
	cout << "Information about commands:" << endl;
	Pipeline P(commands);
	P.runtime();
	P.showTime();
    return 0;
}

