#include "Block.h"

#include "../../Render/Sprite2D.h"

#include "../../Resources/ResourceManager.h"

namespace BatleCity
{
	Block::Block(EGameObjectType game_object_type, const EBlockType block_type, const glm::vec2& position,
				 const glm::vec2& size, const float rotation, const float layer) 

		: IGameObject(game_object_type, position, size, rotation, layer)
		, m_block_type(block_type)
	{ 
		switch (m_block_type)
		{
		case BatleCity::Block::EBlockType::All:
			m_colliders.emplace_back(glm::vec2(0.f), m_size);
			break;
		case BatleCity::Block::EBlockType::Top:
			m_colliders.emplace_back(glm::vec2(0.f, m_size.y / 2.f), m_size);
			break;
		case BatleCity::Block::EBlockType::Right:
			m_colliders.emplace_back(glm::vec2(m_size.x / 2.f, 0.f), m_size);
			break;
		case BatleCity::Block::EBlockType::Bottom:
			m_colliders.emplace_back(glm::vec2(0.f), glm::vec2(m_size.x, m_size.y / 2.f));
			break;
		case BatleCity::Block::EBlockType::Left:
			m_colliders.emplace_back(glm::vec2(0.f), glm::vec2(m_size.x / 2.f, m_size.y));
			break;
		case BatleCity::Block::EBlockType::LeftTop:
			m_colliders.emplace_back(glm::vec2(0.f, m_size.y / 2.f), m_size / 2.f);
			break;
		case BatleCity::Block::EBlockType::LeftBottom:
			m_colliders.emplace_back(glm::vec2(0.f), m_size / 2.f);
			break;
		case BatleCity::Block::EBlockType::RightBottom:
			m_colliders.emplace_back(glm::vec2(m_size.x / 2.f, 0.f), glm::vec2(m_size.x, m_size.y / 2.f));
			break;
		case BatleCity::Block::EBlockType::RightTop:
			m_colliders.emplace_back(m_size / 2.f, m_size / 2.f);
			break;
		case BatleCity::Block::EBlockType::LeftTop_RightBottom:
			break;
		case BatleCity::Block::EBlockType::RightTop_LeftBottom:
			break;
		case BatleCity::Block::EBlockType::WithoutLeftTop:
			break;
		case BatleCity::Block::EBlockType::WithoutLeftBottom:
			break;
		case BatleCity::Block::EBlockType::WithoutRightBottom:
			break;
		case BatleCity::Block::EBlockType::WithoutRightTop:
			break;
		case BatleCity::Block::EBlockType::Nothing:
			break;
		}
	}



	void Block::renderBlock(const ESubBlockLocation block_location) const
	{ }



	void Block::render() const
	{
		switch (m_block_type)
		{
		case BatleCity::Block::EBlockType::All:
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::LeftTop);
			renderBlock(ESubBlockLocation::RightTop);
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::Top:
			renderBlock(ESubBlockLocation::RightTop);
			renderBlock(ESubBlockLocation::LeftTop);
			break;
		case BatleCity::Block::EBlockType::Right:
			renderBlock(ESubBlockLocation::RightTop);
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::Bottom:
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::Left:
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::LeftTop);
			break;
		case BatleCity::Block::EBlockType::LeftTop:
			renderBlock(ESubBlockLocation::LeftTop);
			break;
		case BatleCity::Block::EBlockType::LeftBottom:
			renderBlock(ESubBlockLocation::LeftBottom);
			break;
		case BatleCity::Block::EBlockType::RightBottom:
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::RightTop:
			renderBlock(ESubBlockLocation::RightTop);
			break;
		case BatleCity::Block::EBlockType::LeftTop_RightBottom:
			renderBlock(ESubBlockLocation::LeftTop);
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::RightTop_LeftBottom:
			renderBlock(ESubBlockLocation::RightTop);
			renderBlock(ESubBlockLocation::LeftBottom);
			break;
		case BatleCity::Block::EBlockType::WithoutLeftTop:
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::RightBottom);
			renderBlock(ESubBlockLocation::RightTop);
			break;
		case BatleCity::Block::EBlockType::WithoutLeftBottom:
			renderBlock(ESubBlockLocation::LeftTop);
			renderBlock(ESubBlockLocation::RightBottom);
			renderBlock(ESubBlockLocation::RightTop);
			break;
		case BatleCity::Block::EBlockType::WithoutRightBottom:
			renderBlock(ESubBlockLocation::LeftTop);
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::RightTop);
			break;
		case BatleCity::Block::EBlockType::WithoutRightTop:
			renderBlock(ESubBlockLocation::LeftTop);
			renderBlock(ESubBlockLocation::LeftBottom);
			renderBlock(ESubBlockLocation::RightBottom);
			break;
		case BatleCity::Block::EBlockType::Nothing:
			break;
		}
	}



	void Block::update(const double delta)
	{ }
}