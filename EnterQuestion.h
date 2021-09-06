#pragma once
#include "State.h"
#include "StateMachine.h"
#include <string>

class StateMachine;
class EnterQuestion :
    public State
{
	//methods
public:
	EnterQuestion(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void printMenu() override;
	virtual int getInput() override;
	std::string getStringInput();
	

	//datamembers
public:
	const int numberOfMenuOptions{ 4 };
	const State::StateName name{ ENTERQUESTION };
	
	


private:
	StateMachine& stateMachine;



};

