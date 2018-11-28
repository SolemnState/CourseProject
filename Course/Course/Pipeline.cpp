#include "stdafx.h"
#include "Pipeline.h"

using namespace std;

Pipeline::Pipeline(int num)
{
	numberOfCommands = num;
	nextStage = 0;
	clkCounter = 1;
	Commands = new Command[numberOfCommands];
	stages[0] = -1; stages[1] = -1; stages[2] = -1;
	stages[3] = -1; stages[4] = -1;
	time = new int[numberOfCommands];
	for (int i = 0; i < numberOfCommands; i++)
	{
		cout << "Command # " << i+1 <<":"<< endl;
		Commands[i].showCommandInfo();
	}
	currentCommand=0;
	Commands[currentCommand].nextStage();
	stages[Commands[currentCommand].getStage()] = currentCommand;
	print();
	Commands[currentCommand].addClk();
}

Pipeline::~Pipeline()
{
}

void Pipeline:: runtime()
{
	print();
	while (!checkPipe())
	{
		parallel();
		print();
		if (Commands[currentCommand].TactsForStage(4)==0 && checkStatus())
		{
			Commands[currentCommand].setStatus();
			time[currentCommand] = Commands[currentCommand].getTime();
			stages[4] = -1;
			currentCommand++;
		}
		clkCounter++;
	}
}

void Pipeline::parallel()
{
	checkStage();
	if (Commands[currentCommand].getStage() != 3)
	{
		for (int i = 4; i >= 0; i--)
		{
			if (stages[i] != -1)
				Commands[stages[i]].addClk();
		}
	}
	else
	{
		for (int i = 0; i < CONVSIZE; i++)
		{
			if (stages[i] != -1)
			{
				if (i == 3)
					Commands[stages[i]].addClk();
				else Commands[stages[i]].wait();
			}
		}
	}
}


bool Pipeline::checkPipe()
{
	for (int i = 0; i < numberOfCommands; i++)
	{
		if (!Commands[i].getStatus())
			return false;
	}
	return true;
}



void Pipeline::checkStage()
{
	int currStage = Commands[currentCommand].getStage();
	int j = 0;
	int k = 0;
	if (checkStatus())
	{
		if (currStage != 2 && (currStage != 3 || stages[1] == -1))
		{
			if (Commands[numberOfCommands - 1].getStage()> 0)
			{
				k = Commands[numberOfCommands - 1].getStage();
			}
			for (int i = currStage + 1; i >= k; i--)
			{
				if (j <= nextStage + 1 - currentCommand)
					Commands[currentCommand + j].nextStage();
				if (i >= 1)
					stages[i] = stages[i-1];
				else {
					stages[i] = stages[i+1] + 1;
					nextStage = stages[i];
				}
				j++;
			}
			for (k = 0; k < Commands[numberOfCommands - 1].getStage(); k++)
				stages[k] = -1;
		}
		else
		{
			if (currStage == 2)
			{
				Commands[currentCommand].nextStage();
				stages[currStage + 1] = currentCommand;
				stages[currStage] = -1;
			}
			else
			{
				Commands[currentCommand].nextStage();
				Commands[stages[1]].nextStage();
				stages[2] = stages[1];
				stages[currStage + 1] = currentCommand;
				stages[currStage] = -1;
				stages[1] = -1;
			}
		}
		print();
	}
}

bool Pipeline::checkStatus()
{	
	for (int i = 0; i < CONVSIZE; i++)
	{
		if (Commands[stages[i]].TactsForStage(i) != 0 && stages[i] != -1)
		{
			return  false;
		}
	}
	return true;
}

void Pipeline::print()
{
	for (int i = 0; i < CONVSIZE; ++i) {
		if (stages[i] == -1) {
			cout << "stage # " << i + 1 << " [ - - - ]" << endl;
		}
		else {
			cout << "stage # " << i + 1 << " [ " << stages[i]+1 << " " << Commands[stages[i]].TactsForStage(i) << " " << Commands[stages[i]].getTime() << " ]" << endl;
		}
	}
	cout << endl << endl << endl;
}

void Pipeline::showTime()
{
	cout << "Number of tacts:" << clkCounter << endl;
	for (int i = 0; i < numberOfCommands; i++)
		cout << time[i] << "  ";
	cout << endl;
}
