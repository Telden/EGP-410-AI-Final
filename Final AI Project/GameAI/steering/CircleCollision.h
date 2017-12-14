#ifndef CIRCLEONBOX_H
#define CIRCLEONBOX_H

#include "Vector2D.h"
#include <vector>

class WallUnit;
class UnitManager;
struct BoxWithCenter;

class CircleCollision
{
	private:
		std::vector<BoxWithCenter> walls;
		std::vector<BoxWithCenter> water;
		std::vector<BoxWithCenter> doors;
		UnitManager* mpUnitManager;

      bool alreadyFoundWalls = false;
      bool alreadyFoundWater = false;
	   bool alreadyFoundDoors = false;

      bool wallCollisionSuccess = false;
      bool doorCollisionSuccess = false;

	public:
		CircleCollision();
		~CircleCollision();

      bool circleOnWall(Vector2D position, int spriteWidthHeight);
	  bool circleOnWater(Vector2D position, int spriteWidthHeight);
	  bool circleOnDoor(Vector2D position, int spriteWidthHeight);
	  bool circleOnCircle(Vector2D position, int sriteWidthHeight, Vector2D position2, int spriteWidthHeight2);
};

struct BoxWithCenter
{
	WallUnit* wall;
	Vector2D rectCenter;

	BoxWithCenter(WallUnit* newWall, Vector2D newRectCenter)
	{
		wall = newWall;
		rectCenter = newRectCenter;
	}
};

#endif // !CIRCLEONBOX_H
