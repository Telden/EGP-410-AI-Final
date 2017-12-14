#include "PoliceSteering.h"
#include "KinematicUnit.h"

#include "Game.h"
#include "Graph.h"
#include "Node.h"
#include "UnitManager.h"
#include "Player.h"
#include "Sprite.h"

// steering
#include "WanderToNode.h"

PoliceSteering::PoliceSteering(KinematicUnit *pMover)
{
   mpMover = pMover;
   Node* startingNode = GRAPH->getNode(0);
   mpWander = new WanderToNode(mpMover, startingNode, 5);

   //mpChase = ???
   //mpFlee = ???
   //mpDead = ???

   // add states to state machine
   mStateMachine.AddState(mpWander);
   mStateMachine.AddState(mpChase);
   mStateMachine.AddState(mpFlee);
   mStateMachine.AddState(mpDead);

   // add connections to state machine based on states
   mStateMachine.AddConnection(mpWander, mpChase);
   mStateMachine.AddConnection(mpWander, mpFlee);
   mStateMachine.AddConnection(mpWander, mpDead);

   mStateMachine.AddConnection(mpChase, mpWander);
   mStateMachine.AddConnection(mpChase, mpFlee);
   mStateMachine.AddConnection(mpChase, mpDead);

   mStateMachine.AddConnection(mpFlee, mpWander);
   mStateMachine.AddConnection(mpFlee, mpChase);
   mStateMachine.AddConnection(mpFlee, mpDead);

   mStateMachine.changeCurrentState(mpWander);
}

PoliceSteering::~PoliceSteering()
{
   delete mpTarget;
   delete mpMover;
   delete mpWander;
   delete mpChase;
   delete mpFlee;
   delete mpDead;
}

Steering* PoliceSteering::getSteering()
{
   // do collision to decide the current state?

   // gotta update the player so we can get its current position
   mpTarget = UNIT_MANAGER->getPlayerUnit();

   // make a bool to check if we've collided with the player
   bool colPlayer = false;;
   if(mpMover->mCurrentLevel == mpTarget->mCurrentLevel)
		 colPlayer = mCol.circleOnCircle(mpMover->getPosition(), 50 , mpTarget->getPosition(), 50);

   // report on if we've collided with the player
   if (colPlayer)
      std::cout << "enemy detecting player - circ x circ" << std::endl;
   
   // have the steering object that gets returned be the steering of the current state
   return mStateMachine.doCurrentState();
   return this;
}