#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <vector>

class Steering;
struct ConnectionSM;

class StateMachine
{
   private:
      std::vector<Steering*> mpStates;
      std::vector<ConnectionSM> mConnections;
      
   public:
      Steering* mpCurrentState;

      StateMachine();
      ~StateMachine();

      Steering* doCurrentState();
      void changeCurrentState(Steering* newState);

      bool connectionExists(Steering* from, Steering* to);

      void AddState(Steering* newSteer);
      void AddConnection(Steering* from, Steering* to);
};

struct ConnectionSM
{
   ConnectionSM(Steering* from, Steering* to)
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