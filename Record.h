#pragma once
#include <string>
#include <vector>
#include <array>


class Record
{
	
public:
	Record(){}

	Record(const std::string& q, const std::string& a, const std::array<std::string, 3 >& falses)
		: question(q), correctAnswer(a)
	{
		for (size_t i = 0; i < wrongChoices; i++)
		{
			falseChoices[i] = falses[i];
		}
	}

	Record(const std::string& q, const std::string& a, const std::vector<std::string>& falses)
	: question(q), correctAnswer(a) 
	{
		for (size_t i = 0; i < wrongChoices; i++)
		{
			falseChoices[i] = falses[i];
		}
	}

protected:
	

private:

	static constexpr int wrongChoices{ 3 };

	std::string question;
	std::string correctAnswer;
	std::array<std::string, wrongChoices> falseChoices;



};

