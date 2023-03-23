#include "IGameObject.h"
#ifndef I_DYNAMIC_GAME_OBJECT
#define I_DYNAMIC_GAME_OBJECT

namespace BatleCity
{
	class IDynamicGameObject : public IGameObject
	{
	public:


		enum class EOrientation
		{
			Top = 0,
			Right,
			Bottom,
			Left
		};


		IDynamicGameObject() = default;
		IDynamicGameObject(EGameObjectType game_object_type, const glm::vec2& position, const glm::vec2& size,
						   float rotation, float layer, const glm::vec2& direction, double velocity);

		virtual void onCollision(EGameObjectType game_object_type) = 0;

		void move(const glm::vec2& offset);
		virtual void setVelocity(double velocity);
		void setDirection(const glm::vec2& direction);

		double getVelocity() const;
		const glm::vec2& getDirection() const;

		inline bool isDestroy() const noexcept { return m_is_destroy; };

	protected:

		glm::vec2 m_direction = glm::vec2(0.f, 1.f);
		double m_velocity = 0;
		bool m_is_destroy = false;

	};
}

#endif // !I_DYNAMIC_GAME_OBJECT

