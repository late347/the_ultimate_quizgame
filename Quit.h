#pragma once
#include "State.h"
#include "StateMachine.h"

class Quit :
	public State
{

	//methods
public:
	Quit(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void printMenu() override;
	virtual int getInput() override;

	//datamembers
public:
	const int numberOfMenuOptions{ 1 };
	const State::StateName name{ QUIT };

private:
	StateMachine& stateMachine;


};

