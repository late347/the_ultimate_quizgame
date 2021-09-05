#include "StateMachine.h"
#include <stdexcept>
#include "MainMenu.h"
#include "RemoveQuestions.h"
#include "EnterQuestion.h"
#include "Quit.h"
#include "SaveQuestion.h"



class RemoveQuestions;
class Record;

StateMachine::StateMachine()
 {
	

	// allocate the states here, start from mainmenu
	auto mm = new MainMenu(*this);
	possibleStates[State::StateName::MAINMENU] = mm;
	
	// remember to initialize sm into the first state
	curState = mm;
	

	// put other states into state machine too TODO...
	possibleStates[State::StateName::REMOVEQUESTIONS] = new RemoveQuestions(*this);
	possibleStates[State::StateName::ENTERQUESTION] = new EnterQuestion(*this);
	possibleStates[State::StateName::QUIT] = new Quit(*this);
	possibleStates[State::StateName::SAVEQUESTION] = new SaveQuestion(*this);

}

StateMachine::~StateMachine()
{
	for (auto& state : possibleStates)
	{
		delete state.second;
	}
}

void StateMachine::changeState(State* newStateToEnter)
{
	//check not nullptr
	//exit curState
	//set new state
	//enter new state
	if (newStateToEnter) {
		curState->onExit();
		curState = newStateToEnter;
		curState->onEntry();
	}
	else {
		throw std::logic_error("newStatePtr was nullptr");
	}
}

void StateMachine::changeState(State::StateName theNewState)
{
	auto newPtr = possibleStates.at(theNewState);
	curState->onExit();
	curState = newPtr;
	curState->onEntry();

}
