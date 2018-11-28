#include "stdafx.h"
#include "Command.h"

using namespace std;

Command::Command()
{
	stage = -1;
	clk = 0;
	status = false;
	P1[0] = 90;  P1[1] = 80; P1[2] = 60;
	P2[0] = 90;  P2[1] = 70; P2[2] = 50;
	int p = chooseP(P1);
	operand1.setType1(p);
	operand2.setType1(p);
	command_type.setType2(chooseP(P2));
	clkForStage[0] = 1; 
	clkForStage[1] = operand1.getMemRef();
	clkForStage[2] = operand2.getMemRef();
	clkForStage[3] = command_type.getMemRef();
	clkForStage[4] = operand2.getMemRef();
}

Command::~Command()
{
	stage = -1;
}

void Command::showCommandInfo()
{
	cout << "Type of operand #1: " << operand1.getType() << endl;
	cout << "Memory reference of operand #1: " << clkForStage[1]<< endl;
	cout << "Type of operand #2: " << operand2.getType() << endl;
	cout << "Memory reference of operand #2: " << clkForStage[2] << endl;
	cout << "Tacts for calculation: " << clkForStage[3] << endl;
	cout << "Write-back time: " << clkForStage[4]<<endl;
	cout << "----------------------------------" << endl;
}

void Command::nextStage()
{
	if (stage < 5)
		stage++;
}
void Command::setStage(int num)
{
	if (num == 0)
		stage = 0;
	else stage = num;
}
int Command::getStage()
{
	return stage;
}

int Command::TactsForStage(int idx)
{
	return clkForStage[idx];
}

void Command::addClk()
{
	if (clkForStage[stage] > 0)
		clkForStage[stage]--;
	clk++;
}
void Command::wait()
{
	clk++;
}

bool Command::getStatus()
{
	return status;
}

void Command::setStatus()
{
	this->status = true;
}

int Command::getTime()
{
	return clk;
}

int Command::chooseP(int P[])
{
	int idx = rand() % 3;
	return P[idx];
}
