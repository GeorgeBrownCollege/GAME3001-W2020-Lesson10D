#include "Player.h"
#include "Game.h"

Player::Player():m_currentRow(0), m_currentFrame(0)
{
	TheTextureManager::Instance()->load(
		"../Assets/sprites/megaman-idle.png",
		"player-idle", TheGame::Instance()->getRenderer());

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
	TheTextureManager::Instance()->drawFrame(
		"player-idle", getPosition().x, getPosition().y,
		getWidth(), getHeight(),
		m_currentRow, m_currentFrame, 
		4, 1, 0.12f,
		TheGame::Instance()->getRenderer(),
		0, 255, true);
	
}

void Player::update()
{
}

void Player::clean()
{
}
