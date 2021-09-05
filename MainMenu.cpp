#include "MainMenu.h"
#include <iostream>
#include <limits>

void MainMenu::onEntry()
{
	using namespace std;

	cout << "Welcome to the quiz game, you can add new questions to save to a file\n";
	cout << "you can also take the quiz and tells you the statistics about correct answers\n";
	cout << "you can also remove the file with the questions\n or simply quit the game";

	printMenu();
	int userInput = getInput();

	// here you process the users actions to decide
	switch (userInput)
	{
	case 1: 
		stateMachine.changeState(ENTERQUESTION);
		break;
	case 2:
		// attempt to take the quiz, but dont take the quiz if the questionfile was empty!
		break;
	case 3: 
		// delete questionsfromfile state
		break;
	case 4:
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
