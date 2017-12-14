#ifndef PICKUPUNIT_H
#define PICKUPUNIT_H

#include "Kinematic.h"

class GraphicsBuffer;

class PickupUnit : public Kinematic
{
public:
   PickupUnit(Vector2D position, int diameter, int mode,  int level);
   ~PickupUnit();

   void update();
   void draw();
   int getCurrentLevel() { return mLevel; };
   int getMode();

private:
   int mRadius, mMode;
   bool mActive = true;
   int mRespawnTime = 45;
   int mResetRespawnTime = 45;
   int mLevel;
};

#endif
