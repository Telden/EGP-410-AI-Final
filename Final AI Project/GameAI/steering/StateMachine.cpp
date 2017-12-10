#include "StateMachine.h"

#include "Steering.h"

StateMachine::StateMachine()
{
   
}

StateMachine::~StateMachine()
{
   for (unsigned int i = 0; i < mpStates.size(); i++)
   {
      delete mpStates[i];
   }
}

Steering* StateMachine::doCurrentState()
{
   // do the steering
   return mpCurrentState->getSteering();
}

void StateMachine::AddState(Steering* newSteer)
{
   // add a pointer to the state
   mpStates.push_back(newSteer);
}

void StateMachine::AddConnection(Steering* from, Steering* to)
{
   // add pointers to represent a connection between two states
   mConnections.push_back(Connection(from, to));
}

void StateMachine::changeCurrentState(Steering* newState)
{
   // change the current state to point to something else, this allows us to keep updating mpCurrentState without much effort
   mpCurrentState = newState;
}