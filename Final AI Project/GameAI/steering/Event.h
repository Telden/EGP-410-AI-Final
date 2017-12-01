#pragma once

#include <string>
#include <trackable.h>

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	END_GAME_EVENT,
	DEATH_COLLISION_EVENT,
	MOVEMENT_EVENT_DOWN,
	MOVEMENT_EVENT_LEFT,
	MOVEMENT_EVENT_RIGHT,
	MOVEMENT_EVENT_UP,
	START_GAME_EVENT,
	ATTACK_EVENT_PRIMARY,
	ATTACK_EVENT_SECONDARY,
	LOAD_LEFT_LEVEL,
	LOAD_RIGHT_LEVEL,
	LOAD_UPPER_LEVEL,
	LOAD_LOWER_LEVEL,
	HURT_PLAYER_EVENT,
	PICKUP_KEY_EVENT,
	PICKUP_BOW_EVENT,
	LINK_DEATH_EVENT,
	RESET_GAME_EVENT,
	WIN_GAME_EVENT,
	OPEN_DOOR_EVENT,
	BOSS_DEFEATED_EVENT,
	LOAD_SAVE_EVENT,
	LOAD_GAME_EVENT,
	CHANGE_DIFFICULTY_EVENT,
	PLAY_AUDIO_EVENT,
	STOP_MUSIC_EVENT,
	NUM_EVENT_TYPES,
	SAVE_GAME_EVENT
};

const string EVENT_NAMES[NUM_EVENT_TYPES] =	{	
												"End Game Event",
												"Movement Down Event",
												"Movement Left Event",
												"Movement Right Event",
												"Movement Up Event",
												"Start Game Event",
												"Attack Event Primary",
												"Attack Event Secondary",
												"Load left level",
												"Load right level",
												"Load upper level",
												"Load lower level",
												"Hurt Player Event",
												"Pickup Key Event",
												"Pickup Bow Event",
												"Reset Game Event",
												"Link Death Event",
												"Win Game Event",
												"Boss Defeated Event",
												"Open Door Event",
												"Load Save Event",
												"Change Difficulty Event",
												"Play Audio Event",
												"Load Game Event",
												"Stop Music Event",
												"Save Game Event"
											};

class Event:public Trackable
{
public:
	Event( EventType type );
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;

};