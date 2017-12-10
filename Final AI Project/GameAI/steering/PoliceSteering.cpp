#include "PoliceSteering.h"
#include "KinematicUnit.h"

#include "Game.h"
#include "UnitManager.h"
#include "Player.h"
#include "Sprite.h"

PoliceSteering::PoliceSteering(KinematicUnit *pMover)
   :mpMover(pMover)
{
   //mApplyDirectly = true
}

Steering* PoliceSteering::getSteering()
{
   mpTarget = UNIT_MANAGER->getPlayerUnit();

   //std::cout << "X: " << mpTarget->getPosition().getX() << ", Y:" << mpTarget->getPosition().getY() << std::endl;
   mRay.setStartRay(mpMover->getPosition());
   mRay.setEndRay(mpTarget->getPosition());
   canSeePlayer = mRay.doIt();

   bool colPlayer;
   colPlayer = mCol.circleOnCircle(mpMover->getPosition(), 50 , mpTarget->getPosition(), 50);

   if (colPlayer)
      std::cout << "enemy detecting player - circ x circ" << std::endl;

   /*if (canSeePlayer)
   {
      std::cout << "I can see you!" << std::endl;
   }
   else
   {
      std::cout << "I can't see you..." << std::endl;
   }*/

   return this;
}