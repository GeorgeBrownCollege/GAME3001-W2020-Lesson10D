#include "Level1Scene.h"
#include "Game.h"

Level1Scene::Level1Scene()
{
	Level1Scene::start();
}

Level1Scene::~Level1Scene()
= default;

void Level1Scene::draw()
{
	drawDisplayList();
}

void Level1Scene::update()
{
	updateDisplayList();
}

void Level1Scene::clean()
{

	removeAllChildren();
}

void Level1Scene::handleEvents()
{
	auto wheel = 0;
	
	SDL_Event event;
	SDL_Keycode keyPressed;
	SDL_Keycode keyReleased;
	
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			keyPressed = event.key.keysym.sym;
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				//TheGame::Instance()->changeSceneState(SceneState::PLAY_SCENE);
				break;
			case SDLK_2:
				//TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			}
			// movement keys
			{
				//unused
				/*
				if(keyPressed == SDLK_w)
				{

				}

				if (keyPressed == SDLK_s)
				{

				}
				*/

				if (keyPressed == SDLK_a)
				{
					m_pPlayer->setAnimationState(PLAYER_RUN_LEFT);
				}

				if (keyPressed == SDLK_d)
				{
					m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
				}
			}
			
			break;
		case SDL_KEYUP:
			keyReleased = event.key.keysym.sym;
			if (keyReleased == SDLK_a)
			{
				m_pPlayer->setAnimationState(PLAYER_IDLE_LEFT);
			}

			if (keyReleased == SDLK_d)
			{
				m_pPlayer->setAnimationState(PLAYER_IDLE_RIGHT);
			}
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pPlayer = new Player();
	addChild(m_pPlayer);
}
