#ifndef PICKUPUNIT_H
#define PICKUPUNIT_H

#include "Kinematic.h"

class GraphicsBuffer;

class PickupUnit : public Kinematic
{
public:
   PickupUnit(Vector2D position, int diameter, int mode);
   ~PickupUnit();

   void draw();

   int getMode();

private:
   int mRadius, mMode;
};

#endif
