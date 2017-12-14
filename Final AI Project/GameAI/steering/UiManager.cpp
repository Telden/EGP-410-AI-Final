#include "UiManager.h"
#include <sstream>

UiManager::UiManager()
{
	mpFont = NULL;
}

UiManager::~UiManager()
{
	cleanup();
}

bool UiManager::init()
{
	// Initialize the allegro font system
	al_init_font_addon();
	if (!al_init_ttf_addon())
	{
		printf("ttf font addon not initted properly!\n");
		return false;
	}

	//actually load the font
	mpFont = al_load_ttf_font("cour.ttf", 40, 0);
	if (mpFont == NULL)
	{
		printf("ttf font file not loaded properly!\n");
		return false;
	}

	// If everything loaded correctly, return true
	return true;
}

void UiManager::cleanup()
{
	al_destroy_font(mpFont);
	mpFont = NULL;
}

void UiManager::update(int score)
{
	drawPointerText();
   drawScore(score);
	if (mShouldDraw)
		drawDebugInfo();
}

void UiManager::switchUI()
{
	if (mShouldDraw)
		mShouldDraw = false;
	else
		mShouldDraw = true;
}

//Updates the mouse information from the input manager
void UiManager::updateMouseUiInformation(float& mouseX, float& mouseY, std::string mousePos, std::string currentSelction)
{
	mMouseX = mouseX;
	mMouseY = mouseY;
	mMousePos = mousePos;
	mCurrentSelection = currentSelction;
}

void UiManager::updateUnitUiInformation(float& reactionRadius, float& angularVelocity, float& enemyVelocity, float& cohesionWeight, float& separationWeight, float& allignmentWeight)
{
	mReactionRadius = reactionRadius;
	mAngularVelocity = angularVelocity;
	mEnemyVelocity = enemyVelocity;
	mCohesionWeight = cohesionWeight;
	mSeparationWeight = separationWeight;
	mAllignmentWeight = allignmentWeight;
}
void UiManager::drawPointerText()
{
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), mMouseX, mMouseY, ALLEGRO_ALIGN_CENTRE, mMousePos.c_str());
}

void UiManager::drawDebugInfo()
{
	std::stringstream tmpText;
	
	// Draw the current increase/decrease selection
	tmpText << "Current selection: " << mCurrentSelection;
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 20, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");
	
	// Draw the reaction Radius
	if (mCurrentSelection == "R")
	{
		tmpText << "R: Reaction radius: " << mReactionRadius;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 50, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "R: Reaction radius: " << mReactionRadius;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 50, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	

	// Draw the angular velocity
	if (mCurrentSelection == "G")
	{
		tmpText << "G: Angular velocity: " << mAngularVelocity;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 70, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "G: Angular velocity: " << mAngularVelocity;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 70, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	

	// Draw the enemy velocity
	if (mCurrentSelection == "V")
	{
		tmpText << "V: Enemy velocity: " << mEnemyVelocity;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 90, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "V: Enemy velocity: " << mEnemyVelocity;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 90, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}

	// Draw cohesion weight
	if (mCurrentSelection == "C")
	{
		tmpText << "C: Cohesion weight: " << mCohesionWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 110, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "C: Cohesion weight: " << mCohesionWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 110, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	
	// Draw spearation weight
	if (mCurrentSelection == "S")
	{
		tmpText << "S: Separation weight: " << mSeparationWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 130, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "S: Separation weight: " << mSeparationWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 130, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	

	// Draw allignmnet weight
	if (mCurrentSelection == "A")
	{
		tmpText << "A: Allignment weight: " << mAllignmentWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 150, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "A: Allignment weight: " << mAllignmentWeight;
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 150, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	
	//Draw wall detection
	if (mCurrentSelection == "W")
	{
		tmpText << "W: Toggle wall  detection: ";
		al_draw_text(mpFont, al_map_rgb(mRed, 0, 0), 30, 170, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}
	else
	{
		tmpText << "W: Toggle wall  detection";
		al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 170, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
		tmpText.str("");
	}

	// Draw the rest of the debug options
	tmpText << "+ : Decrease selected value ";
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 190, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");

	tmpText << "- : Decrease selected value ";
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 210, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");

	tmpText << "D: Delete a unit ";
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 230, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");

	tmpText << "ESC: Quit game ";
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 250, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");

	tmpText << "LCTRL + S: Save Settings ";
	al_draw_text(mpFont, al_map_rgb(mRed, mGreen, mBlue), 30, 270, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
	tmpText.str("");
}

// a function to draw the score on the screen
void UiManager::drawScore(int score)
{
   std::stringstream tmpText;
   tmpText << "$" << score;
   al_draw_text(mpFont, al_map_rgb(0, 0, 0), 30, 40, ALLEGRO_ALIGN_LEFT, tmpText.str().c_str());
}