#include "LevelManager.h"

#include "Event.h"
#include <fstream>
#include <string>
#include <iostream>

#include "Animation.h"
#include "Sprite.h"

//Objects
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
#include "PapaSmurf.h"
#include "EnemyPeahat.h"

LevelManager::LevelManager(int scalar)
{
	mScalar = scalar;
	mGridSizeWithScalar = GRID_SIZE * mScalar; 
	mCompensationWithScalar = BG_COMPENSATION * mScalar;

	gpEventSystem->addListener(RESET_GAME_EVENT, this);
	gpEventSystem->addListener(END_GAME_EVENT, this);
	gpEventSystem->addListener(SAVE_GAME_EVENT, this);
	
}

LevelManager::~LevelManager()
{
	clearList();
	gpEventSystem->removeListenerFromAllEvents(this);
	delete mpLink;
}

//Opens up all of the level data files and loads in the data within it to be dispersed throughout the program when needed
void LevelManager::initLevels()
{
	mpLink = new Link(436, 436);
	std::ifstream inputF;
	std::string temp;
	char file_input;
	int c = 0, r = 0; //Columns and rows

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) 
		{
			temp = "Levels/level" + std::to_string(i) + std::to_string(j) + ".txt";
			inputF.open(temp);
			if (inputF.fail())
			{

			}
			else
			{
				//If successfully opened, add the level to the level map
				Level* tempLevel;
				std::string level = std::to_string(i) + std::to_string(j); // i + j = "1" + "5" for level name of "15" for example
				if (i == 0)
				{
					tempLevel = new Level("0" + std::to_string(j)); 
				}
				else
				{
					tempLevel = new Level(level);
				}
				std::cout << "Adding level " << level << std::endl;
				addLevel(level, tempLevel);

				//while (!inputF.eof())
				//{
				//		inputF >> file_input;
				//		switch (file_input)
				//		{
				//		case '1':
				//		{
				//			std::cout << "1";
				//			//Add right-facing statue
				//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 1));
				//			break;
				//		}

				//		case '2':
				//		{
				//			std::cout << "2";
				//			//Add a left-facing statue unit
				//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 2));
				//			break;
				//		}
				//		case '3':
				//		{
				//			std::cout << "3";
				//			//Add a block unit
				//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 3));
				//			break;
				//		}
				//		case '4':
				//		{
				//			std::cout << "4";
				//			//Add a sand unit
				//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 4));
				//			break;
				//		}
				//		case '5':
				//		{
				//			std::cout << "5";
				//			//Add a black unit
				//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 5));
				//			break;
				//		}
				//		case '6':
				//		{
				//			std::cout << "6";
				//			//Add a water unit
				//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 6));
				//			break;
				//		}
				//		case 'W':
				//		{	
				//			//Add a wall unit
				//			std::cout << "W";
				//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 7));
				//			break;
				//		}
				//		case 'A':
				//		{
				//			std::cout << "A";
				//			//Add a Bow Unit
				//			tempLevel->addTreasure(new Treasure("Bow",(mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 7));
				//			break;
				//		}
				//		case 'H':
				//		{
				//			std::cout << "H";
				//			//Add a door unit
				//			inputF >> file_input;
				//			if (file_input == 'D')
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//Add a right horizontal open door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
				//				}
				//				else
				//				{
				//					//Add a left horizontal open door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
				//				}
				//			}
				//			else if(file_input == 'L')//L
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//Add a right horizontal closed door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, false, false));
				//					
				//				}
				//				else
				//				{
				//					//Add a left horizontal closed door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, false, false));
				//					
				//				}
				//			}
				//			else //special locked door
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//Add a right Horizonal special door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, NULL, NULL, 4, false, true));
				//				}
				//				else
				//				{
				//					//add left Horizontal special door
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
				//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, NULL, NULL, 5, false, true));
				//				}
				//			}
				//			break;
				//		}
				//		case 'V':
				//		{
				//			std::cout << "V";
				//			//Add a locked door unit
				//			inputF >> file_input;
				//			if (file_input == 'D')
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//Add a right horizontal open door
				//					//std::cout << "Creating Door Object\n";
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
				//				}
				//				else
				//				{
				//					//Add a left horizontal open door
				//					//std::cout << "Creating Door Object\n";
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
				//				}
				//			}
				//			else if (file_input == 'L')
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//Add a right horizontal closed door
				//					//std::cout << "Creating Door Object\n";
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, false, false));
				//				}
				//				else
				//				{
				//					//Add a left horizontal closed door
				//					//std::cout << "Creating Door Object\n";
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, false, false));
				//				}
				//			}
				//			else
				//			{
				//				inputF >> file_input;
				//				if (file_input == '0')
				//				{
				//					//tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, 4, false, true));
				//				}
				//				else
				//				{
				//					//tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
				//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, 5, false, true));
				//				}
				//			}
				//			break;
				//		}
				//		case 'B':
				//		{
				//			//add a bat unit
				//			std::cout << "B";
				//			tempLevel->addEnemyKese(new EnemyKese((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
				//			break;
				//		}
				//		case 'K':
				//		{
				//			//Add a key unit
				//			std::cout << "K";
				//			tempLevel->addTreasure(new Treasure("Key",(mGridSizeWithScalar * c) + mCompensationWithScalar + 16, (mGridSizeWithScalar * r) + mCompensationWithScalar, 6));
				//			break;
				//		}
				//		case 'S':
				//		{
				//			//Add a skeleton unit
				//			std::cout << "S";
				//			tempLevel->addStalfos(new EnemyStalfos((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, false));
				//			break;
				//		}
				//		case 'Q':
				//		{
				//			//Add a Skeleton holding key
				//			tempLevel->addStalfos(new EnemyStalfos((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, true));
				//			break;
				//		}
				//		case 'C':
				//		{
				//			//Add a black unit
				//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 5));
				//			//Add a 'curse you papa smurf'
				//			tempLevel->addSmurf(new PapaSmurf((mGridSizeWithScalar * c) + mCompensationWithScalar + 160, (mGridSizeWithScalar * r) + mCompensationWithScalar));
				//			break;
				//		}
				//		case 'G':
				//		{
				//			//Add a Gel unit
				//			tempLevel->addEnemyGel(new EnemyGel((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
				//			break;
				//		}
				//		case 'D':
				//		{
				//			//Add Aquamentus unit
				//			tempLevel->addAquamentus(new Aquamentus((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
				//			break;
				//		}
				//		case 'T':
				//		{
				//			//Add Triforce
				//			tempLevel->addTreasure(new Treasure("Triforce",(mGridSizeWithScalar * c) + mCompensationWithScalar +42, (mGridSizeWithScalar * r) + mCompensationWithScalar +35, 0));
				//			break;

				//		}
				//		case 'P':
				//		{
				//			tempLevel->addPeahat(new EnemyPeahat((mGridSizeWithScalar * c) + mCompensationWithScalar + 42, (mGridSizeWithScalar * r) + mCompensationWithScalar + 35, true));
				//			break;
				//		}
				//		case 'p':
				//		{
				//			tempLevel->addPeahat(new EnemyPeahat((mGridSizeWithScalar * c) + mCompensationWithScalar + 42, (mGridSizeWithScalar * r) + mCompensationWithScalar + 35, false));
				//			break;
				//		}
				//		default:
				//		{
				//			std::cout << file_input;
				//			//std::cout << "I do not know what to do with " << file_input << std::endl;
				//			break;
				//		}

				//		
				//	}
				//		c++;

				//		if (c == TOTAL_COLUMNS)
				//		{
				//			std::cout << std::endl;
				//			c = 0;
				//			r++;
				//		}
				//}
				tempLevel = NULL;
			}
			inputF.close();
			std::cout << std::endl;
			c = 0;
			r = 0;
		}
	}
}

void LevelManager::loadSave()
{
	if (mpLink != false)
	{
		delete mpLink;
	}
	ifstream saveFile;
	std::string input_data, tag, filename, direction;
	int temp, locX, locY, spritenum;
	bool tempBool, isActive, linkCreated = false;;
	Level* tempLevel;
	saveFile.open(LOADFILEPATH);
	
	if (saveFile.fail())
	{
		std::cout << "File failed to open\n";
		initLevels();
	}
	else
	{
		saveFile >> input_data;
		mCurrentLevel = atoi(input_data.c_str());

	/*	while (!saveFile.eof())
		{*/
			
			//Load Link
		
			if (!linkCreated)
			{
				saveFile >> input_data;
				locX = atoi(input_data.c_str());
				saveFile >> input_data;
				locY = atoi(input_data.c_str());
				saveFile >> input_data;
				int numKeys = atoi(input_data.c_str());
				saveFile >> input_data;
				int currentHealth = atoi(input_data.c_str());
				saveFile >> input_data;
				int maxHealth = atoi(input_data.c_str());
				saveFile >> direction;
				saveFile >> input_data;
				if (input_data == "0")
					tempBool = false;
				else
					tempBool = true;

				mpLink = new Link(locX, locY, numKeys, currentHealth, maxHealth, direction, tempBool);
				linkCreated = true;
			}
	//	saveFile >> input_data;
	//	if (input_data != "0")
	//	{
	//		tempLevel = new Level(input_data);
	//		filename = input_data;
	//		std::cout << input_data << std::endl;
	//		loadSaveLevel(tempLevel, input_data); //Load the walls, blocks, and tiles
	//		addLevel(filename, tempLevel);

	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str()); //convert the string to an int;

	//													//Add Stalfos
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			saveFile >> input_data;
	//			if (input_data == "True")
	//			{
	//				tempBool = true;

	//			}

	//			else
	//				tempBool = false;

	//			tempLevel->addStalfos(new EnemyStalfos(locX, locY, tempBool));
	//			tempLevel->getEnemyStalfos(i)->setIsActive(isActive);
	//		}

	//		//Add this level's Kese
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			tempLevel->addEnemyKese(new EnemyKese(locX, locY));
	//			tempLevel->getEnemyKese(i)->setIsActive(isActive);
	//		}

	//		//Add this level's gel's
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			tempLevel->addEnemyGel(new EnemyGel(locX, locY));
	//			tempLevel->getEnemyGel(i)->setIsActive(isActive);
	//		}

	//		//Load this level's Peahats
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			saveFile >> input_data;
	//			if (input_data == "True")
	//				tempBool = true;
	//			else
	//				tempBool = false;
	//			tempLevel->addPeahat(new EnemyPeahat(locX, locY, tempBool));
	//			tempLevel->getPeahat(i)->setIsActive(isActive);
	//		}

	//		//Load this Level's AquaMentus
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			tempLevel->addAquamentus(new Aquamentus(locX, locY));
	//			tempLevel->getAquamentus(i)->setIsActive(isActive);
	//		}

	//		//Add this Level's treasures
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			saveFile >> input_data;
	//			spritenum = atoi(input_data.c_str());
	//			saveFile >> tag;
	//			tempLevel->addTreasure(new Treasure(tag, locX, locY, spritenum));
	//			tempLevel->getTreasure(i)->setIsActive(isActive);
	//		}

	//		//Add this Level's Horizontal's Doors
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			saveFile >> input_data;
	//			if (input_data == "True")
	//			{
	//				tempBool = true;
	//				saveFile >> input_data;
	//				spritenum = atoi(input_data.c_str());
	//				tempLevel->addHorizDoor(new HorizontalDoor(locX, locY, NULL, NULL, spritenum, NULL, tempBool));
	//				tempLevel->getHorizDoor(i)->setIsActive(isActive);
	//			}

	//			else //Not special door
	//			{
	//				saveFile >> input_data;
	//				if (input_data == "True") //is open
	//				{
	//					tempBool = true;
	//					saveFile >> input_data;
	//					spritenum = atoi(input_data.c_str());
	//					tempLevel->addHorizDoor(new HorizontalDoor(locX, locY, spritenum, NULL, NULL, true, false));
	//					tempLevel->getHorizDoor(i)->setIsActive(isActive);
	//				}
	//				else
	//				{
	//					tempBool = false;
	//					saveFile >> input_data;
	//					spritenum = atoi(input_data.c_str());
	//					tempLevel->addHorizDoor(new HorizontalDoor(locX, locY, NULL, spritenum, NULL, false, false));
	//					tempLevel->getHorizDoor(i)->setIsActive(isActive);
	//				}
	//			}

	//		}

	//		//Add this Level's Vertical Doors
	//		saveFile >> input_data;
	//		temp = atoi(input_data.c_str());
	//		for (int i = 0; i < temp; i++)
	//		{
	//			saveFile >> input_data;
	//			locX = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			locY = atoi(input_data.c_str());
	//			saveFile >> input_data;
	//			if (input_data == "0")
	//				isActive = false;
	//			else
	//				isActive = true;
	//			saveFile >> input_data;
	//			if (input_data == "True")
	//			{
	//				tempBool = true;
	//				saveFile >> input_data;
	//				spritenum = atoi(input_data.c_str());
	//				tempLevel->addVertDoor(new VerticalDoor(locX, locY, NULL, NULL, spritenum, NULL, tempBool));
	//				tempLevel->getVertDoor(i)->setIsActive(isActive);
	//			}

	//			else //Not special door
	//			{
	//				saveFile >> input_data;
	//				if (input_data == "True") //is open
	//				{
	//					tempBool = true;
	//					saveFile >> input_data;
	//					spritenum = atoi(input_data.c_str());
	//					tempLevel->addVertDoor(new VerticalDoor(locX, locY, spritenum, NULL, NULL, true, false));
	//					tempLevel->getVertDoor(i)->setIsActive(isActive);
	//				}
	//				else
	//				{
	//					tempBool = false;
	//					saveFile >> input_data;
	//					spritenum = atoi(input_data.c_str());
	//					tempLevel->addVertDoor(new VerticalDoor(locX, locY, NULL, spritenum, NULL, false, false));
	//					tempLevel->getVertDoor(i)->setIsActive(isActive);
	//				}
	//			}
	//		}

	//	}
	//	
	//	

	//	

	//	
	//}
	saveFile.close();
 }

}

void LevelManager::loadSaveLevel(Level* tempLevel, std::string levelName)
{
	//ifstream inputF;
	//char file_input;
	//int c = 0, r = 0;
	//
	//inputF.open("Save/level" + levelName + ".txt");
	//if(inputF.fail())
	//{
	//	std::cout << "File failed to open\n";
	//}
	//else
	//{
	//	while (!inputF.eof())
	//	{
	//		inputF >> file_input;
	//		switch (file_input)
	//		{
	//		case '1':
	//		{
	//			std::cout << "1";
	//			//Add right-facing statue
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 1));
	//			break;
	//		}

	//		case '2':
	//		{
	//			std::cout << "2";
	//			//Add a left-facing statue unit
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 2));
	//			break;
	//		}
	//		case '3':
	//		{
	//			std::cout << "3";
	//			//Add a block unit
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 3));
	//			break;
	//		}
	//		case '4':
	//		{
	//			std::cout << "4";
	//			//Add a sand unit
	//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 4));
	//			break;
	//		}
	//		case '5':
	//		{
	//			std::cout << "5";
	//			//Add a black unit
	//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 5));
	//			break;
	//		}
	//		case '6':
	//		{
	//			std::cout << "6";
	//			//Add a water unit
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 6));
	//			break;
	//		}
	//		case 'W':
	//		{
	//			//Add a wall unit
	//			std::cout << "W";
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 7));
	//			break;
	//		}
	//		case 'A':
	//		{
	//			std::cout << "A";
	//			//Add a Bow Unit
	//			tempLevel->addTreasure(new Treasure("Bow", (mGridSizeWithScalar * c) + mCompensationWithScalar + 16, (mGridSizeWithScalar * r) + mCompensationWithScalar, 7));
	//			break;
	//		}
	//		case 'H':
	//		{
	//			std::cout << "H";
	//			//Add a door unit
	//			inputF >> file_input;
	//			if (file_input == 'D')
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//Add a right horizontal open door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
	//				}
	//				else
	//				{
	//					//Add a left horizontal open door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
	//				}
	//			}
	//			else if (file_input == 'L')//L
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//Add a right horizontal closed door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, false, false));

	//				}
	//				else
	//				{
	//					//Add a left horizontal closed door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, false, false));

	//				}
	//			}
	//			else //special locked door
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//Add a right horizontal special door
	//					//tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 0, 2, NULL, true, false));
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, NULL, NULL, 4, false, true));
	//				}
	//				else
	//				{
	//					//tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, 1, 3, NULL, true, false));
	//					tempLevel->addHorizDoor(new HorizontalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar - 12, (mGridSizeWithScalar * r) + mCompensationWithScalar - 32, NULL, NULL, 5, false, true));
	//				}
	//			}
	//			break;
	//		}
	//		case 'V':
	//		{
	//			std::cout << "V";
	//			//Add a locked door unit
	//			inputF >> file_input;
	//			if (file_input == 'D')
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//Add a right horizontal open door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
	//				}
	//				else
	//				{
	//					//Add a left horizontal open door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
	//				}
	//			}
	//			else if (file_input == 'L')
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//Add a right horizontal closed door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, false, false));
	//				}
	//				else
	//				{
	//					//Add a left horizontal closed door
	//					//std::cout << "Creating Door Object\n";
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, false, false));
	//				}
	//			}
	//			else
	//			{
	//				inputF >> file_input;
	//				if (file_input == '0')
	//				{
	//					//tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, NULL, true, false));
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 0, 2, 4, false, true));
	//				}
	//				else
	//				{
	//					//tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, NULL, true, false));
	//					tempLevel->addVertDoor(new VerticalDoor((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar - 12, 1, 3, 5, false, true));
	//				}
	//			}
	//			break;
	//		}
	//		case 'B':
	//		{
	//			//add a bat unit
	//			std::cout << "B";
	//			tempLevel->addEnemyKese(new EnemyKese((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
	//			break;
	//		}
	//		case 'K':
	//		{
	//			//Add a key unit
	//			std::cout << "K";
	//			tempLevel->addTreasure(new Treasure("Key", (mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 6));
	//			break;
	//		}
	//		case 'S':
	//		{
	//			//Add a skeleton unit
	//			std::cout << "S";
	//			tempLevel->addStalfos(new EnemyStalfos((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, false));
	//			break;
	//		}
	//		case 'Q':
	//		{
	//			//Add a Skeleton holding key
	//			tempLevel->addStalfos(new EnemyStalfos((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, true));
	//			break;
	//		}
	//		case 'C':
	//		{
	//			//Add a black unit
	//			tempLevel->addTile(new Tile((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 5));
	//			//Add a 'curse you papa smurf'
	//			tempLevel->addSmurf(new PapaSmurf((mGridSizeWithScalar * c) + mCompensationWithScalar + 160, (mGridSizeWithScalar * r) + mCompensationWithScalar));
	//			break;
	//		}
	//		case 'G':
	//		{
	//			//Add a Gel unit
	//			tempLevel->addEnemyGel(new EnemyGel((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
	//			break;
	//		}
	//		case 'Y':
	//		{
	//			//Add a blackTile
	//			tempLevel->addBlock(new Block((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar, 5));
	//			break;
	//		}
	//		case 'D':
	//		{
	//			//Add Aquamentus unit
	//			tempLevel->addAquamentus(new Aquamentus((mGridSizeWithScalar * c) + mCompensationWithScalar, (mGridSizeWithScalar * r) + mCompensationWithScalar));
	//			break;
	//		}
	//		case 'T':
	//		{
	//			//Add Triforce
	//			tempLevel->addTreasure(new Treasure("Triforce", (mGridSizeWithScalar * c) + mCompensationWithScalar + 42, (mGridSizeWithScalar * r) + mCompensationWithScalar + 35, 0));
	//			break;

	//		}
	//		case 'P':
	//		{
	//			tempLevel->addPeahat(new EnemyPeahat((mGridSizeWithScalar * c) + mCompensationWithScalar + 42, (mGridSizeWithScalar * r) + mCompensationWithScalar + 35, true));
	//			break;
	//		}
	//		case 'p':
	//		{
	//			tempLevel->addPeahat(new EnemyPeahat((mGridSizeWithScalar * c) + mCompensationWithScalar + 42, (mGridSizeWithScalar * r) + mCompensationWithScalar + 35, false));
	//			break;
	//		}
	//		default:
	//		{
	//			std::cout << file_input;
	//			//std::cout << "I do not know what to do with " << file_input << std::endl;
	//			break;
	//		}


	//		}
	//		c++;

	//		if (c == TOTAL_COLUMNS)
	//		{
	//			std::cout << std::endl;
	//			c = 0;
	//			r++;
	//		}
	//	}
	//}
}

void LevelManager::update()
{
	mpLink->update();
	//getCurrentLevel()->update();
}

void LevelManager::render()
{
	
	//getCurrentLevel()->render();
	mpLink->render();
}

Level* LevelManager::getCurrentLevel()
{
	std::map<LevelKey, Level*>::const_iterator iter;
	if (mCurrentLevel < 10)
	{
		std::string tempString;
		tempString = "0" + std::to_string(mCurrentLevel);
		iter = mpLevels.find(tempString);
	}
	else
		iter = mpLevels.find(std::to_string(mCurrentLevel));
	
	if (iter != mpLevels.end())
	{
		return iter->second;
	}
	else
	{
		return NULL;
	}
}

void LevelManager::addLevel(std::string key, Level* newLevel)
{
	mpLevels.insert(std::pair<LevelKey, Level*>(key, newLevel));
}

//Return the total levels within the game whenever needed
int LevelManager::getTotalLevels()
{
	return m_total_levels;
}

void LevelManager::handleEvent(const Event& theEvent)
{
	 if (theEvent.getType() == END_GAME_EVENT)
	{
		saveGame();
	}
	 else if (theEvent.getType() == SAVE_GAME_EVENT)
	 {
		 saveGame();
	 }
	else if (theEvent.getType() == LOAD_LEFT_LEVEL)
	{
		mCurrentLevel -= 10;
	}
	else if (theEvent.getType() == LOAD_RIGHT_LEVEL)
	{
		mCurrentLevel += 10;
	}
	else if (theEvent.getType() == LOAD_UPPER_LEVEL)
	{
		mCurrentLevel -= 1;
	}
	else if (theEvent.getType() == LOAD_LOWER_LEVEL)
	{
		mCurrentLevel += 1;
	}
	else if (theEvent.getType() == RESET_GAME_EVENT)
	{
		mCurrentLevel = 25;
	}
	std::cout << "Loading Level: " << mCurrentLevel << std::endl;
}


void LevelManager::clearList()
{
	std::map<LevelKey, Level*>::iterator iter;
	for (iter = mpLevels.begin(); iter != mpLevels.end(); ++iter)
	{
		Level* pTmpPtr = iter->second;
		delete pTmpPtr;
	}
	mpLevels.clear();
}

bool LevelManager::checkCollisionWithWalls(Unit* check, int distanceX, int distanceY)
{
	// collision formula found here: https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection

	
	for (int i = 0; i < getCurrentLevel()->getHorizDoorSize(); i++)
	{
		if (check->getLocX() + distanceX < getCurrentLevel()->getHorizDoor(i)->getLocX() + 64 &&
			check->getLocX() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) + distanceX > getCurrentLevel()->getHorizDoor(i)->getLocX() &&
			check->getLocY() + distanceY  < getCurrentLevel()->getHorizDoor(i)->getLocY() + 64 &&
			check->getLocY() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) + distanceY> getCurrentLevel()->getHorizDoor(i)->getLocY() && 
			!getCurrentLevel()->getHorizDoor(i)->getIsOpen())
		{
			if (check == mpLink && mpLink->getNumKeys() > 0 && !getCurrentLevel()->getHorizDoor(i)->getIsSpecial())
			{
				getCurrentLevel()->getHorizDoor(i)->setIsActive(false);
				getCurrentLevel()->getHorizDoor(i)->setLocX(-1000);
				gpEventSystem->fireEvent(OPEN_DOOR_EVENT);
			}
			return true;
		}
	}

	for (int i = 0; i < getCurrentLevel()->getVertDoorSize(); i++)
	{
		//std::cout << "Player Y location " << check->getLocY() << " Door Y " << getCurrentLevel()->getVertDoor(i)->getLocY();
		if ((check->getLocX() + distanceX < getCurrentLevel()->getVertDoor(i)->getLocX() + 64 &&
			check->getLocX() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) + distanceX > getCurrentLevel()->getVertDoor(i)->getLocX() &&
			check->getLocY() + distanceY < getCurrentLevel()->getVertDoor(i)->getLocY() + 64 &&
			check->getLocY() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) + distanceY > getCurrentLevel()->getVertDoor(i)->getLocY() &&
			!getCurrentLevel()->getVertDoor(i)->getIsOpen()))
		{
			if (check == mpLink && mpLink->getNumKeys() > 0 && !getCurrentLevel()->getVertDoor(i)->getIsSpecial())
			{
				getCurrentLevel()->getVertDoor(i)->setIsActive(false);
				getCurrentLevel()->getVertDoor(i)->setLocX(-1000);
				gpEventSystem->fireEvent(OPEN_DOOR_EVENT);
			}
			return true;
		}
	}

	for (int i = 0; i < getCurrentLevel()->getWallSize(); i++)
	{
		if (check->getLocX() + distanceX < getCurrentLevel()->getWall(i)->getLocX() + 64 &&
			check->getLocX() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) + distanceX > getCurrentLevel()->getWall(i)->getLocX() &&
			check->getLocY() + distanceY < getCurrentLevel()->getWall(i)->getLocY() + 64 &&
			check->getLocY() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) + distanceY > getCurrentLevel()->getWall(i)->getLocY() )
		{
			return true;
		}
	}

	return false;
}

bool LevelManager::checkCollisionWithDoors(Unit* check, int distanceX, int distanceY)
{
	// collision formula found here: https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection

	for (int i = 0; i < getCurrentLevel()->getHorizDoorSize(); i++)
	{
		if (check->getLocX() < getCurrentLevel()->getHorizDoor(i)->getLocX() + getCurrentLevel()->getHorizDoor(i)->getAnimation().getSprite(getCurrentLevel()->getHorizDoor(i)->getAnimation().getCurrentSprite()).getWidth() * 4 &&
			check->getLocX() > getCurrentLevel()->getHorizDoor(i)->getLocX() &&
			check->getLocY() < getCurrentLevel()->getHorizDoor(i)->getLocY() + getCurrentLevel()->getHorizDoor(i)->getAnimation().getSprite(getCurrentLevel()->getHorizDoor(i)->getAnimation().getCurrentSprite()).getHeight() * 4 &&
			check->getLocY() > getCurrentLevel()->getHorizDoor(i)->getLocY())
		{
			return true;
		}
	}

	for (int i = 0; i < getCurrentLevel()->getVertDoorSize(); i++)
	{
		//std::cout << "Player Y location " << check->getLocY() << " Door Y " << getCurrentLevel()->getVertDoor(i)->getLocY();
		if (check->getLocX() < getCurrentLevel()->getVertDoor(i)->getLocX() + getCurrentLevel()->getVertDoor(i)->getAnimation().getSprite(getCurrentLevel()->getVertDoor(i)->getAnimation().getCurrentSprite()).getWidth() * 4 &&
			check->getLocX() > getCurrentLevel()->getVertDoor(i)->getLocX() &&
			check->getLocY() < getCurrentLevel()->getVertDoor(i)->getLocY() + getCurrentLevel()->getVertDoor(i)->getAnimation().getSprite(getCurrentLevel()->getVertDoor(i)->getAnimation().getCurrentSprite()).getHeight() * 4 &&
			check->getLocY() > getCurrentLevel()->getVertDoor(i)->getLocY())
		{
			return true;
		}
	}

	return false;
}

bool LevelManager::checkCollisionWithSword(Unit* check)
{
	if (check->getLocX() < mpLink->getSword()->getLocX() + (mpLink->getSword()->getAnimation().getSprite(0).getWidth() * 4) &&
		check->getLocX() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) > mpLink->getSword()->getLocX() &&
		check->getLocY() < (mpLink->getSword()->getLocY() + mpLink->getSword()->getAnimation().getSprite(0).getHeight() * 4) &&
		check->getLocY() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) > mpLink->getSword()->getLocY())
	{
		return true;
	}
	
	return false;
}

bool LevelManager::checkCollisionWithArrow(Unit* check)
{
	if (check->getLocX() < mpLink->getArrow()->getLocX() + (mpLink->getArrow()->getAnimation().getSprite(0).getWidth() * 4) &&
		check->getLocX() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) > mpLink->getArrow()->getLocX() &&
		check->getLocY() < (mpLink->getArrow()->getLocY() + mpLink->getArrow()->getAnimation().getSprite(0).getHeight() * 4) &&
		check->getLocY() + (check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) > mpLink->getArrow()->getLocY())
	{
		return true;
	}

	return false;
}

bool LevelManager::checkCollisionWithPlayer(Unit* check)
{
	//std::cout << "width: " << check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() << "\nheight: " << check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() << std::endl;
	if (check->getLocX() < mpLink->getLocX() + (mpLink->getAnimation().getSprite(mpLink->getAnimation().getCurrentSprite()).getWidth() * 4) &&
		(check->getLocX() + check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getHeight() * 4) > mpLink->getLocX() &&
		check->getLocY() < mpLink->getLocY() + (mpLink->getAnimation().getSprite(mpLink->getAnimation().getCurrentSprite()).getHeight() * 4) &&
		(check->getLocY() + check->getAnimation().getSprite(check->getAnimation().getCurrentSprite()).getWidth() * 4) > mpLink->getLocY())
	{
		return true;
	}
	return false;
}

void LevelManager::saveGame()
{
	ofstream outputF;
	outputF.open("Save/SaveData.txt", ios::trunc);
	if (outputF.fail())
	{
		std::cout << "File failed to open\n";
	}
	else // output link
	{
		outputF << mCurrentLevel << " " << mpLink->getLocX() << " " << mpLink->getLocY() << " " << mpLink->getNumKeys() << " " << mpLink->getCurrentHealth() << " " << mpLink->getMaxHealth() << " " << mpLink->getDirection() << " " << mpLink->getBowBool() << std::endl;
	}
	

	std::map<LevelKey, Level*>::iterator iter;
	for (iter = mpLevels.begin(); iter != mpLevels.end(); ++iter)
	{
		Level* pTmpPtr = iter->second;
		pTmpPtr->saveGame(pTmpPtr->getName(), outputF);
	}
	outputF.close();
}

void LevelManager::resetLevels()
{
	mpLink->setLocX(436); mpLink->setLocY(436);
	mCurrentLevel = 25;

	std::map<LevelKey, Level*>::iterator iter;
	for (iter = mpLevels.begin(); iter != mpLevels.end(); ++iter)
	{
		Level* pTmpPtr = iter->second;
		pTmpPtr->reset();
	}
}

void LevelManager::reloadLevels()
{
	ifstream saveFile;
	std::string input_data, tag, filename, direction;
	int temp, locX, locY, spritenum, currentRoom;
	bool tempBool, isActive, linkLoaded = false;
	saveFile.open(LOADFILEPATH);

	if (saveFile.fail())
	{
		std::cout << "File failed to open\n";
		initLevels();
	}
	else
	{
		saveFile >> input_data;
		currentRoom = atoi(input_data.c_str());

		while (!saveFile.eof())
		{

			//Load Link
			if (!linkLoaded)
			{
				saveFile >> input_data;
				locX = atoi(input_data.c_str());
				mpLink->setLocX(locX);
				saveFile >> input_data;
				locY = atoi(input_data.c_str());
				mpLink->setLocY(locY);
				saveFile >> input_data;
				int numKeys = atoi(input_data.c_str());
				mpLink->setNumKeys(numKeys);
				saveFile >> input_data;
				int currentHealth = atoi(input_data.c_str());
				mpLink->setCurrentHealth(currentHealth);
				saveFile >> input_data;
				int maxHealth = atoi(input_data.c_str());
				mpLink->setMaxHealth(maxHealth);
				saveFile >> direction;
				saveFile >> input_data;
				if (input_data == "0")
					tempBool = false;
				else
					tempBool = true;
				mpLink->setcanBow(tempBool);
				linkLoaded = true;
				
			}

			saveFile >> input_data;
			if (input_data != "0")
			{
				mCurrentLevel = atoi(input_data.c_str());
				std::cout << input_data << std::endl;


				saveFile >> input_data;
				temp = atoi(input_data.c_str()); //convert the string to an int;

												 //Add Stalfos
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyStalfos(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyStalfos(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					getCurrentLevel()->getEnemyStalfos(i)->setIsActive(isActive);

					saveFile >> input_data;
					if (input_data == "True")
					{
						tempBool = true;

					}

					else
						tempBool = false;
				}

				//Add this level's Kese
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyKese(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyKese(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					getCurrentLevel()->getEnemyKese(i)->setIsActive(isActive);
				}

				//Add this level's gel's
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyGel(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getEnemyGel(i)->setLocX(locX);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					getCurrentLevel()->getEnemyGel(i)->setIsActive(isActive);
				}

				//Load this level's Peahats
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getPeahat(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getPeahat(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					saveFile >> input_data;
					if (input_data == "True")
						tempBool = true;
					else
						tempBool = false;
					getCurrentLevel()->getPeahat(i)->setIsActive(isActive);
				}

				//Load this Level's AquaMentus
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getAquamentus(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getAquamentus(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					getCurrentLevel()->getAquamentus(i)->setIsActive(isActive);
				}

				//Add this Level's treasures
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getTreasure(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getTreasure(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					saveFile >> input_data;
					spritenum = atoi(input_data.c_str());
					saveFile >> tag;
					getCurrentLevel()->getTreasure(i)->setIsActive(isActive);
				}

				//Add this Level's Horizontal's Doors
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getHorizDoor(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getHorizDoor(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					saveFile >> input_data;
					if (input_data == "True")
					{
						tempBool = true;
						saveFile >> input_data;
						spritenum = atoi(input_data.c_str());
						
						getCurrentLevel()->getHorizDoor(i)->setIsActive(isActive);
					}

					else //Not special door
					{
						saveFile >> input_data;
						if (input_data == "True") //is open
						{
							tempBool = true;
							saveFile >> input_data;
							spritenum = atoi(input_data.c_str());
							getCurrentLevel()->getHorizDoor(i)->setIsActive(isActive);
							getCurrentLevel()->getHorizDoor(i)->setIsOpen(tempBool);
						}
						else
						{
							tempBool = false;
							saveFile >> input_data;
							spritenum = atoi(input_data.c_str());
							getCurrentLevel()->getHorizDoor(i)->setIsActive(isActive);
							getCurrentLevel()->getHorizDoor(i)->setIsOpen(tempBool);
						}
					}

				}

				//Add this Level's Vertical Doors
				saveFile >> input_data;
				temp = atoi(input_data.c_str());
				for (int i = 0; i < temp; i++)
				{
					saveFile >> input_data;
					locX = atoi(input_data.c_str());
					getCurrentLevel()->getVertDoor(i)->setLocX(locX);
					saveFile >> input_data;
					locY = atoi(input_data.c_str());
					getCurrentLevel()->getVertDoor(i)->setLocY(locY);
					saveFile >> input_data;
					if (input_data == "0")
						isActive = false;
					else
						isActive = true;
					saveFile >> input_data;
					if (input_data == "True")
					{
						tempBool = true;
						saveFile >> input_data;
						spritenum = atoi(input_data.c_str());
						getCurrentLevel()->getVertDoor(i)->setIsActive(isActive);
					}

					else //Not special door
					{
						saveFile >> input_data;
						if (input_data == "True") //is open
						{
							tempBool = true;
							saveFile >> input_data;
							spritenum = atoi(input_data.c_str());
							getCurrentLevel()->getVertDoor(i)->setIsActive(isActive);
							getCurrentLevel()->getVertDoor(i)->setIsOpen(tempBool);
						}
						else
						{
							tempBool = false;
							saveFile >> input_data;
							spritenum = atoi(input_data.c_str());
							getCurrentLevel()->getVertDoor(i)->setIsActive(isActive);
							getCurrentLevel()->getVertDoor(i)->setIsOpen(tempBool);
						}
					}
				}

			}
		}
		saveFile.close();
		mCurrentLevel = currentRoom;
	}
}
