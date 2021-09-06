#pragma once
#include <iostream>
#include <limits>
class State
{
public:
	enum StateName
	{
		MAINMENU, 
		ENTERQUESTION, 
		SAVEQUESTION, 
		REMOVEQUESTIONS, 
		QUIZGAME, 
		QUIT
	};


	int getNumericInput(int menuOptions) {
		int a{ 0 };
		bool keepGoing = true;

		while (keepGoing)
		{
			std::cout << "select an option please\n";
			std::cin >> a;
			if (std::cin && a <= menuOptions && a > 0)
			{
				keepGoing = false;
			}
			else
			{
				std::cout << "Your answer was not valid, try again\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		return a;
	}

	virtual ~State() {  }
	
	virtual void onEntry() = 0; 
	virtual void onExit() = 0;
	virtual void printMenu() = 0;
	virtual int getInput() = 0;
};


