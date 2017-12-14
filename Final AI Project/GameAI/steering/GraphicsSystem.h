#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "Trackable.h"
#include "Vector2D.h"

class GraphicsBuffer;

class GraphicsSystem:public Trackable
{
public:
	GraphicsSystem();
	~GraphicsSystem();

	bool init( int width, int height );
	void cleanup();

	void swap();
	void wrapCoordinates( Vector2D& vector );//change the x and y values in the vector to keep them on the visible screen

	//accessors
	int getWidth() const { return mWidth; };
	int getHeight() const { return mHeight; };
	ALLEGRO_DISPLAY* getDisplay() const { return mpDisplay; };
	inline GraphicsBuffer* getBackBuffer() { return mpBackBuffer; };

	static ALLEGRO_BITMAP* switchTargetBitmap( ALLEGRO_BITMAP* pNewTarget );//return old target

   void drawRectangle(Vector2D topLeft, Vector2D bottomRight, ALLEGRO_COLOR color);
   void drawLine(Vector2D start, Vector2D end);
   void drawCircle(Vector2D position, int radius);
   void drawMouse(Vector2D mousePos);
   void drawSewerNode(Vector2D topLeft, Vector2D bottomRight);
   void drawStreetsNode(Vector2D topLeft, Vector2D bottomRight);
private:
	ALLEGRO_DISPLAY* mpDisplay;
	GraphicsBuffer* mpBackBuffer;
	int mWidth;
	int mHeight;
	const int NODE_SIZE = 64;

};