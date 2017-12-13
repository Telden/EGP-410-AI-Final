#include "PoliceSteering.h"
#include "KinematicUnit.h"

#include "Game.h"
#include "UnitManager.h"
#include "Player.h"
#include "Sprite.h"

PoliceSteering::PoliceSteering(KinematicUnit *pMover)
   :mpMover(pMover)
{
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
}

Steering* PoliceSteering::getSteering()
{
   // do collision to decide the current state?

   // gotta update the player so we can get its current position
   mpTarget = UNIT_MANAGER->getPlayerUnit();

   //mRay.setStartRay(mpMover->getPosition());
   //mRay.setEndRay(mpTarget->getPosition());
   //canSeePlayer = mRay.doIt();

   // make a bool to check if we've collided with the player
   bool colPlayer;
   colPlayer = mCol.circleOnCircle(mpMover->getPosition(), 50 , mpTarget->getPosition(), 50);

   // report on if we've collided with the player
   if (colPlayer)
      std::cout << "enemy detecting player - circ x circ" << std::endl;
   
   // have the steering object that gets returned be the steering of the current state
   return mStateMachine.doCurrentState();
}