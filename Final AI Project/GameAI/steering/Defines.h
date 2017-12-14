#pragma once

#include <string>

typedef int IDType;
typedef std::string IDDescriptor;

const IDType INVALID_ID = -1;

const IDType HIGHEST_ID = 9999;
#define TOGGLE_DEBUG gpGame->toggleDebug()
#define MESSAGE_MANAGER gpGame->getMessageManager()
#define GRAPHICS_SYSTEM gpGame->getGraphicsSystem()
#define UNIT_MANAGER gpGame->getUnitManager()
#define SPRITE_MANAGER gpGame->getSpriteManager()
#define UI_MANAGER gpGame->getUiManager()
#define END_GAME gpGame->endGame()
#define GRAPH gpGame->getGraph()
#define AUDIO_MANAGER gpGame->getAudioManager()