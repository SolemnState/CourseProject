#pragma once
#include "stdafx.h"
#include "Command.h"
class Pipeline
{
	Command* Commands;
	int currentCommand;
	int numberOfCommands;
	int clkCounter;
	int stages[5];
	int* time;
	int nextStage;


public:
	Pipeline(int num);
	~Pipeline();
	void runtime();
	void parallel();
	bool checkPipe();
	void print();
	void checkStage();
	bool checkStatus();
	void showTime();

};

