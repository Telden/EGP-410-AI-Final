#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include "Trackable.h"
#include <vector>



class Unit;
class EnemyStalfos;
class EnemyKese;
class EnemyGel;
class Block;
class Treasure;
class HorizontalDoor;
class VerticalDoor;
class Aquamentus;
class Tile;
class EnemyPeahat;
class PapaSmurf;

class Level : public Trackable
{

private:
	std::string mlevelName;
	//std::vector<Unit*> mpUnits;
	std::vector<EnemyStalfos*> mpStalfos;
	std::vector<EnemyGel*>mpGel;
	std::vector<Block*> mpBlocks;
	std::vector<Treasure*>mpTreasures;
	std::vector<EnemyKese*>mpKese;
	std::vector<HorizontalDoor*>mpHorizDoor;
	std::vector<VerticalDoor*>mpVertDoor;
	std::vector<Aquamentus*>mpAquamentus;
	std::vector<Tile*>mpTiles;
	std::vector<EnemyPeahat*>mpPeahat;
	std::vector<PapaSmurf*>mpSmurf;

public:
	Level(std::string levelName);
	~Level();

	//Add Objects to their individual vectors within the level
	void addStalfos(EnemyStalfos* newStalfos);
	void addBlock(Block* blockObj);
	void addTreasure(Treasure* treasureObj);
	void addEnemyKese(EnemyKese* keseObj);
	void addEnemyGel(EnemyGel* gelObj);
	void addHorizDoor(HorizontalDoor* horizDoorObj);
	void addVertDoor(VerticalDoor* horizDoorObj);
	void addAquamentus(Aquamentus* aquamentusObj);
	void addTile(Tile* tileObj);
	void addPeahat(EnemyPeahat* peahatObj);
	void addSmurf(PapaSmurf* smurfObj);

	void update();
	void render();

	//Reset Units
	void reset();

	std::string getName() { return mlevelName; }
	Block* getWall(int value) { return mpBlocks[value]; }
	HorizontalDoor* getHorizDoor(int value) { return mpHorizDoor[value]; }
	VerticalDoor* getVertDoor(int value) { return mpVertDoor[value]; }
	EnemyKese* getEnemyKese(int value) { return mpKese[value]; }
	EnemyStalfos* getEnemyStalfos(int value) { return mpStalfos[value]; }
	EnemyGel* getEnemyGel(int value) { return mpGel[value]; }
	Aquamentus* getAquamentus(int value) { return mpAquamentus[value]; }
	EnemyPeahat* getPeahat(int value) { return mpPeahat[value]; }
	PapaSmurf* getSmurf(int value) { return mpSmurf[value]; }
	Treasure* getTreasure(int value) { return mpTreasures[value]; }


	int getWallSize() { return mpBlocks.size(); }
	int getHorizDoorSize() { return mpHorizDoor.size(); }
	int getVertDoorSize() { return mpVertDoor.size(); }
	int getEnemyStalfosSize() { return mpStalfos.size(); }
	int getEnemyKeseSize() { return mpKese.size(); }
	int getAquamentusSize() { return mpAquamentus.size(); }
	int getPeahatSize() { return mpPeahat.size(); }
	int getSmurfSize() { return mpSmurf.size(); }
	

	//SAVE GAME
	void saveGame(std::string levelNum, std::ofstream& outputF);
	
};
#endif
