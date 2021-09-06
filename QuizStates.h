#pragma once

#include "State.h"
#include "StateMachine.h"
#include <fstream>
#include "Record.h"


class QuizStart : public State 
{
	//methods
public:
	QuizStart(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override
	{
	
	}
	virtual void onExit() override
	{
	
	}
	virtual void printMenu() override
	{
	
	}
	virtual int getInput() override
	{
	
	}

	void initializeQuiz()
	{
		// read the questions from file
		// randomize the questions order
		// go to ask quiz questions and proceed with the quiz
		using namespace std;



		ifstream recordReader(stateMachine.filename, ios::in);
		if (!recordReader)
		{
			throw logic_error("couldnt check if file was empty!?!?\n");
		}		

		gameQuestions.clear();
		
		Record rec;
		cout << "reading the quiz questions from csv file to memory\n";

		//process the records based on csv delimiter
		while (recordReader >> rec )
		{
			
			gameQuestions.push_back(rec);
			rec = Record{};
		}
	}

	//datamembers
public:
	const int numberOfMenuOptions{ 5 };
	const State::StateName name{ QUIZSTART };

private:
	StateMachine& stateMachine;

	// list of questions for the quiz when its playing
	// keep the game questions here because theyre fundamentally belongin to quizgame
	std::vector<Record> gameQuestions;
	size_t correctAnswers{ 0 };

};