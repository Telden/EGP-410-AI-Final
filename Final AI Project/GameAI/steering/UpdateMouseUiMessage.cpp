#include "Game.h"
#include "GraphicsSystem.h"
#include "GameMessageManager.h"
#include "UpdateMouseUiMessage.h"
#include "UiManager.h"

UpdateMouseUiMessage::UpdateMouseUiMessage(Vector2D mousePos) : GameMessage(UPDATE_MOUSE_UI_MESSAGE)
{
	mMousePos = mousePos;
}

UpdateMouseUiMessage::~UpdateMouseUiMessage()
{

}

void UpdateMouseUiMessage::process()
{
	GRAPHICS_SYSTEM->drawMouse(mMousePos);
}