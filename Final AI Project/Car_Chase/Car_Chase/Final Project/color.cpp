#include "Color.h"

//Default Consturctor. Sets color to black
Color::Color()
{
	mRed = 0;
	mGreen = 0;
	mBlue = 0;
}

//Overlaoded constructor to create customized colors
Color::Color(Uint8 R, Uint8 G, Uint8 B)
{
	mRed = R;
	mGreen = G;
	mBlue = B;
}

//Nothing to destroy
Color::~Color()
{

}