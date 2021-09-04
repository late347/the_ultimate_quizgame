#pragma once
#include <fstream>
#include <vector>
class Record;

class FileAccessor
{	

public:
	void writeQuestionToFile(const Record& rec){}
	void getQuestionsFromFile(std::vector<Record>& questionsVec){}
	void shuffleQuestions(std::vector<Record>& questionsVec){}
	void eraseQuestionFile(){}

private:

};

