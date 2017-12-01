#pragma once

#include <Trackable.h>
#include "EventListener.h"

class ExampleListener : public EventListener
{
public:
	ExampleListener();
	~ExampleListener();

	void handleEvent( const Event& theEvent );

private:
	static int msID;

	int mID;
};