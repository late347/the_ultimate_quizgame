#pragma once
#include "State.h"
#include "StateMachine.h"
class MainMenu :
	public State
{
	//methods
public:
	MainMenu(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void printMenu() override;
	virtual int getInput() override;

	//datamembers
public:
	const int numberOfMenuOptions{ 4 };
	const State::StateName name{ MAINMENU };
	
private:
	StateMachine& stateMachine;

};

