#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "DisplayObject.h"
#include "PlayerAnimationState.h"

class Player : public DisplayObject
{
public:
	Player();
	~Player();

	// DisplayObject LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters
	void setAnimationState(PlayerAnimationState state);
	
private:
	int m_currentRow;
	int m_currentFrame;

	PlayerAnimationState m_currentAnimationState;
};

#endif