#pragma once
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <iostream>
#include "SaveQuestion.h"
#include "CommonConstants.h"
#include <algorithm>
class Record
{

public:

	Record() {}

	Record(const std::string& q, const std::string& a, const std::array<std::string, config::falseChoices >& falses)
	{
		
		// verify charcount was ok or truncate it 
		
		
		int length = q.size();
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		question = q.substr(0, length);

		length = a.size();
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		correctAnswer = a.substr(0, length);


		for (size_t i = 0; i < config::falseChoices; i++)
		{
			length = falses[i].size();
			length = (length < config::charlimit ? length : (config::charlimit - 1));

			falseChoices[i] = falses[i].substr(0, length);
		}
	}

	Record(const std::string& q, const std::string& a, const std::vector<std::string>& falses)
	{
		// TODO

			// verify charcount was ok or truncate it 

		int length = q.size();
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		question = q.substr(0, length);

		length = a.size();
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		correctAnswer = a.substr(0, length);

		bool fileWasGood=true;
		if (falses.size() != config::falseChoices)
		{
			fileWasGood = false;
		}


		if (true)
		{
			for (size_t i = 0; i < config::falseChoices; i++)
			{
				length = falses[i].size();
				length = (length < config::charlimit ? length : (config::charlimit - 1));
				falseChoices[i] = falses[i].substr(0, length);
			}
		}
		else
		{
			for (size_t i = 0; i < config::falseChoices; i++)
			{
				falseChoices[i] = "";
				std::cout << "bad false answers existed in the file, creating empty string instead\n";
			}
		}

	}
	std::string getQuestion() const { return  question; }
	std::string getCorrectAnswer() const { return  correctAnswer; }
	std::array<std::string, config::falseChoices> getFalseChoices() const { return falseChoices; }

	void setQuestion(const std::string& val){ question = val; }
	void setCorrectAnswer(const std::string& val) { correctAnswer = val; }

	void setFalseChoices(const std::array<std::string, 3>& newfalses){falseChoices = newfalses;}






private:

	friend std::ostream& operator<< (std::ostream& os, const Record& rec);
	friend std::istream& operator>>(std::istream& is, Record& rec);


	std::string question;
	std::string correctAnswer;
	std::array<std::string, config::falseChoices> falseChoices;



};

