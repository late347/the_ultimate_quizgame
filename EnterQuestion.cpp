#include "EnterQuestion.h"
#include <iostream>
#include <string>
#include <vector>
#include "Record.h"

void EnterQuestion::onEntry()
{
	using namespace std;
	
	/*enter the question and correct answer and three false options*/
	cout << "Enter a question and that you want to be in the quiz game (60 chars) \n";
	std::string question = getStringInput();

	// enter correct answer
	cout << "Enter a correct answer to that question (60 chars) \n";
	std::string correct = getStringInput();

	// enter false choices
	std::vector<std::string> falses;
	for (size_t i = 1; i <= wrongChoices; i++)
	{
		cout << "Enter a false option to that question (60 chars) there will be 3 false options to a question\n";
		falses.push_back(getStringInput());
	}

	// save for the moment the record if its necessary to write it to file
	Record record(question, correct, falses);


	/*ask again the user what to do*/
	printMenu();
	int userInput = getNumericInput(numberOfMenuOptions);

	// handle state transitions based on the user choices.
	switch (userInput)
	{
	case 1:
		// record will be written to file
		stateMachine.saveableQuestionData = record;
		stateMachine.changeState(SAVEQUESTION);
		break;
	case 2:  case 3:
		// dont do anything basically just goto main menu
		// old questions data will be resetted though
		stateMachine.saveableQuestionData = Record{};
		stateMachine.changeState(MAINMENU);
		break;
		// go to main menu also
		break;
	case 4: 
		// quit program
		stateMachine.saveableQuestionData = Record{};
		stateMachine.changeState(QUIT);
		break;
	default:
		throw std::logic_error("unknown state transition based on user input??? not handled well");
		break;
	}


}

void EnterQuestion::onExit()
{
}

void EnterQuestion::printMenu()
{
	using namespace std;
	cout << "Select what you want to do next \n";
	cout << "1. save question to file (you can then add more questions also) \n";
	cout << "2. discard question (after it you go to mainmenu) \n";
	cout << "3. main menu (also discards question) \n";
	cout << "4. quit \n";
}

int EnterQuestion::getInput()
{
	int answ{ 0 };
	answ = getNumericInput(EnterQuestion::numberOfMenuOptions);
	return answ;
}

std::string EnterQuestion::getStringInput()
{
	std::string buf;

	
	bool running = true;
	while(running)
	{
		std::getline(std::cin, buf);
		if (std::cin && buf.size() <= 60) 
		{
			running = false;
		}
		else
		{
			std::cout << "you exceeded character limit, write 60 chars only\n";
			std::cin.clear();
			buf.clear();
		}
	}

	return buf;
}