#ifndef POLICESTEERING_H
#define POLICESTEERING_H

#include "Steering.h"
#include "Raycast.h"
#include "CircleCollision.h"
#include "StateMachine.h"

class KinematicUnit;

class PoliceSteering :public Steering
{
public:
   PoliceSteering(KinematicUnit* pMover);
   ~PoliceSteering() {};

   virtual Steering* getSteering();

private:
   KinematicUnit* mpTarget;
   KinematicUnit* mpMover;

   Raycast mRay;
   CircleCollision mCol;
   StateMachine mStateMachine;
   bool canSeePlayer;

   Steering* mpWander;
   Steering* mpChase;
   Steering* mpFlee;
   Steering* mpDead;
};

#endif