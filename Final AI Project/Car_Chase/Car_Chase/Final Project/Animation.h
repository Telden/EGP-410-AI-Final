#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "Trackable.h"
#include <vector>

#include "Sprite.h"


class Animation : public Trackable
{
	
private:
    std::vector<Sprite> m_animation; 
	int m_total_sprites = 0;
	int m_currentSprite = 0;
	bool m_animation_reset = false;
	int m_currentSpeed = 10;
	int m_maxWaitAmount;
	int m_waitAmount;
	
public:
	Animation(int total_frames, int wait_amount);
	Animation();
	~Animation();
	bool m_RunAnimation = true;
	
	void update();
	int getCurrentSprite();
	double getFramerate();
	void increaseFramerate();
	void decreaseFramerate();
	void addSprite(Sprite spriteObj);
	Sprite getSprite(int index);


};

#endif
