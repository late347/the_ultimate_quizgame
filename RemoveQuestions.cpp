#include "RemoveQuestions.h"
#include <fstream>
#include "StateMachine.h"


void RemoveQuestions::onEntry()
{
	using namespace std;
	cout << "removing the questions from the file...\n";
	removeQuestions();
	int userInput = getInput();
	switch (userInput)
	{
		//mainmenu
	case 1: stateMachine.changeState(MAINMENU); break;
		//quit
	case 2: stateMachine.changeState(QUIT); break;

	default:
		break;
	}
}

void RemoveQuestions::onExit()
{
	
}

void RemoveQuestions::printMenu()
{
	using namespace std;
	cout << "select your next action from below \n";

	cout << "1. main menu (you can then enter questions etc...)\n";
	cout << "2. quit\n";

}

int RemoveQuestions::getInput()
{
	int request = getNumericInput(this->numberOfMenuOptions);
	return request;
}

void RemoveQuestions::removeQuestions()
{
	using namespace std;

	ofstream outQuestionsStream(stateMachine.filename, ios::out | ios::trunc);
	if (!outQuestionsStream)
	{
		throw std::logic_error("couldnt open even the file for removing the questions!??!!");
	}
}
