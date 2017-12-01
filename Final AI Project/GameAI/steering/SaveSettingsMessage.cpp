#include "Game.h"
#include "GameMessageManager.h"
#include "SaveSettingsMessage.h"
#include "UnitManager.h"

SaveSettingsMessage::SaveSettingsMessage() : GameMessage(SAVE_SETTINGS_MESSAGE)
{

}

void SaveSettingsMessage::process()
{
//	UNIT_MANAGER->SaveSettings();
}