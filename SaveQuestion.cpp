#include "SaveQuestion.h"
#include "StateMachine.h"
#include <iostream>
#include <fstream>

void SaveQuestion::onEntry()
{

	writeQuestionsToFile();
	std::cout << "you questions were saved to the file, and then cleared from the memory\n";
	//  questions were saved to file so clear old ones
	stateMachine.resetQuestionsList();
	printMenu();
	int answer = getNumericInput(numberOfMenuOptions);
	switch (answer)
	{
	case 1: 

		// enter question to list
		stateMachine.changeState(ENTERQUESTION);
		break;
	case 2:
		
		// main menu
		stateMachine.changeState(MAINMENU);
		break;
	case 3:
		// quit
		stateMachine.changeState(QUIT);
		break;
	
	default:
		break;
	}
}

void SaveQuestion::writeQuestionsToFile()
{
	using namespace std;
	cout << "saving the question to the file...\n";

	ofstream outQuestionsStream(stateMachine.filename, ios::app);
	if (!outQuestionsStream)
	{
		throw std::logic_error("couldnt open even the file!??!!");
	}

	for (size_t i = 0; i < stateMachine.getQuestionsList().size(); i++)
	{
		auto rec = stateMachine.getQuestionsList()[i];
		// format the file as csv
		outQuestionsStream << rec.getQuestion() << ';' << rec.getCorrectAnswer() << ';';
		for (size_t i = 0; i < 3; i++)
		{
			outQuestionsStream << rec.getFalseChoices()[i];
			if (i < 2)
				outQuestionsStream << ';';
		}
		// start newline for the next record
		outQuestionsStream << endl;
	}

}

void SaveQuestion::onExit()
{
	

}

void SaveQuestion::printMenu()
{
	using namespace std;
	cout << "After the question was saved, select an option what to do next from below \n";
	cout << "1. enter a new question (to the quiz)\n";
	cout << "2. main menu\n";
	cout << "3. quit\n";

	
}

int SaveQuestion::getInput()
{
	int ans = getNumericInput(numberOfMenuOptions);
	return ans;
}
