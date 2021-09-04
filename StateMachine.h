#pragma once
#include <map>
#include "State.h"
#include "Record.h"

class StateMachine
{
	

public:

	
	StateMachine();
	~StateMachine();

	void changeState(State* theNewState);
	void changeState(State::StateName theNewState);

	//possibleStates
	std::map<State::StateName, State*> possibleStates;

	//curState
	State* curState; //one curState of statemachine

	//Record that can be written to the questions file
	Record saveableQuestionData;

	
};

