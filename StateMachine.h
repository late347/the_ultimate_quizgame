#pragma once
#include <map>
#include "State.h"
#include "Record.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "CommonConstants.h"


class StateMachine
{

public:

	StateMachine();
	~StateMachine();

	void changeState(State* theNewState);
	void changeState(State::StateName theNewState);

	void addQuestionToList(const Record& rec)
	{
		questionsList.push_back(rec);
	}
	void resetQuestionsList() { questionsList.clear(); }

	std::vector<Record> getQuestionsList() const { return questionsList; }
	
	// sanity check to verify that the questionsfile has questions before attempting to take the quiz actually
	// cant take the quiz if the file had been erased before attempting to take it
	bool isQuestionFileEmpty()
	{
		using namespace std;
		ifstream questionInStream(config::filename, ios::in);
		if (!questionInStream)
		{
			throw logic_error("couldnt check if file was empty!?!?\n");
		}

		return (questionInStream.peek() == std::ifstream::traits_type::eof());

	}

	//possibleStates
	std::map<State::StateName, State*> possibleStates;

private:

	//current state
	State* curState; 


	// correct answers in the quiz when taking it
	int correctAnswersNumber = 0;


	//Record that can be written to the questions file before writing to file
	// it could be in the state classes like EnterQuestion or SaveQuestion but 
	// both states use it so better to share that data here
	std::vector<Record> questionsList;

	
};

