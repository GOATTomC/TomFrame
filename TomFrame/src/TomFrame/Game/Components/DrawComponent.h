#pragma once
#include <string>

namespace sf
{
	class Sprite;
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

		/*Sets the current sprite*/
		void SetSprite(std::string spriteLocation);

	private:
		sf::Sprite* p_CurrentSprite = nullptr;

		WorldObject* p_Owner = nullptr;

	};
}