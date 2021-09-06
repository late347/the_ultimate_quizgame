#include <iostream>
#include "Record.h"
#include <sstream>
#include <string>
#include "CommonConstants.h"
std::ostream& operator<<(std::ostream& os, const Record& rec)
{
	os << rec.question << rec.correctAnswer;
	for (auto& i : rec.falseChoices)
	{
		os << i;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Record& rec)
{
	// probablyu works for the basic case when all is formatted well!
	// check the formatting from stream was correct and then assign
	// check that there is 5 semicolons, and get the strings before those
	/*
		int semicolons = 0;
	std::istringstream ss;
	std::string q, a, f1, f2, f3;
	std::string endOfLine;


	std::getline(is, q, ';');
	std::getline(is, a, ';');
	std::getline(is, f1, ';');
	std::getline(is, f2, ';');
	std::getline(is, f3, ';');
	std::getline(is, endOfLine, '\n');
	std::vector<std::string> falses;
	falses.push_back(f1);
	falses.push_back(f2);
	falses.push_back(f3);
	Record rec2(q, a, falses);
	rec = rec2;
	*/
	using namespace std;
	string csvLine;

	getline(is, csvLine, '\n');
	if (!is)
	{
		rec = Record{};
		return is;
	}

	size_t start = 0, end = 0, delims = 0;
	string token;
	vector<string> tokens;
	// seek that there are 5 semicolons and max substr of SaveQuestion::charlimit-1 (60 real characters by default)
	while (start != string::npos)
	{

		// find delim
		end = csvLine.find(config::delimiter, start);
		std::string candidate = csvLine.substr(start, end-start);

		// rec must have question, answer and three bad choices per line and not more
		if(candidate.size() >=1 && candidate.size() < config::charlimit && tokens.size() < config::delimitersCount)
		{
			// valid token found
			tokens.push_back(candidate);
		}
		else
		{
			rec = Record{};
			std::cout << "the file was badly formatted sadly!! cant do much with this\n";
			return is;
		}

		delims++;
		//skip to the next substr location
		start = csvLine.find_first_not_of(config::delimiter, end);
		candidate = "";
	}

	if(tokens.size() != config::delimitersCount)
	{
		rec = Record{};
		std::cout << "the file was badly formatted sadly!! cant do much with this\n";
		return is;
	}
	vector<string> falsesVec{tokens[2], tokens[3], tokens[4] };
	
	
	Record rec2{tokens[0], tokens[1], falsesVec};
	rec = rec2;
	return is;
	
}
