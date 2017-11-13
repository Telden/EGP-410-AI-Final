#include "GraphicsSystem.h"
#include "Game.h"
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Font.h"
#include "Color.h"

//Default consrtuctor sets the screen size to 800x600
GraphicsSystem::GraphicsSystem()
{
	mHeight = 600;
	mWidth = 800;
}

//Overloaded Constructor to create custom screen size
GraphicsSystem::GraphicsSystem(int height, int width, int scalar)
{
	mHeight = height;
	mWidth = width;
	mScalar = scalar;
}

//Begins cleanup of display
GraphicsSystem::~GraphicsSystem()
{
	cleanup();
}

//Flips the information on the backbuffer to the screen
void GraphicsSystem:: flip()
{

	
	SDL_RenderPresent(mpRenderer);
	SDL_RenderClear(mpRenderer);
	//SDL_UpdateWindowSurface(mpDisplay);

}

//Returns the screen height
int GraphicsSystem::getHeight()
{
	return(mHeight);
}

//Returns the screen width
int GraphicsSystem::getWidth()
{
	return(mWidth);
}

//Initiallizes all al_ addons and creates the display
int GraphicsSystem::init()
{
	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		std::cout << "Unable to initialize SDL.\n";
	}
	else
	{
		std::cout << "SDL successfully initialized.\n";
	}

	// create the display
	mpDisplay = SDL_CreateWindow("Robbins, Roy - Game", 100, 100, mWidth, mHeight, SDL_WINDOW_OPENGL);

	// check if the display was created
	if (mpDisplay == NULL)
	{
		std::cout << "COULD NOT CREATE DISPLAY" << std::endl;
	}

	//https://wiki.libsdl.org/SDL_RenderClear
	mpRenderer = SDL_CreateRenderer(mpDisplay, -1, SDL_RENDERER_ACCELERATED);
	
	

	return 0;
}

//Part of the destructor - Destroys the display and sets the pointer back to NULL
void GraphicsSystem::cleanup()
{
	SDL_DestroyWindow(mpDisplay);
	mpDisplay = NULL;
}

void GraphicsSystem::drawSprite(Sprite spriteObj, int drawLocX, int drawLocY)
{
	//http://programmersranch.blogspot.com/2014/03/sdl2-animations-with-sprite-sheets.html
	SDL_Rect srcrect = { spriteObj.getLocX(), spriteObj.getLocY(), spriteObj.getHeight(), spriteObj.getWidth() };
	SDL_Rect dstrect = { drawLocX, drawLocY, spriteObj.getHeight() * mScalar, spriteObj.getWidth() *mScalar };
	
	SDL_RenderCopy(mpRenderer, spriteObj.getBuffer()->getTexture(), &srcrect, &dstrect);
	
	//SDL_RenderCopy(mpRenderer, spriteObj.getBuffer()->getTexture(), NULL, new SDL_Rect { drawLocX, drawLocY, spriteObj.getWidth(), spriteObj.getHeight() } );
	//mpTexture = SDL_CreateTextureFromSurface(mpRenderer, spriteObj.getBuffer()->getTexture());
	//SDL_RenderCopy(mpRenderer, mpTexture, NULL, NULL);

	/*SDL_BlitSurface(spriteObj.mp_SpriteBuffer->getSurface(),
		NULL, mpBackground, new SDL_Rect{drawLocX, drawLocY, NULL, NULL});*/
	//al_draw_bitmap_region(spriteObj.getBuffer()->getBitmap(), spriteObj.getLocX(), spriteObj.getLocY(), spriteObj.getWidth(), spriteObj.getHeight(), drawLocX, drawLocY, 0);
}

//Writes a font object onto the screen
void GraphicsSystem::drawText(Font* fontObj, Color* colorObj, int messageX, int messageY, std::string textmessage)
{
	// this code found here: http://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2	

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fontObj->getFont(), textmessage.c_str(), SDL_Color{ colorObj->mRed, colorObj->mGreen, colorObj->mBlue });
	SDL_Texture* Message = SDL_CreateTextureFromSurface(mpRenderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = messageX;
	Message_rect.y = messageY;

	SDL_RenderCopy(mpRenderer, Message, NULL, &Message_rect);

	//al_draw_text(fontObj->mp_font, new SDL_Color{ colorObj->mRed, colorObj->mGreen, colorObj->mBlue }, messageX, messageY, ALLEGRO_ALIGN_CENTRE, textmessage.c_str());

}
void GraphicsSystem::drawBuffer(GraphicsBuffer* bufferObj, int drawLocX, int drawLocY)
{
	//https://gist.github.com/armornick/3434362
	int width, height;
	SDL_QueryTexture(bufferObj->getTexture(), NULL, NULL, &width, &height);
	SDL_Rect temp; temp.x = drawLocX; temp.y = drawLocY, temp.w = width * mScalar; temp.h = height * mScalar;
	SDL_RenderCopy(mpRenderer, bufferObj->getTexture(), NULL, &temp);
}

void GraphicsSystem::fillBackground()
{
	//SDL_RenderClear(mpBlackBG);
}

SDL_Renderer* GraphicsSystem::getRenderer()
{
	return mpRenderer;
	
}