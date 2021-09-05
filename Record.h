#pragma once
#include <string>
#include <vector>
#include <array>


class Record
{

public:
	Record() {}

	Record(const std::string& q, const std::string& a, const std::array<std::string, 3 >& falses)
		: question(q), correctAnswer(a)
	{
		for (size_t i = 0; i < 3; i++)
		{
			falseChoices[i] = falses[i];
		}
	}

	Record(const std::string& q, const std::string& a, const std::vector<std::string>& falses)
		: question(q), correctAnswer(a)
	{
		for (size_t i = 0; i < 3; i++)
		{
			falseChoices[i] = falses[i];
		}
	}
	std::string getQuestion() const { return  question; }
	std::string getCorrectAnswer() const { return  correctAnswer; }
	std::array<std::string, 3> getFalseChoices() const { return falseChoices; }


public:


private:



	std::string question;
	std::string correctAnswer;
	std::array<std::string, 3> falseChoices;



};

