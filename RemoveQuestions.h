#pragma once
#include "State.h"

class StateMachine;

class RemoveQuestions :
    public State
{
public:
	RemoveQuestions(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void printMenu() override;
	virtual int getInput() override;
	void removeQuestions();


	//datamembers
public:
	const int numberOfMenuOptions{ 2 };
	const State::StateName name{ REMOVEQUESTIONS };
	static constexpr int charLimit{ 61 };
	static constexpr int wrongChoices{ 3 };

private:
	StateMachine& stateMachine;
};

