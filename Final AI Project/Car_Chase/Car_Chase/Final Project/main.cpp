#include "Game.h"

#include <Trackable.h>
#include <MemoryTracker.h>
#include <Timer.h>
#include <PerformanceTracker.h>


int main(int argc, char* argv[])
{
	Game::initInstance();
	gpEventSystem = new EventSystem();
	Game::getInstance()->init();
	Game::getInstance()->titleScreen();
	Game::getInstance()->gameLoop();
	Game::deleteInstance();

	delete gpEventSystem;
	gMemoryTracker.reportAllocations(std::cout);
	std::cout << "Press any key to close the program...\n";
	system("pause");

	return 0;
}