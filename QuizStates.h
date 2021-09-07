#pragma once

#include "State.h"
#include "StateMachine.h"
#include <fstream>
#include "Record.h"
#include <algorithm>

class QuizGame : public State 
{
	//methods
public:
	QuizGame(StateMachine& sm) : stateMachine(sm) {}
	virtual void onEntry() override
	{
		initializeQuiz();
		playQuiz();
		



		stateMachine.changeState(MAINMENU);
	
	}
	virtual void onExit() override
	{
		
		float correctPercentage = (correctCount / gameQuestions.size() * 100);
		
		std::cout << "thank you for playing the Quiz Game!!\n";
		std::cout << "you got " << correctPercentage << " % of the questions correct\n";
		correctCount = 0;
		gameQuestions.clear();
	}

	bool playQuiz()
	{
		// which question we are now asking
		size_t qIdx = 0;
		int selection = 0;
		// play the game or go main menu 

		while (qIdx < gameQuestions.size() && selection != config::lastMenuChoiceQuiz)
		{
			auto correct_and_options = askQuestion(qIdx);
			
			int selection = getInput();
			
			auto userChoice = correct_and_options.second[selection-1];
			if (userChoice.compare(correct_and_options.first) == 0)
			{
				correctCount++;
			}
			
			qIdx++;
		}

		return false;
	}


	std::pair<const std::string, std::array<std::string, config::falseChoices+1>> askQuestion(size_t idx)
	{
		using namespace std;
		auto rec = gameQuestions[idx];
		array<string, config::falseChoices+1> options;

		// ask question
		cout << rec.getQuestion() << endl;

		string correct = rec.getCorrectAnswer();
		options[0] = correct;

		// get the question options and the correct answer and represent options random order
		for (size_t i = 0; i < config::falseChoices; i++)
		{
			options[i+1] = rec.getFalseChoices()[i];
		}

		// shuffle the question options
		std::random_shuffle(options.begin(), options.end());
		
		int optIdx = 1;

		// print the randomized options
		for (auto& opt : options)
		{
			cout << optIdx << ". " << opt << endl;
			optIdx++;
		}

		// return the options and the correct answer in pair
		pair <string, array<string, config::falseChoices + 1>> thePair{correct, options};
		return thePair;
	}



	
	virtual void printMenu() override
	{
	
	}
	virtual int getInput() override
	{
		return getNumericInput(config::falseChoices +2);
	}

	void initializeQuiz()
	{
		// read the questions from file
		// randomize the questions order
		// go to ask quiz questions and proceed with the quiz
		using namespace std;

		ifstream recordReader(config::filename, ios::in);
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
	const int numberOfMenuOptions{ config::falseChoices+2 };
	const State::StateName name{ QUIZGAME };

private:
	StateMachine& stateMachine;

	// list of questions for the quiz when its playing
// keep the game questions here for now
	std::vector<Record> gameQuestions;
	size_t correctCount = 0;

};

