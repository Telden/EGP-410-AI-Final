#include "KinematicWanderSteering.h"
#include "DynamicSeekSteering.h"
#include "KinematicUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include <stdlib.h>

KinematicWanderSteering::KinematicWanderSteering(KinematicUnit *pMover)
:mpMover(pMover)
{
	mApplyDirectly = true;
}

Steering* KinematicWanderSteering::getSteering()
{
	
	
	mLinear = mpMover->getOrientationAsVector() * mpMover->getMaxVelocity(); 
	mAngular = mpMover->getOrientation() + ( genRandomBinomial() * 0.5 );
	return this;
}