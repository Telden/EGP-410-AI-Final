//REST IN PIECE YOU SWEET GLORIOUS BASTARDS

//Graphics System

//mpBlackBG = SDL_CreateRenderer(mpDisplay, 0, 0);
//SDL_SetRenderDrawColor(mpBlackBG, 255, 0, 0, 255);


//std::map<UnitKey, Unit*> mp_Units;
//
/*
//Map Functions
void addUnit(std::string key, Unit*);
Unit* getUnit(const UnitKey& key);
void clearList();
*/

/*
	void UnitManager::addUnit(std::string key, Unit* newUnit)
{
	mp_Units.insert(std::pair<UnitKey, Unit*>(key, newUnit));
}

Unit* UnitManager::getUnit(const UnitKey& key)
{
	std::map<UnitKey, Unit*>::const_iterator iter = mp_Units.find(key);
	if (iter != mp_Units.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

void UnitManager::clearList()
{
	std::map<UnitKey, Unit*>::iterator iter;
	for (iter = mp_Units.begin(); iter != mp_Units.end(); ++iter)
	{
		Unit* pTmpBuffer = iter->second;
		delete pTmpBuffer;
	}
	mp_Units.clear();
}





////Snake level loading
////Load level data
//inputF >> m_level[i]->m_SnakeSpeed;
//inputF >> m_level[i]->m_startingSegments;
//inputF >> m_level[i]->m_winCondition;
//inputF >> m_level[i]->m_FoodPoints;
//inputF >> m_level[i]->m_SpeedUpPoints;
//inputF >> m_level[i]->m_SpeedDownPoints;
//inputF >> m_level[i]->m_FoodSpawnFrequency;
//inputF >> m_level[i]->m_SpeedUpSpawnFrequency;
//inputF >> m_level[i]->m_SpeedDownSpawnFrequency;
//inputF >> m_level[i]->m_numWalls;
////Initialize the dynamic arrays with the number of walls within the specific level
//m_level[i]->m_wallX = new int[m_level[i]->m_numWalls];
//m_level[i]->m_wallY = new int[m_level[i]->m_numWalls];
//m_level[i]->m_animation = new int[m_level[i]->m_numWalls];
//m_level[i]->m_wall.reserve(m_level[i]->m_numWalls);

////Load all of the data corropsonding to each wall
//for (int j = 0; j < m_level[i]->m_numWalls; j++)
//{
//	inputF >> m_level[i]->m_wallX[j];
//	inputF >> m_level[i]->m_wallY[j];
//	inputF >> m_level[i]->m_animation[j];
//	m_level[i]->m_wall.push_back(Wall(m_level[i]->m_wallX[j], m_level[i]->m_wallY[j], m_level[i]->m_animation[j], mp_GS));

//Draw all of the wall object
void LevelManager::render()
{
for (int i = 0; i < m_level[m_currentLevel]->m_numWalls; i++)
{
m_level[m_currentLevel]->m_wall[i].draw(m_level[m_currentLevel]->m_wall[i].getSpriteNum());
}
}



m_foodSpawn = newLevel->m_FoodSpawnFrequency;
m_foodSpawnReset = newLevel->m_FoodSpawnFrequency;
m_PowerUpSpawn = newLevel->m_SpeedDownSpawnFrequency;
m_PowerUpSpawnReset = newLevel->m_SpeedDownSpawnFrequency;
m_PowerDownSpawn = newLevel->m_SpeedUpSpawnFrequency;
m_PowerDownSpawnReset = newLevel->m_SpeedUpSpawnFrequency;
m_winCondition = newLevel->m_winCondition;
mp_SM->setFrameDelay(newLevel->m_SnakeSpeed);
mp_SM->setTotalParts(newLevel->m_startingSegments);
mp_UI->setFoodPoints(newLevel->m_FoodPoints);
mp_UI->setPowerDownPoints(newLevel->m_SpeedUpPoints);
mp_UI->setPowerUpPoints(newLevel->m_SpeedDownPoints);
*/