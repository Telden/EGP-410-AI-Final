#include "CircleCollision.h"

#include "WallUnit.h"
#include <math.h>
#include "UnitManager.h"
#include "allegro5\allegro_primitives.h"
#include "Game.h"

CircleCollision::CircleCollision()
{
   
}

CircleCollision::~CircleCollision()
{
	if (mpUnitManager != NULL)
	{
		delete mpUnitManager;
	}
}

// used for: enemy and walls - player and walls
bool CircleCollision::circleOnWall(Vector2D position, int spriteWidthHeight)
{
   if (!alreadyFoundWalls)
   {
      mpUnitManager = UNIT_MANAGER;

      // calculate rectangle centers beforehand
      for (int i = 0; i < mpUnitManager->getNumOfWalls(); i++)
      {
         Vector2D tmp;
         tmp.setX(mpUnitManager->getWallUnit(i)->getTopLeft().getX() + (mpUnitManager->getWallUnit(i)->getWidth() / 2));
         tmp.setY(mpUnitManager->getWallUnit(i)->getTopLeft().getY() + (mpUnitManager->getWallUnit(i)->getHeight() / 2));

         walls.push_back(BoxWithCenter(mpUnitManager->getWallUnit(i), tmp));
      }
      alreadyFoundWalls = true;
   }
	float radius = spriteWidthHeight / 2;

	// calculate the midpoint from the actual position and sprite width/height (which are the same cause we're a circle)
	Vector2D circCenter = (position.getX() + (radius),
						   position.getY() + (radius)
					      );

   wallCollisionSuccess = false;

	for (unsigned int i = 0; i < mpUnitManager->getNumOfWalls(); i++)
	{
      // check to see if the wall is on the same level of the hierarchy
		if (walls[i].wall->getLevel() == gpGame->getCurrentLevel())
		{
         // used for seeing the mid-point of the walls
			//al_draw_circle(walls[i].rectCenter.getX(), walls[i].rectCenter.getY(), 50, al_map_rgb(255, 0, 0), 2);

			// calculate distance between circle center and rectangle center
			Vector2D distance;
			distance.setX(abs(position.getX() - walls[i].rectCenter.getX()));
			distance.setY(abs(position.getY() - walls[i].rectCenter.getY()));

         // because break is breaking my collision, use a bool to keep track instead
         bool breakplz = false;

			// if distance is greater than half of the circle + half of the rectangle, no collision
			if (distance.getX() > (walls[i].wall->getWidth() / 2) + radius)
			{
				// no collision
				breakplz = true;
			}
			if (distance.getY() > (walls[i].wall->getHeight() / 2) + radius)
			{
				// no collision
            breakplz = true;
			}

         // if we didn't "break" above, keep checking
         if (!breakplz)
         {
			   // if distance is less than half of the rectangle, collision
			   if (distance.getX() <= (walls[i].wall->getWidth() / 2))
			   {
				   wallCollisionSuccess = true;//return true;
			   }
			   if (distance.getY() <= (walls[i].wall->getHeight() / 2))
			   {
               wallCollisionSuccess = true;//return true;
			   }
         }
		}
	}
   return wallCollisionSuccess;
}

// used for: enemy and water - player and water
bool CircleCollision::circleOnWater(Vector2D position, int spriteWidthHeight)
{
   if (!alreadyFoundWater)
   {
      mpUnitManager = UNIT_MANAGER;

      // calculate rectangle centers beforehand
      for (int i = 0; i < mpUnitManager->getNumOfWater(); i++)
      {
         Vector2D tmp;
         tmp.setX(mpUnitManager->getWaterUnit(i)->getTopLeft().getX() + (mpUnitManager->getWaterUnit(i)->getWidth() / 2));
         tmp.setY(mpUnitManager->getWaterUnit(i)->getTopLeft().getY() + (mpUnitManager->getWaterUnit(i)->getHeight() / 2));

         water.push_back(BoxWithCenter(mpUnitManager->getWaterUnit(i), tmp));
      }
      alreadyFoundWater = true;
   }
   float radius = spriteWidthHeight / 2;

   // calculate the midpoint from the actual position and sprite width/height (which are the same cause we're a circle)
   Vector2D circCenter = (position.getX() + (radius),
      position.getY() + (radius)
      );

   for (unsigned int i = 0; i < water.size(); i++)
   {
	   if (water[i].wall->getLevel() == gpGame->getCurrentLevel())
	   {
		   al_draw_circle(water[i].rectCenter.getX(), water[i].rectCenter.getY(), 50, al_map_rgb(255, 0, 0), 2);

		   // calculate distance between circle center and rectangle center
		   Vector2D distance;
		   distance.setX(abs(position.getX() - water[i].rectCenter.getX()));
		   distance.setY(abs(position.getY() - water[i].rectCenter.getY()));

		   // if distance is greater than half of the circle + half of the rectangle, no collision
		   if (distance.getX() >(water[i].wall->getWidth() / 2) + radius)
		   {
			   // no collision
			   break;
		   }
		   if (distance.getY() > (water[i].wall->getHeight() / 2) + radius)
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
     
   }

   return false;
}

bool CircleCollision::circleOnDoor(Vector2D position, int spriteWidthHeight)
{
   if (!alreadyFoundDoors)
   {
      mpUnitManager = UNIT_MANAGER;

      // calculate rectangle centers beforehand
      for (int i = 0; i < mpUnitManager->getNumOfDoors(); i++)
      {
         Vector2D tmp;
         tmp.setX(mpUnitManager->getDoorUnit(i)->getTopLeft().getX() + (mpUnitManager->getDoorUnit(i)->getWidth() / 2));
         tmp.setY(mpUnitManager->getDoorUnit(i)->getTopLeft().getY() + (mpUnitManager->getDoorUnit(i)->getHeight() / 2));

         doors.push_back(BoxWithCenter(mpUnitManager->getDoorUnit(i), tmp));
      }
      alreadyFoundDoors = true;
   }
   float radius = spriteWidthHeight / 2;

   // calculate the midpoint from the actual position and sprite width/height (which are the same cause we're a circle)
   Vector2D circCenter = (position.getX() + (radius),
      position.getY() + (radius)
      );

   doorCollisionSuccess = false;

   for (unsigned int i = 0; i < mpUnitManager->getNumOfDoors(); i++)
   {
      // check to see if the wall is on the same level of the hierarchy
      if (doors[i].wall->getLevel() == gpGame->getCurrentLevel())
      {
         // used for seeing the mid-point of the walls
         //al_draw_circle(walls[i].rectCenter.getX(), walls[i].rectCenter.getY(), 50, al_map_rgb(255, 0, 0), 2);

         // calculate distance between circle center and rectangle center
         Vector2D distance;
         distance.setX(abs(position.getX() - doors[i].rectCenter.getX()));
         distance.setY(abs(position.getY() - doors[i].rectCenter.getY()));

         // because break is breaking my collision, use a bool to keep track instead
         bool breakplz = false;

         // if distance is greater than half of the circle + half of the rectangle, no collision
         if (distance.getX() > (doors[i].wall->getWidth() / 2) + radius)
         {
            // no collision
            breakplz = true;
         }
         if (distance.getY() > (doors[i].wall->getHeight() / 2) + radius)
         {
            // no collision
            breakplz = true;
         }

         // if we didn't "break" above, keep checking
         if (!breakplz)
         {
            // if distance is less than half of the rectangle, collision
            if (distance.getX() <= (doors[i].wall->getWidth() / 2))
            {
               doorCollisionSuccess = true;//return true;
            }
            if (distance.getY() <= (doors[i].wall->getHeight() / 2))
            {
               doorCollisionSuccess = true;//return true;
            }
         }
      }
   }
   return doorCollisionSuccess;
}


// used for: enemy and player - player and pickups
bool CircleCollision::circleOnCircle(Vector2D position, int spriteWidthHeight, Vector2D position2, int spriteWidthHeight2)
{
	float radius = spriteWidthHeight / 2;
	float radius2 = spriteWidthHeight / 2;

	// get the distance
	float distance = sqrt(
                     pow(position2.getX() - position.getX(), 2) +
                     pow(position2.getY() - position.getY(), 2)
                        );

   // for debugging
   al_draw_circle(position.getX(), position.getY(), radius, al_map_rgb(255, 0, 0), 2);
   al_draw_circle(position2.getX(), position2.getY(), radius2, al_map_rgb(255, 0, 0), 2);

	// if the distance between the two center points 
	if (distance > radius + radius2)
	{
		return false;
	}
	return true;
}