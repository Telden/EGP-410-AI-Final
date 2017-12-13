#include "StateMachine.h"

#include "Steering.h"
#include "WanderToNode.h"

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
   // check to see if the connection actually exists before changing states
   if (connectionExists(mpCurrentState, newState))
   {
      // change the current state to point to something else, this allows us to keep updating mpCurrentState without much effort
      mpCurrentState = newState;
   }
}

bool StateMachine::connectionExists(Steering* from, Steering* to)
{
   // check to see if mConnections contains the connection before changing states
   for (unsigned int i = 0; i < mConnections.size(); i++)
   {
      // if we didn't find the from, don't bother
      if (mConnections[i].mpFrom == from)
      {
         // if we find the to, the connection exists
         if (mConnections[i].mpTo == to)
         {
            return true;
         }
      }
   }
   // otherwise the connection wasn't found
   return false;
}