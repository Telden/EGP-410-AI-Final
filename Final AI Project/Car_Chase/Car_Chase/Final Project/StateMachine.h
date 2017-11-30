#ifndef STATEMACHINE_H
#define STATEMACHINE_H

class State;

class StateMachine
{
	protected :
		State* mInitialState;
		State* mCurrentState;

	public :
		StateMachine();
		virtual ~StateMachine();
};

#endif