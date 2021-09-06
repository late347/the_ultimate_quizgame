#pragma once
#include <string>
#include "CommonConstants.h"
// chould be used to writing to a random access file (binary mode writing/reading)
// doing it would require exact size strings but would allow random access and exact insertion and deletion nicely
class CstyleRecord
{
public:

	CstyleRecord(const std::string& q = "",
		const std::string& corr = "",
		const std::string& wrong1 = "",
		const std::string& wrong2 = "",
		const std::string& wrong3 = "")

	{


	}


	void setQuestion(const std::string& val)
	{
		int length = val.size();
		// truncate if necessary
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		val.copy(question, length);
		question[length] = '\0';
	}
	std::string getQuestion()const
	{
		return std::string(question);
	}


	void setCorrectAnswer(const std::string& val)
	{
		int length = val.size();
		// truncate if necessary
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		val.copy(correctAnswer, length);
		correctAnswer[length] = '\0';
	}
	std::string getCorrectAnswer()const { return std::string(correctAnswer); }


	std::string getFirstFalseChoice()const
	{
		return std::string(false1);
	}
	void setFirstFalseChoice(const std::string& val)
	{
		int length = val.size();
		// truncate if necessary
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		val.copy(false1, length);
		false1[length] = '\0';
	}

	void setSecondFalseChoice(const std::string& val)
	{
		int length = val.size();
		// truncate if necessary
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		val.copy(false2, length);
		false2[length] = '\0';
	}
	std::string getSecondFalseChoice() { return std::string(false2); }


	void setThirdFalseChoice(const std::string& val)
	{
		int length = val.size();
		// truncate if necessary
		length = (length < config::charlimit ? length : (config::charlimit - 1));
		val.copy(false3, length);
		false3[length] = '\0';
	}
	std::string getThirdFalseChoice() { return std::string(false3); }




private:
	char question[config::charlimit];
	char correctAnswer[config::charlimit];
	char false1[config::charlimit];
	char false2[config::charlimit];
	char false3[config::charlimit];
};

