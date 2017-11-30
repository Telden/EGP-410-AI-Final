#ifndef POLICESTATES_H
#define POLICESTATES_H

#include "StateMachine.h"

class PoliceStates : public StateMachine
{
	private :
		enum state { wander = 0, chase = 1, flee = 2, dead = 3 };

	public :
		PoliceStates();
		~PoliceStates();

		void handleEvent(const Event& theEvent);
};

#endif