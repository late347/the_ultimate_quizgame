#pragma once
#include <map>
#include "State.h"
#include "Record.h"
#include <iostream>

class StateMachine
{

public:

	StateMachine();
	~StateMachine();

	void changeState(State* theNewState);
	void changeState(State::StateName theNewState);

	//possibleStates
	std::map<State::StateName, State*> possibleStates;

	//bool checkQuestionsFileEmtpy() const 
	//{ // has atleast one question, in there
	//	
	//}

private:

	//curState
	State* curState; //one curState of statemachine

public:
	//Record that can be written to the questions file
	Record saveableQuestionData;

	//filename for questions file for records
	 const char* filename = "quizgame_questions.csv";
	
};

