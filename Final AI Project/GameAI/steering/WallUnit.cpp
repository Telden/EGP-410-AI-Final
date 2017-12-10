#include "WallUnit.h"
#include "Game.h"
#include "GraphicsSystem.h"

// mode is 0 for walls, 1 for water
WallUnit::WallUnit(Vector2D topLeft, Vector2D bottomRight, int mode)
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

   mMode = mode;
}

void WallUnit::Init()
{

}

WallUnit::~WallUnit()
{
	
}

void WallUnit::draw()
{
	gpGame->getGraphicsSystem()->drawRectangle(mTopLeft, mBottomRight);
}