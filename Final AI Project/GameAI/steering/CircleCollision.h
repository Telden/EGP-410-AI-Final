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
		UnitManager* mpUnitManager;

      bool alreadyFoundWalls = false;

	public:
		CircleCollision();
      //CircleCollision(UnitManager* um);
		~CircleCollision();

		bool circleOnBox(Vector2D position, int spriteWidthHeight);
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
