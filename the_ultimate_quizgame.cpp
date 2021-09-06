// the_ultimate_quizgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "Record.h"
#include <vector>


#include <iostream>

int main()
{
	using namespace std;
    std::cout << "Hello World! Welcome to the quiz game!\n";
	std::cout << "Welcome to the quiz game, you can add new questions to save to a file\n";
	std::cout << "you can also take the quiz and tells you the statistics about correct answers\n";
	std::cout << "you can also remove the file with the questions\n or simply quit the game";


	// read the questions from file
	// randomize the questions order
	// go to ask quiz questions and proceed with the quiz
	
	std::vector<Record> gameQuestions;


	ifstream recordReader("quizgame_questions.csv", ios::in);
	if (!recordReader)
	{
		throw logic_error("couldnt check if file was empty!?!?\n");
	}

	

	Record rec;
	cout << "reading the quiz questions from csv file to memory\n";

	//process the records based on csv delimiter
	while (recordReader >> rec)
	{

		gameQuestions.push_back(rec);
		rec = Record{};
		int debug346 = 0;
	}
	return 0;
}





