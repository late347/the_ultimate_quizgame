#include "Quit.h"
#include "State.h"
#include "StateMachine.h"
#include <iostream>



void Quit::onEntry()
{
	printMenu();
}

void Quit::onExit()
{
}

void Quit::printMenu()
{
	using namespace std;
	cout << "you decided to quit the game, thank you for playing!\n";
}

int Quit::getInput()
{
	return 0;
}
