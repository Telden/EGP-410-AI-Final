#include "WallUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"

// mode is 0 for walls, 1 for water
WallUnit::WallUnit(Vector2D topLeft, Vector2D bottomRight, int level)
:Kinematic(topLeft, 0, 0, 0) // initializing velocity, orientation, and rotational velocity as 0
{
	mTopLeft = topLeft;
	mBottomRight = bottomRight;

	mTopRight.setX(mBottomRight.getX());
	mTopRight.setY(mTopLeft.getY());

	mBottomLeft.setX(mTopLeft.getX());
	mBottomLeft.setY(mBottomRight.getY());

	mHeight = mBottomLeft.getY() - mTopLeft.getY();
	mWidth = mTopRight.getX() - mTopLeft.getX();
	mWidth = mWidth;

   mLevel = level;
}

void WallUnit::Init()
{

}

WallUnit::~WallUnit()
{
	
}

void WallUnit::draw(int currentLevel, int colorID)
{
   // only draw if the object is on the current level
	if(currentLevel == mLevel)
   {
      // check which color to draw
      switch (colorID)
      {
         case 0:
         {
            gpGame->getGraphicsSystem()->drawRectangle(mTopLeft, mBottomRight, al_map_rgb(127, 127, 127));
            break;
         }
         case 1:
         {
            gpGame->getGraphicsSystem()->drawRectangle(mTopLeft, mBottomRight, al_map_rgb(0, 0, 255));
            break;
         }
         case 2:
         {
            gpGame->getGraphicsSystem()->drawRectangle(mTopLeft, mBottomRight, al_map_rgb(200, 200, 200));
            break;
         }
      }
   }
}