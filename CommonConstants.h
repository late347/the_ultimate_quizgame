#pragma once

#ifndef COMMONCONSTANTS_H
#define COMMONCONSTANTS_H



namespace config
{
	// char limit for questions size in quiz
	static constexpr int charlimit = 61;

	// for false options in the quiz per each question
	static constexpr int falseChoices = 3;

	//for csv questions file
	static constexpr char delimiter = ';';

	// delimiters per line in csv depends on the amount of falsechoices per question!
	// 5 delimiters when there are 
	/*
	question;answer;false1;false2;false3;\n
	question;answer;false1;false2;false3;\n
	question;answer;false1;false2;false3;\n
	question;answer;false1;false2;false3;\n
	...
	*/
	static constexpr int delimitersCount = 5;

	//filename for questions file for records
	static const char* filename = "quizgame_questions.csv";

	// in the actual quizgame it prints out the 1 correct option, and 3 false options and quitChoice
	// so its here to denote when you play the game and select quit it actually quits as the last choice...
	// quizstates.h
	static constexpr int quitChoiceMenuNumber = (falseChoices + 2);
}

#endif // !COMMONCONSTANTS_H
