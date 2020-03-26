#include "Player.h"
#include "Game.h"

Player::Player():m_currentRow(0), m_currentFrame(0), m_currentAnimationState(PLAYER_IDLE_RIGHT)
{
	TheTextureManager::Instance()->load(
		"../Assets/sprites/megaman-idle.png",
		"player-idle", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load(
		"../Assets/sprites/megaman-run.png",
		"player-run", TheGame::Instance()->getRenderer());

	// define frameWidth
	setWidth(81);

	// define frameHeight
	setHeight(58);

	setPosition(400.0f, 300.0f);
	setType(PLAYER);
	setIsColliding(false);
}

Player::~Player()
= default;

void Player::draw()
{
	switch(m_currentAnimationState)
	{
	case PLAYER_IDLE_RIGHT:
		TheTextureManager::Instance()->drawFrame(
			"player-idle", getPosition().x, getPosition().y,
			getWidth(), getHeight(),
			m_currentRow, m_currentFrame,
			4, 1, 0.12f,
			TheGame::Instance()->getRenderer(),
			0, 255, true);
		break;
	case PLAYER_IDLE_LEFT:
		TheTextureManager::Instance()->drawFrame(
			"player-idle", getPosition().x, getPosition().y,
			getWidth(), getHeight(),
			m_currentRow, m_currentFrame,
			4, 1, 0.12f,
			TheGame::Instance()->getRenderer(),
			0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	case PLAYER_RUN_RIGHT:
		TheTextureManager::Instance()->drawFrame(
			"player-run", getPosition().x, getPosition().y,
			getWidth(), getHeight(),
			m_currentRow, m_currentFrame,
			4, 1, 0.25f,
			TheGame::Instance()->getRenderer(),
			0, 255, true);
		break;
	case PLAYER_RUN_LEFT:
		TheTextureManager::Instance()->drawFrame(
			"player-run", getPosition().x, getPosition().y,
			getWidth(), getHeight(),
			m_currentRow, m_currentFrame,
			4, 1, 0.25f,
			TheGame::Instance()->getRenderer(),
			0, 255, true, SDL_FLIP_HORIZONTAL);
		break;
	}
	
	
	
	
}

void Player::update()
{
}

void Player::clean()
{
}

void Player::setAnimationState(const PlayerAnimationState state)
{
	m_currentAnimationState = state;
}
