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

	Record reccc;
	rec = reccc;
	return is;
	
}
