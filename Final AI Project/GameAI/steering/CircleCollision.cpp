#include "CircleCollision.h"

#include "WallUnit.h"
#include <math.h>
#include "UnitManager.h"

CircleCollision::CircleCollision(UnitManager* um)
{
	mpUnitManager = um;

	// calculate rectangle centers beforehand
	for (int i = 0; i < mpUnitManager->getNumOfWalls(); i++)
	{
		Vector2D tmp;
		tmp.setX(mpUnitManager->getWallUnit(i)->getTopLeft().getX() - (mpUnitManager->getWallUnit(i)->getWidth() / 2));
		tmp.setY(mpUnitManager->getWallUnit(i)->getTopLeft().getY() - (mpUnitManager->getWallUnit(i)->getHeight() / 2));

		walls.push_back(BoxWithCenter(mpUnitManager->getWallUnit(i), tmp));
	}
}

CircleCollision::~CircleCollision()
{
	if (mpUnitManager != NULL)
	{
		delete mpUnitManager;
	}
}

// used for: enemy and walls - player and walls
bool CircleCollision::circleOnBox(Vector2D position, int spriteWidthHeight)
{
	float radius = spriteWidthHeight / 2;

	// calculate the midpoint from the actual position and sprite width/height (which are the same cause we're a circle)
	Vector2D circCenter = (position.getX() + (radius),
						   position.getY() + (radius)
					      );

	for (unsigned int i = 0; i < walls.size(); i++)
	{
		// calculate distance between circle center and rectangle center
		Vector2D distance;
		distance.setX(abs(circCenter.getX() - walls[i].rectCenter.getX()));
		distance.setY(abs(circCenter.getY() - walls[i].rectCenter.getY()));

		// if distance is greater than half of the circle + half of the rectangle, no collision
		if (distance.getX() > (walls[i].wall->getWidth() / 2) + radius)
		{
			// no collision
			break;
		}
		if (distance.getY() > (walls[i].wall->getHeight() / 2) + radius)
		{
			// no collision
			break;
		}

		// if distance is less than half of the rectangle, collision
		if (distance.getX() <= (walls[i].wall->getWidth() / 2))
		{
			return true;
		}
		if (distance.getY() <= (walls[i].wall->getHeight() / 2))
		{
			return true;
		}
	}

	return false;
}

// used for: enemy and player - player and pickups
bool CircleCollision::circleOnCircle(Vector2D position, int spriteWidthHeight, Vector2D position2, int spriteWidthHeight2)
{
	float radius = spriteWidthHeight / 2;
	float radius2 = spriteWidthHeight / 2;

	// calculate center points of the circles
	Vector2D circCenter = (position.getX() + (radius),
						   position.getY() + (radius)
	);
	Vector2D circCenter2 = (position2.getX() + (radius2),
						    position2.getY() + (radius2)
	);

	// get the distance
	Vector2D distance = circCenter - circCenter2;

	// if the distance between the two center points 
	if (abs(distance.getLength()) > abs(spriteWidthHeight - spriteWidthHeight2))
	{
		return false;
	}
	return true;
}