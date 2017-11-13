#include "Level.h"
#include "Unit.h"

#include "Level.h"
#include "EnemyKese.h"
#include "EnemyStalfos.h"
#include "EnemyGel.h"
#include "Link.h"
#include "Block.h"
#include "Treasures.h"
#include "HorizontalDoor.h"
#include "VerticalDoor.h"
#include "Aquamentus.h"
#include "Tile.h"
#include "EnemyPeahat.h"
#include "PapaSmurf.h"
#include <fstream>

Level::Level(std::string levelName)
{
	mlevelName = levelName;
}

//Delete pointers
Level::~Level()
{
	for (unsigned int i = 0; i < mpStalfos.size(); i++)
	{
		EnemyStalfos* dltPtr = mpStalfos[i];
		delete dltPtr;
	}
	mpStalfos.clear();
	for (unsigned int i = 0; i < mpBlocks.size(); i++)
	{
		Block* dltPtr = mpBlocks[i];
		delete dltPtr;
	}
	mpBlocks.clear();
	for (unsigned int i = 0; i < mpTreasures.size(); i++)
	{
		Treasure* dltPtr = mpTreasures[i];
		delete dltPtr;
	}
	mpTreasures.clear();
	for (unsigned int i = 0; i < mpKese.size(); i++)
	{
		EnemyKese* dltPtr = mpKese[i];
		delete dltPtr;
	}
	mpKese.clear();

	for (unsigned int i = 0; i < mpGel.size(); i++)
	{
		EnemyGel* dltPtr = mpGel[i];
		delete dltPtr;
	}
	mpGel.clear();

	for (unsigned int i = 0; i < mpHorizDoor.size(); i++)
	{
		HorizontalDoor* dltPtr = mpHorizDoor[i];
		delete dltPtr;
	}
	mpHorizDoor.clear();

	for (unsigned int i = 0; i < mpVertDoor.size(); i++)
	{
		VerticalDoor* dltPtr = mpVertDoor[i];
		delete dltPtr;
	}
	mpVertDoor.clear();

	for (unsigned int i = 0; i < mpAquamentus.size(); i++)
	{
		Aquamentus* dltPtr = mpAquamentus[i];
		delete dltPtr;
	}
	mpAquamentus.clear();

	for (unsigned int i = 0; i < mpTiles.size(); i++)
	{
		Tile* dltPtr = mpTiles[i];
		delete dltPtr;
	}
	mpTiles.clear();

	for (unsigned int i = 0; i < mpPeahat.size(); i++)
	{
		EnemyPeahat* dltPtr = mpPeahat[i];
		delete dltPtr;
	}
	for (unsigned int i = 0; i < mpSmurf.size(); i++)
	{
		PapaSmurf* dltPtr = mpSmurf[i];
		delete dltPtr;
	}
	mpTiles.clear();
}

//Render all of the currently active units
void Level::render()
{
	for (unsigned int i = 0; i < mpStalfos.size(); i++)
	{
		if (mpStalfos[i]->getIsActive())
			mpStalfos[i]->render();
	}
	for (unsigned int i = 0; i < mpBlocks.size(); i++)
	{
		mpBlocks[i]->render();
	}
	for (unsigned int i = 0; i < mpTreasures.size(); i++)
	{
		if (mpTreasures[i]->getIsActive())
				mpTreasures[i]->render();
	}
	for (unsigned int i = 0; i < mpKese.size(); i++)
	{
		if (mpKese[i]->getIsActive())
			mpKese[i]->render();
	}
	for (unsigned int i = 0; i < mpGel.size(); i++)
	{
		if (mpGel[i]->getIsActive())
			mpGel[i]->render();
	}
	for (unsigned int i = 0; i < mpHorizDoor.size(); i++)
	{
		if (mpHorizDoor[i]->getIsActive())
			mpHorizDoor[i]->render();
	}
	for (unsigned int i = 0; i < mpVertDoor.size(); i++)
	{
		if (mpVertDoor[i]->getIsActive())
			mpVertDoor[i]->render();
	}
	for (unsigned int i = 0; i < mpAquamentus.size(); i++)
	{
		if (mpAquamentus[i]->getIsActive())
			mpAquamentus[i]->render();
	}
	for (unsigned int i = 0; i < mpTiles.size(); i++)
	{
		if (mpTiles[i]->getIsActive())
			mpTiles[i]->render();
	}
	for (unsigned int i = 0; i < mpPeahat.size(); i++)
	{
		if (mpPeahat[i]->getIsActive())
			mpPeahat[i]->render();
	}
	for (unsigned int i = 0; i < mpSmurf.size(); i++)
	{
		if (mpSmurf[i]->getIsActive())
			mpSmurf[i]->render();
	}
}

//Update all of the currently active units
void Level::update()
{
	for (unsigned int i = 0; i < mpStalfos.size(); i++)
	{
		if (mpStalfos[i]->getIsActive())
			mpStalfos[i]->update();
	}
	for (unsigned int i = 0; i < mpKese.size(); i++)
	{
		if (mpKese[i]->getIsActive())
			mpKese[i]->update();
	}

	for (unsigned int i = 0; i < mpGel.size(); i++)
	{
		if (mpGel[i]->getIsActive())
			mpGel[i]->update();
	}

	for (unsigned int i = 0; i < mpTreasures.size(); i++)
	{
		if (mpTreasures[i]->getIsActive())
			mpTreasures[i]->update();
	}
	for (unsigned int i = 0; i < mpHorizDoor.size(); i++)
	{
		if (mpHorizDoor[i]->getIsActive())
			mpHorizDoor[i]->update();
	}
	for (unsigned int i = 0; i < mpVertDoor.size(); i++)
	{
		if (mpVertDoor[i]->getIsActive())
			mpVertDoor[i]->update();
	}
	for (unsigned int i = 0; i < mpAquamentus.size(); i++)
	{
		if (mpAquamentus[i]->getIsActive())
			mpAquamentus[i]->update();
	}
	for (unsigned int i = 0; i < mpPeahat.size(); i++)
	{
		if (mpPeahat[i]->getIsActive())
			mpPeahat[i]->update();
	}
	for (unsigned int i = 0; i < mpSmurf.size(); i++)
	{
		if (mpSmurf[i]->getIsActive())
			mpSmurf[i]->update();
	}
}

//Add a Stalfos
void Level::addStalfos(EnemyStalfos* newStalfos)
{
	mpStalfos.push_back(newStalfos);
}

//Add a Kese
void Level::addEnemyKese(EnemyKese* keseObj)
{
	mpKese.push_back(keseObj);
}

//Add a EnemyGel
void Level::addEnemyGel(EnemyGel* gelObj)
{
	mpGel.push_back(gelObj);
}

//Add a block
void Level::addBlock(Block* blockObj)
{
	mpBlocks.push_back(blockObj);
}

//Add Treasure
void Level::addTreasure(Treasure* treasureObj)
{
	mpTreasures.push_back(treasureObj);
}

//Add Horizontal door
void Level::addHorizDoor(HorizontalDoor* horizDoorObj)
{
	mpHorizDoor.push_back(horizDoorObj);
}

//add Vertical Door
void Level::addVertDoor(VerticalDoor* vertDoorObj)
{
	mpVertDoor.push_back(vertDoorObj);
}

//Add an Aquamentus 
void Level::addAquamentus(Aquamentus* aquamentusObj)
{
	mpAquamentus.push_back(aquamentusObj);
}

//Add a tile 
void Level::addTile(Tile* tileObj)
{
	mpTiles.push_back(tileObj);
}

//Add a Peahat
void Level::addPeahat(EnemyPeahat* peahatObj)
{
	mpPeahat.push_back(peahatObj);
}

//Add a smurf
void Level::addSmurf(PapaSmurf* smurfObj)
{
	mpSmurf.push_back(smurfObj);
}

void Level::saveGame(std::string levelNum, std::ofstream& outputF)
{
	std::cout << levelNum << std::endl;
	if (outputF.fail())
	{
		std::cout << "File failed to open\n";
	}
	else
	{
		outputF << levelNum << std::endl;

		//Output this level's stalfos
		outputF << mpStalfos.size() << std::endl;
		for (unsigned int i = 0; i < mpStalfos.size(); i++)
		{
			outputF << mpStalfos[i]->getLocX() << " " << mpStalfos[i]->getLocY() << " ";
			outputF << mpStalfos[i]->getIsActive();
				if (mpStalfos[i]->getIsDropping())
					outputF << " True" << std::endl;
				else
					outputF << " False" << std::endl;
			
		}

		//Output this level's kese
		outputF << mpKese.size() << std::endl;
		for (unsigned int i = 0; i < mpKese.size(); i++)
		{
				
			outputF << mpKese[i]->getLocX() << " " << mpKese[i]->getLocY() << " ";
			outputF << mpKese[i]->getIsActive() << std::endl;
			
		}

		//Output This Level's Gels
		outputF << mpGel.size() << std::endl;
		for (unsigned int i = 0; i < mpGel.size(); i++)
		{
			
			outputF << mpGel[i]->getLocX() << " " << mpGel[i]->getLocY() << " " << mpGel[i]->getIsActive() << std::endl;
			
		}

		//Output This Level's Peahats
		outputF << mpPeahat.size() << std::endl;
		for (unsigned int i = 0; i < mpPeahat.size(); i++)
		{
			
				outputF << mpPeahat[i]->getLocX() << " " << mpPeahat[i]->getLocY() << " " << mpPeahat[i]->getIsActive();

				if (mpPeahat[i]->getMoveHorizontal())
					outputF << " True" << std::endl;
				else
					outputF << " False" << std::endl;
			
		}

		//Add This Level's Aquamentus
		outputF << mpAquamentus.size() << std::endl;
		for (unsigned int i = 0; i < mpAquamentus.size(); i++)
		{
			
			outputF << mpAquamentus[i]->getLocX() << " " << mpAquamentus[i]->getLocY() << " " << mpAquamentus[i]->getIsActive() << std::endl;
		
		}

		//Add This Level's Treasures
		outputF << mpTreasures.size() << std::endl;
		for (unsigned int i = 0; i < mpTreasures.size(); i++)
		{
			
				outputF << mpTreasures[i]->getLocX() << " " << mpTreasures[i]->getLocY() << " " << mpTreasures[i]->getIsActive();
				outputF << " " << mpTreasures[i]->getSpriteNum();
				outputF << " " << mpTreasures[i]->getTag() << std::endl;
			
			
		}

		//Add the current state of Horizontal Doors
		outputF << mpHorizDoor.size() << std::endl;
		for (unsigned int i = 0; i < mpHorizDoor.size(); i++)
		{
			
				outputF << mpHorizDoor[i]->getLocX() << " " << mpHorizDoor[i]->getLocY() << " " << mpHorizDoor[i]->getIsActive();
				if (mpHorizDoor[i]->getIsSpecial())
				{
					outputF << " True ";
					outputF << mpHorizDoor[i]->getSpecialDoorSprite() << std::endl;
				}
				else
				{
					outputF << " False " << std::endl;
					if (mpHorizDoor[i]->getIsOpen())
					{
						outputF << " True ";
						outputF << mpHorizDoor[i]->getOpenDoorSprite() << std::endl;
					}

					else
					{
						outputF << " False ";
						outputF << mpHorizDoor[i]->getClosedDoorSpite() << std::endl;
					}

				}

			

		}

		//Add the current state of Vertical Doors
		outputF << mpVertDoor.size() << std::endl;
		for (unsigned int i = 0; i < mpVertDoor.size(); i++)
		{
		
				outputF << mpVertDoor[i]->getLocX() << " " << mpVertDoor[i]->getLocY() << " " << mpVertDoor[i]->getIsActive();
				if (mpVertDoor[i]->getIsSpecial())
				{
					outputF << " True ";
					outputF << mpVertDoor[i]->getSpecialDoorSprite() << std::endl;
				}
				else
				{
					outputF << " False " << std::endl;
					if (mpVertDoor[i]->getIsOpen())
					{
						outputF << " True ";
						outputF << mpVertDoor[i]->getOpenDoorSprite() << std::endl;
					}

					else
					{
						outputF << " False ";
						outputF << mpVertDoor[i]->getClosedDoorSpite() << std::endl;
					}

				}

			
		}
	}
}

//If the game is  being continued by making a new game, reset all of the objects in the game
void Level::reset()
{
	for (unsigned int i = 0; i < mpStalfos.size(); i++)
	{
		mpStalfos[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpKese.size(); i++)
	{
		mpKese[i]->setIsActive(true);
	}

	for (unsigned int i = 0; i < mpGel.size(); i++)
	{
		mpGel[i]->setIsActive(true);
	}

	for (unsigned int i = 0; i < mpTreasures.size(); i++)
	{
		mpTreasures[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpHorizDoor.size(); i++)
	{
		mpHorizDoor[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpVertDoor.size(); i++)
	{
		mpVertDoor[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpAquamentus.size(); i++)
	{
		mpAquamentus[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpPeahat.size(); i++)
	{
		mpPeahat[i]->setIsActive(true);
	}
	for (unsigned int i = 0; i < mpSmurf.size(); i++)
	{
		mpSmurf[i]->setIsActive(true);
	}
}