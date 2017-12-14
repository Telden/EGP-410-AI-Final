#pragma once

#include "Trackable.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>


class UiManager : public Trackable
{
public:
	UiManager();
	~UiManager();

	//Loads the font and initializes allegro font systems
	bool init();

	//clean up pointers and turn off allegro systems
	void cleanup();

	// Update the UI every frame
	void update(int score);

	//Update mouse UI information
	void updateMouseUiInformation(float& mouseX, float& mouseY, std::string mousePos, std::string currentSelection);

	//Update unit UI information
	void updateUnitUiInformation(float& reactionRadius, float& angularVelocity, float& enemyVelocity, float& cohesionWeight, float& separationWeight, float& allignmentWeight);

	// Draw the coordinents of the mouse posision
	void drawPointerText();

	// Draw the debug info
	void drawDebugInfo();

	//Switch the UI on or off
	void switchUI();

   // score
   void drawScore(int score);

private:
	ALLEGRO_FONT* mpFont;
	bool mShouldDraw = false;

	//UI variables
	int mReactionRadius;
	int mAngularVelocity;
	int mEnemyVelocity;
	int mCohesionWeight;
	int mSeparationWeight;
	int mAllignmentWeight;
	int mMouseX;
	int mMouseY;

	std::string mMousePos;
	std::string mCurrentSelection;

	//Font color
	int mRed = 255;
	int mGreen = 255;
	int mBlue = 255;
};