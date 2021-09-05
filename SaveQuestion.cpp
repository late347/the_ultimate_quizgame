#include "SaveQuestion.h"
#include "StateMachine.h"
#include <iostream>
#include <fstream>

void SaveQuestion::onEntry()
{
	writeQuestion();
	int answer = getNumericInput(numberOfMenuOptions);
	switch (answer)
	{
	case 1: 
		stateMachine.changeState(ENTERQUESTION);
		break;
	case 2:
		// go to take the quiz start state
		// TODO
		break;
	case 3:
		// del questions from file
		stateMachine.changeState(REMOVEQUESTIONS);
		break;
	case 4:
		stateMachine.changeState(MAINMENU);
		break;
	case 5:
		stateMachine.changeState(QUIT);
		break;
	default:
		break;
	}
}

void SaveQuestion::writeQuestion()
{
	using namespace std;
	cout << "saving the question to the file...\n";

	ofstream outQuestionsStream("quizgame_questions.csv",  ios::app);
	if (!outQuestionsStream)
	{
		throw std::logic_error("couldnt open even the file!??!!");
	}

	// format the file as csv
	outQuestionsStream << stateMachine.saveableQuestionData.getQuestion() << ';' << stateMachine.saveableQuestionData.getCorrectAnswer() << ';';
	for (size_t i = 0; i < 3; i++)
	{
		outQuestionsStream << stateMachine.saveableQuestionData.getFalseChoices()[i];
		if (i < 2)
			outQuestionsStream << ';';
	}
	outQuestionsStream << endl;

}

void SaveQuestion::onExit()
{
	// resett the savedData
	stateMachine.saveableQuestionData = Record{};

}

void SaveQuestion::printMenu()
{
	using namespace std;
	cout << "After the question was saved, select an option what to do next from below \n";
	cout << "1. enter a new question (to the quiz)\n";
	cout << "2. take the quiz\n";
	cout << "3. delete all questions\n";
	cout << "4. main menu\n";
	cout << "5. quit\n";
	
}

int SaveQuestion::getInput()
{
	int ans = getNumericInput(numberOfMenuOptions);
	return ans;
}
