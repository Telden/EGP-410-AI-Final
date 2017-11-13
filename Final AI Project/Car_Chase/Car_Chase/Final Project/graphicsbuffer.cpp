#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Game.h"

GraphicsBuffer::GraphicsBuffer()
{
	mpImage = NULL;
	mHeight = 0;
	mWidth = 0;

}

GraphicsBuffer::GraphicsBuffer(std::string FILE_PATH)
{
	const char *BACKGROUND_PATH_CHAR = FILE_PATH.c_str();
	mpImage = IMG_LoadTexture(Game::getInstance()->getGraphicsSystem()->getRenderer(), BACKGROUND_PATH_CHAR);
	SDL_QueryTexture(mpImage, NULL, NULL, &mWidth, &mHeight);
}

GraphicsBuffer::~GraphicsBuffer()
{
	if (mpImage != NULL)
	{
		SDL_DestroyTexture(mpImage);
	}
	mpImage = NULL;
}

//returns height
int GraphicsBuffer::getheight()
{
	return(mHeight);
}

//returns width
int GraphicsBuffer::getWidth()
{
	return(mWidth);
}

SDL_Texture* GraphicsBuffer::getTexture()
{
	return mpImage;
}