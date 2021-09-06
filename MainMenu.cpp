#include "MainMenu.h"
#include <iostream>
#include <limits>
void MainMenu::onEntry()
{
	using namespace std;

	

	printMenu();
	int userInput = getInput();

	// here you process the users actions to decide
	switch (userInput)
	{
	case 1: 
		// enter a question to list
		stateMachine.changeState(ENTERQUESTION);
		break;
	case 2:
		// attempt to take the quiz, but dont take the quiz if the questionfile was empty!
		if (!stateMachine.isQuestionFileEmpty())
		{
			//TODO finish the quiz states!!!
			stateMachine.changeState(QUIZSTART);
			break;
		}
		else
		{
			std::cout << "questions File was totally empty cannot start quiz, going back to mainmenu\n";
			stateMachine.changeState(MAINMENU);
			break;
		}
	case 3: 
		// delete questionsfromfile state
		stateMachine.changeState(REMOVEQUESTIONS);
		break;
	case 4:
		// quit game
		stateMachine.changeState(QUIT);
		break;
	default:
		break;
	}
}

void MainMenu::onExit()
{
}

void MainMenu::printMenu()
{
	using namespace std;
	cout << "1. enter a new question (to the quiz)\n";
	cout << "2. take the quiz\n";
	cout << "3. delete all questions\n";
	cout << "4. quit\n";
	
}

int MainMenu::getInput()
{
	int answer{ 0 };
	bool keepAsking = true;
	answer = getNumericInput(numberOfMenuOptions);
	return answer;
}
