#pragma once
#include <map>
#include "State.h"
#include "Record.h"
#include <iostream>
#include <fstream>
#include <iomanip>

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
		ifstream questionInStream(filename, ios::in);
		if (!questionInStream)
		{
			throw logic_error("couldnt check if file was empty!?!?\n");
		}
		// pFile.peek() == std::ifstream::traits_type::eof()

		return (questionInStream.peek() == std::ifstream::traits_type::eof());

	}

	//possibleStates
	std::map<State::StateName, State*> possibleStates;

private:

	//curState
	State* curState; //one curState of statemachine



	int correctAnswersNumber = 0;


	//Record that can be written to the questions file before writing to file
	std::vector<Record> questionsList;

public:
	
	

	//filename for questions file for records
	 const char* filename = "quizgame_questions.csv";
	
};

