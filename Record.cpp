#include <iostream>
#include "Record.h"

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
	// TODO: write properly
	// check the formatting from stream was correct and then assign
	// check that there is 5 semicolons, and get the strings before those
	int semicolons = 0;
	std::string q, a, f1, f2, f3;

	std::getline(is, q, ';');
	std::getline(is, a, ';');
	std::getline(is, f1, ';');
	std::getline(is, f2, ';');
	std::getline(is, f3, ';');
	std::vector<std::string> falses;
	falses.push_back(f1);
	falses.push_back(f2);
	falses.push_back(f3);
	Record rec2(q, a, falses);
	rec = rec2;
	return is;

}
