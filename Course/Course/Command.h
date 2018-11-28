#pragma once
#include "Type.h"
#include "stdafx.h"
class Command
{
private: 
	int stage;
	int clk;
	bool status;
	int clkForStage[CONVSIZE]; 
	int P1[3];
	int P2[3];
	type operand1;
	type operand2;
	type command_type;

public:
	Command();
	~Command();
	int chooseP(int P[]);
	void showCommandInfo();
	void nextStage();
	void setStage(int num);
	int getStage();
	int TactsForStage(int idx);
	bool getStatus();
	void setStatus();
	int getTime();
	void addClk();
	void wait();

};

