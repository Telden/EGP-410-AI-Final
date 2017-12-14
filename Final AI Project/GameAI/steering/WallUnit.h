#ifndef WALLUNIT_H
#define WALLUNIT_H

#include "Kinematic.h"

class GraphicsBuffer;

class WallUnit : public Kinematic
{
	public:
		WallUnit(Vector2D topLeft, Vector2D bottomRight, int level);
		~WallUnit();

		void Init();

		void draw(int currentLevel);

		Vector2D getTopLeft() { return mTopLeft; } 
		Vector2D getTopRight() { return mTopRight; }
		Vector2D getBottomLeft() { return mBottomLeft; }
		Vector2D getBottomRight() { return mBottomRight; }
		int getLevel() { return mLevel; }
		int getHeight() { return mHeight; }
		int getWidth() { return mWidth; }

	private:
		Vector2D mTopLeft, mTopRight, mBottomLeft, mBottomRight;
		int mHeight, mWidth;
		int mLevel;
};

#endif
