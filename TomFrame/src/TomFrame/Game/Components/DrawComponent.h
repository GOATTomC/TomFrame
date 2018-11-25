#pragma once
namespace sf
{
	class Sprite;
}

namespace TomFrame
{
	class DrawComponent
	{
	public:
		DrawComponent();
		~DrawComponent();

		sf::Sprite* GetCurrentSprite() { return p_CurrentSprite; }

	private:
		sf::Sprite* p_CurrentSprite = nullptr;

	};
}