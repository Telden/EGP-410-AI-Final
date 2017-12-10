#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <vector>

class Steering;
struct Connection;

class StateMachine
{
   private:
      std::vector<Steering*> mpStates;
      std::vector<Connection> mConnections;
      Steering* mpCurrentState;

   public:
      StateMachine();
      ~StateMachine();

      Steering* doCurrentState();
      void changeCurrentState(Steering* newState);

      void AddState(Steering* newSteer);
      void AddConnection(Steering* from, Steering* to);
};

struct Connection
{
   Connection(Steering* from, Steering* to)
   {
      mpFrom = from;
      mpTo = to;
   }

   /*~Connection()
   {
      if (mpFrom != NULL) delete mpFrom;
      if (mpTo != NULL) delete mpTo;
   }*/
   
   Steering* mpFrom;
   Steering* mpTo;
};

#endif