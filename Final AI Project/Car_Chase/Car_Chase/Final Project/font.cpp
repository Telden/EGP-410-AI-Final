#include "Font.h"

//Default constructor sets the font size to 12
Font::Font()
{
	mp_font = NULL;
	m_fontSize = 12;
}

//Overloaded Constructor to establish font file path and custom font size
Font::Font(std::string FILE_PATH, int size)
{
	const char* FONT_PATH_CHAR = FILE_PATH.c_str();
	m_fontSize = size;
	mp_font = TTF_OpenFont(FONT_PATH_CHAR, m_fontSize);
}

//Destroys and font objects
Font::~Font()
{
	delete mp_font;
	mp_font = NULL;
}

//Returns the font size 
int Font::getSize()
{
	return(m_fontSize);
}

TTF_Font* Font::getFont()
{
	return mp_font;
}