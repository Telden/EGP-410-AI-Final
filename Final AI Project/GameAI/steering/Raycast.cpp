#include "Raycast.h"

#include "WallUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"
#include "UnitManager.h"
Raycast::Raycast()
{
   for (int i = 0; i < UNIT_MANAGER->getNumOfWalls(); i++)
   {
      walls.push_back(CastWall(UNIT_MANAGER->getWallUnit(i)));
   }
}

Raycast::~Raycast()
{

}

bool Raycast::doIt()
{
   // startRay = this enemy's position
   // endRay = player's position

   gpGame->getGraphicsSystem()->drawLine(startRay, endRay);
   
   // cycle through each wall
   for (unsigned int i = 0; i < walls.size(); i++)
   {
      // reset intersects
      walls[i].intersects = 0;
      float tmp = 0;

      // cycle through each corner of that wall
      for (int j = 0; j < NUMBER_OF_VERTICES_ON_A_RECTANGLE_LOL; j++)
      {
         // check each corner of the wall to see if we're intersecting
         switch(j)
         {
            case 0:
            {
               tmp = result(walls[i].unit->getTopLeft());
               break;
            }
            case 1:
            {
               tmp = result(walls[i].unit->getTopRight());
               break;
            }
            case 2:
            {
               tmp = result(walls[i].unit->getBottomLeft());
               break;
            }
            case 3:
            {
               tmp = result(walls[i].unit->getBottomRight());
               break;
            }
            default:
            {
               std::cout << "something went horribly wrong, " << j << " exceeded expectations..." << std::endl;
            }
         }

         if (tmp > 0)
         {
            walls[i].intersects++;
         }
         else if (tmp < 0)
         {
            walls[i].intersects--;
         }
         else
         {
            // add nothing for 0
         }
      }

      //std::cout << walls[i].intersects << std::endl;

      // check our results, if we intersected at all, we can't see the player
      // if all our interesects returned positive or negative ONLY, do nothing, no intersection occured
      if (walls[i].intersects == NUMBER_OF_VERTICES_ON_A_RECTANGLE_LOL || walls[i].intersects == NUMBER_OF_VERTICES_ON_A_RECTANGLE_LOL * -1)
      {
         return true;
      }

      // "step B"
      // check points on X
      if (startRay.getX() > walls[i].unit->getTopRight().getX() &&
            endRay.getX() > walls[i].unit->getTopRight().getX())
      {
         //std::cout << "right";
         return true;
      }
      if (startRay.getX() < walls[i].unit->getBottomLeft().getX() &&
            endRay.getX() < walls[i].unit->getBottomLeft().getX())
      {
         //std::cout << "left";
         return true;
      }
      // check points on Y
      if (startRay.getY() > walls[i].unit->getTopRight().getY() &&
            endRay.getY() > walls[i].unit->getTopRight().getY())
      {
         //std::cout << "above";
         return true;
      }
      if (startRay.getY() < walls[i].unit->getBottomLeft().getY() &&
            endRay.getY() < walls[i].unit->getBottomLeft().getY())
      {
         //std::cout << "below";
         return true;
      }
   }

   return false;
   
   /*if (walls.size() > 0 && walls[0].intersects >= 0)
   {
      std::cout << "positive";
      for (unsigned int i = 0; i < walls.size(); i++)
      {
         std::cout << walls[i].intersects << std::endl;
         if (walls[i].intersects < 0)
         {
            std::cout << " but a negative was found";
            return true;
         }
      }
      std::cout << std::endl;
   }
   else if (walls.size() > 0 && walls[0].intersects < 0)
   {
      std::cout << "negative";
      for (unsigned int i = 0; i < walls.size(); i++)
      {
         std::cout << walls[i].intersects << std::endl;
         if (walls[i].intersects >= 0)
         {
            std::cout << " but a positive was found";
            return true;
         }
      }
      std::cout << std::endl;
   }
   return false;*/
}

// check for intersection
float Raycast::result(Vector2D point)
{
   /*std::cout << ((endRay.getY() - startRay.getY()) * point.getX()) +
      ((startRay.getX() - endRay.getX()) * point.getY()) +
      ((endRay.getX() * startRay.getY()) - (startRay.getX() * endRay.getY())) << std::endl;*/
   return ((endRay.getY() - startRay.getY()) * point.getX()) +
   ((startRay.getX() - endRay.getX()) * point.getY()) +
   ((endRay.getX() * startRay.getY()) - (startRay.getX() * endRay.getY()));
}