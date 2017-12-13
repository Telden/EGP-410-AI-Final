#include "DeadSteering.h"

#include "KinematicUnit.h"

DeadSteering::DeadSteering(KinematicUnit* pMover)
{

}

Steering* DeadSteering::getSteering()
{
   if (counter < maxCount)
   {
      counter++;
   }
   else
   {
      // change position to "respawn"
      // call to change state
      counter = 0;
      return this;
   }

   // move the enemy far away from the world
   mpMover->setPosition(Vector2D(-1000, -1000));

   // no need to move
   mLinear = 0;
   mAngular = 0;
   return this;
}