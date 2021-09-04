#include "SaveQuestion.h"

void SaveQuestion::onEntry()
{
	using namespace std;
	cout << "saving the question to the file...\n";

}

void SaveQuestion::onExit()
{
}

void SaveQuestion::printMenu()
{
	using namespace std;
	cout << "After the question was saved, select an option what to do next from below \n";
	cout << "1. enter a new question (to the quiz)\n";
	cout << "2. take the quiz\n";
	cout << "3. delete all questions\n";
	cout << "4. quit\n";
	
}

int SaveQuestion::getInput()
{
	int ans = getNumericInput(numberOfMenuOptions);
	return ans;
}
