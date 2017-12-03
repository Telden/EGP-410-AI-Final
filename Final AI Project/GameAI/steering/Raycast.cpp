#include "Raycast.h"

#include "WallUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"

Raycast::Raycast()
{

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
      // cycle through each corner of that wall
      for (int j = 0; j < NUMBER_OF_VERTICES_ON_A_RECTANGLE_LOL; j++)
      {
         // check each corner of the wall to see if we're intersecting
         switch(j)
         {
            case 0:
            {
               walls[i].intersects += result(walls[i].unit->getTopLeft());
               break;
            }
            case 1:
            {
               walls[i].intersects += result(walls[i].unit->getTopRight());
               break;
            }
            case 2:
            {
               walls[i].intersects += result(walls[i].unit->getBottomLeft());
               break;
            }
            case 3:
            {
               walls[i].intersects += result(walls[i].unit->getBottomRight());
               break;
            }
            default:
            {
               std::cout << "something went horribly wrong, " << j << " exceeded expectations..." << std::endl;
            }
         }
      }

      // check our results, if we intersected at all, we can't see the player
      if (walls[i].intersects == (float)walls.size() || walls[i].intersects == (float)walls.size() * -1)
      {
         // if all our interesects returned positive or negative ONLY, do nothing, no intersection occured
      }
      else
      {
         // in any other case, an intersection has occured
         return true;
      }
   }

   return false;
}

// check for intersection
float Raycast::result(Vector2D point)
{
   return (endRay.getY() - startRay.getY()) * point.getX() + (startRay.getX() - endRay.getX()) * point.getY() + (endRay.getX() * startRay.getY() + startRay.getX() * endRay.getY());
}