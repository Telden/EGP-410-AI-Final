#ifndef DEADSTEERING_H
#define DEADSTEERING_H

#include "Steering.h"
#include "CircleCollision.h"
#include "StateMachine.h"

class KinematicUnit;

class DeadSteering :public Steering
{
public:
   DeadSteering(KinematicUnit* pMover);
   ~DeadSteering() {};

   virtual Steering* getSteering();

private:
   KinematicUnit* mpMover;

   int counter = 0;
   int maxCount = 300;
};

#endif