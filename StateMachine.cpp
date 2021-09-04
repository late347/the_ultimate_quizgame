#include "StateMachine.h"
#include <stdexcept>
#include "MainMenu.h"

StateMachine::StateMachine()
 {
	
	// allocate the states here, start from mainmenu
	auto mm = new MainMenu(*this);
	possibleStates[State::StateName::MAINMENU] = mm;
	// remember to initialize the first state
	curState = mm;

	// put other states into state machine too

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
