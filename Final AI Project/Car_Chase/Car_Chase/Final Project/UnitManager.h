#pragma once
#ifndef UNITMANAGER_H
#define UNITMANAGER_H

#include "Trackable.h"

#include "Unit.h"

typedef std::string UnitKey;
class UnitManager : public Trackable
{
private: 
	std::map<UnitKey, Unit*> mp_Units;
public:
	UnitManager();
	~UnitManager();


	//Map Functions
	void initUnits();
	void addUnit(std::string key, Unit*);
	Unit* getUnit(const UnitKey& key);
	void clearList();

};
#endif // !UNITMANAGER_H
