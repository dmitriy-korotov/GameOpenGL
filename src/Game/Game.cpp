#include "Game.h"
#include "Level.h"

#include "../Resources/ResourceManager.h"

#include "../Render/ShaderProgram.h"
#include "../Render/Texture2D.h"
#include "../Render/Sprite2D.h"
#include "../Render/AnimatedSprite2D.h"

#include "GameObjects/Tank.h"

#include <GLFW/glfw3.h>
#include <iostream>

namespace BatleCity
{
	Game::Game(const glm::vec2& window_size) : m_window_size(window_size),
											   m_current_game_state(Game::EGameStates::Active)
	{ 
		m_keys.fill(false);
	}



	Game::~Game()
	{ }



	bool Game::init()
	{
        if (!Resources::ResourceManager::loadResourcesJSON("res/resources.json"))
        {
            std::cerr << "Can't load all resources from JSON" << std::endl;
            return false;
        }

        std::shared_ptr<RenderEngine::AnimatedSprite2D> tank_sprite = Resources::ResourceManager::getAnimatedSprite("yellowTankAnimatedSprite");
        if (tank_sprite == nullptr)
        {
            std::cerr << "Can't find animatad sprite: " << "yellowTankAnimatedSprite" << std::endl;
            return false;
        }
        tank_sprite->setState("tankTopState");

        m_tank = std::make_unique<Tank>(tank_sprite, glm::vec2(0.f, 0.f), glm::vec2(15.f, 15.f), 0.00000005f);
        m_tank2 = std::make_unique<Tank>(std::move(tank_sprite), glm::vec2(30.f, 30.f), glm::vec2(15.f, 15.f), 0.00000005f);
        m_level = std::make_unique<Level>(std::move(*Resources::ResourceManager::getLevel(1)));
		
        return true;
	}



	void Game::setKey(const int key, const int action)
	{
        m_keys[key] = action;
	}

	void Game::update(const uint64_t delta)
	{
       if (m_level)
       {
           m_level->update(delta);
       }
       if (m_tank)
       {
           if (m_tank)
           {
               if (m_keys[GLFW_KEY_W])
               {
                   m_tank->setOrientation(Tank::EOrientation::Top);
                   m_tank->move(true);
               }
               else if (m_keys[GLFW_KEY_D])
               {
                   m_tank->setOrientation(Tank::EOrientation::Right);
                   m_tank->move(true);
               }
               else if (m_keys[GLFW_KEY_S])
               {
                   m_tank->setOrientation(Tank::EOrientation::Bottom);
                   m_tank->move(true);
               }
               else if (m_keys[GLFW_KEY_A])
               {
                   m_tank->setOrientation(Tank::EOrientation::Left);
                   m_tank->move(true);
               }
               else
               {
                   m_tank->move(false);
               }
           }
           m_tank->update(delta);
       }

       if (m_tank2)
       {
           if (m_tank2)
           {
               if (m_keys[GLFW_KEY_UP])
               {
                   m_tank2->setOrientation(Tank::EOrientation::Top);
                   m_tank2->move(true);
               }
               else if (m_keys[GLFW_KEY_RIGHT])
               {
                   m_tank2->setOrientation(Tank::EOrientation::Right);
                   m_tank2->move(true);
               }
               else if (m_keys[GLFW_KEY_DOWN])
               {
                   m_tank2->setOrientation(Tank::EOrientation::Bottom);
                   m_tank2->move(true);
               }
               else if (m_keys[GLFW_KEY_LEFT])
               {
                   m_tank2->setOrientation(Tank::EOrientation::Left);
                   m_tank2->move(true);
               }
               else
               {
                   m_tank2->move(false);
               }
           }
           m_tank2->update(delta);
       }
	}



	void Game::render()
	{
        if (m_tank)
        {
            m_tank->render();
        }
        if (m_tank2)
        {
            m_tank2->render();
        }
        if (m_level)
        {
            m_level->render();
        }
	}
}