#pragma once
#include "State.h"
class StateMachine;

class SaveQuestion :
    public State
{
public:
	SaveQuestion(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override;
	virtual void onExit() override;
	virtual void printMenu() override;
	virtual int getInput() override;
	void writeQuestionsToFile();


	//datamembers
public:
	const int numberOfMenuOptions{ 3 };
	const State::StateName name{ SAVEQUESTION };
	static constexpr int charLimit{ 61 };
	static constexpr int wrongChoices{ 3 };
	static constexpr char delimiter = ';';

private:
	StateMachine& stateMachine;
};

