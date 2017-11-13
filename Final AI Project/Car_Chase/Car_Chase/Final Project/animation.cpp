#include "Animation.h"

Animation::Animation(int total_frames, int wait_amount)
{
	m_animation.reserve(total_frames);
	m_maxWaitAmount = wait_amount;
	m_waitAmount = m_maxWaitAmount;
}

Animation::Animation()
{

}

Animation::~Animation()
{


}

void Animation::update()
{
	if (m_waitAmount > 0)
	{
		m_waitAmount--;
	}
	else
	{
		if (m_currentSprite < m_total_sprites - 1)
		{
			m_currentSprite++;
		}
		else
		{
			m_currentSprite = 0;
		}
		m_waitAmount = m_maxWaitAmount;
		
	}
}

int Animation::getCurrentSprite()
{
	return m_currentSprite;
}

double Animation::getFramerate()
{
	return m_currentSpeed;
}

void Animation::increaseFramerate()
{
	if(m_currentSpeed > 1)
		m_currentSpeed -= 1;
}

	
void Animation::decreaseFramerate()
{
	if (m_currentSpeed < 60)
		m_currentSpeed += 1;
}


void Animation::addSprite(Sprite spriteObj)
{
	m_animation.push_back(spriteObj);
	m_total_sprites++;
}

Sprite Animation::getSprite(int index)
{
	return m_animation[index];
}