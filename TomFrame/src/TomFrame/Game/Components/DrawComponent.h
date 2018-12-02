#pragma once
#include <string>

namespace sf
{
	class Sprite;

	template<typename T>
	class Vector2;

	typedef Vector2<float> Vector2f;
}

namespace TomFrame
{
	class WorldObject;

	class DrawComponent
	{
	public:
		DrawComponent(WorldObject* owner);
		~DrawComponent();

		/*Returns the current sprite*/
		sf::Sprite* GetCurrentSprite() { return p_CurrentSprite; }
		/*Returns the size of the current sprite*/
		sf::Vector2f GetSpriteSize();

		/*Sets the current sprite*/
		void SetSprite(std::string spriteLocation);

	private:
		sf::Sprite* p_CurrentSprite = nullptr;

		WorldObject* p_Owner = nullptr;

	};
}