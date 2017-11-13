#pragma once

#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <Trackable.h>
#include <map>
#include <string>


class Animation;
class BufferManager;
class GraphicsBuffer;
class GraphicsBufferManager;

typedef std::string AnimationKey;

class AnimationManager : public Trackable
{
private:
	std::map<AnimationKey, Animation*> mpAnimations;

public:
	AnimationManager();
	~AnimationManager();

	// UPDATE
	void updateAnimations();

	// MANIPULATING GRAPHICS BUFFERS
	void initAnimation(GraphicsBufferManager* mp_GBM);
	void addAnimation(std::string name, Animation* newAnimation);
	void removeAnimation(const AnimationKey& key);
	Animation* getAnimation(const AnimationKey& key);

	// DELETION
	void clearList();
};

#endif