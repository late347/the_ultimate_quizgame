#pragma once
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iostream>
#include "SaveQuestion.h"


class Record
{

public:

	Record() {}

	Record(const std::string& q, const std::string& a, const std::array<std::string, 3 >& falses)
	{
		// verify charcount was ok or truncate it 
		question = q;
			correctAnswer = a;

		for (size_t i = 0; i < 3; i++)
		{
			falseChoices[i] = falses[i];
		}
	}

	Record(const std::string& q, const std::string& a, const std::vector<std::string>& falses)
	{

			// verify charcount was ok or truncate it 
		question = q;
		correctAnswer = a;
		for (size_t i = 0; i < 3; i++)
		{
			falseChoices[i] = falses[i];
		}
	}
	std::string getQuestion() const { return  question; }
	std::string getCorrectAnswer() const { return  correctAnswer; }
	std::array<std::string, 3> getFalseChoices() const { return falseChoices; }

	void setQuestion(const std::string& val){ question = val; }
	void setCorrectAnswer(const std::string& val) { correctAnswer = val; }

	void setFalseChoices(const std::array<std::string, 3>& newfalses){falseChoices = newfalses;}



public:


private:

	friend std::ostream& operator<< (std::ostream& os, const Record& rec);
	friend std::istream& operator>>(std::istream& is, Record& rec);


	std::string question;
	std::string correctAnswer;
	std::array<std::string, 3> falseChoices;



};

