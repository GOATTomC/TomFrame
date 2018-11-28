#pragma once
#include "../../Core.h"
#include <string>
#include <map>

namespace sf
{
	class Texture;
}

namespace TomFrame
{
	class TextureManager
	{
	public:
		TOMFRAME_API TextureManager();
		~TextureManager();

		/*Returns the requested texture if existing*/
		TOMFRAME_API sf::Texture* GetTexture(std::string spritePath);

	private:
		/*Search if we have used this texture before and returns it*/
		sf::Texture* SearchTexture(std::string spritePath);
		/*Saves the texture in to the manager and returns it*/
		sf::Texture* InsertTexture(std::string spritePath);


		//A map off all the stored textures
		std::map<std::string, sf::Texture*> m_LoadedTextures;


	};
}